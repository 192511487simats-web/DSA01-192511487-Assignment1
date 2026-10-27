# Task 1 – Complexity Analysis and Design Comparison

## 1. Purpose

This section compares procedural programming and Object-Oriented Programming for the City Metro Smart-Card System. It also analyses the time and space complexity of the main fare-processing operations.

## 2. Time Complexity

Assume the fare table contains a fixed number of zones and the program processes one journey at a time.

| Operation            | Description                                               | Time Complexity |
| -------------------- | --------------------------------------------------------- | --------------- |
| Retrieve base fare   | Obtain the fare for the selected zone                     | O(1)            |
| Check peak hours     | Compare the journey time with the defined time boundaries | O(1)            |
| Calculate final fare | Apply the surcharge or a defined concession               | O(1)            |
| Check card balance   | Verify that the required minimum balance remains          | O(1)            |
| Deduct fare          | Subtract the fare from the card balance                   | O(1)            |
| Process one journey  | Perform the fare calculation and balance validation       | O(1)            |

Each operation requires a fixed number of steps when the fare table and rules are directly accessible. Therefore, the processing time for one journey is O(1).

If the system processes **n journeys**, and each journey is processed independently in constant time, the total time complexity is O(n).

## 3. Space Complexity

The program stores a limited amount of information for each journey, such as the zone, journey time, fare and card balance.

| Data            | Purpose                             | Space Requirement                |
| --------------- | ----------------------------------- | -------------------------------- |
| Card balance    | Stores the available money          | O(1)                             |
| Zone value      | Identifies the selected zone        | O(1)                             |
| Journey time    | Determines whether peak hours apply | O(1)                             |
| Calculated fare | Stores the fare for the journey     | O(1)                             |
| Fare constants  | Store the fixed fare rules          | O(1) for a fixed number of zones |

The auxiliary space required to process one journey is O(1), assuming the system does not store a growing journey history in memory.

If the system stores all n journeys in memory, the space required for that history becomes O(n).

## 4. Procedural Programming vs Object-Oriented Programming

| Comparison                  | Procedural Programming                             | Object-Oriented Programming                                          |
| --------------------------- | -------------------------------------------------- | -------------------------------------------------------------------- |
| Organisation                | Functions and variables                            | Classes and objects                                                  |
| Balance protection          | Depends on how variables and functions are managed | Private data and controlled member functions can protect the balance |
| Reuse                       | Functions can be reused                            | Classes and member functions can be reused                           |
| Maintenance                 | Changes may affect several functions               | Responsibilities can be separated into classes                       |
| Time complexity per journey | O(1)                                               | O(1)                                                                 |
| Auxiliary space per journey | O(1)                                               | O(1)                                                                 |
| Suitability                 | Suitable for a small implementation                | Suitable for a system expected to grow                               |

Both approaches can achieve the same asymptotic time and space complexity. OOP does not automatically make fare calculation faster; its main advantages are organisation, data protection and maintainability.

## 5. Effect of Fare Rule Changes

Suppose the metro authority changes the Outer Zone fare from ₹30 to ₹35.

If the fare value is repeated in multiple parts of the program, each occurrence may need to be updated. Missing one occurrence could produce inconsistent results.

If the fare is stored in one central fare table or named constant, the developer can update the value in one place. The remaining fare calculation logic can continue to use that value.

The lookup and calculation can remain O(1) when the table size is fixed and the selected fare is accessed directly.

## 6. Conclusion

The fare calculation, peak-hour checking, balance validation and fare deduction operations can each run in O(1) time for a single journey. Processing n journeys takes O(n) time when each journey is handled independently.

Both procedural and OOP implementations can have O(1) auxiliary space per journey. However, OOP provides a clearer structure for protecting the card balance and maintaining separate responsibilities. Centralising fare rules also makes future changes easier and reduces the risk of inconsistent fare values.

