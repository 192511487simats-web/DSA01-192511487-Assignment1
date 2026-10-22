# TASK 4 – Control Implicit Conversions

## 1. Introduction

Implicit conversion happens when C++ automatically converts a value from one data type to another. These conversions are useful, but they can sometimes produce unexpected results. In a metro fare system, incorrect conversions may cause calculation errors. Therefore, explicit type conversion should be used wherever necessary.

## 2. Integer Division and Integer-to-Double Conversion

In the expression `double c = a / b;`, both `a` and `b` are integers. Therefore, integer division takes place first. Since `7 / 2` gives `3`, the result stored in `c` is `3.0`.

In `double d = static_cast<double>(a) / b;`, the value of `a` is explicitly converted to `double`. The calculation becomes `7.0 / 2`, which produces `3.5`.

Thus, using `static_cast<double>` prevents the fractional part from being lost during integer division.

## 3. Character-to-Integer Promotion

In `char ch = 'A' + 2;`, the character `'A'` is promoted to an integer during the calculation. Adding 2 gives the character code for `'C'`, so `ch` stores `'C'`.

In `ch + 1`, the character is promoted to an integer. With the usual ASCII character encoding, the result is `68`.

## 4. Integer-to-Boolean Conversion

In `bool flag = 5;`, the non-zero integer value `5` is converted to `true`.

By default, `cout` prints a Boolean value as `1` or `0`. After applying `std::boolalpha`, it prints `true` or `false`.

Therefore, the output is `1 true`.

## 5. Signed and Unsigned Comparison

The variable `s` contains `-1` as an `int`, while `u` contains `1` as an `unsigned int`.

During the comparison `s < u`, the signed value is converted to an unsigned value under the usual arithmetic conversions for these types. The converted value of `-1` is a large unsigned value, so the comparison is false on the usual system where `unsigned int` has the same width as `int`.

Therefore, the program prints `s >= u`.

A compiler may warn about comparing signed and unsigned values because the conversion can produce unexpected results.

## 6. Narrowing Conversions and Brace Initialisation

A narrowing conversion may lose information when a value is converted to a type that cannot represent it exactly.

For example:

```cpp
int x = 3.7;
```

This converts `3.7` to `3`, losing the fractional part.

However:

```cpp
int x{3.7};
```

is rejected by the compiler because brace initialisation prevents this narrowing conversion.

Brace initialisation is therefore a safer choice when declaring variables.

## 7. Use of static_cast

`static_cast` explicitly converts a value to another type.

Example:

```cpp
double result = static_cast<double>(7) / 2;
```

The result is `3.5` because the division is performed using floating-point arithmetic.

Explicit conversions make the programmer's intention clearer and help prevent mistakes.

## 8. Predicted Output

The predicted output, written before running the program, is:

```text
3 3.5
C 68
1 true
s >= u
```

The output assumes a system using ASCII-compatible character values and the usual representation of `int` and `unsigned int`.

## 9. Explanation of the Output

* **Line 1:** Integer division produces `3`, while explicit conversion produces `3.5`.
* **Line 2:** Character arithmetic produces `'C'`; printing `ch + 1` displays its integer value, `68`.
* **Line 3:** The integer `5` becomes `true`. The output changes from `1` to `true` after `std::boolalpha`.
* **Line 4:** The signed-to-unsigned conversion makes the comparison false on the usual system described above.

## 10. Alternative Concept and Complexity Analysis

If every conversion were written explicitly using `static_cast`, the program would be easier to understand because the intended data types would be clear. Brace initialisation could also prevent accidental narrowing conversions.

For example:

```cpp
double result = static_cast<double>(7) / 2;
```

The time complexity of the arithmetic operations remains **O(1)**, and the space complexity remains **O(1)** because only a fixed number of variables are used.

Explicit conversions generally do not require additional memory or significantly change execution time. However, brace initialisation can detect certain narrowing errors at compile time, before the program runs.

## 11. Conclusion

Implicit conversions can affect arithmetic results, character operations, Boolean output and comparisons. Using `static_cast` when needed and brace initialisation for safer declarations makes C++ programs more reliable. These practices are important in a metro fare system, where accurate calculations are required.
