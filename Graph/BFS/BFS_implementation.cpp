#include <bits/stdc++.h>
using namespace std;

const int N  = 1e3 + 500;
vector<int> adj[N];
int h[N];
bool seen[N];
int par[N];

void input(){
    /*
    2--\ /---4
    |   3    |
    1--/ \---5
    */
   adj[0] = {0};
   adj[1] = {2 , 3};
   adj[2] = {1 , 3};
   adj[3] = {1 , 2 , 4 , 5};
   adj[4] = {3 , 5};
   adj[5] = {3 , 4};
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    /*------------------------------------*/
    input();
    memset(seen , false , sizeof seen);
    memset(h , 63 , sizeof h);
    //with queue :
    queue<int> q;
    q.push(1);
    seen[1] = true;
    h[1] = 0;
    while(!q.empty()){
        int v = q.front();
        q.pop();
        cout << v << " -> " << h[v] << endl;
        for(int u : adj[v]){
            if(!seen[u]){
                q.push(u);
                seen[u] = true;
                h[u] = h[v] + 1;
            }
        }
    }

    cout << "~~~~~~~~~~~~~~~~~~~~~~~~\n";

    memset(seen , false , sizeof seen);
    memset(h , 63 , sizeof h);
    //with vector :
    vector<int> edge;
    edge.push_back(1);
    seen[1] = true;
    h[1] = 0;
    for(int i = 0 ; i < edge.size() ; i++){
        int v = edge[i];
        cout << v << " -> " << h[v] << endl;
        for(int u : adj[v]){
            if(!seen[u]){
                edge.push_back(u);
                seen[u] = true;
                h[u] = h[v] + 1 ;
                par[u] = v;
            }
        }
    }

    cout << "~~~~~~~~~~~~~~~~~~~~~~~~\n"
         << "Shortest Path :\n";

    //shortest path :
    vector<int> path;
    int target = 5;
    while(target != 1){
        path.push_back(target);
        target = par[target];
    }
    path.push_back(1);
    reverse(path.begin() , path.end());
    for(int i : path)
        cout << i << " ";
    cout << endl;
    return 0;
}