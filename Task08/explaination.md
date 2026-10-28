# Task 8: Read and Print Data Safely

## Aim

To validate user input, recover from invalid input, format monetary values, and display a clear metro journey report.

## 1. Input Validation

The program uses `cin >> value` to read an integer. If the user enters letters instead of a number, the input operation fails.

* `cin.clear()` resets the input stream's error state.
* `cin.ignore(numeric_limits<streamsize>::max(), '\n')` discards the invalid input until the end of the line.
* A loop repeats the input request until a valid integer is entered.

The program also validates the zone, hour, and non-negative card balance.

## 2. Formatting Money

The program includes `<iomanip>` to format output.

* `fixed` displays floating-point values in fixed-point notation.
* `setprecision(2)` displays two digits after the decimal point.
* `setw(2)` sets a minimum field width of two characters.
* `setfill('0')` adds leading zeroes to the hour, such as `09:00`.

## 3. Journey Report

The report displays the selected zone, journey time, peak or off-peak status, fare, journey decision, and remaining balance.

The peak-hour condition is `(hour >= 8 && hour < 10) || (hour >= 17 && hour < 20)`. The program adds a 20% surcharge during peak hours.

The minimum remaining balance is Rs 50. If paying the fare would leave less than Rs 50, the journey is denied and the balance is unchanged.

## 4. Alternative Concept: getline() and stoi()

Another approach is to read an entire line with `getline()` and convert it using `stoi()` inside a `try-catch` block.

* With `cin >>`, invalid input sets the stream's failure state. The program must clear that state and discard the bad input before retrying.
* With `getline()` and `stoi()`, the program can catch conversion exceptions and request another line. It should also check that the entire line was consumed, because `stoi()` can accept a valid numeric prefix followed by extra characters.
* Processing a line of length L takes O(L) time in either approach.
* The input buffer requires O(L) space when storing the entire line. Direct formatted extraction does not require the program to store the complete input line itself.

## Conclusion

The program validates numeric input, recovers from invalid entries, applies the fare rules, and presents the journey details in a readable format.
