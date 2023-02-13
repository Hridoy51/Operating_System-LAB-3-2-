#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, x;
  cin >> n;
  vector<pair<int, int>> Burst;
  vector<int> BT(n + 1);
  map<int, int> TurnOver;
  for (int i = 1; i <= n; i++) {
    cin >> x;
    BT[i] = x;
    Burst.push_back({x, i});
  }
  sort(Burst.begin(), Burst.end());
  int turn = 0;

  for (auto a : Burst) {

    turn += a.first;
    TurnOver[a.second] = turn;
  }
  cout << "AVERAGE TURNOVER : " << (double)turn / n << endl;
  cout << "AVG WAITING : " << (double)TurnOver[n - 1] / 2 << endl;
  cout << "TASK :  ";
  for (int i = 1; i <= n; i++) {
    cout << i << " ";
  }
  cout << endl << "TURN :  ";
  for (int i = 1; i <= n; i++) {
    cout << TurnOver[i] << " ";
  }
  cout << endl << "Wait :  ";
  for (int i = 1; i <= n; i++) {
    cout << TurnOver[i] - BT[i] << " ";
  }
  cout << endl << "THE GANDCHART: " << endl << 0;

  for (auto a : Burst) {
    cout << "---P" << a.second << "---" << TurnOver[a.second];
  }
}