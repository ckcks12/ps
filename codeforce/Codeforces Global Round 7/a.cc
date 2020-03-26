//
// Created by Eunchan Lee on 3/19/20.
//

#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        if (n == 1) {
            cout << -1 << endl;
            continue;
        }
        cout << 2;
        for (int i = n - 1; i > 0; --i) {
           cout << 3;
        }
        cout << endl;
    }
}


