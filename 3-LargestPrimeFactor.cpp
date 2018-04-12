#include <iostream>
#include <cmath>

using namespace std;
class Solution {
public:
    int getLargestPrimeFactor(unsigned long long num) {
        int max = int(sqrt(num));
        int *array = (int*)malloc((max + 1) * sizeof(int));
        for (int i = 0; i < max + 1; ++i) array[i] = 1;
        array[0] = 0;
        array[1] = 0;
        for (int i = 2; i < max + 1; ++i) {
            if (array[i]) {
                for (int j = i + i; j < max + 1; j += i) {
                    array[j] = 0;
                }
            }
        }
        for (int i = max; i >= 0; --i) {
            if (array[i] && num % i == 0) {
                return i;
            }
        }
        free(array);
        return -1;
    }
};

int main() {
    Solution test;
    cout << test.getLargestPrimeFactor(600851475143) << endl;
    return 0;
}
