#include <iostream>
#include <iomanip>
#include <sstream>
#include <string>
using namespace std;
const long long MIN_BALANCE=5000;
const int BASE_FARE[]={1000,2000,3000};
bool parseInt(string s,int &v)
{
    stringstream ss(s);
    char extra;
    if(!(ss>>v)) return false;
    if(ss>>extra) return false;
    return true;
}
bool validZone(int zone)
{
    return zone>=1&&zone<=3;
}
bool validRecharge(long long amount)
{
    return amount>=0;
}
bool isPeak(int hour)
{
    return (hour>=8&&hour<10)||(hour>=17&&hour<20);
}
long long calculateFare(int zone,int hour)
{
    if(!validZone(zone)||hour<0||hour>23) return -1;
    long long fare=BASE_FARE[zone-1];
    if(isPeak(hour)) fare+=fare*20/100;
    return fare;
}
bool canTravel(long long balance,long long fare)
{
    return fare>=0&&balance-fare>=MIN_BALANCE;
}
void test(string name,int zone,string hourText,long long balance,long long expectedFare)
{
    int hour;
    bool hourValid=parseInt(hourText,hour)&&hour>=0&&hour<=23;
    long long fare=hourValid?calculateFare(zone,hour):-1;
    bool passed=fare==expectedFare;
    cout<<left<<setw(28)<<name<<" Expected: "<<setw(6)<<expectedFare<<" Actual: "<<setw(6)<<fare<<(passed?" PASS":" FAIL")<<'\n';
}
int main()
{
    cout<<"METRO FARE TEST REPORT\n";
    cout<<"All fares are in paise.\n\n";
    test("Inner off-peak",1,"12",10000,1000);
    test("Inner peak",1,"9",10000,1200);
    test("Middle off-peak",2,"12",10000,2000);
    test("Middle peak",2,"18",10000,2400);
    test("Outer off-peak",3,"12",10000,3000);
    test("Outer peak",3,"9",10000,3600);
    test("Boundary 08:00",1,"8",10000,1200);
    test("Boundary 10:00",1,"10",10000,1000);
    test("Boundary 17:00",1,"17",10000,1200);
    test("Boundary 20:00",1,"20",10000,1000);
    test("Unknown zone",4,"12",10000,-1);
    test("Letters for hour",1,"abc",10000,-1);
    cout<<"\nBalance exactly Rs 50 after fare:\n";
    cout<<(canTravel(6000,1000)?"PASS":"FAIL")<<'\n';
    cout<<"Insufficient balance:\n";
    cout<<(!canTravel(5900,1000)?"PASS":"FAIL")<<'\n';
    cout<<"Negative recharge:\n";
    cout<<(!validRecharge(-1000)?"PASS":"FAIL")<<'\n';
    cout<<"Five-journey total:\n";
    long long fares[]={1000,2000,3000,1200,2400};
    long long total=0;
    for(long long f:fares) total+=f;
    cout<<"Expected: 9600 paise (Rs 96.00)\n";
    cout<<"Actual: "<<total<<" paise (Rs "<<fixed<<setprecision(2)<<total/100.0<<")\n";
    return 0;
}
