#include <bits/stdc++.h>
using namespace std;
int p, r;
int available[1000];
int maximun[1000][1000];
int allocation[1000][1000], need[1000][1000];
int work[1000];
vector<int> safeSequence;

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
  vector<int> finished(1000, 0);
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
  safeSequence.clear();
}
bool vlaid_req(int p, vector<int> req) {
  int ct = 0;
  for (int i = 0; i < r; i++) {
    if (need[p][i] >= req[i] and available[i] >= req[i])
      ct++;
  }
  return (ct == r);
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
  cout << "BEFORE REQUEST : \n";
  if (safety_sequence()) {
    cout << "THE Safety Sequence is : ";
    printSeq();
  } else {
    cout << "THERE IS NO SAFE SEQUENCE\n";
  }
  cout << "AFTER REQUEST : \n";
  int req_pro;
  cin >> req_pro;
  vector<int> req(r);
  for (int i = 0; i < r; i++)
    cin >> req[i];
  if (!vlaid_req(req_pro, req)) {
    cout << "THE REQUEST IS INVALID\n";
  } else {
    for (int i = 0; i < r; i++) {
      allocation[req_pro][i] += req[i];
      need[req_pro][i] -= req[i];
      available[i] -= req[i];
    }
    if (safety_sequence()) {
      cout << "YES, THE REQUEST IS GRANTED... \n After the request the "
              "safeSequence : ";
      printSeq();
    } else {
      cout << "THERE IS NO SAFE SEQUENCE THE SYSTEM IS ROOLED BACK\n";
    }
  }
}