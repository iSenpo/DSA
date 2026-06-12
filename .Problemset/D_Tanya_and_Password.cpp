#include <bits/stdc++.h>
using namespace std;

const int M = 2e5 + 50;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    vector<string> str(n);
    for(int i = 0 ; i < n ; i++){
        cin >> str[i];
    }

    unordered_map<string , int> StoID;
    vector<string> IDtoS;

    auto get_id = [&](const string &s) -> int{
        auto it = StoID.find(s);
        if(it != StoID.end()){
            return it->second;
        }
        int id = (int)StoID.size();
        StoID[s] = id;
        IDtoS.push_back(s);
        return id;
    };

    const int N = n*2 + 5;
    vector<vector<int>> adj(N);
    vector<int> In(N , 0);
    vector<int> Out(N , 0);

    for(int i = 0 ; i < n ; i++){
        string u = str[i].substr(0 , 2);
        string v = str[i].substr(1 , 2);
        int uID = get_id(u);
        int vID = get_id(v);
        adj[uID].push_back(vID);
        Out[uID]++;
        In[vID]++;
    }

    int start = -1 , end = -1;
    for(int i = 0 ; i < (int)StoID.size() ; i++){
        if(Out[i] - In[i] == 1){
            if(start != -1){
                cout << "NO\n";
                return 0;
            }
            start = i;
        }
        else if(In[i] - Out[i] == 1){
            if(end != -1){
                cout << "NO\n";
                return 0;
            }
            end = i;
        }
        else if(In[i] != Out[i]){
            cout << "NO\n";
            return 0;
        }
    }
    if(start == -1){
        start = get_id(str[0].substr(0 , 2));
    }

    for(int i = 0 ; i < (int)StoID.size() ; i++){
        reverse(adj[i].begin(), adj[i].end());
    }

    vector<int> path;
    stack<int> st;
    st.push(start);

    while(!st.empty()){
        int u = st.top();
        if(!adj[u].empty()){
            int v = adj[u].back();
            adj[u].pop_back();
            st.push(v);
        }
        else{
            path.push_back(u);
            st.pop();
        }
    }

    if(path.size() != n + 1){
        cout << "NO\n";
        return 0;
    }

    reverse(path.begin(), path.end());

    string pass = IDtoS[path[0]];
    for(int i = 1 ; i < (int)path.size() ; i++){
        pass += IDtoS[path[i]][1];
    }

    cout << "YES\n" << pass << '\n';

    return 0;
}
