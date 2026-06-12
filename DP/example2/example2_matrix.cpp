#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N  = 1e5 + 500;

int n , m;
vector<vector<int>> dp;
vector<vector<int>> input;
int counter = 0;
int matrix(int i , int j){
    counter++;
    //base : 
    if(i >= n || j >= m){
        return 1e5;
    }
    if(i == n-1 && j == m-1){
        return input[n-1][m-1];
    }
    //dp : 
    if(dp[i][j] != -1){
        return dp[i][j];
    }
    return dp[i][j] = input[i][j] + min(matrix(i+1 , j) , matrix(i , j+1));
}
int main(){
    cin >> n >> m;
    dp.resize(n,vector<int> (m , -1));
    input.resize(n,vector<int> (m , -1));
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < m ; j++){
            cin >> input[i][j];
        }
    }
    dp[n-1][m-1] = input[n-1][m-1];
    cout<< matrix(0 , 0) << " \t " << counter;
    return 0;
}   