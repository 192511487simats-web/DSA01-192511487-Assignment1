# Task 12 – Re-evaluate and Adapt the Design

## A. Impact Analysis

The original metro system supported three zones: Inner, Middle and Outer. The updated requirements introduce an Airport Zone with a base fare of ₹60, a 10% weekend discount and a monthly pass that permits unlimited journeys in two selected zones.

The following changes are required:

1. Add `Airport` to the `Zone` enumeration.
2. Increase the fare table from three entries to four.
3. Add a weekend discount constant.
4. Modify the fare calculation so the weekend discount does not combine with the peak surcharge.
5. Introduce a `Pass` class to store the two covered zones.
6. Update validation, output and test cases for the additional zone.

## B. Evaluation of the Original Design

The original switch-based fare logic can calculate fares for three zones, but it requires additional cases and careful updates when a new zone is introduced. A fare table makes the base fares easier to maintain in one place.

The original `SmartCard` class can still protect the balance and enforce the minimum-balance rule. However, the monthly pass introduces a separate responsibility: deciding whether a journey is covered by the pass. A separate `Pass` class is therefore a suitable design choice.

Worked examples:

* Airport weekday off-peak: ₹60.
* Airport weekday peak: ₹60 + 20% = ₹72.
* Outer weekend during peak hours: ₹30 − 10% = ₹27.
* Inner journey covered by a pass: ₹0.
* Middle journey not covered by an Inner/Airport pass: ₹20.

These results demonstrate that the new fare rules can be handled without removing the original card-balance protection.

## C. Adaptation and Implementation

The revised program retains integer paise to avoid floating-point rounding in currency calculations.

A fare table stores the base fare for each zone. The fare calculation applies the weekend discount first when the weekend flag is true. Otherwise, it applies the peak surcharge when the peak flag is true.

The `Pass` class stores two selected zones. If the journey zone is covered, the fare is zero. Otherwise, the normal fare calculation is used.

The `SmartCard` class remains responsible for checking whether a fare can be deducted while leaving at least ₹50 in the balance.

## D. Evidence-Based Defence

The program's tests demonstrate the new requirements:

| Test                               |                      Expected result |
| ---------------------------------- | -----------------------------------: |
| Airport off-peak weekday           |                                  ₹60 |
| Airport peak weekday               |                                  ₹72 |
| Outer weekend during peak hours    |                                  ₹27 |
| Inner journey covered by pass      |                                   ₹0 |
| Airport journey covered by pass    |                                   ₹0 |
| Middle journey not covered by pass |                                  ₹20 |
| Airport fare with ₹100 balance     | Journey denied; balance remains ₹100 |
| Invalid zone                       |                             Rejected |

The Airport journey is denied because deducting ₹60 from ₹100 would leave ₹40, which is less than the required ₹50 minimum balance.

## Complexity Analysis

A fare-table lookup takes O(1) time because it accesses an array entry directly. The discount or surcharge calculation also takes O(1) time.

The `Pass` class uses a set to store the two selected zones. Looking up a zone takes O(log p) time, where p is the number of zones stored in the set. The pass requires O(p) storage.

## Limitations

This demonstration models the two zones covered by a pass but does not implement pass expiry, passenger identity validation, recharge, renewal or persistent ownership. The fare table and zone enumeration must also remain consistent.

A production system would need additional validation, transaction logging, secure pass management and persistent card storage.

## Conclusion

I recommend modifying rather than completely redesigning the original system. The `SmartCard` class and integer-paise representation remain useful. A four-entry fare table, a separate weekend-discount rule and a `Pass` class accommodate the new requirements while keeping the fare calculation organized and testable.
