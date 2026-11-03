#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fo(i, n) for(int i = 0 ; i < n ; i++)
int MOD = 1e9 + 7;
const int N  = 1e5 + 500;
int arr[N];

void solve()
{

}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    int Max = 1;
    int counter = 1;
    fo(i , n)
        cin >> arr[i];
    for(int i = 1; i < n ; i++){
        if(arr[i] > arr[i-1]){
            counter++;
        }
        else{
            counter = 1;
        }
        Max = max(Max , counter);
    }    
    cout << Max;
    return 0;
}