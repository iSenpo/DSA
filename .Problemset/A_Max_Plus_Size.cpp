#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ln '\n'
#define fo(i, n) for(int i = 0 ; i < n ; i++)
#define all(x) (x).begin(),(x).end()
int MOD = 1e9 + 7;
const int N  = 1e5 + 500;
int arr[N];

int in(){
    int x;
    cin >> x;
    return x;
}
void solve()
{
    int n = in();
    int a[n];
    for(int i = 0 ; i < n ; i++){
        cin >> a[i];
    }
    int Max = 0;
    for(int i = 0 ; i < n ; i++){
        vector<int> ans;
        int j = i%2;
        int tmax = 0;
        for(j ; j < n ; j+= 2){
            ans.push_back(a[j]);
            tmax = max(tmax , a[j]);
        }
        tmax = tmax + ans.size();
        Max = max(tmax, Max);
    }
    cout << Max << endl;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    /*------------------------------------*/
    int t = in();
    while(t--){
        solve();
    }
    return 0;
}