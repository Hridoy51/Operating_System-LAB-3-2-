#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, number_of_frame, x;
  vector<int> v;
  int pagefaultct = 0;
  cin >> number_of_frame >> n;
  map<int, int> m;
  // 7,0,1,2,0,3,0,4,2,3,0,3,0,3,2,1,2,0,1,7,0,1
  vector<int> frame(number_of_frame, -1);
  for (int i = 0; i < n; i++) {
    cin >> x;
    v.push_back(x);
  }
  int ct = 0, f = 0;
  for (int i = 0; i < n; i++) {
    m[v[i]] = i;
    f = 0;
    for (int k = 0; k < number_of_frame; k++) {
      if (v[i] == frame[k])
        f = 1;
    }
    if (f) {
      cout << v[i] << "-> \n";
      pagefaultct++;
      continue;
    }
    if (ct < number_of_frame) {
      frame[ct] = v[i];
      ct++;
    } else {
      int r = INT32_MAX, temp;
      for (int j = 0; j < number_of_frame; j++) {
        if (r > m[frame[j]]) {
          r = m[frame[j]];
          temp = j;
        }
      }
      frame[temp] = v[i];
    }
    cout << v[i] << "-> ";
    for (int j = 0; j < number_of_frame; j++) {
      if (frame[j] != -1) {
        cout << frame[j] << " ";
      }
    }
    if (!f)
      cout << "[Page fault occurred]";
    cout << endl;
  }
  cout << "TOTAL PAGE FAULT : " << n - pagefaultct;
}