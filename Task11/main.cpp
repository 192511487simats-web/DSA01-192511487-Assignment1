#include <iostream>
#include <iomanip>
using namespace std;
enum class Zone { Inner, Middle, Outer };
constexpr long long MIN_BALANCE_PAISE = 5000;
constexpr int PEAK_SURCHARGE_PERCENT = 20;
constexpr int ZONE_COUNT = 3;
const long long BASE_FARE_PAISE[ZONE_COUNT] = {1000, 2000, 3000};
class SmartCard
{
private:
    long long balancePaise;
public:
    SmartCard(long long initialBalance) : balancePaise(initialBalance) {}
    bool canTravel(long long farePaise) const
    {
        return farePaise >= 0 && balancePaise - farePaise >= MIN_BALANCE_PAISE;
    }
    bool deductFare(long long farePaise)
    {
        if (!canTravel(farePaise))
            return false;
        balancePaise -= farePaise;
        return true;
    }
    long long getBalance() const
    {
        return balancePaise;
    }
};
long long calculateFare(Zone zone, bool peak)
{
    int index = static_cast<int>(zone);
    if (index < 0 || index >= ZONE_COUNT)
        return -1;
    long long fare = BASE_FARE_PAISE[index];
    if (peak)
        fare += fare * PEAK_SURCHARGE_PERCENT / 100;
    return fare;
}
void printMoney(long long paise)
{
    cout << "Rs " << paise / 100 << "." << setw(2) << setfill('0') << paise % 100 << setfill(' ');
}
int main()
{
    SmartCard card(10000);
    cout << "METRO SMART-CARD FINAL DESIGN\n";
    cout << "Minimum balance: ";
    printMoney(MIN_BALANCE_PAISE);
    cout << "\n";
    for (int i = 0; i < ZONE_COUNT; i++)
    {
        Zone zone = static_cast<Zone>(i);
        long long offPeak = calculateFare(zone, false);
        long long peak = calculateFare(zone, true);
        cout << "Zone " << i + 1 << " off-peak: ";
        printMoney(offPeak);
        cout << ", peak: ";
        printMoney(peak);
        cout << "\n";
    }
    long long fare = calculateFare(Zone::Outer, true);
    cout << "Outer peak journey fare: ";
    printMoney(fare);
    cout << "\nJourney allowed: " << (card.deductFare(fare) ? "Yes" : "No") << "\n";
    cout << "Remaining balance: ";
    printMoney(card.getBalance());
    cout << "\n";
    cout << "Fare lookup complexity: O(1)\n";
    cout << "Currency storage: integer paise using long long\n";
    return 0;
}
