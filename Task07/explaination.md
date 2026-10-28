# Task 7: From Procedural to Object-Oriented

## Aim

To implement metro fare logic using procedural programming and object-oriented programming and compare both approaches.

## 1. Procedural Approach

The procedural version uses separate variables and free functions. The functions calculate the fare and check whether a journey is allowed. The balance is stored in a variable and updated when a journey is approved.

## 2. Object-Oriented Approach

The object-oriented version uses a SmartCard class. The balance is declared private, so code outside the class cannot modify it directly. The class provides canTravel() to check the balance and deduct() to deduct a fare only when the journey is permitted.

## 3. Preventing a Negative or Insufficient Balance

The deduct() method checks canTravel() before subtracting the fare. It returns false if the remaining balance would fall below the minimum of 5000 paise. This prevents the method from performing an invalid deduction.

The minimum balance is Rs 50. The initial balance is Rs 100. After the Rs 36 peak-hour Outer-zone fare, the balance is Rs 64. A further Rs 20 fare is denied because it would leave Rs 44, which is below the minimum.

## 4. Comparison

| Feature                  | Procedural                        | Object-oriented                        |
| ------------------------ | --------------------------------- | -------------------------------------- |
| Balance storage          | Separate variable                 | Private class member                   |
| Fare calculation         | Free function                     | Can also use a free function           |
| Balance validation       | Separate function                 | Class method                           |
| Balance protection       | Depends on how functions are used | Private member restricts direct access |
| Changing minimum balance | Update the shared rule            | Update the shared rule                 |
| Time complexity          | O(1) per journey                  | O(1) per journey                       |
| Extra space              | O(1)                              | O(1) per card                          |

## 5. Alternative Concept and Complexity Analysis

If balance were a public data member, other code could directly assign an invalid value, such as a negative balance. Making the balance private and requiring updates through deduct() protects the class invariant. Encapsulation does not change the time or space complexity of the basic operations.

The minimum balance is defined once as MIN_BALANCE, making it easier to update the rule consistently in both designs.

## Conclusion

Both approaches can calculate fares and validate journeys. The SmartCard class provides stronger encapsulation because it prevents outside code from directly modifying the balance and centralizes the balance-validation rule.
