#include <iostream>
#include <vector>
#include <queue>
#include <deque>
using namespace std;


struct shark {
   int r, c, s, d, z;
};
int R, C, M;
int ans = 0;
int fisherman = 0;
vector<shark> sharks;
deque<int> arr[101][101];
int dir[5][2] = { {0,0},{-1,0},{1,0},{0,1},{0,-1} }; 

void kill() {
   for (int i = 1; i <= R; i++) {
      for (int j = 1; j <= C; j++) {
         deque<int>& q = arr[i][j];
         if (q.size() <= 1) continue;
         while (q.size() != 1) {
            shark& a = sharks[q[0]];
            shark& b = sharks[q[1]];
            if (a.z < b.z) {
               a.z = -1;
            } else {
               b.z = -1;
               q[1] = q[0];
            }
            q.pop_front();
         }
      }
   }
   
}

void move() {
   for (int i = 0; i < sharks.size(); ++i) {
      shark& tmp = sharks[i];
      if (tmp.z == -1) continue;

      arr[tmp.r][tmp.c].pop_front();
      if (tmp.d == 1 || tmp.d == 2) {
         int dist = tmp.s % ((R-1)*2);
         for (int j = 0; j < dist; j++) {
            int dr = tmp.r + dir[tmp.d][0];
            if (dr > R) {
               tmp.d = 1;
               dr -= 2;
            }
            if (dr < 1) {
               tmp.d = 2;
               dr += 2;
            }
            tmp.r = dr;
         }
      }
      else {
         int dist = tmp.s % ((C-1)*2);
         for (int j = 0; j < dist; j++) {
            int dc = tmp.c + dir[tmp.d][1];
            if (dc > C) {
               tmp.d = 4;
               dc -= 2;
            }
            if (dc < 1) {
               tmp.d = 3;
               dc+= 2;
            }
            tmp.c = dc;
         }
      }
      arr[tmp.r][tmp.c].push_back(i);
   }
}

void fishing() {
   for (int c = 1; c <= C; ++c) {
      for (int r = 1; r <= R; ++r) {
         if (arr[r][c].size() > 0) {
            int i = arr[r][c][0];
            ans += sharks[i].z;
            sharks[i].z = -1; //상어의 크기를 -1로 바꾸어서 죽은 놈이라는 것을 알림
            arr[r][c].pop_front();
            break; //맨위에 상어만 잡으니까 break
         }
      }
      move();
      kill();
   }
}
int main() {
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   cout.tie(NULL);
   cin >> R >> C >> M;

   for(int i=0;i<M;i++) {
      int r, c, s, d, z;
      cin >> r >> c >> s >> d >> z;
      arr[r][c].push_back(i);
      //입력에 두마리가 한 곳에 오는 경우는 없다
      sharks.push_back({ r,c,s,d,z });
   }

   fishing();
   cout << ans << endl;
   return 0;
}