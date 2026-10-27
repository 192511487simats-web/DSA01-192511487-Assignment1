# Task 2 – Use Tokens, Keywords, Identifiers and Constants Correctly

## 1. Aim

To understand and use C++ tokens, keywords, identifiers, constants and enumerations correctly while implementing the fare calculation logic of a City Metro Smart-Card System.

## 2. Problem Description

The metro system has three zones with different base fares:

| Zone        | Base Fare |
| ----------- | --------: |
| Inner Zone  |       ₹10 |
| Middle Zone |       ₹20 |
| Outer Zone  |       ₹30 |

A 20% surcharge is applied during peak hours. The smart card must retain a minimum balance of ₹50 after deducting the fare.

The program uses named constants to store the fare values, surcharge percentage and minimum balance requirement. This avoids repeating the same values throughout the code.

## 3. Tokens in C++

Tokens are the smallest individual elements of a C++ program.

The main categories of tokens are:

| Token Type  | Examples                                | Purpose                                          |
| ----------- | --------------------------------------- | ------------------------------------------------ |
| Keywords    | `int`, `long`, `bool`, `if`, `return`   | Have predefined meanings in C++                  |
| Identifiers | `calculateFare`, `balance`, `finalFare` | Name variables and functions                     |
| Constants   | `1000`, `2000`, `3000`, `20`, `5000`    | Represent fixed values                           |
| Operators   | `=`, `+`, `-`, `*`, `/`, `>=`           | Perform calculations and comparisons             |
| Punctuators | `{`, `}`, `(`, `)`, `;`, `,`            | Define program structure and separate statements |

Correct use of tokens makes a program readable and understandable.

## 4. Keywords and Identifiers

### Keywords

Keywords are reserved words in C++ and cannot be used as ordinary identifiers.

Examples from the program include `int`, `long`, `bool`, `enum`, `class`, `switch`, `case`, `if` and `return`.

### Identifiers

Identifiers are user-defined names given to variables, functions and constants.

Examples from the program include:

* `getBaseFare`
* `calculateFare`
* `canTravel`
* `balance`
* `finalFare`
* `INNER_FARE_PAISE`

The identifiers describe their purpose and improve code readability.

## 5. Constants: #define, const and constexpr

### 5.1 #define

The `#define` directive creates a preprocessor macro.

Example:

```cpp
#define PEAK_SURCHARGE_PERCENT 20
```

Macros are processed by the preprocessor. They do not provide the same type checking and scope behaviour as ordinary C++ constants.

### 5.2 const

The `const` keyword declares an object that cannot be modified through that object after initialisation.

Example:

```cpp
const int minimumBalance = 50;
```

It is useful for values that must remain unchanged during normal program execution.

### 5.3 constexpr

The `constexpr` keyword allows suitable values and expressions to be evaluated at compile time.

Example:

```cpp
constexpr int PEAK_SURCHARGE_PERCENT = 20;
```

The program uses `constexpr` for fixed fare values and the peak surcharge percentage.

**Reason for choosing constexpr:** It provides type checking and follows C++ language rules. It is generally preferable to a macro for fixed numeric values because it supports typed declarations and scope rules.

## 6. Use of enum and enum class

An enumeration represents a set of named values.

Example:

```cpp
enum class Zone
{
    Inner,
    Middle,
    Outer
};
```

The program uses `enum class` to represent the three metro zones.

| Feature                        | enum                                             | enum class                                         |
| ------------------------------ | ------------------------------------------------ | -------------------------------------------------- |
| Scope                          | Enumerator names may enter the surrounding scope | Enumerator names belong to the enumeration's scope |
| Implicit conversion to integer | Generally allowed                                | Not implicitly allowed                             |
| Type safety                    | Less restrictive                                 | More restrictive                                   |
| Example                        | `Inner`                                          | `Zone::Inner`                                      |

The program uses `enum class` because it provides better type safety and reduces accidental mixing of zone values with unrelated integers.

## 7. Naming Conventions

The program uses uppercase names with underscores for constants.

Examples:

* `INNER_FARE_PAISE`
* `MIDDLE_FARE_PAISE`
* `OUTER_FARE_PAISE`
* `PEAK_SURCHARGE_PERCENT`
* `MIN_BALANCE_PAISE`

Function names use descriptive camelCase, such as `getBaseFare()` and `calculateFare()`.

These naming conventions make the code easier to read and maintain.

## 8. Fare Calculation

The program stores fare amounts in paise to avoid floating-point rounding issues in these calculations.

| Zone        | Fare in Rupees | Fare in Paise |
| ----------- | -------------: | ------------: |
| Inner Zone  |            ₹10 |          1000 |
| Middle Zone |            ₹20 |          2000 |
| Outer Zone  |            ₹30 |          3000 |

The peak surcharge is calculated as:

Peak surcharge = Base fare × 20 / 100

For an Outer Zone journey:

Base fare = ₹30

Peak surcharge = ₹30 × 20 / 100 = ₹6

Final fare = ₹30 + ₹6 = ₹36

## 9. Balance Validation

The initial smart-card balance is ₹100.

Final fare = ₹36.

Remaining balance = ₹100 − ₹36 = ₹64.

The minimum required balance is ₹50. Since the remaining balance is ₹64, the journey is allowed.

The `canTravel()` function checks whether the balance remaining after deducting the fare is at least the minimum required amount.

## 10. Alternative Approach

The program could use `#define` macros instead of `constexpr` constants and an ordinary `enum` instead of `enum class`.

However, macros do not provide the same type checking and scope behaviour as typed constants. An ordinary enumeration also allows more implicit conversions.

Therefore, `constexpr` and `enum class` are preferred for this implementation because they provide clearer declarations and safer handling of fixed values and zone names.

For a fixed number of zones, retrieving the base fare and calculating the final fare take O(1) time. These operations require O(1) auxiliary space.

## 11. Conclusion

This task demonstrates the use of C++ tokens, keywords, identifiers, constants and enumerations in a metro fare system.

The use of descriptive identifiers, `constexpr` constants and `enum class` improves code readability, type safety and maintainability.

The program calculates the Outer Zone peak-hour fare as ₹36. Since the remaining balance is ₹64, the journey is allowed.
