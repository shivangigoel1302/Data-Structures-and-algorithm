#include <iostream>
using namespace std;
bool isDict(string word){
string dictionary[] = {"mobile","samsung","sam","sung","man","mango",
                           "icecream","and","go","i","like","ice","cream"};
    for(int i = 0 ; i < 13; i++){
        if(dictionary[i].compare(word) == 0){
            return true;
        }
    }
    return false;
}
bool wordBreak(string s , int n){
    bool dp[n+1] = {false};
    for(int i = 1 ; i <= n ; i++){
         if(dp[i] == false && isDict(s.substr(0,i))){
             dp[i] = true;
         }
         if(dp[i] == true){
             if(i== n){
                 return true;
             }
             for(int j = i+1; j<= n ; j++){
                 if(dp[j] == false && isDict(s.substr(i,j-i))){
                     dp[j] = true;
                 }
                 if(j == n && dp[j] == true){
                     return true;
                 }
             }
         }
    }

    return false;
}
int main() {
    string s;
    cin>>s;
    if(wordBreak(s,s.size())){
        cout<<"YES";
    }
    else{
        cout<<"NO";
    }
}
