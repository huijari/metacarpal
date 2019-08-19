#pragma once

#include <iostream>
#include <string>

namespace Metacarpal {

class Producer {
 private:
  unsigned int count;
  unsigned int failed;

 public:
  Producer() : count(0), failed(0) {}

  /**
   * Create a new test
   *
   * @param name - test name
   */
  void test(const std::string& name) { std::cout << "# " << name << std::endl; }

  /**
   * Generate a passing assertion with an optional message
   *
   * @param message - optional message
   * @returns true
   */
  bool pass(const std::string& message = "") {
    this->count++;
    std::cout << "ok " << this->count << " " << message << std::endl;
    return true;
  }

  /**
   * Generate a failing assertion with an optional message
   *
   * @param message - optional message
   * @returns false
   */
  bool fail(const std::string& message = "") {
    this->failed++;
    std::cout << "not ";
    this->pass(message);
    return false;
  }

  /**
   * Assert that value is truthy with an optional description message
   *
   * @param value - value to be asserted
   * @param message - optional description message
   * @returns true if ok
   */
  bool ok(const bool value, const std::string& message = "") {
    if (value)
      return this->pass(message);
    else
      return this->fail(message);
  }

  /**
   * Assert that both values are equal with an optional description message
   *
   * @param value - actual value
   * @param expected - expected value
   * @param message - optional description message
   * @returns true if equal
   */
  template <class T>
  bool equal(const T value, const T expected, const std::string& message = "") {
    bool result;
    if (value == expected)
      result = this->pass(message);
    else {
      result = this->fail(message);
      std::cout << "  ---" << std::endl;
      std::cout << "    operator:\tequal" << std::endl;
      std::cout << "    expected:\t" << expected << std::endl;
      std::cout << "    actual:\t" << value << std::endl;
      std::cout << "  ..." << std::endl;
    }
    return result;
  }

  /**
   * Declare the end of the tests, finalizing the producer's output
   *
   * @returns the number of failed tests capped at 254
   */
  int end() {
    std::cout << "1.." << this->count << std::endl;
    std::cout << "# tests " << this->count << std::endl;
    std::cout << "# pass " << this->count - this->failed << std::endl;
    std::cout << "# fail " << this->failed << std::endl;

    if (this->failed < 255)
      return this->failed;
    return 254;
  }
};

}  // namespace Metacarpal
