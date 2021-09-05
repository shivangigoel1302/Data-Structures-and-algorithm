#include<iostream>
#include<stack>
#include<cstring>
using namespace std;
int prec(char c){
    if(c == '^'){
        return 3;
    }
    else if( c== '/' || c=='*'){
        return 2;
    }
    else if( c== '+' || c== '-'){
        return 1;
    }
    return -1;
}
string topostfix(string s){
    stack<char>st;
    string ans = "";
    for(int i = 0 ; i < s.size(); i++){
         if(s[i] >= 'a' && s[i] <='z' || (s[i] >= 'A' && s[i] <= 'Z')){
             ans+=s[i];
         }
         else if(s[i] == '('){
             st.push('(');
         }
         else if(s[i] == ')'){
             while(!st.empty() && st.top() != '('){
                 char x = st.top();
                 st.pop();
                 ans+=x;
             }
             if(st.top() == '('){
                 st.pop();
             }
         }
         else{
             while(!st.empty() && prec(s[i]) <= prec(st.top())){
                 char x = st.top();
                 st.pop();
                 ans+=x;
             }
             st.push(s[i]);
         }
    }
    while(!st.empty()){
        char x = st.top();
        st.pop();
        ans+=x;
    }
    return ans;
}
int main(){

    string s;
    cin>>s;
    cout<<topostfix(s);
}
