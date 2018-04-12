#include <iostream>

#define ARRAY_MAX 100
#define MAX 4000000

using namespace std;

class Solution {
    public:
        // the simplest solution
        unsigned long getSumofEvenFibonacciNumbers() {

            int last1 = 1;
            int last2 = 2;
            int now;

            unsigned long sum = 2;
            for (int i = 2; last1 + last2 < MAX; ++i) {
                now = last1 + last2;
                last1 = last2;
                last2 = now;
                if (now % 2 == 0) sum += now;
            }
            return sum;

        }
        // better solutions:
        // 1. we can find that every third numbers is even, so the if statement is not needed
        // 2. all even numbers -- have a beautiful structure: F(n) = F(n - 1) + F(n - 2)  = 4F(n-3) + F(n - 6);
};


int main()
{
    Solution test;
    cout << test.getSumofEvenFibonacciNumbers() << endl;
}
