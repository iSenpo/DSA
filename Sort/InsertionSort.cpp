#include <bits/stdc++.h>
using namespace std;

void insertionSort(int a[] , int n){
    for(int i = 1; i < n ; ++i){
        int k = a[i];
        int j = i - 1;
        while(j >= 0 && a[j] > k){
            a[j + 1] = a[j];
            --j;
        }
        a[j + 1] = k;
    }
}
void print(int b[] , int n){
    for(int i = 0 ; i < n ; i++){
        cout << b[i] << ' ';
    }
    cout << '\n';
}
int main(){
    int n;
    cin >> n;
    int array[n];
    for(int i = 0 ; i < n ; ++i){
        cin >> array[i];
    }
    cout << "Befor Sort:\n";
    print(array , n);
    insertionSort(array , n);
    cout << "After Sort:\n";
    print(array , n);
    return 0;
}
//Shayan Erfanian - 40311126044