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

    // exposing list in public
    std::vector<std::tuple<std::chrono::microseconds, std::chrono::microseconds,
                           std::chrono::microseconds>> list;

    void testWith(void sortF(std::vector<long long>::iterator,
                             std::vector<long long>::iterator));
    void clearList();
    void printList();
    unsigned int getUpLim() { return upLim; }
};
