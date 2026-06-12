#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N  = 1e5 + 500;

int a[N][2];

int distance(int a[2] , int b[2]){
    int dx = abs(a[0] - b[0]);
    int dy = abs(a[1] - b[1]);
    return dx*dx + dy*dy ;
}
int ClosestPair(int l ,int r){
    //base :
    if(r - l <= 1){
        return 2e9;
    }
    if(r - l == 2){
        return distance(a[0] , a[1]);
    }
    if(r - l == 3){
        return min(distance(a[0] , a[1]) , distance(a[0] , a[2]) , distance(a[1] , a[2]));
    }

    //divide :
    int m = (l + r) / 2;
    int d = min (ClosestPair(l , m) , ClosestPair(m , r));

    //conquer & combine :
    int ans = 0;
    vector<int> mid;
    for(int i = l; i < r; i++){
        if(abs(a[i][0] - m) < d){
            mid.push_back(a[i][1]);
        }
    }
    for(int i = 0 ; i < mid.size() ; i++){
        for(int j = i +1 ; j < mid.size() && j <= i+7 ;j++){
            int dis = abs(mid[i] - mid[j]);
            d = min(d,dis);
        }
    }
    return d;
}
int main(){
    int n;
    cin >> n;

    for(int i = 0; i< n ; i++){
        cin >> a[i][0] >> a[i][1];
    }
    sort(a , a + n);
    ClosestPair(0 , n);
    return 0;
}