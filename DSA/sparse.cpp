#include <bits/stdc++.h>
using namespace std;

int main(){
    int n , m;
    cin >> n >> m;
    int matrix[n][m];
    int cnt = 0;
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < m ; j++){
            cin >> matrix[i][j];
            if(matrix[i][j] != 0){
                cnt++;
            }
        }
    }
    int sparse[cnt + 1][3];
    sparse[0][0] = n + 1;
    sparse[0][1] = m + 1;
    sparse[0][2] = cnt;
    int k = 1;
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < m ; j++){
            if(matrix[i][j] != 0){
                sparse[k][0] = i + 1;
                sparse[k][1] = j + 1;
                sparse[k][2] = matrix[i][j];
                k++;
            }
        }
    }
    for(int i = 0 ; i <= cnt ; i++){
        cout << sparse[i][0] - 1 << ' ';
        cout << sparse[i][1] - 1 << ' ';
        cout << sparse[i][2] << '\n';
    }
}