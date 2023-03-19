#include <bits/stdc++.h>
#define vti vector<int>
using namespace std;
int p, r;
int visited[10000];
vti graph[1000];
int global, dead = 0;
void dfs(int x) {
  if (!visited[x])
    visited[x] = 1;
  for (int i = 0; i < graph[x].size(); i++) {
    if (graph[x][i] == global) {
      dead = 1;
      return;
    }
    if (!visited[i])
      dfs(graph[x][i]);
  }
}
int main() {
  string a, b;
  cin >> p >> r;
  vti in_r[r + 1], out_r[r + 1];
  while (cin >> a >> b) {

    int x = a[1] - 48;
    int y = b[1] - 48;
    if (a[0] == 'p') {
      in_r[y].push_back(x);
    } else
      out_r[x].push_back(y);
  }
  for (int i = 1; i <= r; i++) {
    for (int j = 0; j < in_r[i].size(); j++) {
      for (int k = 0; k < out_r[i].size(); k++) {
        graph[in_r[i][j]].push_back(out_r[i][k]);
      }
    }
  }
  for (int i = 1; i <= p; i++) {
    for (int j = 0; j <= p; j++)
      visited[j] = 0;
    if (dead == 1) {
      break;
    }
    global = i;
    if (!visited[i]) {
      dfs(i);
    }
  }
  if (dead == 1)
    cout << "DEADLOCK DETECTED";
  else
    cout << "THERE IS NO DEADLOCK";
}