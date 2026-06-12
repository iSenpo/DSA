#include <bits/stdc++.h>
using namespace std;

int main(){
    int r;
    cout <<"Enter Number of Rows :\n";
    cin >> r;
    int v;
    cout <<"Enter Number of Values :\n";
    cin >> v;
    vector<int> rowptr(r + 1);
    vector<int> values(v);
    vector<int> colindx(v);
    int w = 0;
    cout << "Enter rowptrs :\n";
    for(int i = 0 ; i <= r ; i++){
        cin >> rowptr[i];
    }
    cout << "Enter col indexes :\n";
    for(int i = 0 ; i < v ; i++){
        cin >> colindx[i];
        w = max(w , colindx[i]);
    }
    cout << "Enter values :\n";
    for(int i = 0 ; i < v ; i++){
        cin >> values[i];
    }
    vector<vector<int>> matrix(r , vector<int>(w + 1 , 0));
    for(int i = 0 ; i < r ; i++){
        int cnt = rowptr[i + 1] - rowptr[i];
        for(int j = rowptr[i] ; j < rowptr[i + 1] ; j++){
            matrix[i][colindx[j]] = values[j];
        }
    }
    cout << "~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~\n";
    for(int i = 0 ; i < r ; i++){
        for(int j = 0 ; j < w + 1 ; j++){
            cout << matrix[i][j] << ' ';
        }
        cout << '\n';
    }
    return 0;
}