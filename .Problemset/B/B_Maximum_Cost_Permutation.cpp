#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ln '\n'
#define fo(i, n) for(int i = 1 ; i <= n ; i++)
#define all(x) (x).begin(),(x).end()
int MOD = 1e9 + 7;
const int N  = 1e5 + 500;
int arr[N];

inline int in(){
    int x;
    cin >> x;
    return x;
}
void solve()
{
    int n = in();
    int a[n + 1];
    vector<int> mis;
    vector<bool> mark(n + 1, false);
    fo(i , n) {
        cin >> a[i];
        mark[a[i]] = true;
    }
    fo(i , n){
        if(!mark[i]){
            mis.push_back(i);
        }
    }
    int l = 0;
    int r = 0;
    fo(i , n){
        if(a[i] == 0){
            bool exit = false;
            for(int j : mis){
                if(i != j){
                    l = i;
                    exit = true;
                    break;
                }
            }
            if(exit){
                break;
            }
        }
        else if(a[i] != i){
            l = i;
            break;
        }
    }
    for(int i = n ; i > 0 ; i--){
        if(a[i] == 0){
            bool exit = false;
            for(int j : mis){
                if(i != j){
                    r = i;
                    exit = true;
                    break;
                }
            }
            if(exit){
                break;
            }
        }
        else if(a[i] != i){
            r = i;
            break;
        }
    }
    if(r == l){
        cout << 0 << ln;
        return;
    }
    cout << r - l + 1<< ln;
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