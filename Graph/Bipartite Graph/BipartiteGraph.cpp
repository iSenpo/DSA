#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ln '\n'
const int N = 1e5;

vector<int> adj[N];
int part[N];
void input(){
    adj[0] = {0};
    adj[1] = {2 , 6};
    adj[2] = {1 , 3};
    adj[3] = {2 , 4};
    adj[4] = {3 , 5};
    adj[5] = {4 , 6};
    adj[6] = {5 , 1};
}
void print(){
    for(int i = 1; i<= 6 ; i++){
        cout << i << " : " << adj[i][0] <<" -> "<< part[adj[i][0]]<< " , " 
                           << adj[i][1]<<" -> "<< part[adj[i][1]] << ln; 
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    /*------------------------------------*/
    input();
    bool bipartite = true;
    memset(part , 0 , sizeof(part));
    
    queue<int> q;
    q.push(1);
    part[1] = 1;
    while(!q.empty()){
        int v = q.front();
        q.pop();
        for(int i = 0 ; i < adj[v].size() ; i++){
            if(part[adj[v][i]] != 0){
                if(part[adj[v][i]] == part[v]){
                    bipartite = false;
                }
            }
            if(part[adj[v][i]] == 0){
                q.push(adj[v][i]);
                part[adj[v][i]] = part[v] * -1;
            }
        }
    }
    print();
    cout << bipartite << ln;
    return 0;
}