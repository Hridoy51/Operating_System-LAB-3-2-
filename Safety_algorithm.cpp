#include <bits/stdc++.h>
using namespace std;
int p, r;
int available[1000];
int maximun[1000][1000];
int allocation[1000][1000], need[1000][1000];
int work[1000];
vector<int> safeSequence;

vector<int> finished(1000, 0);
bool Valid_need(int p) {
  int ct = 0;
  for (int i = 0; i < r; i++) {
    if (work[i] >= need[p][i])
      ct++;
  }
  if (ct == r)
    return 1;
  return 0;
}
bool safety_sequence() {
  int ct = 0;
  for (int i = 0; i < r; i++)
    work[i] = available[i];
  for (int i = 0; i < p; i++) {
    if (!finished[i] and Valid_need(i)) {
      for (int j = 0; j < r; j++)
        work[j] += allocation[i][j];
      safeSequence.push_back(i);
      finished[i] = 1;
      i = -1;
      ct++;
    } else {
      if (i == p - 1) {
        return false;
      }
    }
    if (p == ct) {
      break;
    }
  }
  return true;
}
void printSeq() {
  for (auto a : safeSequence)
    cout << a << " ";
  cout << endl;
}
int main() {
  cin >> p >> r;
  for (int i = 0; i < r; i++)
    cin >> available[i];
  for (int i = 0; i < p; i++) {
    for (int j = 0; j < r; j++) {
      cin >> maximun[i][j];
    }
  }
  for (int i = 0; i < p; i++) {
    for (int j = 0; j < r; j++) {
      cin >> allocation[i][j];
      need[i][j] = maximun[i][j] - allocation[i][j];
    }
  }
  if (safety_sequence()) {
    cout << "THE Safety Sequence is : ";
    printSeq();
  } else {
    cout << "THERE IS NO SAFE SEQUENCE";
  }
}