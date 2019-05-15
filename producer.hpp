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
  void test(std::string name) {
		std::cout << "# " << name << std::endl;
	}

	/**
	 * Generate a passing assertion with an optional message
	 * 
	 * @param message - optional message
	 */
  void pass(std::string message = "") {
		this->count++;
		std::cout << "ok " << this->count << " " << message << std::endl;
	}

	/**
	 * Generate a failing assertion with an optional message
	 * 
	 * @param message - optional message
	 */
  void fail(std::string message = "") {
		this->failed++;
		std::cout << "not ";
		this->pass(message);
	}


	/**
	 * Assert that value is truthy with an optional description message
	 * 
	 * @param value - value to be asserted
	 * @param message - optional description message
	 */
  void ok(bool value, std::string message = "") {
		if (value)
			this->pass(message);
		else
			this->fail(message);
	}

	/**
	 * Assert that both values are equal with an optional description message
	 * 
	 * @param value - actual value
	 * @param expected - expected value
	 * @param message - optional description message
	 */
  template <class T>
  void equal(T value, T expected, std::string message = "") {
    if (value == expected)
      this->pass(message);
    else {
      this->fail(message);
      std::cout << "  ---" << std::endl;
      std::cout << "    operator:\tequal" << std::endl;
      std::cout << "    expected:\t" << expected << std::endl;
      std::cout << "    actual:\t" << value << std::endl;
      std::cout << "  ..." << std::endl;
    }
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
