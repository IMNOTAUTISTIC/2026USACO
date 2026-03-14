#include <iostream>
#include <vector>
#include <numeric>
#include <cmath>
#include <algorithm>
#include <cstdint> 

using namespace std;

void solve() {
    int n;
    if (!(cin >> n)) return; // vbase case

    vector<int64_t> p(n);
    int64_t total_sum = 0;

    for (int i = 0; i < n; ++i) {
        cin >> p[i];
        total_sum += p[i];
    }

    int64_t min_diff = -1;

    for (int i = 0; i < (1 << n); ++i) {
        int64_t current_group_sum = 0;
        for (int j = 0; j < n; ++j) {
            if ((i >> j) & 1) {
                current_group_sum += p[j];
            }
        }

        int64_t other_group_sum = total_sum - current_group_sum;
        int64_t current_diff = abs(current_group_sum - other_group_sum);

        if (min_diff == -1 || current_diff < min_diff) {
            min_diff = current_diff;
        }
    }

    cout << min_diff << endl;
}

int main() {
    solve();
    return 0;
}
