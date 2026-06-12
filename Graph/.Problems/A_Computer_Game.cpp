#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ln '\n'

int n;
bool isOk(int x , int y){
    if(x < 0 || x > 1 || y >= n){
        return false;
    }
    return true;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    /*------------------------------------*/
    int t;
    cin >> t;
    while(t--){
        cin >> n;
        vector<vector<bool>> seen(2 , vector<bool> (n , false));
        char a[2][n];
        string s;
        cin >> s;
        for(int i = 0 ; i < n ; i++){
            a[0][i] = s[i];
        }
        string t;
        cin >> t;
        for(int i = 0 ; i < n ; i++){
            a[1][i] = t[i];
        }
        stack<pair<int , int>> st;
        st.push({0 , 0});
        while(!st.empty()){
            pair<int , int> pr = st.top();
            int v = pr.first;
            int u = pr.second;
            st.pop();
            seen[v][u] = true;
            if(v == 0){
                //DOWN
                if(isOk(v + 1 , u) && !seen[v + 1][u] && a[v + 1][u] != '1'){
                    st.push({v + 1 , u});
                    seen[v + 1][u] = true;
                }
                //DOWN-RIGHT
                if(isOk(v + 1 , u + 1) && !seen[v + 1][u + 1] && a[v + 1][u + 1] != '1'){
                    st.push({v + 1 , u + 1});
                    seen[v + 1][u + 1] = true;
                }
            }
            if(v == 1){
                //UP
                if(isOk(v - 1 , u) && !seen[v - 1][u] && a[v - 1][u] != '1'){
                    st.push({v - 1 , u});
                    seen[v - 1][u] = true;
                }
                //UP-RIGHT
                if(isOk(v - 1 , u + 1) && !seen[v - 1][u + 1] && a[v - 1][u + 1] != '1'){
                    st.push({v - 1 , u + 1});
                    seen[v - 1][u + 1] = true;
                }
            }
            //RIGHT
            if(isOk(v , u + 1) && !seen[v][u + 1] && a[v][u + 1] != '1'){
                    st.push({v , u + 1});
                    seen[v][u + 1] = true;
            }
        }
        if(seen[1][n-1]){
            cout << "YES\n";
        }
        else{
            cout << "NO\n";
        }
    }
    return 0;
}