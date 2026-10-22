# TASK 1 – Understand the Problem and Identify the Objects

## 1. Objects in the Metro Fare System

The Namma Metro Smart-Card System calculates the fare based on the farthest zone travelled and the time of travel. The metro has three zones: Inner, Middle and Outer. The fares are ₹10, ₹20 and ₹30, respectively. During peak hours, an additional 20% is charged. A passenger must have at least ₹50 remaining on their card after paying the fare.

The main objects in this system are SmartCard, Passenger, Journey, Zone and FareTable.

**SmartCard:** It stores the card balance and provides operations to check whether a passenger can travel and deduct the fare. The balance should be private so that it cannot be changed directly without validation.

**Passenger:** It stores passenger details and category. The category is needed because students and senior citizens receive concessions.

**Journey:** It stores journey details, such as the zone travelled and the travel time. It helps determine the correct fare and whether the peak surcharge applies.

**Zone:** The metro has Inner, Middle and Outer zones. Each zone has a different base fare. In C++, these can be represented using `enum class Zone`.

**FareTable:** It stores the base fares, peak surcharge and minimum balance requirement. Keeping these values in one place makes future fare changes easier.

These objects are useful because each one has a separate responsibility. This makes the program easier to understand and maintain.

## 2. Procedural and Object-Oriented Approaches

In a procedural program, we could use variables to store the card balance and journey details. Separate functions such as `calculateFare()`, `isPeakHour()` and `canTravel()` would perform the required operations.

This approach works, but if the balance is stored in a global variable, different functions may change it without checking the rules.

In an object-oriented program, the data and related functions are grouped into classes. For example, the SmartCard class can control balance deductions, while FareTable manages the fare rules.

Both approaches can calculate the same fare. However, the object-oriented approach is easier to organise and maintain when the fare rules change.

## 3. Basic Principles of OOP

### Encapsulation

Encapsulation means keeping data and the functions that operate on it together in a class. In this system, the SmartCard balance can be private, and methods can control how money is deducted. This helps prevent invalid balance changes.

### Abstraction

Abstraction means showing only the necessary operations while hiding the internal details. For example, the `canTravel()` function can tell the program whether a passenger is allowed to travel without exposing all the balance-checking steps.

### Inheritance

Inheritance allows one class to derive from another. For example, Student and SeniorCitizen classes could inherit common details from a Passenger class and implement their concession rules.

However, inheritance is not compulsory for this small system. A passenger category and a separate concession rule may be sufficient.

### Polymorphism

Polymorphism allows different classes to provide their own implementation of a common operation. For example, different concession policies could implement the same discount-calculation method.

This would be useful if the metro introduced several types of concessions in the future.

## 4. Rules for a Correct Journey

The following rules must be followed:

1. The zone must be valid.
2. The base fare must match the farthest zone travelled.
3. The 20% surcharge applies during 8:00–10:00 AM and 5:00–8:00 PM.
4. The balance after paying the fare must be at least ₹50.
5. If a journey is rejected, the card balance must remain unchanged.
6. The card balance must never become negative.
7. Student and senior-citizen concessions must follow the defined concession rules.
8. Fare values should be stored centrally to avoid using inconsistent values in different parts of the program.

The peak-hour boundaries must be handled carefully. Exactly 8:00 AM and 5:00 PM are peak times, while exactly 10:00 AM and 8:00 PM are outside peak hours.

The assignment does not specify the concession percentage or the order in which the concession and surcharge should be applied. These details must be defined before the complete fare calculation is implemented.

## 5. Alternative Concept and Complexity Analysis

If the system used a procedural approach, the card balance could be stored in a variable and functions could calculate the fare and check whether travel is allowed.

If the system used an object-oriented approach, classes such as SmartCard, Journey and FareTable would manage the related data and operations.

For a fixed number of zones, both approaches require a constant number of operations to calculate a fare and validate a journey.

| Operation          | Procedural approach | OOP approach |
| ------------------ | ------------------- | ------------ |
| Fare calculation   | O(1)                | O(1)         |
| Balance validation | O(1)                | O(1)         |
| Space per card     | O(1)                | O(1)         |

Therefore, the time complexity per journey is O(1) in both approaches, and the space complexity per card is also O(1).

The main difference is maintainability. In a procedural program, changing a fare rule may require changes in several functions if the rule is repeated. In an object-oriented program, the change can often be limited to the relevant class or fare policy.

## 6. Conclusion

The Metro Smart-Card System can be organised using SmartCard, Passenger, Journey, Zone and FareTable. Each object has a separate responsibility, which makes the program easier to manage.

The SmartCard class can protect the balance, while FareTable can keep the fare rules in one place. Both procedural and object-oriented approaches have the same basic time and space complexity, but a well-designed object-oriented approach makes future changes easier.
