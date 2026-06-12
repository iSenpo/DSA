#include <bits/stdc++.h>
using namespace std;

int main(){
    int r1 , v1;
    cout << "Enter number of Rows of Matrix A :\n";
    cin >> r1;
    cout << "Enter number of Elements :\n";
    cin >> v1;
    int rowptr1[r1 + 1];
    int colindex1[v1];
    int values1[v1];
    cout << "Enter Row Pointers of Matrix A:\n";
    for(int i = 0 ; i <= r1 ; i++){
        cin >> rowptr1[i];
    }
    cout << "Enter Colum indexes of Matrix A:\n";
    for(int i = 0 ; i < v1 ; i++){
        cin >> colindex1[i];
    }
    cout << "Enter Values of Matrix A :\n";
    for(int i = 0 ; i < v1 ; i++){
        cin >> values1[i];
    }

    int r2 , v2;
    cout << "Enter number of Rows of Matrix B :\n";
    cin >> r2;
    cout << "Enter number of Elements :\n";
    cin >> v2;
    int rowptr2[r2 + 1];
    int colindex2[v2];
    int values2[v2];
    cout << "Enter Row Pointers of Matrix B:\n";
    for(int i = 0 ; i <= r2 ; i++){
        cin >> rowptr2[i];
    }
    cout << "Enter Colum indexes of Matrix B:\n";
    for(int i = 0 ; i < v2 ; i++){
        cin >> colindex2[i];
    }
    cout << "Enter Values of Matrix B :\n";
    for(int i = 0 ; i < v2 ; i++){
        cin >> values2[i];
    }

    int r3 = max(r1 , r2);
    int v3 = 0;
    vector<int> rowptr3(r3 + 1) , colindex3 , values3;
    rowptr3.push_back(0);
    for(int i = 0 ; i < r3 ; i++){
        int start1 = rowptr1[i] , end1 = rowptr1[i + 1];
        int start2 = rowptr2[i] , end2 = rowptr2[i + 1];
        map<int , int> c;
        set<int> cols;
        for(int j = start1 ; j < end1 ; j++){
            c[j] += values1[j];
            cols.insert(j);
        }
        for(int j = start2 ; j < end2 ; j++){
            c[j] += values2[j];
            cols.insert(j);
        }
        int w = cols.size();
        int raw = rowptr3[i] + cols.size();
        rowptr3[i + 1] = raw;
        for(int j = 0 ; j < w ; j++){
            int v = *cols.begin();
            cols.erase(cols.begin());
            colindex3.push_back(v);
            values3.push_back(c[v]);
        }
    }
    cout << "~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~\n";
    cout << "ROW POINTER C :\n";
    for(int i = 0 ; i <= r3 ; i++){
        cout << rowptr3[i] << ' ';
    }
    cout << "\n~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~\n";
    cout << "COl POINTER C :\n";
    for(int i = 0 ; i < colindex3.size() ; i++){
        cout << colindex3[i] << ' ';
    }
    cout << "\n~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~\n";
    cout << "VALUES  C :\n";
    for(int i = 0 ; i < values3.size() ; i++){
        cout << values3[i] << ' ';
    }
    return 0;
}