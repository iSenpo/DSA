#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ln '\n'

const int N  = 1e3 + 500;
vector<vector<bool>> seen;
vector<vector<char>> a;

int dx[4] = {0 , 0 , 1 , -1};
int dy[4] = {1 , -1 , 0 , 0};
int n , m;

bool isOK(int x , int y){
    if(x <= 0 || y <= 0 || x > n || y > m)
        return false;
    if(seen[x][y])
        return false;
    if(a[x][y] == '#')
        return false;
    return true;
}
void dfs(int x , int y){
    seen[x][y] = true;
    for(int i = 0 ; i < 4 ; i++)
        if(isOK(x + dx[i] , y + dy[i]))
            dfs(x + dx[i] , y + dy[i]);
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    /*------------------------------------*/
    cin >> n >> m;
    a.resize(n + 1 , vector<char>(m + 1));
    seen.resize(n + 1 , vector<bool>(m + 1));

    for(int i = 1 ; i <= n ; i++){
        for(int j = 1 ; j <= m ; j++){
            cin >> a[i][j];
        }
    }
    int counter = 0;
    for(int i = 1 ; i <= n ; i++){
        for(int j = 1 ; j <= m ; j++){
            if(a[i][j] == '#')
                continue;
            else{
                if(!seen[i][j]){
                    counter++;
                    dfs(i , j);
                }        
            }
        }
    }
    cout << counter << ln;
    return 0;
}