#include <bits/stdc++.h>

using namespace std;

#define MAX 200000000
bitset<MAX> sieve;

class Solution {
public:
    int primePalindrome(int N) {
        // init prime numbers using Eratosthenes
        for (int i=2; i<sqrt(MAX); i++) {
            cout << i << endl;
            for (int j=i; j<MAX; j+=i) {
                sieve.set(j);
                sieve.
            }
        }
        return N;
    }
};

int main() {
    Solution s;

    cout << s.primePalindrome(6) << endl;
    cout << s.primePalindrome(8) << endl;
    cout << s.primePalindrome(13) << endl;
}

