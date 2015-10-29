#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <tuple>
#include <iomanip>

class sortT {
   private:
    std::vector<std::vector<long long>> asc;
    std::vector<std::vector<long long>> desc;
    std::vector<std::vector<long long>> random;
    unsigned int upLim; // Upperlimit 1=10, 2=100...
    void seed();
    unsigned int findSentinel(); // returns largest upperlimit possible

  public:
    // default + param constructor -> calls seed()
    sortT(unsigned int lim = 3) : upLim(lim) {
        if (upLim < 1)
            upLim = 3;
        else {
            unsigned int s = findSentinel();
            if (upLim > s) { upLim = 3; }
        }
        seed();
    };

 public:
    // default + param constructor -> calls seed()
    sortT(unsigned int lim = 3) : upLim(lim) {
        if (upLim < 1)
            upLim = 3;
        else {
            unsigned int s = findSentinel();
            if (upLim > s) { upLim = 3; }
        }
        seed();
    };

    // exposing list in public
    std::vector<std::tuple<std::chrono::microseconds, std::chrono::microseconds,
                           std::chrono::microseconds>> list;

    void testWith(void sortF(std::vector<long long>::iterator,
                             std::vector<long long>::iterator));
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
    unsigned int getUpLim() { return upLim; }
};
