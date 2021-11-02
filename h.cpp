// C++ program to sort an array of dates
#include<bits/stdc++.h>
using namespace std;
  
// Structure for date
struct Date
{
    int day, month, year;
};
int main()
{
    
    int x;
    int y;
    int z;

    Date arr[] = {
                  {25,  3, 2010},
                  { 3, 12, 1676},
                  {18, 11, 1982},
                  {19,  4, 2015},
                  { 9,  7, 2015}};
                  cin >> arr[1].day;
    int n = sizeof(arr)/sizeof(arr[0]);

    cout << "Sorted dates are\n";
    for (int i=0; i<n; i++)
    {
        cout << arr[i].day << " " << arr[i].month
             << " " << arr[i].year;
        cout << endl;
    }
}