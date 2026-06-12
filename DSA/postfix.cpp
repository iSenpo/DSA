#include <bits/stdc++.h>
using namespace std;

//a+b*(c/(d+e))/f
int main(){
    string s;
    cin >> s;
    stack<char> st;
    string ans;
    map<char , int> order;
    order['^'] = 3;
    order['*'] = 2;
    order['/'] = 2;
    order['+'] = 1;
    order['-'] = 1;
    for(int i = 0 ; i < s.size() ; i++){
        if(s[i] >= 'a' && s[i] <= 'z'){
            ans += s[i];
        }
        else if(s[i] == '('){
            st.push(s[i]);
        }
        else if(s[i] == ')'){
            while(!st.empty() && st.top() != '('){
                ans += st.top();
                st.pop();
            }
            if(!st.empty() && st.top() == '('){
                st.pop();
            }
        }
        else{
            while(!st.empty() && st.top() != '(' && order[st.top()] >= order[s[i]]){
                ans += st.top();
                st.pop();
            }
            st.push(s[i]);
        }
    }
    while(!st.empty()){
        ans += st.top();
        st.pop();
    }
    cout << ans << '\n';
    return 0;
}