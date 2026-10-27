#include <iostream>
#include <iomanip>
#include <climits>

using namespace std;

int main()
{
    // Different C++ data types
    bool peakHour = true;
    char zoneCode = 'O';
    int journeyCount = 3000000;
    long long farePaise = 3000;
    unsigned int passengerCount = 1000;
    float temperature = 25.5f;
    double fareRupees = 30.00;
    auto surchargePercent = 20;

    cout << "===== DATA TYPES AND SIZES =====\n";

    cout << "Size of bool: " << sizeof(peakHour) << " bytes\n";
    cout << "Size of char: " << sizeof(zoneCode) << " bytes\n";
    cout << "Size of int: " << sizeof(journeyCount) << " bytes\n";
    cout << "Size of long long: " << sizeof(farePaise) << " bytes\n";
    cout << "Size of unsigned int: "
         << sizeof(passengerCount) << " bytes\n";
    cout << "Size of float: " << sizeof(temperature) << " bytes\n";
    cout << "Size of double: " << sizeof(fareRupees) << " bytes\n";
    cout << "Size of auto variable: "
         << sizeof(surchargePercent) << " bytes\n";

    cout << "\n===== TYPE COMPATIBILITY =====\n";

    int a = 7;
    int b = 2;

    double integerDivision = a / b;
    double floatingDivision = static_cast<double>(a) / b;

    bool flag = 5;

    cout << "Integer division assigned to double: "
         << integerDivision << '\n';

    cout << "Floating-point division: "
         << floatingDivision << '\n';

    cout << "Integer converted to bool: "
         << boolalpha << flag << '\n';

    cout << "\n===== MONEY REPRESENTATION =====\n";

    long long fareInPaise = 1001;
    double fareInRupees = 10.01;

    cout << fixed << setprecision(2);

    cout << "Fare stored in paise: Rs "
         << static_cast<double>(fareInPaise) / 100 << '\n';

    cout << "Fare stored in double: Rs "
         << fareInRupees << '\n';

    cout << "\n===== INTEGER LIMITS =====\n";

    cout << "Minimum int: " << INT_MIN << '\n';
    cout << "Maximum int: " << INT_MAX << '\n';
    cout << "Minimum long long: " << LLONG_MIN << '\n';
    cout << "Maximum long long: " << LLONG_MAX << '\n';

    cout << "\n===== NETWORK COLLECTION =====\n";

    long long totalPaise =
        static_cast<long long>(journeyCount) * 3000;

    cout << "Journeys per day: " << journeyCount << '\n';

    cout << "Collection at Rs 30 per journey: Rs "
         << static_cast<double>(totalPaise) / 100 << '\n';

    cout << "Total collection in paise: "
         << totalPaise << '\n';

    cout << "Maximum int: " << INT_MAX << '\n';

    if (totalPaise > INT_MAX)
    {
        cout << "Result: int is insufficient for this total in paise.\n";
    }
    else
    {
        cout << "Result: int can represent this total in paise.\n";
    }

    cout << "\n===== ROUNDING DEMONSTRATION =====\n";

    double repeatedFare = 0.10;
    double totalDouble = 0.0;

    for (int i = 0; i < 10; i++)
    {
        totalDouble += repeatedFare;
    }

    long long totalIntegerPaise = 0;

    for (int i = 0; i < 10; i++)
    {
        totalIntegerPaise += 10;
    }

    cout << setprecision(17);

    cout << "Double total for ten 10-paise fares: "
         << totalDouble << " rupees\n";

    cout << "Integer-paise total: "
         << totalIntegerPaise << " paise\n";

    cout << "Integer-paise total in rupees: "
         << fixed << setprecision(2)
         << static_cast<double>(totalIntegerPaise) / 100
         << " rupees\n";

    return 0;
}
