#include <iostream>
using namespace std;

void selectionSort(int arr[], int n) {
    for(int i=0;i<n-1;i++) {
        int min_idx=i;
        for(int j=i+1;j<n;j++) {
            if(arr[j]<arr[min_idx]) min_idx=j;
        }
        int temp=arr[i]; arr[i]=arr[min_idx]; arr[min_idx]=temp;
    }
}

void merge(int arr[], int l, int m, int r) {
    int n1=m-l+1, n2=r-m;
    int L[n1], R[n2];
    for(int i=0;i<n1;i++) L[i]=arr[l+i];
    for(int i=0;i<n2;i++) R[i]=arr[m+1+i];
    int i=0,j=0,k=l;
    while(i<n1 && j<n2) {
        if(L[i]<=R[j]) arr[k++]=L[i++];
        else arr[k++]=R[j++];
    }
    while(i<n1) arr[k++]=L[i++];
    while(j<n2) arr[k++]=R[j++];
}

void mergeSort(int arr[], int l, int r) {
    if(l<r) {
        int m=l+(r-l)/2;
        mergeSort(arr,l,m);
        mergeSort(arr,m+1,r);
        merge(arr,l,m,r);
    }
}

int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;
    int arr[n];
    cout << "Enter elements: ";
    for(int i=0;i<n;i++) cin >> arr[i];

    int choice;
    cout << "Enter 1 for Selection Sort or 2 for Merge Sort: ";
    cin >> choice;

    if(choice==1) selectionSort(arr,n);
    else if(choice==2) mergeSort(arr,0,n-1);

    cout << "Sorted array: ";
    for(int i=0;i<n;i++) cout << arr[i] << " ";
    return 0;
}