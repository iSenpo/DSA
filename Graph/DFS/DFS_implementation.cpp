#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 500;

vector<int> adj[N];
bool seen[N];

//Recursive:
void DFS(int v){
    seen[v] = true;
    cout << v << " ";
    for(int i = 0 ; i < adj[v].size() ; i++){
        if(!seen[adj[v][i]]){
            DFS(adj[v][i]);
        }
    }
}

//Iterative:
void DFS2(int v){
    seen[v] = true;
    stack<int> st;
    st.push(v);
    while(!st.empty()){
      int u = st.top();
      cout << u << " ";
      st.pop();
      seen[u] = true;
      for(int i = 0 ; i < adj[u].size() ; i++){
        if(!seen[adj[u][i]]){
            st.push(adj[u][i]);
            seen[adj[u][i]] = true;
        }
      }
    }
}
void input(){
    /*
    |0 1 1 0|
    |1 0 1 1|
    |1 1 0 0|
    |0 1 0 0|    
     */
    adj[0] = {0};
    adj[1] = {2 , 3};
    adj[2] = {1 , 3 , 4};
    adj[3] = {1 , 2};
    adj[4] = {2};
}
int main(){
    input();
    while(1){
        int n;
        memset(seen , false , sizeof(seen));
        cout << "\nRecursive :\n";
        cin >> n;
        DFS(n);
        memset(seen , false , sizeof(seen));
        cout << "\nIterative \n";
        cin >> n;
        DFS2(n);
    }
    return 0;
}