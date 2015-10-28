#include "cs-iv-algorithm.h"

unsigned int sortT::findSentinel() {

    /*
     * Get numeric limit of long long
     * find out max upperlimit by clean divide of 10
    */

    return std::numeric_limits<long long>::digits10;
}

void sortT::seed() {
    // reserve upLim amount of sub-vectors
    random.reserve(upLim);
    asc.reserve(upLim);
    desc.reserve(upLim);

    for (unsigned int i = 1; i <= upLim; ++i) {
        unsigned int j = i;
        long long limit = 1;
        while (j != 0) {
            limit *= 10;
            --j;
        }

        // r,a,d represent sub-vectors for random,...
        std::vector<long long> r, a, d;
        r.reserve(limit);
        a.reserve(limit);
        d.reserve(limit);

        // random number generation
        std::random_device rd;
        std::mt19937 eng(rd());
        std::uniform_int_distribution<> distr(1, 10000);

        for (long long k = 1; k <= limit; ++k) {
            r.push_back(distr(eng));
            a.push_back(k);
            d.push_back(limit - k);
        }

        random.push_back(r);
        asc.push_back(a);
        desc.push_back(d);
    }
}

void sortT::testWith(void sortF(std::vector<long long>::iterator,
                                std::vector<long long>::iterator)) {
    unsigned int i = 0;

    while (i < upLim) {
        auto tp1 = std::chrono::high_resolution_clock::now();
        sortF(random[i].begin(), random[i].end());
        auto tp2 = std::chrono::high_resolution_clock::now();
        auto duration1 =
            std::chrono::duration_cast<std::chrono::microseconds>(tp2 - tp1);

        tp1 = std::chrono::high_resolution_clock::now();
        sortF(asc[i].begin(), asc[i].end());
        tp2 = std::chrono::high_resolution_clock::now();
        auto duration2 =
            std::chrono::duration_cast<std::chrono::microseconds>(tp2 - tp1);

        tp1 = std::chrono::high_resolution_clock::now();
        sortF(desc[i].begin(), desc[i].end());
        tp2 = std::chrono::high_resolution_clock::now();
        auto duration3 =
            std::chrono::duration_cast<std::chrono::microseconds>(tp2 - tp1);

        list.push_back(std::make_tuple(duration1, duration2, duration3));
        ++i;
    }
}

void sortT::printList() {
    unsigned int i = 1;

    std::cout << std::left;
    std::cout << std::setw(10) << "Iteration" << std::setw(0) << "|\t";
    std::cout << std::setw(10) << "limit" << std::setw(0) << "|\t";
    std::cout << std::setw(10) << "RandomBox" << std::setw(0) << "|\t";
    std::cout << std::setw(10) << "AscBox" << std::setw(0) << "|\t";
    std::cout << std::setw(10) << "DescBox" << std::setw(0) << "|\t";

    for (auto &listTuple : list) {

        unsigned int j = i;
        long long limit = 1;
        while (j > 0) {
            limit *= 10;
            --j;
        }

        std::cout << "\n";
        std::cout << std::setw(10) << i << std::setw(0) << "|\t";
        std::cout << std::setw(10) << limit << std::setw(0) << "|\t";
        std::cout << std::setw(10) << std::get<0>(listTuple).count()
                  << std::setw(0) << "|\t";
        std::cout << std::setw(10) << std::get<1>(listTuple).count()
                  << std::setw(0) << "|\t";
        std::cout << std::setw(10) << std::get<2>(listTuple).count()
                  << std::setw(0) << "|\t";

        ++i;
    }
    std::cout << std::endl;
}
