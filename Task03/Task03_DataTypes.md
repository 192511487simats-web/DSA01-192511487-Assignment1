# TASK 3 – Choose Data Types and Check Type Compatibility

## 1. Data Types Used in the Metro Fare System

Different data types are needed to store the fare, card balance, journey time, zone and number of journeys.

| Value                       | Data type                | Reason                                                                                                     |
| --------------------------- | ------------------------ | ---------------------------------------------------------------------------------------------------------- |
| Fare in paise               | `long long`              | Stores money as whole paise without floating-point rounding.                                               |
| Card balance in paise       | `long long`              | Supports large balances and fare calculations.                                                             |
| Peak-hour status            | `bool`                   | Stores either `true` or `false`.                                                                           |
| Passenger category code     | `char` or an enumeration | Represents a category; an enumeration is clearer for named categories.                                     |
| Zone                        | `enum class Zone`        | Represents Inner, Middle and Outer without mixing them with unrelated integers.                            |
| Hour and minute             | `int`                    | Stores the hour and minute used to check peak periods.                                                     |
| Journey count               | `long long`              | Safely represents the expected daily counts, including 3,000,000 journeys.                                 |
| Percentage                  | `int`                    | Stores the 20% surcharge as a whole number.                                                                |
| Average fare or measurement | `double`                 | Suitable for calculations that genuinely require fractional values, but not ideal for storing exact money. |
| Inferred local variable     | `auto`                   | Lets the compiler infer a type from the initial value. It is not a separate fixed-size storage type.       |

## 2. Checking `sizeof` on My System

The size of a type depends on the compiler and platform. The following program prints the sizes reported by the system where it is compiled.

```cpp
#include <iostream>
#include <climits>

int main() {
    std::cout << "sizeof(bool) = " << sizeof(bool) << '\n';
    std::cout << "sizeof(char) = " << sizeof(char) << '\n';
    std::cout << "sizeof(int) = " << sizeof(int) << '\n';
    std::cout << "sizeof(unsigned int) = "
              << sizeof(unsigned int) << '\n';
    std::cout << "sizeof(long long) = "
              << sizeof(long long) << '\n';
    std::cout << "sizeof(float) = " << sizeof(float) << '\n';
    std::cout << "sizeof(double) = " << sizeof(double) << '\n';

    std::cout << "INT_MIN = " << INT_MIN << '\n';
    std::cout << "INT_MAX = " << INT_MAX << '\n';
    std::cout << "UINT_MAX = " << UINT_MAX << '\n';
    std::cout << "LLONG_MIN = " << LLONG_MIN << '\n';
    std::cout << "LLONG_MAX = " << LLONG_MAX << '\n';

    return 0;
}
```

For a typical GCC implementation on Windows, the expected sizes are:

| Type           | Typical size |
| -------------- | -----------: |
| `bool`         |       1 byte |
| `char`         |       1 byte |
| `int`          |      4 bytes |
| `unsigned int` |      4 bytes |
| `long long`    |      8 bytes |
| `float`        |      4 bytes |
| `double`       |      8 bytes |

These are typical results, not a substitute for running the program. The actual output from my compiler must be recorded after execution.

## 3. Why Money Should Be Stored in Integer Paise

Money should be stored in integer paise instead of `double` rupees because floating-point values cannot represent every decimal fraction exactly.

For example, ₹10.00 can be represented as `1000` paise. A 20% surcharge on ₹30.00 can be calculated using integer arithmetic:

```cpp
long long baseFare = 3000;
long long peakFare =
    baseFare + baseFare * 20 / 100;
```

The result is `3600` paise, which is exactly ₹36.00.

Using integer paise avoids errors caused by repeatedly adding or rounding floating-point values. The program can convert the final paise amount to rupees only when displaying it.

## 4. Type Compatibility in C++

C++ applies conversion rules when different types appear in the same expression.

### Integer and double

```cpp
int a = 5;
double b = 2.5;
double result = a + b;
```

The integer `a` is converted to `double` before the addition. The result is `7.5`.

