#include <bits/stdc++.h>

using namespace std;

// File Name Format: "D:\Academic  Study Material\THIRD YEAR\EVEN
// SEMISTER\Operating System\Lab"

int main() {
  string operation;
  cin >> operation;
  cin.ignore();
  if (operation == "Create") {
    string name;
    getline(cin, name);
    ofstream newFile(name.c_str());
    time_t timeNow =
        chrono::system_clock::to_time_t(chrono::system_clock::now());
    newFile << "File has created\nTime: " << ctime(&timeNow) << endl;
    newFile.close();

  } else if (operation == "Rename") {
    string oldname, newname;
    getline(cin, oldname);
    getline(cin, newname);
    int mark = rename(oldname.c_str(), newname.c_str());
    if (mark) {
      cout << "Error renaming file!";
    } else
      cout << "File successfully renamed";
  } else if (operation == "Delete") {
    string fileName;
    getline(cin, fileName);
    int mark = remove(fileName.c_str());
    if (mark) {
      cout << "Couldn't delete file!";
    } else
      cout << "File successfully deleted";
  } else if (operation == "Copy") {
    string from, to;
    getline(cin, from);
    getline(cin, to);
    string line;
    // For writing text file
    // Creating ofstream & ifstream class object
    ifstream in_file(from.c_str());
    ofstream out_file(to.c_str());
    if (in_file and out_file) {
      while (getline(in_file, line)) {
        out_file << line << endl;
      }

      printf("File copied successfully");
    } else {
      // Something went wrong
      printf("Cannot read File");
    }

    // Closing file
    in_file.close();
    out_file.close();
  } else
    cout << "Invalid operation name!";
}