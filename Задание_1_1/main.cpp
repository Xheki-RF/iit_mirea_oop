#include <stdlib.h>
#include <stdio.h>
#include <iostream>
using namespace std;


double convert(int temp)
{
    return (temp-32)* 5.0f/ 9.0f;
}

double avgT(double arr[],int n)
{
    double sum = 0.0f;
    for (int i= 0; i < n; i++)
    {
        sum += arr[i];
    }
    return sum / n;
}

int main()
{
    int days;
    cin >> days;
    if (7 <= days && days <= 30)
    {
        double temp_arr[30];
        int t;
        
        for (int i = 0; i < days; i++)
        {
            cin >> t;
            temp_arr[i] = convert(t);
        }
        
        cout << "Temperature data:";

        for (int i = 0; i < days; i++)
        {
            cout << " " << temp_arr[i];
        }
    
        double avg_temp = avgT(temp_arr, days);
        cout << "\nAverage temperature: " << avg_temp;

    }
    else
    {
        cout << "n is wrong";
    }
}