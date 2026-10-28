# Task 9: Implement and Test the Fare Logic

## Aim

To implement metro fare calculation and validate the fare rules using normal, boundary, and invalid test cases.

## 1. Fare Rules

The base fares are stored as integer paise:

* Inner zone: 1000 paise (Rs 10)
* Middle zone: 2000 paise (Rs 20)
* Outer zone: 3000 paise (Rs 30)

A 20% surcharge applies during peak hours: 08:00–09:59 and 17:00–19:59.

The fare is calculated using integer arithmetic to avoid floating-point inaccuracies in monetary calculations.

## 2. Boundary Testing

The program tests 08:00, 10:00, 17:00, and 20:00.

* 08:00: Peak hour.
* 10:00: Off-peak.
* 17:00: Peak hour.
* 20:00: Off-peak.

These cases verify that the start times are inclusive and the end times are exclusive.

## 3. Invalid Input Testing

The program checks:

* Unknown zone: rejected with a fare result of -1.
* Letters entered for the hour: rejected.
* Negative recharge: rejected by the recharge validation function.
* Invalid hour values: rejected by the fare calculation function.

The parseInt() function checks whether the supplied hour text represents a complete integer.

## 4. Balance Validation

The minimum remaining balance is Rs 50.

For a fare of Rs 10:

* Starting balance Rs 60 leaves exactly Rs 50, so travel is permitted.
* Starting balance Rs 59 leaves Rs 49, so travel is denied.

The canTravel() function implements this rule.

## 5. Five-Journey Calculation

The five journeys have these fares:

* Inner off-peak: Rs 10
* Middle off-peak: Rs 20
* Outer off-peak: Rs 30
* Inner peak: Rs 12
* Middle peak: Rs 24

Total = Rs 10 + Rs 20 + Rs 30 + Rs 12 + Rs 24 = Rs 96.

The program calculates the total as 9600 paise and compares it with the hand-calculated total.

## 6. Alternative Concept and Complexity Analysis

A table-driven test system stores each test's input and expected result in a structure and processes the table in a loop. For t test cases, the execution time is O(t), and storing the test table requires O(t) space.

Adding a new boundary test is straightforward: add another row to the table with the input and expected result. This is easier to maintain than writing a separate test statement for every case.

## Conclusion

The test program checks the fare rules for all three zones, peak-hour boundaries, invalid inputs, minimum balance conditions, and the total for five journeys.
