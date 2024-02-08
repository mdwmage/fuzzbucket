#include <string>

enum version { latest, commit, tag, release };

class Package {
 private:
  std::string source;
  version lockType;
  bool isLocked;
  std::string lock;

 public:
  // Constructors and Deconstructor
  Package();
  Package(std::string);
  Package(std::string, version);
  Package(std::string, version, std::string);
  ~Package();
  // Getters & Setters
  std::string getSource();
  std::string getLock();
  version getLockType();
  bool getIsLocked();
  void setSource(std::string);
  void setIsLocked(bool);
  void setLock(std::string);
  void setLock(bool, std::string);
  void setLockType(version);
  // Methods
  void download();
  std::string toString();
};
