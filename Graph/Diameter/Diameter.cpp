#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ln '\n'

const int N  = 1e5 + 500;
vector<int> adj[N];
int diameter[N];
int DownPath[N];


void input(){
    /*
                 1
               /   \
              2     3
                 /    \
                4      5
               / \    / \
              6   7  8   9
             /            \
            10             11


            output :
            Diameter = 6 
            10 -> 6 -> 4 -> 3 -> 5 -> 9 -> 11
            {10 , 11}
    */
    adj[1] = {2 , 3};
    adj[3] = {4 , 5};
    adj[4] = {6 , 7};
    adj[5] = {8 , 9};
    adj[6] = {10};
    adj[9] = {11};
}
int DownDP(int v){
    if(adj[v].empty()){
        return DownPath[v] = 0;
    }
    int BestChild = 0;
    for(int i : adj[v]){
        BestChild = max(BestChild , DownDP(i));
    }
    return DownPath[v] = BestChild + 1;
}
void Diameter(int v){
    int ans = 0;
    vector<int> edges;
    for(int i : adj[v]){
        Diameter(i);
        edges.push_back(DownPath[i]);
        ans = max(ans , diameter[i]);
    }
    if(edges.empty()){
        diameter[v] = 0;
        return;
    }
    sort(edges.begin() , edges.end());
    if(edges.size() == 1){
        diameter[v] = 1 + edges[0];
    }
    else{
        diameter[v] = 2 + edges[edges.size() - 1] + edges[edges.size() - 2];
    }
    diameter[v] = max(diameter[v] , ans);
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    /*------------------------------------*/
    input();
    DownDP(1);
    Diameter(1);
    cout << diameter[1];
    return 0;
}