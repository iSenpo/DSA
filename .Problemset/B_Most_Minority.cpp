#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ln '\n'
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
    /*------------------------------------*/
    int n , m;
    cin >> n >> m;
    string s[n];
    for(int i = 0 ; i < n ;i++){
        cin >> s[i];
    }
    int a[n];
    memset(a , 0 , sizeof a);
    for(int i = 0 ; i < m ; i++){
        int one = 0 , zero = 0;
        for(int j = 0 ; j < n ; j++){
            if(s[j][i] == '1'){
                one++;
            }
            else{
                zero++;
            }
        }
        if(one == 0 || zero == 0){
            for(int j = 0 ; j < n ; j++){
                a[j]++;
            }
        }
        if(one < zero){
            for(int j = 0 ; j < n ; j++){
                if(s[j][i] == '1'){
                    a[j]++;
                }
            }
        }
        if(zero < one){
            for(int j = 0 ; j < n ; j++){
                if(s[j][i] == '0'){
                    a[j]++;
                }
            }
        }
    }
    vector<int> ans;
    int Max = 0;

    for(int i = 0 ; i < n ; i++){
        Max = max(Max , a[i]);
    }
    for(int i = 0 ; i < n ; i++){
        if(a[i] == Max){
            ans.push_back(i+1);
        }
    }
    sort(ans.begin() , ans.end());
    for(int i = 0 ; i < ans.size() ; i++){
        cout << ans[i] << ' ';
    }
    return 0;
}