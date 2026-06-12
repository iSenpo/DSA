#include <bits/stdc++.h>
using namespace std;
int Largest(int s, int e,vector<int> a){
    int n = e - s + 1;
    vector<int> h(n);
    int ct = 0;
    for(int i =0 ; i < a.size() ; i++){
        if(i >= s && i <= e){
            h[ct] = a[i];
            ct++;
        }
    }
    stack<int> stk;
    vector<int> R(n);
    vector<int> L(n);
    for(int i = n-1 ; i>=0 ; i--){
        while(!stk.empty() && h[stk.top()] >= h[i]){
            stk.pop();
        }
        if(stk.empty()){
            R[i] = n-1;
        }
        else{
            R[i] = stk.top()-1;
        }
        stk.push(i);
    }
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
            L[i] = stk.top()+1;
        }
        stk.push(i);
    }
    int Max = 0;
    for(int i = 0; i < n ; i++){
        Max = max(Max,(R[i] - L[i] + 1) * h[i]);
    }
    return Max;
}
int main()
{
    int n;
    cin>>n;
    vector<int> h(n);
    int sum = 0;
    for(int i = 0 ;i<n; i++){
        cin>>h[i];
        sum+= i+1;
    }
    int start,end;
    vector<int> answer(sum);
    cin >> start >> end;
    int counter = 0;
    for(int i = 0 ; i < n ; i++){
        for(int j = i ; j < n ; j++){
            answer[counter] = Largest(i,j,h);
            counter++;
        }
    }
    //sort(answer.begin(),answer.end());
    for(int i = 0 ; i < sum ; i++){
        cout<<answer[i]<<" ";
    }
    return 0;
}
