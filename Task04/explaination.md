# Task 4 – Control Implicit Conversions

## 1. Aim

To identify implicit type conversions in C++, understand integer division and signed/unsigned comparisons, and use explicit conversions to make programs safer and more predictable.

## 2. Predicted Output

**My predicted output before execution:**

```text
3 3.5
C 68
1 true
s >= u
```

## 3. Actual Output

After compiling and executing the program, the output was:

```text
3 3.5
C 68
1 true
s >= u
```

The predicted output matches the expected output on a typical C++ implementation.

## 4. Explanation of Implicit Conversions

### 4.1 Integer Division and Conversion to Double

The program contains:

```cpp
int a = 7, b = 2;
double c = a / b;
```

Both operands are integers. Therefore, integer division is performed first.

7 / 2 = 3

The integer result `3` is then converted to `double`, producing `3.0`.

The next statement is:

```cpp
double d = static_cast<double>(a) / b;
```

Here, `a` is explicitly converted to `double` before division.

7.0 / 2 = 3.5

Therefore, the output is:

```text
3 3.5
```

This demonstrates that assigning an integer division result to a `double` does not recover the discarded fractional part.

### 4.2 Character Promotion to Integer

The program contains:

```cpp
char ch = 'A' + 2;
```

The character literal `'A'` participates in arithmetic. It is promoted to an integer value, and 2 is added.

The resulting character is `C` on an ASCII-compatible implementation.

The next statement is:

```cpp
cout << ch << ' ' << ch + 1 << '\n';
```

The character `ch` is printed as a character. In `ch + 1`, it is promoted to an integer before addition.

On an ASCII-compatible system, `C` has the integer value 67. Therefore:

67 + 1 = 68

The output is:

```text
C 68
```

### 4.3 Integer-to-Boolean Conversion

The program contains:

```cpp
bool flag = 5;
```

In C++, zero converts to `false`, while a non-zero arithmetic value converts to `true`.

Therefore, `flag` becomes `true`.

The statement:

```cpp
cout << flag << ' ' << boolalpha << flag << '\n';
```

Initially, the Boolean value is displayed as `1`. After `boolalpha` is applied, Boolean values are displayed as words.

The output is:

```text
1 true
```

### 4.4 Signed and Unsigned Comparison

The program contains:

```cpp
unsigned int u = 1;
int s = -1;

cout << (s < u ? "s < u" : "s >= u") << '\n';
```

The comparison combines a signed `int` and an `unsigned int`.

Under the usual arithmetic conversions for these types, the signed value `-1` is converted to unsigned. Its resulting value is very large, so the comparison `s < u` is false.

Therefore, the conditional operator selects:

```text
s >= u
```

This demonstrates why mixing signed and unsigned values can cause surprising comparisons and compiler warnings.

## 5. How Explicit Conversions Improve Safety

An explicit conversion makes the intended conversion visible in the source code.

Example:

```cpp
double result = static_cast<double>(a) / b;
```

This ensures that floating-point division is performed.

Brace initialisation can prevent certain narrowing conversions.

For example:

```cpp
int x{3.7};
```

This is rejected by the compiler because converting `3.7` to `int` would discard the fractional part.

A valid alternative is:

```cpp
int x{3};
```

When a conversion is genuinely intended, an explicit cast can make that intention clear:

```cpp
int x = static_cast<int>(3.7);
```

This produces `3`, but the fractional part is discarded. An explicit cast should be used only when that loss of information is acceptable.

## 6. Alternative Approach and Complexity Analysis

If conversions were written explicitly wherever appropriate, the code would make its intentions clearer.

For example:

```cpp
double result = static_cast<double>(a) / b;
```

For integer values, brace initialisation can help prevent accidental narrowing:

```cpp
int count{3};
```

However, explicit casts do not automatically make every conversion safe. The programmer must still choose the correct destination type and understand possible loss of information.

| Aspect         | Implicit Conversions                                       | Explicit Conversions                                       |
| -------------- | ---------------------------------------------------------- | ---------------------------------------------------------- |
| Readability    | Conversion may be less obvious                             | Intent is clearer                                          |
| Type checking  | Some unsafe narrowing is permitted in ordinary assignments | Brace initialisation rejects certain narrowing conversions |
| Runtime        | Usually similar for equivalent operations                  | Usually similar for equivalent operations                  |
| Memory         | Usually unchanged for equivalent operations                | Usually unchanged for equivalent operations                |
| Main advantage | Concise code                                               | Greater clarity and control                                |

For these examples, both approaches require O(1) time and O(1) auxiliary space. Explicit conversions mainly improve clarity and help avoid unintended behaviour; they do not automatically improve performance.

## 7. Conclusion

This task demonstrates several important C++ conversion rules: integer division, integer-to-double conversion, character promotion, integer-to-Boolean conversion, and signed/unsigned comparison.

Using `static_cast` where appropriate and brace initialisation for new variables can make conversions clearer and prevent certain errors at compile time. Understanding these rules is essential for implementing reliable fare calculations and balance checks.
