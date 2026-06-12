#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;
typedef pair<int, int> pii;

#define all(x)      (x).begin(),(x).end()
#define X           first
#define Y           second
#define sep         ' '
#define endl        '\n'
#define SZ(x)       ll(x.size())

const ll MAXN = 1e6 + 10;
const ll LOG = 22;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; //998244353; //1e9 + 9;

ll q, n, m, A[MAXN], B[MAXN], C[MAXN];

int main() {
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

    cin >> q;
    while(q--){
        cin >> n >> m;
        vector<pll> vec;
        vector<ll> bad;
        set<pll> st;
        for(int i = 0; i < n; i++){
            cin >> A[i];
            st.insert({A[i], i});
        }
        for(int i = 0; i < m; i++){
            cin >> B[i];
        }
        for(int i = 0; i < m; i++){
            cin >> C[i];
            if(C[i] > 0){
                vec.push_back({B[i], C[i]});
            }
            else{
                bad.push_back(B[i]);
            }
        }
        sort(all(vec));
        reverse(all(vec));
        int ans = 0;
        vector<pll> rem;
        while(vec.size() > 0 && st.size() > 0){
            auto it = st.begin();
            pll swor = (*it);
            st.erase(it);
            pll mons = vec.back();
            if(swor.X < mons.X){
                rem.push_back(swor);
                continue;
            }
            ans++;
            vec.pop_back();
            st.insert({max(mons.Y, swor.X), swor.Y});
        }
        for(pll i : rem){
            st.insert(i);
        }
        sort(bad.begin(), bad.end());
        for(int i : bad){
            // cout << i << " " << st.size() << endl;
            while(st.size() > 0){
                auto it = st.begin();
                pll swor = (*it);
                st.erase(it);
                if(swor.X < i){
                    continue;
                }
                ans++;
                break;
            }
        }
        cout << ans << endl;
    }

    return 0;
}
/*

*/
