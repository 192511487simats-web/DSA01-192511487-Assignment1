# Task 6: Design the Control Structures

## Aim

To use decision-making and looping statements to calculate metro fares and process journeys.

## 1. Pseudocode

BEGIN

1. Set the initial balance to 10000 paise.
2. Store the journeys with their zones and peak-hour status.
3. FOR each journey:
   a. Use SWITCH to select the base fare.
   b. IF it is peak hour, add the 20% surcharge.
   c. IF the remaining balance is at least 5000 paise:

   * Deduct the fare.
   * Display the fare and remaining balance.
     d. ELSE:
   * Display "Denied (low balance)".
     e. Display the remaining balance.
4. END FOR
   END

## 2. Control Structures

* switch: Selects the base fare according to the zone.
* if-else: Checks peak-hour status and whether the card has enough balance.
* Conditional operator: Can replace a simple if-else expression when selecting between two values.
* for loop: Processes a known collection of journeys.
* Range-based for loop: Processes each journey directly from the array. It is suitable for this program.
* while loop: Is useful when processing continues until a condition becomes false.
* break: Exits a switch case after selecting the fare.
* continue: Can skip an invalid journey when processing a larger list.
* default: Handles a zone value that does not match any listed switch case.

## 3. Fare Calculation

The base fares are stored as integer paise:

* Inner: 1000 paise
* Middle: 2000 paise
* Outer: 3000 paise

During peak hours, the program adds 20% using integer arithmetic. Therefore, an Outer-zone fare becomes 3600 paise, or Rs 36.00.

## 4. Balance Validation

The function canTravel() returns true only when the balance remaining after deducting the fare is at least 5000 paise (Rs 50).

The third journey is denied because the balance of Rs 54 would fall below Rs 50 after paying the Rs 20 fare. The balance therefore remains Rs 54.

## 5. Alternative Concept and Complexity Analysis

An array lookup could replace the switch statement by selecting the fare using the zone's index. Both approaches take O(1) time for one fare lookup. The array uses O(1) space because it contains a fixed number of fares. A fourth zone would require extending the array and updating the zone representation; a switch design would require adding another case.

## Conclusion

The program uses switch, if-else, a range-based for loop, and integer paise calculations to determine fares and prevent journeys that would leave less than Rs 50 on the card.
