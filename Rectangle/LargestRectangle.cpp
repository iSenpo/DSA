//largest rectangle / using stack with order = O(n)  
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    int h[n];
    for(int i = 0 ;i<n; i++){
        cin>>h[i];
    }
    stack<int> stk;
    int R[n];
    int L[n];
    for(int i = n-1 ; i>=0 ; i--){
        while(!stk.empty() && h[stk.top()] >= h[i]){
            stk.pop();
        }
        if(stk.empty()){
            R[i] = n-1;
        }
        else{
            R[i] = stk.top() - 1;
        }
        stk.push(i);
    }
    // Right limit is ok (❁´◡`❁)
    while(stk.size()){
        stk.pop();
    }
    for(int i = 0 ; i < n ; i++){
        while(!stk.empty() && h[stk.top()] >= h[i]){
            stk.pop();
        }
        if(stk.empty()){
            L[i] = 0;
        }
        else{
            L[i] = stk.top() + 1;
        }
        stk.push(i);
    }
    // Left limit is ok too (❁´◡`❁)
    int Max = 0;
    for(int i = 0; i < n ; i++){
        Max = max(Max,(R[i] - L[i] + 1) * h[i]);
    }
    cout<<Max;
    //cool
    return 0;
}
