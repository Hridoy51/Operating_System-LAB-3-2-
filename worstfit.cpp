#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, x;
  string s;
  cin >> n;
  vector<pair<int, int>> v;
  for (int i = 1; i <= n; i++) {
    cin >> x;
    cin >> s;
    v.push_back({x, i});
  }
  sort(v.rbegin(), v.rend());
  int new_task;
  cin >> new_task >> s;
  for (auto a : v) {
    if (a.first >= new_task) {
      cout << "The new Process is get the free slot number " << a.second
           << " where the size is " << a.first << " " << s << endl;
      return 0;
    }
  }
  cout << "There is no free slot to fit the new Process";
}