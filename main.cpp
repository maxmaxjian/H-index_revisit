#include <iostream>
#include <vector>
#include <algorithm>

// class Pred {
//   private:
//     int num;

//   public:
//     Pred(int n) : num(n) {}

//     void incr() {
//         num++;
//     }

//     int get() {
//         return num;
//     }

//     bool operator()(int i) {
//         return i > num;
//     }
// };

// class solution {
//   public:
//     int hIndex(const std::vector<int> & citations) {
//         int min = *std::min_element(citations.begin(), citations.end());
//         Pred pred(min);
//         auto cites = citations;
//         auto it = std::partition(cites.begin(), cites.end(), pred);
//         while (it-cites.begin() > pred.get()) {
//             pred.incr();
//             it = std::partition(cites.begin(), cites.end(), pred);
//         }
//         return pred.get();
//     }
// };

#include <iterator>

class solution {
  public:
    int hIndex(const std::vector<int> & citations) {
        int hidx = *std::min_element(citations.begin(), citations.end());
        auto cites = citations;
        auto it = std::partition(cites.begin(), cites.end(), [&](int i){return i >= hidx;});
        std::cout << hidx << " -> ";
        std::copy(cites.begin(), cites.end(), std::ostream_iterator<int>(std::cout, " "));
        std::cout << std::endl;
        while (it-cites.begin() > hidx) {
            hidx++;
            it = std::partition(cites.begin(), cites.end(), [&](int i){return i >= hidx;});
            std::cout << hidx << " -> ";
            std::copy(cites.begin(), cites.end(), std::ostream_iterator<int>(std::cout, " "));
            std::cout << std::endl;
        }        
        if (it != cites.begin())
            return hidx;
        else
            return 0;
    }
};

int main() {
    std::vector<int> citations{3,0,1,6,5};

    solution soln;
    int hidx = soln.hIndex(citations);
    std::cout << "The H-index is:\n"
              << hidx << std::endl;
}
