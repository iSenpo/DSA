#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ln '\n'
#define fo(i, n) for(int i = 0 ; i < n ; i++)
int MOD = 1e9 + 7;
const int N  = 1e5 + 500;
int arr[N];

void solve()
{

}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    /*------------------------------------*/
    ll n , q;
    cin >> n >> q;
    vector<ll> A(n) , B(n) , mq(n);
    ll Sum = 0;
    for(int i = 0 ; i < n ; i++){
        cin >> A[i];
    }
    for(int i = 0 ; i < n ; i++){
        cin >> B[i];
    }
    for(int i = 0 ; i < n ; i++){
        mq[i] = min(A[i] , B[i]);
        Sum += mq[i];
    }
    while(q--){
        char c;
        int a , b;
        cin >> c >> a >> b;
        a--;
        if(c == 'A'){
            A[a] = b;
            Sum -= mq[a];
            mq[a] = min(A[a] , B[a]);
            Sum += mq[a];
            cout << Sum <<ln;
        }
        else{
            B[a] = b;
            Sum -= mq[a];
            mq[a] = min(A[a] , B[a]);
            Sum += mq[a];
            cout << Sum <<ln;
        }
    }
    return 0;
}