#include <bits/stdc++.h>
using namespace std;
/*
 * @lc app=leetcode id=866 lang=cpp
 *
 * [866] Prime Palindrome
 */

// @lc code=start
        bitset<200000000> B;
class Solution {
public:
    int primePalindrome(int N) {
        int d = 0;
        int n = N;
        while (0 < n && ++d)
            n /= 10;
        int k = (d + 1) / 2;

        for (int i = 2; i < 10; ++i)
            if (isPrime(i)) B[i] = 1;
        
        if (N < 10) {
            for (int i = N; i < 11; ++i)
                if (B[i]) return i;
            return 11;
        }

        if (isPrime(N) && isPalindrome(N)) {
            return N;
        }

        int p = N;
        while (p < 200000000) {
            p = nextPalindrome(p);
            // cout << p << endl;
            if (isPrime(p)) return p;
        }

        return -1;
    }
    int isPalindrome(int p) {
        int d = 0;
        int m = p;
        while (0 < m && ++d)
            m /= 10;
        int k = (d + 1) / 2;
        
        int r = p;
        m = 0;
        for (int i = 0; i < d-k; ++i) {
            m += r % 10;
            m *= 10;
            r /= 10;
        }

        if (d & 1) return r == m;
        else return r == m/10;

    }
    int nextPalindrome(int n) {
        int d = 0;
        int m = n;
        while (0 < m && ++d)
            m /= 10;
        int k = (d + 1) / 2;
        
        int R = n;
        for (int i = 0; i < d-k; ++i)
            R /= 10;

        int p, r;

        r = R / 10;
        p = r;
        while (0 < r) {
            p *= 10;
            p += r % 10;
            r /= 10;
        }
        if (n < p) return p;
        
        r = R + 1;
        r /= 10;
        p = R + 1;
        while (0 < r) {
            p *= 10;
            p += r % 10;
            r /= 10;
        }
        if (n < p) return p;

        r = R;
        p = r;
        while (0 < r) {
            p *= 10;
            p += r % 10;
            r /= 10;
        }
        if (n < p) return p;

        r = R + 1;
        p = r;
        while (0 < r) {
            p *= 10;
            p += r % 10;
            r /= 10;
        }
        return p;
    }
    bool isPrime(int n) {
        if (n <= 3) return true;
        if (n % 2 == 0 || n % 3 == 0) return false;
        for (int i=5; i*i<=n; i+=6) 
            if (n % i == 0 || n % (i + 2) == 0)
                return false;
        return true;
    }
};
// @lc code=end


int main() {
    Solution s;
    cout << s.primePalindrome(102) << endl;
}