#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <cstdint>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int64_t> p(n);
    for(int i = 0; i < n; i++) {
        cin >> p[i];
    };
    int64_t min_diff = -1;
    for(int i = 0; i < (1 << n); i++) {
        int64_t sum1 = 0; // of first basket
        int64_t sum2 = 0; // of second
        for (int j = 0; j < n; j++) {    
            if ((i >> j) & 1) {
                sum1 += p[j];
            } else {
                sum2 += p[j];
            };
        };
        int64_t diff = abs(sum1 - sum2);
        int64_t min_diff = LLONG_MAX; 
        if (diff < min_diff) {
            min_diff = diff;
        }

    }
    cout << min_diff;
    return 0;
}
