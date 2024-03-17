#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define test int t; cin >> t; while(t--)
#define Ctest int t,cas=0; cin >> t; while(cas++<t)

int main()
{
    int ele;
    cout << "Enter amount of Tasks: ";
    cin >> ele;
    vector<pair<int,int>> data;

    cout << "enter the tasks as starting and ending: "<<endl;

    for(int i=0 ; i<ele ; i++)
    {
        int a,b;
        cin >> a >> b;
        data.push_back({b,a});
    }
    sort(data.begin(),data.end());

    vector<int> answer(ele,0);
    int temp=0;

    for(int i=0 ; i<ele ; i++)
    {
        if(temp<=data[i].second)
        {
            temp = data[i].first;
            answer[i] = 1;
        }
    }

    cout << "selected tasks : "<<endl;

    for(int i=0 ; i<ele ; i++)
    {
        if(answer[i]==1)
        {
            cout << data[i].second << " " << data[i].first << endl;
        }
    }
    return 0;
}


// It has done by sorting the vector. but it also can be done by using priority queue
