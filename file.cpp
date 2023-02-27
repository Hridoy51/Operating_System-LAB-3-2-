#include <bits/stdc++.h>
using namespace std;
// input D:\Academic  Study Material\THIRD YEAR\EVEN SEMISTER\Operating
// System\Lab
int main() {
  string operation;
  cin >> operation;
  cin.ignore();
  if (operation == "Create") {
    string name;
    getline(cin, name);
    ofstream newname(name.c_str());
    newname.close();
  } else if (operation == "Rename") {
    string newname, oldname;
    getline(cin, oldname);
    getline(cin, newname);
    int flag = rename(oldname.c_str(), newname.c_str());
    if (flag)
      cout << "Error!\n";
    else
      cout << "Sucessfull\n";
  } else if (operation == "Delete") {
    string oldname;
    getline(cin, oldname);
    int flag = remove(oldname.c_str());
    if (flag)
      cout << "Error!\n";
    else
      cout << "Sucessfull\n";
  } else if (operation == "Copy") {
    string from, to;
    getline(cin, from);
    getline(cin, to);
    ifstream source(from.c_str());
    ofstream destination(to.c_str());
    string s;
    if (source and destination) {
      while (getline(source, s)) {
        destination << s << "\n";
      }
      cout << "successfully copied\n";
    } else
      cout << "Error!\n";
  } else if (operation == "Move") {
    string from, to;
    getline(cin, from);
    getline(cin, to);
    ifstream source(from.c_str());
    ofstream destination(to.c_str());
    string s;
    if (source and destination) {
      while (getline(source, s)) {
        destination << s << "\n";
      }
      source.close();
      remove(from.c_str());
      cout << "successfully moved\n";
    } else
      cout << "Error!\n";
  }
}