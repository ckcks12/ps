#include <bits/stdc++.h>

using namespace std;

int f(int n, int k) {
    if (n > 0 && k == 0) return 0;
    else if (n == 0 && k > 0) return 0;
    else if (n == 0 && k == 0) return 1;
    else if (n == 1 && k == 1) return 1;

    int a;
    if (n & 1) a = n - 2;
    else a = n - 1;
    for (int i = a; i >= 1; i-=2)
        if (f(n - i, k - 1)) return 1;
    return 0;
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int T, n, k, m;

    cin >> T;
    while (T--) {
        cin >> n >> k;
        if (k == 1)
            if (n & 1) cout << "YES" << endl;
            else cout << "NO" << endl;
        else if (k == 2 && n & 1) cout << "YES" << endl;
        else cout << (f(n, k) ? "YES" : "NO") << endl;
    }
}


