Task 11 – Recommend and Defend the Final Design

1. Recommended Data Types

I recommend using long long to store money in paise. Integer paise avoids floating-point rounding errors when calculating fares and maintaining card balances.

I recommend enum class Zone to represent the Inner, Middle and Outer zones. It improves readability and helps prevent accidental mixing of zone values with unrelated integers.

The SmartCard class stores the balance privately. Its member functions check whether a journey is permitted, deduct the fare and return the current balance. This encapsulation protects the card balance from uncontrolled modification.

2. Recommended Constants

Named constants such as MIN_BALANCE_PAISE, PEAK_SURCHARGE_PERCENT and ZONE_COUNT make the program easier to understand and maintain.

The base fares are stored in a table:

Inner Zone: ₹10

Middle Zone: ₹20

Outer Zone: ₹30

The peak surcharge is 20%, and the minimum balance after a journey must be ₹50.

I recommend constexpr for compile-time policy values that are known in advance. A fare table is suitable for storing the base fares together in one place.

3. Fare Revision

For a small assignment with fixed fares, the constants and fare table can be changed in the source code. The program must then be compiled and deployed again.

For a real metro system with frequent fare revisions, the fares could instead be read from a configuration file when the gate starts. The program should validate the file and reject invalid or incomplete fare values.

4. Limitations

The current implementation supports only three zones and a fixed 20% peak surcharge. A future requirement such as an Airport Zone, weekend discounts or monthly passes would require additional fare rules and tests.

The program does not implement persistent card storage, transaction logs, concurrent updates, secure configuration management or recovery after a power failure. These would be necessary in a production system.

5. Correctness at Network Scale

The program stores money in integer paise using long long, reducing the risk of overflow when handling large totals compared with a typical 32-bit int.

For example, three million journeys costing ₹30 each would produce a total of ₹90,000,000, or 9,000,000,000 paise. This paise total exceeds the maximum value of a typical 32-bit signed int, but fits in a 64-bit long long.

The fare lookup takes O(1) time because it accesses an entry in a fixed-size fare table. Each card balance and fare value uses O(1) space.

This supports efficient calculations for a large number of journeys, although production-scale reliability would still require load testing and safe transaction handling.

6. Alternative: Configuration File

If the program reads z fare values from a configuration file at startup:

Startup time for reading the fare values is O(z).

Storage for the fare table is O(z).

Updating fares does not require recompiling the program, provided the configuration format remains compatible.

The program must validate the file and handle missing, malformed or invalid values safely.

For a fixed assignment, compiled constants are simpler. For a metro network where fares change frequently, a validated configuration file is more maintainable because it avoids recompiling and redistributing the application for every fare revision.

Conclusion

I recommend retaining the SmartCard class, integer-paise currency representation, scoped zone enumeration and centralized fare table. These choices improve safety, readability and maintainability. The test program verifies the three zone fares, peak surcharge and minimum-balance rule. A configuration file would be a better choice if fares change frequently in the operational system.

