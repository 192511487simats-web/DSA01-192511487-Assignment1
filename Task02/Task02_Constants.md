# TASK 2 – Use Tokens, Keywords, Identifiers and Constants Correctly

## 1. Tokens in C++

Tokens are the smallest individual elements of a C++ program. The five kinds of tokens used in the fare system are:

| Token type  | Examples                          | Purpose                                                         |
| ----------- | --------------------------------- | --------------------------------------------------------------- |
| Keywords    | `int`, `bool`, `switch`, `return` | Define the language's rules and statements.                     |
| Identifiers | `fare`, `balance`, `SmartCard`    | Name variables, functions and classes.                          |
| Constants   | `1000`, `3000`, `20`              | Represent fixed values such as fares and surcharge percentages. |
| Operators   | `+`, `-`, `==`, `&&`              | Perform arithmetic, comparisons and logical operations.         |
| Punctuators | `;`, `{}`, `()`, `[]`             | Structure statements, blocks, functions and arrays.             |

These tokens work together to implement the metro fare calculation.

## 2. Defining Fare Values and Limits

The fare values should be declared in one place so that a fare revision does not require changing several expressions.

```cpp
#include <iostream>

enum class Zone { Inner, Middle, Outer };

constexpr long long BASE_PAISE[] = {1000, 2000, 3000};
constexpr int PEAK_SURCHARGE_PERCENT = 20;
constexpr long long MIN_BALANCE_PAISE = 5000;
```

The base fares are stored in paise: 1000 paise represents ₹10, 2000 paise represents ₹20, and 3000 paise represents ₹30. The minimum remaining balance is 5000 paise, which represents ₹50.

The surcharge percentage is stored separately. If the metro changes a fare or the surcharge, the corresponding constant can be updated in one place.

## 3. Difference Between `#define`, `const` and `constexpr`

### `#define`

A macro is processed by the preprocessor before compilation.

```cpp
#define PEAK_SURCHARGE 20
```

It does not have normal C++ type checking or namespace scope in the same way as a declared variable.

### `const`

The `const` keyword prevents modification through the declared object.

```cpp
const int surcharge = 20;
```

A `const` object has a type and follows normal C++ scope rules.

### `constexpr`

The `constexpr` keyword allows a value to be used in constant expressions when its requirements are satisfied.

```cpp
constexpr int surcharge = 20;
```

For fixed fare values, `constexpr` is a suitable choice because the values are known at compile time and can be checked by the compiler.

A compiler may not need to allocate separate storage for a constant if its value can be substituted into the program. Therefore, it is not correct to assume that every `constexpr` variable always occupies storage.

## 4. Using `enum` and `enum class`

A traditional enumeration can be declared as follows:

```cpp
enum Zone { Inner, Middle, Outer };
```

An unscoped enumeration allows its enumerator names to be used in the surrounding scope and can convert to an integer.

A scoped enumeration is declared as:

```cpp
enum class Zone { Inner, Middle, Outer };
```

Its values must be qualified, for example `Zone::Inner`. It does not implicitly convert to an integer.

For this system, `enum class` is safer because it distinguishes zone values from unrelated integers and improves readability.

## 5. Naming Rules and Conventions

C++ identifiers:

* May contain letters, digits and underscores.
* Must not begin with a digit.
* Must not be a reserved keyword.
* Are case-sensitive.

For example, `baseFare`, `MIN_BALANCE_PAISE` and `calculateFare` are valid identifiers.

Descriptive names make the program easier to understand. A consistent naming convention also helps prevent confusion between variables, functions and constants.

## 6. Alternative Concept and Complexity Analysis

If the program used `#define` macros instead of `constexpr` constants and `enum class`, the fare values could still be substituted into expressions and the program could calculate fares.

However, macros do not provide the same type checking or scope rules as normal C++ declarations. An unscoped enumeration also allows more implicit conversions than `enum class`.

For example, `Zone::Inner` is a distinct scoped-enum value, whereas a macro containing `1000` is simply replaced with the token `1000`.

### Time Complexity

Using a macro or a `constexpr` constant does not change the asymptotic running time of a fare calculation. Retrieving a fixed fare or applying a fixed percentage surcharge requires O(1) time.

### Space Complexity

A macro itself does not occupy runtime storage. A `constexpr` value also may not require separate runtime storage when the compiler can use the value directly. If an object needs storage because of how it is used, its storage depends on the implementation and usage.

Therefore, macros do not automatically make the program faster or use less memory. For this fare system, `constexpr` and `enum class` are preferable because they provide clearer types and safer code.

## Conclusion

Using `constexpr` for fixed fares, surcharge percentages and balance limits keeps the rules organised. Using `enum class` for zones improves type safety. These choices make the fare system easier to read, maintain and extend.
