# TASK 1 – Understand the Problem and Identify the Objects

**Assignment Title:** Design, Implement and Validate the Fare Logic of a City Metro Smart-Card System
**Course Outcome:** CO1
**Maximum Marks:** 4

## 1. Aim

To analyse the Namma Metro Smart-Card Fare System using object-oriented programming (OOP), identify the main objects and their data and behaviour, explain the basic principles of OOP, and establish the rules required for a correct journey.

## 2. Problem Analysis

The Namma Metro system divides its network into three zones: Inner, Middle and Outer. The fare is determined by the farthest zone travelled, with fares of ₹10, ₹20 and ₹30 respectively.

A 20% surcharge applies during peak hours:

* Morning peak: 8:00 AM to 10:00 AM.
* Evening peak: 5:00 PM to 8:00 PM.

Students and senior citizens receive concessions. Passengers use stored-value smart cards, and a journey is permitted only if at least ₹50 remains on the card after deducting the fare.

The system must calculate fares accurately, apply the correct fare rules, prevent negative balances and avoid inconsistent fare values.

**Assumption:** The exact concession percentages and eligibility rules are not specified in the scenario. Therefore, they must be defined by the fare policy rather than assumed.

## 3. Identification of Objects

### 3.1 SmartCard

**Data (Attributes):**

* Card ID
* Current balance

**Behaviour (Methods):**

* Recharge the card
* Check the balance
* Validate whether a journey can be paid for
* Deduct the fare

**Justification:** The SmartCard object manages stored money and ensures that a fare deduction does not leave the balance below ₹50. Keeping the balance private prevents other parts of the program from modifying it incorrectly.

### 3.2 Passenger

**Data (Attributes):**

* Passenger ID
* Passenger category, such as regular passenger, student or senior citizen

**Behaviour (Methods):**

* Identify the passenger category
* Check concession eligibility

**Justification:** The Passenger object stores passenger-related information and helps determine whether a concession applies. Separating passenger details from card details allows a passenger to be represented independently of the payment mechanism.

### 3.3 Journey

**Data (Attributes):**

* Source zone
* Destination zone
* Journey date and time

**Behaviour (Methods):**

* Validate the journey
* Determine the farthest zone travelled
* Calculate the applicable fare using the fare policy

**Justification:** The Journey object represents one trip and provides the information needed to calculate the fare. Keeping journey information separate makes it easier to test different routes and travel times.

### 3.4 Zone

**Data (Attributes):**

* Zone ID
* Zone name
* Zone order or distance-related information

**Behaviour (Methods):**

* Identify the zone
* Provide the zone's position in the network

**Justification:** The Zone object represents a part of the metro network. It helps the system identify the farthest zone travelled and supports future network expansion.

### 3.5 FareTable

**Data (Attributes):**

* Inner-zone fare: ₹10
* Middle-zone fare: ₹20
* Outer-zone fare: ₹30
* Peak-hour surcharge rate: 20%
* Applicable concession rules

**Behaviour (Methods):**

* Retrieve the base fare
* Determine whether the journey falls within peak hours
* Apply the surcharge
* Apply eligible concessions
* Return the final fare

**Justification:** The FareTable object centralises fare values and fare rules. This prevents the same values from being duplicated throughout the program. When a fare changes, the corresponding rule can be updated in one place.

## 4. Procedural Programming and Object-Oriented Programming

### 4.1 Procedural Approach

In procedural programming, the system could use global variables and free functions.

Example pseudocode:

```text
GLOBAL cardBalance
GLOBAL innerFare = 10
GLOBAL middleFare = 20
GLOBAL outerFare = 30

FUNCTION calculateFare(sourceZone, destinationZone, journeyTime)
    Determine the farthest zone travelled
    Retrieve the corresponding base fare
    Apply the peak-hour surcharge when applicable
    Apply an eligible passenger concession
    RETURN final fare
END FUNCTION

FUNCTION validateJourney(cardBalance, fare)
    IF cardBalance - fare >= 50
        RETURN true
    ELSE
        RETURN false
    END IF
END FUNCTION

FUNCTION deductFare(fare)
    IF validateJourney(cardBalance, fare)
        cardBalance = cardBalance - fare
        RETURN success
    ELSE
        RETURN failure
    END IF
END FUNCTION
```

In this approach, data is stored in variables and manipulated by separate functions. If global data is accessible to many functions, an incorrect modification may affect the system.

### 4.2 Object-Oriented Approach

In object-oriented programming, data and related operations are grouped into classes such as `SmartCard`, `Passenger`, `Journey`, `Zone` and `FareTable`.

Example pseudocode:

```text
CREATE SmartCard
CREATE Passenger
CREATE Journey
CREATE FareTable

fare = FareTable.calculateFare(Journey, Passenger)

IF SmartCard.canPay(fare)
    SmartCard.deductFare(fare)
    DISPLAY updated balance
ELSE
    DISPLAY "Journey rejected"
END IF
```

The object-oriented approach assigns responsibilities to appropriate objects. The SmartCard manages its balance, the Journey represents the trip, and the FareTable manages fare calculations.

### 4.3 Comparison

| Feature          | Procedural Programming                                    | Object-Oriented Programming                             |
| ---------------- | --------------------------------------------------------- | ------------------------------------------------------- |
| Organisation     | Functions and variables                                   | Classes and objects                                     |
| Data handling    | May use shared global variables                           | Data can be encapsulated within objects                 |
| Fare rules       | Implemented in functions                                  | Centralised in a fare-policy class                      |
| Maintenance      | Duplicated rules may require changes in several functions | Centralised rules can reduce the number of changes      |
| Extensibility    | New features may increase function complexity             | New classes or policies can support additional features |
| Time per journey | O(1)                                                      | O(1)                                                    |
| Memory per card  | O(1)                                                      | O(1)                                                    |

