#pragma once

#include <string>

namespace Metacarpal {

class Producer {
 private:
  unsigned int count;
  unsigned int failed;

 public:
  Producer();

	/**
	 * Create a new test
	 * 
	 * @param name - test name
	 */
  void test(std::string name);

	/**
	 * Generate a passing assertion with an optional message
	 * 
	 * @param message - optional message
	 */
  void pass(std::string message = "");

	/**
	 * Generate a failing assertion with an optional message
	 * 
	 * @param message - optional message
	 */
  void fail(std::string message = "");


	/**
	 * Assert that value is truthy with an optional description message
	 * 
	 * @param value - value to be asserted
	 * @param message - optional description message
	 */
  void ok(bool value, std::string message = "");

	/**
	 * Assert that both values are equal with an optional description message
	 * 
	 * @param value - actual value
	 * @param expected - expected value
	 * @param message - optional description message
	 */
  template <class T>
  void equal(T value, T expected, std::string message = "") {}

	/**
	 * Declare the end of the tests, finalizing the producer's output
	 * 
	 * @returns the number of failed tests capped at 254
	 */
  int end();
};

}  // namespace Metacarpal
