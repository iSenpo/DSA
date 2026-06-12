#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int , int>
#define ln '\n'

const int N = 1e5 + 10;

vector<int> In[N] , Out[N];
vector<int> Sorted;
bool mark[N];
int cnt = 0 ;
int color[N];

//fill Sorted
void dfs1(int v){
    mark[v] = true;
    for(int i : Out[v]){
        if(!mark[i]){
            dfs1(i);
        }
    }
    Sorted.push_back(v);
}

//Color Vertices
void dfs2(int v){
    mark[v] = true;
    color[v] = cnt;
    for(int i : In[v]){
        if(!mark[i]){
            dfs2(i);
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    /*------------------------------------*/
    int n , m;
    cin >> n >> m;
    for(int i = 0 ; i < m ; i++){
        int v , u;
        cin >> v >> u;
        v--;
        u--;
        Out[v].push_back(u);
        In[u].push_back(v);
    }
    //Topological Sort
    for(int i = 0 ; i < n ; i++){
        if(!mark[i]){
            dfs1(i);
        }
    }
    reverse(Sorted.begin() , Sorted.end());

    //Components
    memset(mark , false , sizeof mark);
    for(int i : Sorted){
        if(!mark[i]){
            dfs2(i);
            cnt++;
        }
    }

    //output
    for(int i = 0 ; i < n ; i++){
        cout << color[i] + 1 << ' ';
    }
    return 0;
}
