# Task 3 – Choose Data Types and Check Type Compatibility

## 1. Aim

To select appropriate C++ data types for the City Metro Smart-Card System, understand type compatibility, examine integer limits, and compare integer-paise storage with floating-point money storage.

## 2. Data-Type Selection

Different values in the metro system require different data types.

| Value                          | Recommended Type              | Reason                                                                |
| ------------------------------ | ----------------------------- | --------------------------------------------------------------------- |
| Peak-hour status               | `bool`                        | Stores true or false                                                  |
| Zone code                      | `char` or `enum class`        | Represents a zone identifier                                          |
| Journey count                  | `int` or `long long`          | Stores the number of journeys                                         |
| Fare in paise                  | `long long`                   | Stores money in exact integer units within the type's range           |
| Card balance in paise          | `long long`                   | Supports safe balance and collection calculations                     |
| Passenger count                | `unsigned int` or `long long` | Represents a non-negative count when range requirements are satisfied |
| Approximate temperature        | `float`                       | Suitable for measurements where single precision is sufficient        |
| General scientific calculation | `double`                      | Provides greater floating-point precision than `float`                |
| Fixed surcharge percentage     | `constexpr int`               | Stores a compile-time constant                                        |
| Zone                           | `enum class Zone`             | Represents a fixed set of named zone values                           |

The type should be selected according to the value's meaning, required precision and possible range.

An unsigned type should not be used automatically for every non-negative value. Signed types are often easier to use when subtraction or negative intermediate values may occur.

## 3. The sizeof Operator

The `sizeof` operator returns the size of a type or object in bytes.

Example:

```cpp
cout << sizeof(int);
cout << sizeof(double);
```

On a typical modern desktop C++ implementation:

| Data Type      | Common Size |
| -------------- | ----------: |
| `bool`         |      1 byte |
| `char`         |      1 byte |
| `int`          |     4 bytes |
| `long long`    |     8 bytes |
| `unsigned int` |     4 bytes |
| `float`        |     4 bytes |
| `double`       |     8 bytes |

These are common sizes, not universal guarantees for every implementation. The actual sizes should be measured using `sizeof` on the compiler used for the assignment.

## 4. Why Money Should Be Stored in Integer Paise

Money should generally be stored in the smallest relevant integer currency unit rather than as binary floating-point rupees.

For example:

₹10.01 = 1001 paise

The program can store this amount as:

```cpp
long long farePaise = 1001;
```

Integer-paise arithmetic avoids the binary floating-point representation errors that can occur when decimal values such as 0.10 are stored in a `double`.

For a fare of ₹30, the value stored in paise is 3000. A 20% surcharge can be calculated using integer arithmetic:

Surcharge = 3000 × 20 / 100 = 600 paise.

Final fare = 3000 + 600 = 3600 paise = ₹36.

For this example, integer arithmetic produces an exact result. If a percentage calculation produces a fractional paise, the system must define an explicit rounding rule.

## 5. Type Compatibility

C++ allows values of different types to participate in expressions, but conversions may occur.

### 5.1 Integer Division

```cpp
int a = 7;
int b = 2;
double result = a / b;
```

The expression `a / b` uses integer division because both operands are integers. The result is 3, which is then converted to `double`.

Therefore, `result` becomes 3.0 rather than 3.5.

### 5.2 Floating-Point Division

```cpp
double result = static_cast<double>(a) / b;
```

The explicit conversion changes `a` to `double` before division. The result is 3.5.

### 5.3 Integer to Boolean Conversion

```cpp
bool flag = 5;
```

A non-zero integer converts to `true`; zero converts to `false`.

### 5.4 Type Promotion

Smaller integer types such as `char` are commonly promoted to `int` when used in arithmetic expressions. The resulting expression may therefore have a different type from the original variable.

Understanding these conversions helps prevent unexpected results.

## 6. Integer Limits and the <climits> Header

The `<climits>` header provides constants describing integer ranges.

Examples include:

* `INT_MIN`: minimum representable value of `int`
* `INT_MAX`: maximum representable value of `int`
* `LLONG_MIN`: minimum representable value of `long long`
* `LLONG_MAX`: maximum representable value of `long long`

On a common system with a 32-bit `int`, `INT_MAX` is 2,147,483,647.

The assignment describes a network processing 3,000,000 journeys per day. If each journey costs ₹30, the total collection is:

Total = 3,000,000 × ₹30

Total = ₹90,000,000

In paise:

Total = 3,000,000 × 3000 = 9,000,000,000 paise.

This exceeds the typical maximum value of a 32-bit signed `int`. Therefore, `int` is insufficient to store this total in paise on such a system.

A `long long` is a suitable choice for this total, provided the expected maximum value remains within its range.

## 7. Alternative: double Rupees vs long long Paise

### Double Rupees

A `double` stores a floating-point approximation of a real number. It is useful for scientific calculations, but many decimal fractions cannot be represented exactly in binary floating-point.

Repeated additions can therefore accumulate small rounding errors.

### Integer Paise

A `long long` stores whole-number paise exactly, provided the value does not exceed the type's range.

| Feature                            | `double` Rupees         | `long long` Paise     |
| ---------------------------------- | ----------------------- | --------------------- |
| Representation                     | Binary floating-point   | Integer               |
| Exact decimal currency arithmetic  | Not guaranteed          | Exact for whole paise |
| Addition time                      | O(1)                    | O(1)                  |
| Typical storage                    | 8 bytes                 | 8 bytes               |
| Main concern                       | Floating-point rounding | Integer overflow      |
| Suitability for stored-value fares | Less suitable           | Preferred             |

Both types commonly occupy 8 bytes on a modern system. The actual sizes should be confirmed with `sizeof`.

## 8. Rounding Error Demonstration

The program adds ten fares of 0.10 rupees using `double`.

The mathematical total is ₹1.00, but the stored floating-point result may be slightly below or above the exact value.

The program also adds ten integer amounts of 10 paise:

10 × 10 = 100 paise = ₹1.00.

The integer-paise calculation produces an exact result for this example.

The floating-point error can vary with the values and number of additions. It should be measured experimentally rather than assumed to grow by a fixed amount for every journey.

## 9. Time and Space Complexity

Adding one fare to a running total takes O(1) time with either `double` or `long long`.

Both types commonly require 8 bytes per stored value on the target system, so the space used by one variable is O(1).

For n journeys, processing all fares takes O(n) time. If only a running total is maintained, the auxiliary space remains O(1).

The main difference is numerical correctness: integer paise provides exact arithmetic for whole-paise values, while floating-point arithmetic may introduce rounding error.

## 10. Conclusion

The data types used in the metro system must be selected according to the required precision and range. Integer paise stored in `long long` is appropriate for fares, card balances and large collection totals.

The `sizeof` operator and `<climits>` constants help verify data-type sizes and ranges on the actual compiler. The demonstrated division and rounding examples also show why type compatibility must be understood carefully.

For reliable fare calculations, integer-paise arithmetic is preferred, while `double` should be reserved for calculations where floating-point approximation is acceptable.
