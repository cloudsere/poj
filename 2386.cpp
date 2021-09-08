#include <iostream>
using namespace std;
#define MAX_N 100
#define MAX_M 100

int N, M;
char field[MAX_N][MAX_M];

void dfs(int i, int j) {
    field[i][j] = '.';
	for (int dx = -1; dx <= 1; dx++) {
	  for (int dy = -1; dy <= 1; dy++) {
	     int x = i + dx;
	     int y = j + dy;
	     if (x < N && y < M && x >= 0 && y >= 0 && field[x][y] == 'W') {
	       dfs(x, y);
	     }
	  }
	}
}

int main() {
  cin >> N >> M;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      cin >> field[i][j];
    }
  }

  int result = 0;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      if (field[i][j] == 'W') {
	      dfs(i, j);
	      result++;
      }
    }
  }
  
  cout << result << endl;
  return 0;
}