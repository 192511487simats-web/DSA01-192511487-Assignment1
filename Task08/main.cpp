#include <iostream>
#include <iomanip>
#include <limits>
using namespace std;
int readNumber(const char prompt[])
{
    int value;
    while(true)
    {
        cout<<prompt;
        if(cin>>value)
            return value;
        cout<<"Invalid input! Enter a number.\n";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(),'\n');
    }
}
int main()
{
    int zone,hour,balance;
    zone=readNumber("Enter zone (1=Inner, 2=Middle, 3=Outer): ");
    while(zone<1||zone>3)
    {
        cout<<"Invalid zone!\n";
        zone=readNumber("Enter zone (1=Inner, 2=Middle, 3=Outer): ");
    }
    hour=readNumber("Enter hour (0-23): ");
    while(hour<0||hour>23)
    {
        cout<<"Invalid hour!\n";
        hour=readNumber("Enter hour (0-23): ");
    }
    balance=readNumber("Enter card balance in rupees: ");
    while(balance<0)
    {
        cout<<"Balance cannot be negative!\n";
        balance=readNumber("Enter card balance in rupees: ");
    }
    int baseFare[]={1000,2000,3000};
    int fare=baseFare[zone-1];
    bool peak=(hour>=8&&hour<10)||(hour>=17&&hour<20);
    if(peak)
        fare+=fare*20/100;
    int balancePaise=balance*100;
    cout<<"\n===== METRO JOURNEY REPORT =====\n";
    cout<<"Zone: "<<(zone==1?"Inner":zone==2?"Middle":"Outer")<<'\n';
    cout<<"Time: "<<setw(2)<<setfill('0')<<hour<<":00"<<setfill(' ')<<'\n';
    cout<<"Period: "<<(peak?"Peak":"Off-peak")<<'\n';
    cout<<fixed<<setprecision(2);
    cout<<"Fare: Rs "<<fare/100.0<<'\n';
    if(balancePaise-fare>=5000)
    {
        balancePaise-=fare;
        cout<<"Journey: Allowed\n";
    }
    else
        cout<<"Journey: Denied (minimum balance rule)\n";
    cout<<"Remaining balance: Rs "<<balancePaise/100.0<<'\n';
    cout<<"================================\n";
    return 0;
}
