//
// Created by Eunchan Lee on 3/20/20.
//

#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int T;
    cin >> T;

    T--;
    int a1;
    cin >> a1;

    int ma = a1;
    cout << ma << " ";

    int n;
    while (T--) {
        cin >> n;
        cout << ma + n << " ";
        ma = max(ma, ma + n);
    }
    cout << endl;
}



