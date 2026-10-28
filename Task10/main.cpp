#include <iostream>
#include <iomanip>
#include <climits>
using namespace std;
int main()
{
    const double fareRupees=10.01;
    const long long farePaise=1001;
    const long long journeys[]={20000,500000,3000000};
    cout<<fixed<<setprecision(2);
    cout<<"DOUBLE VS INTEGER-PAISE TOTALS\n";
    for(long long n:journeys)
    {
        double totalDouble=0.0;
        long long totalPaise=0;
        for(long long i=0;i<n;i++)
        {
            totalDouble+=fareRupees;
            totalPaise+=farePaise;
        }
        double integerTotalRupees=totalPaise/100.0;
        cout<<"\nJourneys: "<<n<<'\n';
        cout<<"Double total: Rs "<<totalDouble<<'\n';
        cout<<"Integer-paise total: Rs "<<integerTotalRupees<<'\n';
        cout<<setprecision(10);
        cout<<"Difference: Rs "<<totalDouble-integerTotalRupees<<'\n';
        cout<<setprecision(2);
    }
    long long networkPaise=3000000LL*3000LL;
    cout<<"\nINT RANGE: "<<INT_MIN<<" to "<<INT_MAX<<'\n';
    cout<<"Network total: "<<networkPaise<<" paise\n";
    cout<<"Network total in rupees: Rs "<<networkPaise/100.0<<'\n';
    cout<<"Fits in int: "<<(networkPaise<=INT_MAX?"Yes":"No")<<'\n';
    cout<<"Fits in long long: Yes\n";
    return 0;
}
