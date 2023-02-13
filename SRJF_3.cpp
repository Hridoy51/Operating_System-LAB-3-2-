#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, b, a;
  cin >> n;
  vector<int> Arrival(100);
  vector<int> BT(100);
  priority_queue<pair<int, int>> Q;
  for (int i = 1; i <= n; i++) {
    cin >> b;
    Q.push({-b, i});
    Arrival[i] = 0;
    BT[i] = b;
  }
  int m;
  cin >> m;
  vector<pair<int, int>> V;
  for (int i = n + 1; i <= (n + m); i++) {
    cin >> a >> b;
    Arrival[n + 1] = a;
    V.push_back({b, i});
    BT[i] = b;
  }
  int time = 0;
  vector<int> Task;
  map<int, int> ComplitionTime;
  while (!Q.empty()) {
    pair<int, int> a;
    a = Q.top();
    Q.pop();
    a.first = abs(a.first);
    a.first -= 1;
    time++;
    if (!a.first) {
      ComplitionTime[a.second] = time;
    }
    Task.push_back(a.second);
    int k = 0;
    if (time <= m) {
      Q.push({-V[k].first, V[k].second});
      k++;
    }
  }
  cout << "TASK :  ";
  int avgT = 0, avgW = 0;
  for (int i = 1; i <= n + m; i++) {
    cout << i << " ";
  }
  cout << endl << "TURN :  ";
  for (int i = 1; i <= n + m; i++) {
    cout << ComplitionTime[i] - Arrival[i] << " ";
    avgT += ComplitionTime[i] - Arrival[i];
  }
  cout << endl << "Wait :  ";
  for (int i = 1; i <= n + m; i++) {
    cout << ComplitionTime[i] - Arrival[i] - BT[i] << " ";
    avgW += ComplitionTime[i] - Arrival[i] - BT[i];
  }
  cout << endl;
  cout << "AVERAGE TURNOVER : " << (double)avgT / n << endl;
  cout << "AVG WAITING : " << (double)avgW / n << endl;
  cout << "THE GANDCHART: " << endl << 0;
  int j = 1;
  for (int i = 0; i < Task.size(); i++) {
    cout << "---P" << Task[i] << "---" << j;
    j++;
  }
}