# metacarpal

tap-producing test harness for cpp

## Installation

To get started you need to download the latest version which is just a single header and include it in your test file.

## Example usage

```cpp
#include <producer.hpp>

int main() {
  Metacarpal::Producer p;

  p.test("sum");
  p.equal(1 + 1, 2, "one plus one should be 2");

  p.test("logic");
  p.ok(true && true, "true and true should be truthy");
  if (false || true)
    p.pass("or is working");
  else
    p.fail("or isn't working");

	p.test("failing");
	p.equal("this string should be", "that");

  return p.end();
}
```

## Example output
```
# sum
ok 1 1 plus 1 should be 2
# logic
ok 2 true and true should be truthy
ok 3 or is working
# failing
not ok 4 
  ---
    operator:   equal
    expected:   that
    actual:     this string should be
  ...
1..4
# tests 4
# pass 3
# fail 1
```

## API

### void test(std::string name)

Create a new test

- @param name - test name

### void pass(std::string message = "")

Generate a passing assertion with an optional message

- @param message - optional message

### void fail(std::string message = "")

Generate a failing assertion with an optional message

- @param message - optional message

### void ok(bool value, std::string message = "")

Assert that value is truthy with an optional description message

- @param value - value to be asserted
- @param message - optional description message

### void equal(T value, T expected, std::string message = "")

Assert that both values are equal with an optional description message

- @param value - actual value
- @param expected - expected value
- @param message - optional description message

### int end()

Declare the end of the tests, finalizing the producer's output

- @returns the number of failed tests capped at 254

## Reporters

The TAP output is somewhat good even for humans,
but if you want a more colorful/pretty output there are lots of [custom reporters](https://github.com/sindresorhus/awesome-tap#reporters).

## License

GPL-3.0
