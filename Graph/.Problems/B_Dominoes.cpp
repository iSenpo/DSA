#include <bits/stdc++.h>
using namespace std;

const int N = 7;
const int M = 1e2 + 10;
vector<int> ind[N];
pair<int , int> edg[M];
vector<pair<int , char>> ans;
int ptr[N];
bool mark[M];

inline int in(){
    int x;
    cin >> x;
    return x;
}

void tour(int v, int i){
    while(ptr[v] < ind[v].size()){
        //find edge : 
        int e = ind[v][ptr[v]];
        //find u :
        int u = edg[e].first;
        if(u == v)
            u = edg[e].second;
        //~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ 
        ptr[v]++;
        if(!mark[e]){
            mark[e] = true;
            tour(u , e);
        }
    }
    if(i != -1){
        pair<int , int> e = edg[i];
        if(e.first == v){
            ans.push_back({i , '+'});
        }
        else{
            ans.push_back({i , '-'});
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    /*------------------------------------*/
    int n = in();
    int v , u;
    for(int i = 0 ; i < n ; i++){
        cin >> v >> u;
        ind[v].push_back(i);
        ind[u].push_back(i);
        edg[i] = {v , u};
    }
    int odd = 0;
    int ctr = 0;
    for(int i = 0; i < N ; i++){
        if(ind[i].size() % 2 == 1){
            odd = i;
            ctr++;
        }
    }
    if(ctr > 2){
        cout << "No solution\n";
        return 0;
    }
    if(ind[odd].size() % 2 == 0){
        for(int i = 0 ; i < N ; i++){
            if(ind[i].size() > 0){
                odd = i;
            }
        }
    }
    tour(odd , -1);
    if(ans.size() < n){
         cout << "No solution\n";
        return 0;
    }
    for(int i = 0 ; i < ans.size() ; i++){
        cout << ans[i].first + 1 << ' ' << ans[i].second << '\n'; 
    }
    return 0;
}