Both approaches can be efficient. The main advantage of OOP is better organisation and maintainability, not automatically lower execution time or memory usage.

## 5. Basic Principles of OOP

### 5.1 Encapsulation

Encapsulation combines data and related methods within a class and restricts direct access to internal data.

For example, the SmartCard class can store its balance in a private variable. A public method can deduct a fare only if the remaining balance is at least ₹50.

This prevents other parts of the program from directly assigning an invalid balance.

### 5.2 Abstraction

Abstraction exposes necessary operations while hiding implementation details.

For example, the gate software can call a method such as `calculateFare()` without needing to know every internal calculation step.

This simplifies the interaction between the gate software and the fare system.

### 5.3 Inheritance

Inheritance allows a derived class to reuse the attributes and methods of a base class.

For example, a base class named `Passenger` could have derived classes named `Student` and `SeniorCitizen`.

Each derived class could provide its own concession-eligibility behaviour.

However, inheritance should be used only when the passenger categories genuinely need different behaviour. A passenger-category field and a concession policy may be simpler for a small system.

### 5.4 Polymorphism

Polymorphism allows the same interface to produce different behaviour depending on the object or implementation.

For example, a virtual method named `getConcession()` could return different concession values for student and senior-citizen passenger classes.

The fare calculation system could call the same method without needing to know the specific passenger subclass.

## 6. Rules Every Correct Journey Must Satisfy

1. **Valid zones:** The source and destination must be valid zones in the metro network.
2. **Correct fare:** The fare must be determined by the farthest zone travelled.
3. **Peak-hour surcharge:** The 20% surcharge must be applied only during the specified peak periods.
4. **Correct time boundaries:** The system must consistently define whether the peak periods include their start and end times. The stated ranges are 8:00–10:00 AM and 5:00–8:00 PM; the exact boundary convention should be documented and tested.
5. **Concession eligibility:** A concession must be applied only to passengers who qualify under the defined policy.
6. **Minimum remaining balance:** A journey is permitted only when the balance after deducting the fare is at least ₹50.
7. **No negative balance:** A fare deduction must never make the card balance negative.
8. **Accurate monetary calculations:** Integer paise should be used for monetary calculations to avoid floating-point rounding errors.
9. **Consistent fare values:** Fare values and surcharge rates should be defined centrally rather than repeated throughout the code.
10. **Valid recharge:** Invalid recharge amounts must not corrupt the stored balance.

### Example

Suppose the card balance is ₹100 and the final fare is ₹30.

Remaining balance:

₹100 − ₹30 = ₹70

Since ₹70 is at least ₹50, the journey is permitted.

If the balance is ₹70 and the fare is ₹30:

₹70 − ₹30 = ₹40

Since ₹40 is below ₹50, the journey must be rejected.

## 7. Alternative Concept and Complexity Analysis

If the fare system were implemented using global variables and free functions instead of classes, the program would still perform the same basic operations: fare calculation, concession application, balance validation and fare deduction.

### 7.1 Time Complexity

A journey requires a fixed number of operations:

* Retrieve the base fare.
* Check the travel time.
* Apply the surcharge and concession.
* Validate the balance.
* Deduct the fare if permitted.

Assuming a fixed fare table and constant-time lookups, each journey takes **O(1)** time in both procedural and object-oriented implementations.

### 7.2 Space Complexity

For one card, the system stores a fixed number of values, such as the card ID and balance. The auxiliary storage needed for a single journey is also constant when a fixed number of values is used.

Therefore, the space required per card and the auxiliary space per journey are **O(1)** in both approaches.

### 7.3 Effect of Changing a Fare Rule

Suppose the Outer-zone fare changes from ₹30 to ₹35.

In a procedural implementation, if the fare value is duplicated across multiple functions, each occurrence may need to be updated. This increases the risk of inconsistent calculations.

In an object-oriented implementation, if the fare is centralised in the FareTable class, the fare value can be changed in one place. The remaining code can continue using the same fare-calculation interface.

This advantage depends on good design: a procedural implementation that also centralises its fare rules can be equally easy to maintain.

### Complexity Summary

| Operation                       | Procedural Approach | OOP Approach       |
| ------------------------------- | ------------------- | ------------------ |
| Calculate one journey's fare    | O(1)                | O(1)               |
| Validate one card's balance     | O(1)                | O(1)               |
| Deduct a fare                   | O(1)                | O(1)               |
| Store one card's balance        | O(1)                | O(1)               |
| Change a centralised fare value | O(1) lookup/update  | O(1) lookup/update |

These are theoretical Big-O analyses under the stated assumptions. Actual execution-time measurements are not included because Task 1 does not require an executable program.

## 8. Conclusion

The object-oriented approach is suitable for the Namma Metro Smart-Card Fare System because it separates passenger information, card balances, journey details, zones and fare policies into clearly defined responsibilities.

Encapsulation protects card balances, abstraction simplifies fare operations, inheritance can represent passenger categories, and polymorphism can support different concession policies.

Both procedural and object-oriented implementations can achieve O(1) time per journey and O(1) space per card. The principal benefit of OOP is improved organisation, maintainability and extensibility as the metro network grows.

The design should also support future changes, such as adding a fourth zone, weekend discounts and monthly passes, without duplicating fare rules.
