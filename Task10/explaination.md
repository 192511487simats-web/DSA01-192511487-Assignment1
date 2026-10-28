# Task 10: Compare Expectations with Execution

## Aim

To compare floating-point and integer-paise totals, evaluate integer overflow, and understand compiler warnings.

## 1. Double and Integer-Paise Comparison

The program calculates totals for 20,000, 500,000, and 3,000,000 journeys using a fare of Rs 10.01.

The double method repeatedly adds 10.01 rupees. The integer method repeatedly adds 1001 paise.

Expected totals:

|  Journeys |   Expected total |
| --------: | ---------------: |
|    20,000 |    Rs 200,200.00 |
|   500,000 |  Rs 5,005,000.00 |
| 3,000,000 | Rs 30,030,000.00 |

Binary floating-point cannot represent every decimal fraction exactly. Repeated additions may therefore accumulate a small error. Integer-paise arithmetic represents these fares exactly, provided the integer type does not overflow.

## 2. Integer Overflow

A network of 3,000,000 journeys charged at Rs 30 per journey collects:

3,000,000 × 3000 paise = 9,000,000,000 paise.

A typical 32-bit signed int has a maximum value of 2,147,483,647. The network total exceeds this limit, so accumulating the total in a signed int would cause signed integer overflow, which is undefined behavior in C++.

A long long can represent this total safely on common systems with a 64-bit long long type.

## 3. Compiler Warnings

Compile using the options `-Wall -Wextra` to enable common compiler warnings.

These options can reveal issues such as:

* Variables declared but never used.
* Function parameters that are not used.
* Suspicious comparisons or other questionable code.

The exact warnings depend on the source code and compiler version. The provided program is designed to avoid common unused-variable and unused-parameter warnings. Record the warnings actually shown by your compiler rather than claiming warnings appeared when none did.

## 4. Alternative Concept and Complexity Analysis

For 3,000,000 journeys:

* int cannot safely store the total of 9,000,000,000 paise.
* long long can store the total within its range.
* double can represent this whole-number total at this magnitude, but floating-point arithmetic may introduce rounding errors for repeated decimal-fare calculations.

Each addition takes O(1) time. The three methods each use O(1) additional space for the accumulator. The complete repeated-addition experiment takes O(n) time for n journeys.

## Conclusion

Integer-paise arithmetic is preferable for fare accounting because it represents whole paise exactly and avoids floating-point rounding. A sufficiently wide integer type, such as long long, is required to prevent overflow when accumulating network-wide totals.
