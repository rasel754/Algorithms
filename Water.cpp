#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<int> H(n);
        for (int i = 0; i < n; i++) {
            cin >> H[i];
        }

        int max1 = -1, idx1 = -1;
        int max2 = -1, idx2 = -1;

        for (int i = 0; i < n; i++) {
            if (H[i] > max1) {
                max2 = max1;
                idx2 = idx1;
                max1 = H[i];
                idx1 = i;
            } else if (H[i] > max2) {
                max2 = H[i];
                idx2 = i;
            }
        }

        if (idx1 < idx2) {
            cout << idx1 << " " << idx2 << endl;
        } else {
            cout << idx2 << " " << idx1 << endl;
        }
    }

    return 0;
}