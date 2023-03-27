#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, number_of_frame, x, pagefaultct = 0;
  vector<int> v;
  cin >> number_of_frame >> n;
  // 7,0,1,2,0,3,0,4,2,3,0,3,0,3,2,1,2,0,1,7,0,1
  vector<int> frame(number_of_frame, -1);
  bool f = 0;
  int p = 0;
  for (int i = 0; i < n; i++) {
    cin >> x;
    f = 0;
    for (int k = 0; k < number_of_frame; k++) {
      if (x == frame[k])
        f = 1;
    }
    if (f) {
      cout << x << "-> \n";
      pagefaultct++; // page fault hoinai...count
      continue;
    }
    frame[p] = x;
    cout << x << "-> ";
    int ct = 0;
    for (int j = 0; j < number_of_frame; j++) {
      if (frame[j] != -1) {
        cout << frame[j] << " ";
      }
    }
    if (!f)
      cout << "[Page fault occurred]";
    cout << endl;
    p++;
    if (p == number_of_frame)
      p = 0;
  }
  cout << "TOTAL PAGE FAULT : " << n - pagefaultct;
}