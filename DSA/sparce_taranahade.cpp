#include <bits/stdc++.h>
using namespace std;

int main(){
    int n , m;
    cin >> n >> m;
    int A[n][m];
    int cnt = 0;
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < m ; j++){
            cin >> A[i][j];
            if(A[i][j] != 0){
                cnt++;
            }
        }
    }
    int SparseA[cnt + 1][3];
    SparseA[0][0] = n;
    SparseA[0][1] = m;
    SparseA[0][2] = cnt;
    int k = 1;
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < m ; j++){
            if(A[i][j] != 0){
                SparseA[k][0] = i;
                SparseA[k][1] = j;
                SparseA[k][2] = A[i][j];
                k++;
            }
        }
    }
    cout << "~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ \n";
    cout << "Sparse Matrix A :\n";
    cout << "~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ \n";
    for(int i = 0 ; i <= cnt ; i++){
        cout << SparseA[i][0] << ' ';
        cout << SparseA[i][1] << ' ';
        cout << SparseA[i][2] << '\n';
    }
    int SparseB[cnt + 1][3];
    SparseB[0][0] = n;
    SparseB[0][1] = m;
    SparseB[0][2] = cnt;
    for(int i = 1 ; i <= cnt ; i++){
        SparseB[i][0] = SparseA[i][1];
        SparseB[i][1] = SparseA[i][0];
        SparseB[i][2] = SparseA[i][2];
    }
    for(int i = 1 ; i <= cnt ; i++){
        for(int j = 1 ; j <= cnt - i ; j++){
            if(SparseB[j][0] > SparseB[j + 1][0]){
                swap(SparseB[j] , SparseB[j + 1]);
            }
        }
    }
    cout << "~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ \n";
    cout << "Sparse Taranahade Matrix A :\n";
    cout << "~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ \n";
    for(int i = 0 ; i <= cnt ; i++){
        cout << SparseB[i][0] << ' ';
        cout << SparseB[i][1] << ' ';
        cout << SparseB[i][2] << '\n';
    }
    int B[n][m];
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < m ; j++){
            B[i][j] = 0;
        }
    }
    for(int i = 1 ; i <= cnt ; i++){
        B[SparseB[i][0]][SparseB[i][1]] = SparseB[i][2];
    }
    cout << "~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ \n";
    cout << "Taranahde Matrix A :\n";
    cout << "~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ \n";
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < m ; j++){
            cout << B[i][j] << ' ';
        }
        cout << '\n';
    }
}