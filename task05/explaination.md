# Task 5: Operator Precedence and Expressions

## Aim

To understand operator precedence, increment operators, conditional expressions, integer division, and remainder operations in C++.

## 1. Operator Precedence

The expression `x + y * 2` evaluates multiplication before addition.

With `x = 5` and `y = 3`:

* `5 + 3 * 2 = 11`
* `(5 + 3) * 2 = 16`

Parentheses change the order of evaluation.

## 2. Increment Operators

* `x++` uses the current value of `x` and then increments it.
* `++y` increments `y` before using its value.

Therefore, `x++ + ++y` evaluates to `5 + 4 = 9`. After the expression, `x = 6` and `y = 4`.

## 3. Conditional Operator

The expression `x > y ? x : y` returns the greater value. Since `x = 6` and `y = 4`, the result is `6`.

The expression `x % 4 * 2` evaluates from left to right for these operators:
`(6 % 4) * 2 = 4`.

## 4. Integer Division and Remainder

Integer division discards the fractional part:

* `10 / 3 = 3`
* `-10 / 3 = -3`

The remainder operator gives:

* `10 % 3 = 1`
* `-10 % 3 = -1`

In C++, integer division truncates toward zero, and the remainder has the sign of the dividend when the remainder is nonzero.

## 5. For Loop

The loop uses `i = 0, 3, 6, 9`.

Therefore:
`k = 0 + 3 + 6 + 9 = 18`.

## 6. Common Mistake: `i = i++`

Avoid using expressions such as `i = i++` to update a variable. The result is not a reliable way to increment it and can cause undefined behavior in C++. Use `i++` or `++i` as a separate statement instead.

## Alternative Concept and Complexity Analysis

The loop visits values from 0 to 9 in steps of 3, so it executes four times. More generally, a loop that processes `n` values takes O(n) time. This program uses a constant amount of extra memory, so its space complexity is O(1).

## Conclusion

This program demonstrates operator precedence, increment operators, conditional expressions, integer division, remainders, and loop execution in C++.
