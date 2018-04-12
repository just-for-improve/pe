#include <iostream>

using namespace std;

class Solution {
    public:
        int MultiplesOf3And5(int limit) {
            int sum = 0;
            for (int i = 0; i < limit; ++i) {
                if (i % 3 == 0 || i % 5 == 0) {
                    sum += i;
                }
            }
            return sum;
        }
        // sum-3 = 3 + 6 + 9 + ... + 999 = 3 * (1 + 2 + ... + 333)
        // sum-5 = 5 + 10 + 15 + ... + 995 = 5 * (1 + 2 + ... + 199)
        // added twice: sum-15 = 15 + 30 + 45 + ...
        // so sum = sum-3 + sum-5 - sum-15 
        //
        int bestSolution(int limit) {
            return sumDivisibleBy(3, limit) + sumDivisibleBy(5, limit) - sumDivisibleBy(15, limit);
        }
        // how to cal sum-n
        // sum-3 = 3 * (1 + 333) * 333 / 2
        // sum-5 = 5 * (1 + 199) * 199 / 2
        int sumDivisibleBy(int n, int limit) {
            return n * (1 + (limit) / n) * (limit / n) / 2;
        }
};

int main()
{
    Solution test;
    cout << test.bestSolution(999) << endl;
    return 0;
}
