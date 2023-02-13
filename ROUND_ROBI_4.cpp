#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, q, x;
  cin >> n >> q;
  queue<pair<int, int>> Burst;
  vector<int> BT(n + 1);
  for (int i = 1; i <= n; i++) {
    cin >> x;
    BT[i] = x;
    Burst.push({i, x});
  }
  int time = 0;
  vector<int> Time_Break, Task;
  map<int, int> TurnOver;
  while (!Burst.empty()) {
    pair<int, int> a;
    a = Burst.front();
    Burst.pop();
    if (a.second <= q) {
      time += a.second;
      TurnOver[a.first] = time;
      Time_Break.push_back(time);
      Task.push_back(a.first);

    } else {
      time += q;
      a.second -= q;
      Time_Break.push_back(time);
      Task.push_back(a.first);
      Burst.push(a);
    }
  }
  cout << "TASK :  ";
  int avgT = 0, avgW = 0;
  for (int i = 1; i <= n; i++) {
    cout << i << " ";
  }
  cout << endl << "TURN :  ";
  for (int i = 1; i <= n; i++) {
    cout << TurnOver[i] << " ";
    avgT += TurnOver[i];
  }
  cout << endl << "Wait :  ";
  for (int i = 1; i <= n; i++) {
    cout << TurnOver[i] - BT[i] << " ";
    avgW += TurnOver[i] - BT[i];
  }
  cout << endl;
  cout << "AVERAGE TURNOVER : " << (double)avgT / n << endl;
  cout << "AVG WAITING : " << (double)avgW / n << endl;
  cout << "THE GANDCHART: " << endl << 0;
  for (int i = 0; i < Time_Break.size(); i++) {
    cout << "---P" << Task[i] << "---" << Time_Break[i];
  }
}