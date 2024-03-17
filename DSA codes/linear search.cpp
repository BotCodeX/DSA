#include<iostream>
 using namespace std;

 int main()
 {
     int n;
     cout << "Enter Amount of Data: ";
     cin >> n;
     int data[n];
     for(int i=0 ; i<n ; i++)
     {
         cin >> data[i];
     }
     int key;
     bool check=false;
     cout << "Enter Key : ";
     cin >> key;
     for(int i=0 ; i<n ; i++)
     {
         if(data[i]==key)
         {
             check=true;
             break;
         }
     }
     if(check)
     {
         cout << "Key Found"<<endl;
     }
     else
     {
         cout << "Key Not Found"<<endl;
     }
 }

