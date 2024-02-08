#include <iostream>

#include "package.hpp"
using namespace std;

const char VERSION[] = "0.0.1";

void checkArgs(int, string[]);

int main(int argc, char *argv[]) {
  // Convert args to strings
  string args[argc];
  for (int i = 0; i < argc; i++) {
    args[i] = argv[i];
  }
  // Compute Args
  if (argc >= 2) {
    cout << "Fuzzbucket Package Manager" << endl;
    checkArgs(argc, args);
  }
}

void checkArgs(int argc, string args[]) {
  if (args[1].compare("help") == 0) {
    cout << "Commands:" << endl;
    cout << "- build: generates build files for project" << endl
         << "- get {url}: adds repo to dependency list and downloads it" << endl
         << "- help: displays this output" << endl
         << "- init: create new Fuzzbucket project" << endl
         << "- list: lists packages installed" << endl
         << "- version: shows fuzzbucket version" << endl;
    exit(0);
  } else if (args[1].compare("version") == 0) {
    cout << "Version: " << VERSION << endl;
    exit(0);
  }
}
