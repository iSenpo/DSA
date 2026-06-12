#include <bits/stdc++.h>
using namespace std;

const int MAXN  = 200 + 10 , MAXX = 10 * 1000 + 10;
int a[MAXN];
bool dpl[MAXN][MAXX]{false};
bool dpr[MAXN][MAXX]{false};
vector<int> ans;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n , x;
    cin >> n >> x;
    
    for(int i = 1; i <= n ;i++){
        cin >> a[i];
    }

    //base 
    dpl[0][0] = true;

    for(int i = 1; i<= n ; i++)
    {
        //base
        dpl[i][0] = true;

        for(int j = 1; j <= x ; j++)
        {
            dpl[i][j] = dpl[i - 1][j];

            if(a[i] <= j)
            {
                dpl[i][j] |= dpl[i - 1][j - a[i]];
            }
        }
    }
    //base 
    dpr[n + 1][0] = true;

    for(int i = n; i >= 1 ; i--)
    {
        //base
        dpr[i][0] = true;

        for(int j = 1; j <= x ; j++)
        {
            dpr[i][j] = dpr[i + 1][j];
            
            if(a[i] <= j)
            {
                dpr[i][j] |= dpr[i + 1][j - a[i]];
            }
        }
    }

    for(int i = 1 ; i <= n ; i++)
    {
        bool flag = false;
        for(int t = 0 ; t <= x ; t++)
        {
            if(dpl[i - 1][t] && dpr[i + 1][x - t])
            {
                flag = true;
            }
        }
        if(!flag){
            ans.push_back(a[i]);
        }
    }
    cout << ans.size() << endl;
    for(auto k : ans){
        cout << k << " ";
    }
    cout << endl;
    return 0;
}