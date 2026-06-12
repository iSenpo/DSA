#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ln '\n'
const int INF = 1e9;
const int N = 1e6;
int n , m;
vector<vector<char>> a;
bool swch = false;
int minH = INF;
bool mark;
bool seen[500][500];
bool isOk(int i , int j){
    if(i < 0 || j < 0 || i > n-1 || j > m-1){
        return false;
    }
    if(a[i][j] == '#'){
        return false;
    }
    if(a[i][j] == 'o' && swch){
        return false;
    }
    if(a[i][j] == 'x' && !swch){
        return false;
    }
    if(seen[i][j] && a[i][j] == '?'){
        return false;
    }
    if(seen[i][j] && a[i][j] == 'S'){
        return false;
    }
    if(a[i][j] == '?'){
        swch = !swch;
    }
    return true;
}
int dfs(int i , int j , int height){
    if(a[i][j] == 'G'){
        mark = true;
        minH = min(minH , height);
    }
    if(isOk(i-1 , j -1)){
        dfs(i-1 , j -1 , height + 1);
    }
    if(isOk(i+1 , j -1)){
        dfs(i+1 , j -1 , height + 1);
    }
    if(isOk(i-1 , j +1)){
        dfs(i-1 , j +1 , height + 1);
    }
    if(isOk(i+1 , j +1)){
        dfs(i+1 , j +1 , height + 1);
    }
    seen[i][j] = true;
    return 0;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    /*------------------------------------*/

    cin >> n >> m;
    int start[2];
    a.resize(n + 1 , vector<char>(m + 1));

    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < m ; j++){
            cin >> a[i][j];
            if(a[i][j] == 'S'){
                start[0] = i;
                start[1] = j;
            }
        }
    }
    dfs(start[0],start[1],0);
    if(!mark){
        cout << -1;
        return 0;
    }
    cout << minH;
    return 0;
}