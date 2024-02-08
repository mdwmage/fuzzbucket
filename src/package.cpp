#include "package.hpp"

#include <string>
using namespace std;

// Functions
string versionToString(version ver) {
  string s = "";
  switch (ver) {
    case latest:
      s = "latest";
      break;
    case commit:
      s = "commit";
      break;
    case tag:
      s = "tag";
      break;
    case release:
      s = "release";
      break;
    default:
      s = "latest";
  }
  return s;
}

/*******************
 * Class Definition
 ******************/

// Constructors
Package::Package() {
  source = "source.xyz/user/repo.git";
  lockType = version::latest;
  lock = "none";
}

Package::Package(string src) {
  setSource(src);
  setLockType(version::latest);
  setIsLocked(false);
  setLock("");
}

Package::Package(string src, version ver) {
  setSource(src);
  setLockType(ver);
  setIsLocked(false);
  setLock("");
}

Package::Package(string src, version ver, string lok) {
  setSource(src);
  setLockType(ver);
  setIsLocked(true);
  setLock(lok);
}

// Deconstructor
Package::~Package() {}

// Getters
version Package::getLockType() { return lockType; }
string Package::getSource() { return source; }
string Package::getLock() { return lock; }
bool Package::getIsLocked() { return isLocked; }

// Setters
void Package::setLockType(version ver) { lockType = ver; }
void Package::setSource(string src) { source = src; }
void Package::setLock(string lok) { lock = lok; }
void Package::setIsLocked(bool lok) { isLocked = lok; }

// Methods
string Package::toString() {
  string s = "latest";
  switch (lockType) {
    case latest:
      s = "latest";
      break;
    case commit:
      s = "commit";
      break;
    case tag:
      s = "tag";
      break;
    case release:
      s = "release";
      break;
    default:
      s = "latest";
  }

  if (isLocked) {
    return source + "@" + versionToString(lockType) + " via: " + lock;
  } else {
    return source + versionToString(lockType);
  }

  return source + versionToString(lockType) + " via: " + lock;
}
