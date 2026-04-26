#include <iostream>
using namespace std;
int main()
{
    int a[50], n, key;
    int found = 0;
    cout << "Enter number of elements: ";
    cin >> n;
    cout << "Enter " << n << " elements:\n";
    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    cout << "Enter element to search: ";
    cin >> key;
    for(int i = 0; i < n; i++)
    {
        if(a[i] == key)
        {
            cout << "Element found at position " << i + 1 << endl;
            found = 1;
            break;
        }
    }
    if(found == 0)
    {
        cout << "Element not found" << endl;
    }
    return 0;
}