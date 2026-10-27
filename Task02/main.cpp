#include <iostream>

using namespace std;

// Fare constants stored in paise
constexpr long long INNER_FARE_PAISE = 1000;
constexpr long long MIDDLE_FARE_PAISE = 2000;
constexpr long long OUTER_FARE_PAISE = 3000;

constexpr int PEAK_SURCHARGE_PERCENT = 20;
constexpr long long MIN_BALANCE_PAISE = 5000;

// Enumeration for metro zones
enum class Zone
{
    Inner,
    Middle,
    Outer
};

// Function to retrieve the base fare
long long getBaseFare(Zone zone)
{
    switch (zone)
    {
        case Zone::Inner:
            return INNER_FARE_PAISE;

        case Zone::Middle:
            return MIDDLE_FARE_PAISE;

        case Zone::Outer:
            return OUTER_FARE_PAISE;
    }

    return 0;
}

// Function to calculate the final fare
long long calculateFare(Zone zone, bool peak)
{
    long long fare = getBaseFare(zone);

    if (peak)
    {
        fare += fare * PEAK_SURCHARGE_PERCENT / 100;
    }

    return fare;
}

// Function to check the minimum balance requirement
bool canTravel(long long balance, long long fare)
{
    return balance - fare >= MIN_BALANCE_PAISE;
}

int main()
{
    Zone zone = Zone::Outer;
    bool peak = true;

    long long balance = 10000;

    long long baseFare = getBaseFare(zone);
    long long finalFare = calculateFare(zone, peak);

    cout << "Base fare: Rs " << baseFare / 100 << '\n';
    cout << "Final fare: Rs " << finalFare / 100 << '\n';

    if (canTravel(balance, finalFare))
    {
        cout << "Journey allowed: Yes" << '\n';
    }
    else
    {
        cout << "Journey allowed: No" << '\n';
    }

    return 0;
}
