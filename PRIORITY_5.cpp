#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  int p, b;
  vector<int> BT(n + 1);
  vector<pair<int, pair<int, int>>> V;
  for (int i = 1; i <= n; i++) {
    cin >> p >> b;
    V.push_back({p, {b, i}});
    BT[i] = b;
  }
  sort(V.begin(), V.end());

  vector<pair<int, int>> Burst;

  map<int, int> TurnOver;
  for (auto a : V) {
    Burst.push_back({a.second.first, a.second.second});
  }
  // sort(Burst.begin(), Burst.end());
  int turn = 0;

  for (auto a : Burst) {

    turn += a.first;
    TurnOver[a.second] = turn;
  }

  cout << "TASK :  ";
  for (int i = 1; i <= n; i++) {
    cout << i << " ";
  }
  int t = 0, w = 0;
  cout << endl << "TURN :  ";
  for (int i = 1; i <= n; i++) {
    cout << TurnOver[i] << " ";
    t += TurnOver[i];
  }
  cout << endl << "Wait :  ";
  for (int i = 1; i <= n; i++) {
    cout << TurnOver[i] - BT[i] << " ";
    w += (TurnOver[i] - BT[i]);
  }
  cout << endl << "AVERAGE TURNOVER : " << (double)t / n << endl;
  cout << "AVG WAITING : " << (double)w / n << endl;
  cout << endl << "THE GANDCHART: " << endl << 0;

  for (auto a : Burst) {
    cout << "---P" << a.second << "---" << TurnOver[a.second];
  }
}
