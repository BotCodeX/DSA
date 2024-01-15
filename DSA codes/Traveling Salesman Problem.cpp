#include<bits/stdc++.h>
using namespace std;
typedef vector<int> Vector1;
typedef pair<int,Vector1> Pair1;
typedef vector<vector<int> > Vector2;
priority_queue<pair<Pair1,Vector2>> data;

int n,cost=0;

vector<vector<int> > Reduce(vector<vector<int> >Tvector)
{
    int row=0,col=0;
    //row reduce
    for(int i=0; i<n; i++)
    {
        int x = *min_element(Tvector[i].begin(),Tvector[i].end());
        if(x<10000) row+=x;
        for(int j=0; j<n; j++)
        {
            if(Tvector[i][j]>10000) continue;
            else Tvector[i][j]-=x;
        }
    }
    //column reduce
    for(int i=0; i<n; i++)
    {
        vector<int>temp;
        for(int j=0; j<n; j++)
        {
            temp.push_back(Tvector[j][i]);
        }
        int x= *min_element(temp.begin(),temp.end());
        if(x<10000) col+=x;
        for(int j=0; j<n; j++)
        {
            if(Tvector[j][i]>10000) continue;
            else Tvector[j][i]-=x;
        }
    }
    cost =row+col;
    return Tvector;
}

void Print(vector<vector<int> >Rvec)
{
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            if(Rvec[i][j]>10000)
            {
                cout<<"$ ";
            }
            else
            {
                cout << Rvec[i][j]<<"  ";
            }
        }
        cout << endl;
    }
}


int main()
{
    vector<vector<int> >Tvector,Rvec,TV,rtemp;
    int temp,Rc;
    cin >> n;

    for(int i=0; i<n; i++)
    {
        vector<int> row;
        for(int j=0; j<n; j++)
        {
            cin >> temp;
            if(i==j)
            {
                row.push_back(INT_MAX);
            }
            else
            {
                row.push_back(temp);
            }
        }
        Tvector.push_back(row);
    }
    Rvec=Reduce(Tvector);
    Rc=cost;
//    cout << "first :\n";
//    Print(Rvec);

    for(int i=1 ; i<n ; i++)
    {
        int cst;
        TV=Rvec;
        for(int j=0; j<n; j++)
        {
            TV[0][j]=INT_MAX;
        }
        for(int j=0; j<n; j++)
        {
            TV[j][i]=INT_MAX;
        }
        TV[i][0]=INT_MAX;
        rtemp = Reduce(TV);

        cst=Rc+cost+Rvec[0][i];
//        cout << "first layer: \n";
//        Print(rtemp);
//        cout << cst <<endl;

        vector<int>path;
        path.push_back(i);
        data.push(make_pair(make_pair(-1*cst,path),rtemp));
    }

    while(data.top().first.second.size()!=n-1)
    {
        rtemp=data.top().second;
        int rcost = -1*data.top().first.first;
        vector<int>rpath = data.top().first.second;

//        cout << "poped layer:" << rpath.back() <<endl;
//        Print(rtemp);
//        cout << rcost <<endl;
        data.pop();

        int des;
        for(int i=1 ; i<n ; i++)
        {
            auto it = find(rpath.begin(),rpath.end(),i);
            if(!(it!=rpath.end()))
            {
                des = i;
                int sou = rpath.back();
                TV=rtemp;
                for(int j=0; j<n; j++)
                {
                    TV[sou][j]=INT_MAX;
                }
                for(int j=0; j<n; j++)
                {
                    TV[j][des]=INT_MAX;
                }
                TV[des][0]=INT_MAX;
                TV=Reduce(TV);
                int temp = -1*(rcost + cost + rtemp[sou][des]);

//                cout << "later layer:" <<sou <<" | "<< des <<endl;
//                Print(TV);
//                cout << temp <<" "<<rcost<<" "<<cost<<" "<< rtemp[sou][des]<<endl;

                vector<int>tph = rpath;
                tph.push_back(des);
                data.push(make_pair(make_pair(temp,tph),TV));
            }
        }
    }
    cout << "The path is : 1  " ;
    for(int i=0 ; i<data.top().first.second.size() ; i++)
    {
        cout << data.top().first.second[i]+1<<"  ";
    }
    cout << "\nCost : ";
    cout << -1*data.top().first.first;
}

/*
5
0 20 30 10 11
15 0 16 4   2
3  5  0  2  4
19 6  18  0 3
16 4  7  16 0
*/

