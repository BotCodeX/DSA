#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define test ll t; cin >> t; while(t--)
#define Ctest ll t,cas=0; cin >> t; while(cas++<t)
vector<ll> prime(1010,0);
vector<ll>serial;

void sieve(ll n)
{
    for(ll i=2 ; i<n ; i++)
    {
        if(prime[i]==0)
        {
            serial.push_back(i);
            for(ll j=i*i ; j<=n ; j+=i)
            {
                prime[j]=1;
            }
        }
    }
    for(ll i=0 ; i<serial.size() ; i++)
    {
        cout << serial[i]<<endl;
    }
}

int main()
{
    sieve(1010);
    ll n,k,cnt=0;
    cin >>n >>k;
    for(int i=2 ; i<=n ; i++)
    {
        ll t=0;

    }

    return 0;
}
