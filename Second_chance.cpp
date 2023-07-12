#include <bits/stdc++.h>
using namespace std;
int lengthOfSequence, numOfFrames;
vector<int> bits(100, 0);
vector<int> frames(100, -1);
int pointer = 0;
bool isThere(int x) {
  for (int i = 0; i < numOfFrames; i++) {
    if (frames[i] == x) {
      bits[i] = 1;
      return true;
    }
  }
  return false;
}
void replace(int x) {
  while (true) {
    if (!bits[pointer]) {
      frames[pointer] = x;
      pointer = (pointer + 1) % numOfFrames;
      break;
    } else {
      bits[pointer] = 0;
      pointer = (pointer + 1) % numOfFrames;
    }
  }
}
void printframes(vector<int> frames) {
  for (int i = 0; i < numOfFrames; i++) {
    if (frames[i] != -1)
      cout << frames[i] << " ";
  }
  cout << endl;
}
int main() {

  cin >> lengthOfSequence >> numOfFrames;
  int x;
  int ct = 0;
  for (int i = 0; i < lengthOfSequence; i++) {
    cin >> x;
    if (isThere(x)) {
      cout << x << "-> \n";
      // printframes(frames);
      ct++;
    } else {
      replace(x);
      cout << x << "-> ";
      // cout << frames[0];
      printframes(frames);
    }
  }
  cout << "Num of Page fault is " << lengthOfSequence - ct;
}