### Integer and bool

```cpp
int value = 5;
bool flag = value;
```

A nonzero integer converts to `true`, while zero converts to `false`. Therefore, `flag` becomes `true`.

### Integer division

```cpp
int a = 7;
int b = 2;
double result = a / b;
```

The division happens using integers first, so `7 / 2` produces `3`. That result is then converted to `3.0`.

To obtain `3.5`, one operand must be converted before division:

```cpp
double result = static_cast<double>(a) / b;
```

### Signed and unsigned values

Comparing a negative signed integer with an unsigned integer can produce an unexpected result because the signed value may be converted to unsigned.

For example:

```cpp
int s = -1;
unsigned int u = 1;

std::cout << (s < u ? "s < u" : "s >= u");
```

On a typical implementation, the output is `s >= u`, because `s` is converted to an unsigned value before the comparison.

This is why signedness should be considered carefully when comparing values.

## 5. Ranges from `<climits>`

The `<climits>` header provides limits for integer types.

On a typical system with a 32-bit `int`:

* `INT_MIN` is −2,147,483,648.
* `INT_MAX` is 2,147,483,647.
* `UINT_MAX` is 4,294,967,295.
* `LLONG_MIN` is −9,223,372,036,854,775,808.
* `LLONG_MAX` is 9,223,372,036,854,775,807.

The exact limits should be confirmed by running the program.

### Is `int` enough for a day's collection?

The assignment states that the network may process 3,000,000 journeys per day.

If every journey costs ₹30, the total is:

3,000,000 × ₹30 = ₹90,000,000.

In paise, the total is:

3,000,000 × 3,000 = 9,000,000,000 paise.

This exceeds `INT_MAX`, so a signed 32-bit `int` cannot safely hold the total in paise.

A `long long` is a safer choice for accumulating the network collection in paise.

## 6. Precision Example: `double` Rupees versus Integer Paise

The following program compares repeated addition using integer paise with repeated addition using `double` rupees.

```cpp
#include <iostream>
#include <iomanip>

int main() {
    const int n = 1000000;

    long long totalPaise = 0;
    double totalRupees = 0.0;

    for (int i = 0; i < n; ++i) {
        totalPaise += 10;
        totalRupees += 0.10;
    }

    double integerBasedRupees =
        static_cast<double>(totalPaise) / 100.0;

    std::cout << std::fixed << std::setprecision(10);
    std::cout << "Integer-paise total: "
              << integerBasedRupees << '\n';
    std::cout << "Double-rupee total: "
              << totalRupees << '\n';
    std::cout << "Difference: "
              << totalRupees - integerBasedRupees << '\n';

    return 0;
}
```

The exact mathematical total is ₹100,000.00.

The integer-paise total is exact for this calculation. The repeated `double` addition may produce a small difference because many decimal fractions, including `0.10`, are not represented exactly in binary floating-point.

The measured difference must be taken from the actual program output.

## 7. Alternative Concept and Complexity Analysis

If the system stored money as `double` rupees instead of `long long` paise, each addition would still take O(1) time.

For `n` fares, accumulating the total would take O(n) time in either approach.

On a typical 64-bit GCC platform, `long long` and `double` each occupy 8 bytes. Therefore, the space used by one value is O(1) in either approach.

However, their numerical behaviour differs:

* Integer paise stores exact whole-paise amounts, provided the value stays within the integer range.
* `double` can represent a much wider range of magnitudes, but decimal fractions may have rounding errors.
* Repeated floating-point addition can accumulate rounding differences. The exact error depends on the values, their order and the number of additions; it cannot be assumed to grow by a fixed amount for every fare.

For this fare system, integer paise is the better choice because the final amount must be exact to the paisa.

## Conclusion

The system should use `long long` for fares, balances and large collection totals, `bool` for conditions, `int` for hours and minutes, and `enum class` for zones.

The `sizeof` results and integer ranges should be verified by executing the program on the actual compiler. Integer paise avoids floating-point rounding in fare calculations, and `long long` can hold the expected daily collection in paise.

