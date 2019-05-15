#pragma once

#include <string>

namespace Metacarpal {

class Producer {
 private:
  unsigned int count;
  unsigned int failed;

 public:
  Producer();
  void test(std::string name);
  void pass(std::string message = "");
  void fail(std::string message = "");
  void ok(bool isOk, std::string message = "");
  template <class T>
  void equal(T value, T expected, std::string message = "") {}
  int end();
};

}  // namespace Metacarpal
