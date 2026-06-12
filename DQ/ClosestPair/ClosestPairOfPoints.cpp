#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int , int> pr;
const int N  = 1e5 + 500;

int DeltaX(pr a ,pr b){
    return abs(a.first - b.first);
}
int Distance(pr a, pr b){
    int dx = abs(a.first - b.first);
    int dy = abs(a.second - b.second);
    return dx*dx + dy*dy ;
}
int DnQ(int l , int r , pr a[]){
    if(r - l <= 1){
        return 1e9;
    }
    int m = (l + r) / 2;
    int d = min(DnQ(l , m , a) , DnQ(m , r , a));
    vector<pr> mid;
    for(int i = l ; i < r ; i++){
        if(DeltaX(a[i] , a[m]) <= d){
            mid.push_back({a[i].second , a[i].first});
        }
    }
    sort(mid.begin() , mid.end());
    int ans = d;
    for(int i = 0; i < mid.size() ; i++){
        int j = i + 1 ;
        while(j < mid.size() && DeltaX(mid[i] , mid[j]) <= d){
            ans = min(ans , Distance(mid[j] , mid[i]));
            j++;
        }
    }
    return ans;
}
int main(){
    int n;
    cin >> n;
    pr a[n];
    int x , y;
    for(int i = 0 ; i < n ; i++){
        cin >> x >> y;
        a[i] = {x , y};
    }
    sort(a , a + n);
    cout << sqrt(DnQ(0 , n , a));
    return 0;
}