#include <iostream>
using namespace std;
const long long MIN_BALANCE=5000;
long long calculateFare(int zone,bool peak)
{
    long long fare=zone*1000;
    if(peak)
        fare+=fare*20/100;
    return fare;
}
bool proceduralCanTravel(long long balance,long long fare)
{
    return balance-fare>=MIN_BALANCE;
}
class SmartCard
{
private:
    long long balance;
public:
    SmartCard(long long initialBalance)
    {
        balance=initialBalance;
    }
    bool canTravel(long long fare) const
    {
        return balance-fare>=MIN_BALANCE;
    }
    bool deduct(long long fare)
    {
        if(!canTravel(fare))
            return false;
        balance-=fare;
        return true;
    }
    long long getBalance() const
    {
        return balance;
    }
};
int main()
{
    long long balance=10000;
    long long fare=calculateFare(3,true);
    cout<<"Procedural approach:"<<'\n';
    if(proceduralCanTravel(balance,fare))
    {
        balance-=fare;
        cout<<"Journey allowed"<<'\n';
    }
    else
        cout<<"Journey denied"<<'\n';
    cout<<"Balance: Rs "<<balance/100<<'\n';
    SmartCard card(10000);
    cout<<"Object-oriented approach:"<<'\n';
    if(card.deduct(fare))
        cout<<"Journey allowed"<<'\n';
    else
        cout<<"Journey denied"<<'\n';
    cout<<"Balance: Rs "<<card.getBalance()/100<<'\n';
    cout<<"Attempt to deduct Rs 20:"<<'\n';
    if(card.deduct(2000))
        cout<<"Journey allowed"<<'\n';
    else
        cout<<"Journey denied"<<'\n';
    cout<<"Balance: Rs "<<card.getBalance()/100<<'\n';
    return 0;
}
