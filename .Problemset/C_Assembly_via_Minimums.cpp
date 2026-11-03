#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N  = 1e5 + 500;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int size = n*(n-1)/2;
        vector<int> a(size);
        int max = 0;
        for(int i = 0; i < size ; i++){
            cin >> a[i];
            if(a[i] > max){
                max = a[i];
            }
        }
        sort(a.begin() , a.end());
        int counter = 0;

    }
    return 0;
}