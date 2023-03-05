#include <bits/stdc++.h>
using namespace std;
int p, r;
int available[1000];
int request[1000][1000];
int allocation[1000][1000];
int work[1000];
vector<int> safeSequence;

bool Valid_req(int p) {
  int ct = 0;
  for (int i = 0; i < r; i++) {
    if (work[i] >= request[p][i])
      ct++;
  }
  if (ct == r)
    return 1;
  return 0;
}
bool Detect_Dead_Lock() {
  vector<int> finished(1000, 0);
  int ct = 0, cut = 0;
  for (int i = 0; i < r; i++)
    work[i] = available[i];
  for (int i = 0; i < p; i++) {
    int cnt = 0;
    for (int j = 0; j < r; j++) {
      if (allocation[i][j] == 0)
        cnt++;
    }
    if (cnt == r) {
      finished[i] = true;
      safeSequence.push_back(i);
    }
  }

  for (int i = 0; i < p; i++) {
    if (!finished[i] and Valid_req(i)) {
      for (int j = 0; j < r; j++)
        work[j] += allocation[i][j];
      safeSequence.push_back(i);
      finished[i] = 1;
      ct++;
    }
    if (i == p - 1) {
      i = -1;
      cut++;
    }
    if (cut > p or ct == p)
      break;
  }
  return (ct == p);
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
      cin >> allocation[i][j];
    }
  }
  for (int i = 0; i < p; i++) {
    for (int j = 0; j < r; j++) {
      cin >> request[i][j];
    }
  }
  if (Detect_Dead_Lock()) {
    cout << "THE System is not in a dead...There is a safe sequence \nThe "
            "sequence is : ";
    printSeq();
  } else {
    cout << "The System is in a DEAD_LOCK ";
  }
}