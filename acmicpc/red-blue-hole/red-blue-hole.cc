#include <bits/stdc++.h>

using namespace std;

bool V[100][100];
char M[100][100];
int R, G, B, T;

int check(char c, int x, int y) {
	if (!(0 <= x && x<T && 0 <= y && y < T)) return 0;
	if (V[y][x]) return 0;
	int cnt = 0;
	if (M[y][x] == c) cnt++;
	else return 0;
	V[y][x] = true;
	return cnt + (
		check(c, x-1, y) + 
		check(c, x+1, y) +
		check(c, x, y-1) +
		check(c, x, y+1)
	);
}

int checkRG(int x, int y) {
	if (!(0 <= x && x<T && 0 <= y && y < T)) return 0;
	if (V[y][x]) return 0;
	int cnt = 0;
	if (M[y][x] == 'R' || M[y][x] == 'G') cnt++;
	else return 0;
	V[y][x] = true;
	return cnt + (
		checkRG(x-1, y) +
		checkRG(x+1, y) +
		checkRG(x, y-1) +
		checkRG(x, y+1) 
	);
}

int main() {
	cin >> T;
	for (int y=0; y<T; ++y)
		for (int x=0; x<T; ++x)
			cin >> M[y][x];

	for (int y=0; y<T; ++y)
		for (int x=0; x<T; ++x) {
			char c = M[y][x];
			if (c == 'R' && check('R', x, y) > 0) R++;
			else if (c == 'G' && check('G', x, y) > 0) G++;
			else if (c == 'B' && check('B', x, y) > 0) B++;
		}
	cout << R + G + B << " ";
	R = 0;
	G = 0;
	B = 0;
	memset(V, 0, 100 * 100);
	for (int y=0; y<T; ++y)
		for (int x=0; x<T; ++x) {
			char c = M[y][x];
			if (c == 'R' || c == 'G'){
				if (checkRG(x, y) > 0) R++;
			}
			else if (c == 'B' && check('B', x, y) > 0) {
				B++;
			}
		}
	cout << R + B << endl;
}