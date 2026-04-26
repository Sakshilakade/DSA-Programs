#include <iostream>
using namespace std;
int main()
{
    int a[50], n, key, j;
    cout << "Enter number of elements: ";
    cin >> n;
    cout << "Enter " << n << " elements:\n";
    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for(int i = 1; i < n; i++)
    {
        key = a[i];     
        j = i - 1;
        while(j >= 0 && a[j] > key)
        {
            a[j + 1] = a[j];  
            j--;
        }
        a[j + 1] = key;  
    }
    cout << "Sorted array:\n";
    for(int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    return 0;
}