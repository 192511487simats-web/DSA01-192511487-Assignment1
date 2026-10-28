#include <iostream>
#include <iomanip>
#include <set>
using namespace std;
enum class Zone { Inner, Middle, Outer, Airport };
constexpr int ZONE_COUNT = 4;
constexpr long long MIN_BALANCE_PAISE = 5000;
constexpr int PEAK_SURCHARGE_PERCENT = 20;
constexpr int WEEKEND_DISCOUNT_PERCENT = 10;
const long long BASE_FARE_PAISE[ZONE_COUNT] = {1000, 2000, 3000, 6000};
const char* ZONE_NAMES[ZONE_COUNT] = {"Inner", "Middle", "Outer", "Airport"};
bool validZone(Zone zone)
{
    int i = static_cast<int>(zone);
    return i >= 0 && i < ZONE_COUNT;
}
long long calculateFare(Zone zone, bool peak, bool weekend)
{
    if (!validZone(zone))
        return -1;
    long long fare = BASE_FARE_PAISE[static_cast<int>(zone)];
    if (weekend)
        fare = fare - fare * WEEKEND_DISCOUNT_PERCENT / 100;
    else if (peak)
        fare = fare + fare * PEAK_SURCHARGE_PERCENT / 100;
    return fare;
}
void printMoney(long long paise)
{
    cout << "Rs " << paise / 100 << "." << setw(2) << setfill('0') << paise % 100 << setfill(' ');
}
class SmartCard
{
private:
    long long balancePaise;
public:
    SmartCard(long long balance) : balancePaise(balance) {}
    bool deductFare(long long fare)
    {
        if (fare < 0 || balancePaise - fare < MIN_BALANCE_PAISE)
            return false;
        balancePaise -= fare;
        return true;
    }
    long long getBalance() const
    {
        return balancePaise;
    }
};
class Pass
{
private:
    set<Zone> coveredZones;
public:
    Pass(Zone first, Zone second)
    {
        coveredZones.insert(first);
        coveredZones.insert(second);
    }
    bool covers(Zone zone) const
    {
        return coveredZones.count(zone) > 0;
    }
    long long journeyFare(Zone zone, bool peak, bool weekend) const
    {
        if (!validZone(zone))
            return -1;
        if (covers(zone))
            return 0;
        return calculateFare(zone, peak, weekend);
    }
};
int main()
{
    cout << fixed << setprecision(2);
    cout << "METRO SMART-CARD: UPDATED DESIGN\n";
    cout << "\n1. AIRPORT ZONE TESTS\n";
    cout << "Airport weekday off-peak: ";
    printMoney(calculateFare(Zone::Airport, false, false));
    cout << "\nAirport weekday peak: ";
    printMoney(calculateFare(Zone::Airport, true, false));
    cout << "\n";
    cout << "\n2. WEEKEND DISCOUNT TEST\n";
    cout << "Outer weekend during peak hours: ";
    printMoney(calculateFare(Zone::Outer, true, true));
    cout << "\n";
    cout << "\n3. MONTHLY PASS TEST\n";
    Pass pass(Zone::Inner, Zone::Airport);
    cout << "Inner journey with pass: ";
    printMoney(pass.journeyFare(Zone::Inner, false, false));
    cout << "\nAirport journey with pass: ";
    printMoney(pass.journeyFare(Zone::Airport, true, false));
    cout << "\nMiddle journey not covered by pass: ";
    printMoney(pass.journeyFare(Zone::Middle, false, false));
    cout << "\n";
    cout << "\n4. SMART-CARD BALANCE TEST\n";
    SmartCard card(10000);
    long long fare = calculateFare(Zone::Airport, false, false);
    cout << "Initial balance: ";
    printMoney(card.getBalance());
    cout << "\nAirport fare: ";
    printMoney(fare);
    cout << "\nJourney allowed: " << (card.deductFare(fare) ? "Yes" : "No");
    cout << "\nFinal balance: ";
    printMoney(card.getBalance());
    cout << "\n";
    cout << "\n5. INVALID ZONE TEST\n";
    cout << "Invalid zone rejected: " << (calculateFare(static_cast<Zone>(9), false, false) == -1 ? "Yes" : "No") << "\n";
    cout << "\nComplexity: fare lookup O(1); pass lookup O(log p)\n";
    return 0;
}
