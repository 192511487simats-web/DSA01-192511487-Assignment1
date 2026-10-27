# Task 1 – Understand the Problem and Identify the Objects

## 1. Aim

To analyse the fare logic of a City Metro Smart-Card System, identify its main objects, define the fare calculation rules, and understand how Object-Oriented Programming (OOP) can be used to design a reliable and maintainable system.

## 2. Problem Description

The City Metro Smart-Card System calculates the fare for passengers travelling between different zones. The system must calculate the correct fare, apply the peak-hour surcharge when applicable, verify the card balance, and allow or deny travel according to the minimum balance requirement.

The system has three zones:

| Zone        | Base Fare |
| ----------- | --------: |
| Inner Zone  |       ₹10 |
| Middle Zone |       ₹20 |
| Outer Zone  |       ₹30 |

A 20% surcharge is applied during peak hours:

* Morning peak: 8:00 AM to 10:00 AM
* Evening peak: 5:00 PM to 8:00 PM

The smart card must retain a minimum balance of ₹50 after the fare is deducted. Students and senior citizens are eligible for concessions, but the exact concession percentages and eligibility rules must be specified before they can be implemented.

## 3. Identification of Objects

The main objects in the system are SmartCard, Passenger, Journey, Zone and FareTable.

| Object    | Data / Attributes                           | Behaviour / Functions                                  |
| --------- | ------------------------------------------- | ------------------------------------------------------ |
| SmartCard | Card number, balance                        | Check balance, recharge card, deduct fare              |
| Passenger | Passenger ID, passenger category            | Identify passenger category and concession eligibility |
| Journey   | Source zone, destination zone, journey time | Identify journey details and peak-hour status          |
| Zone      | Zone name and zone category                 | Identify the applicable travel zone                    |
| FareTable | Base fares and surcharge percentage         | Retrieve base fare and calculate final fare            |

Each object represents a specific responsibility in the metro system. This separation makes the design easier to understand, test and maintain.

## 4. Procedural Programming Approach

In procedural programming, the system can be implemented using variables, functions and conditional statements.

The program would store the card balance and journey details in variables. Functions would calculate the fare, check the peak-hour period and validate the remaining balance.

Example pseudocode:

```text
START
    Read passenger category
    Read travel zone
    Read journey time
    Read smart-card balance

    Get the base fare for the selected zone

    IF journey time is during peak hours
        Add the 20% surcharge
    END IF

    IF passenger is eligible for a concession
        Apply the specified concession rule
    END IF

    IF balance - fare >= 50
        Deduct the fare
        Allow travel
    ELSE
        Deny travel
    END IF

    Display fare and remaining balance
STOP
```

The procedural approach is suitable for a small program. However, as the system grows, managing passenger details, cards, journeys and fare rules in separate variables and functions may become difficult.

## 5. Object-Oriented Programming Approach

Object-Oriented Programming organises the program around objects that combine data and related functions.

For this system, separate classes can be created for SmartCard, Passenger, Journey and FareTable. Each class manages the data and operations related to its responsibility.

For example, the SmartCard class can maintain the card balance and provide functions to check whether a journey is affordable and deduct the fare safely.

The FareTable class can store the base fares and surcharge percentage and provide functions to calculate the fare.

This design separates the responsibilities of different components and makes future modifications easier.

## 6. Application of OOP Principles

### 6.1 Encapsulation

Encapsulation combines data and the functions that operate on that data in a class.

For example, the SmartCard balance should be private. Other parts of the program should use controlled functions to check the balance or deduct a fare. This prevents unauthorised changes and helps prevent an invalid negative balance.

### 6.2 Abstraction

Abstraction exposes the necessary operations while hiding implementation details.

For example, the fare calculation function can return the final fare without requiring the passenger-processing component to know every calculation step.

### 6.3 Inheritance

Inheritance allows a new class to reuse the properties and functions of an existing class.

For example, StudentPassenger and SeniorCitizenPassenger could inherit common passenger details from a Passenger base class if the design requires different passenger categories.

Inheritance is optional; a simpler design could store the passenger category in a single Passenger class.

### 6.4 Polymorphism

Polymorphism allows a common interface to provide different behaviour for different object types.

For example, if student and senior-citizen concessions are implemented through separate passenger classes, each class could provide its own concession calculation. The exact concession rules must be defined before implementation.

## 7. Fare and Journey Rules

The system should follow these rules:

1. Each zone must have a clearly defined base fare.
2. The Inner Zone fare is ₹10.
3. The Middle Zone fare is ₹20.
4. The Outer Zone fare is ₹30.
5. A 20% surcharge applies during the specified morning and evening peak periods.
6. Peak-hour boundaries must be implemented consistently.
7. Student and senior-citizen concessions must be applied only when eligibility is confirmed and the concession rules are defined.
8. A journey is permitted only when the balance remaining after fare deduction is at least ₹50.
9. A fare must not be deducted when the journey is denied.
10. The program must display the fare charged, the journey decision and the remaining balance.
11. Fare values and surcharge percentages should be maintained centrally to simplify future changes.
12. Invalid journey details and invalid balance values must be handled safely.

**Assumption:** The exact treatment of the starting and ending times of peak periods must be confirmed from the assignment's rules. The implementation should use one consistent boundary convention.

## 8. Conclusion

The City Metro Smart-Card System can be implemented using either procedural programming or Object-Oriented Programming. The procedural approach is straightforward for a small solution, whereas OOP provides better organisation by separating smart cards, passengers, journeys and fare calculations into individual responsibilities.

Using encapsulation to protect the card balance and centralising fare rules will improve reliability and maintainability. Therefore, an OOP-based design is a suitable choice for a metro fare system that may need additional zones, passenger concessions and other fare rules in the future.
