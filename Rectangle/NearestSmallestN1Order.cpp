#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    int a[n];
    int answer[n];
    stack<int> stk;
    for(int i = 0 ; i<n ; i++){
        cin>>a[i];
    }
    for(int i = n-1; i>=0 ; i--){
        while(!stk.empty() && a[stk.top()] >= a[i]){
            stk.pop();
        }
        if(stk.empty()){
            answer[i] = -1;
        }
        else{
            answer[i] = stk.top();
        }
        stk.push(i);
    }
    
    for(int i = 0 ; i<n ; i++){
        cout<<a[answer[i]] << " ";
    }
    return 0;
}
