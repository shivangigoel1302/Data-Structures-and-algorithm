#include <iostream>
#include<cmath>
#include<algorithm>
using namespace std;
class node{
   public:
   node* child[2];
   node(){
       child[0]=child[1] = NULL;
   }
};
node* root;

void insert(int x){
    node* curr = root;
    for(int bit = 30 ; bit >=0 ; bit--){
        int set = (x >> bit )&1;
        if(curr->child[set] == NULL){
            curr->child[set] = new node();
        }
        curr = curr->child[set];
    }
}
bool search(int val){
    node* curr = root;
    for(int bits = 30 ; bits >=0 ; bits--){
        int set = (val >>bits) & 1;
        if(curr->child[set] == NULL) return false;
        curr = curr->child[set];
    }
    return true;
}
int max_xor(int x){
    node* curr = root;
    int y = 0;
    for(int bits = 30 ; bits>=0 ; bits--){
        int set = (x>>bits)&1;
        if(set){
            if(curr->child[0] == NULL) {
                curr = curr->child[1];
                y |= (1<<bits);
            }
            else{
                curr = curr->child[0];
            }
        }
        else{
             if(curr->child[1] == NULL) {
                curr = curr->child[0];

            }
            else{
                curr = curr->child[1];
                y |= (1<<bits);
            }
        }
    }
    return y;
}
int main() {
    int n;
    cin>>n;
    int a[100];
    root = new node();
    for(int i = 0 ; i < n ; i++){
        cin>>a[i];
        insert(a[i]);
    }
    // if(search(4)){
    //     cout<<"found";
    // }
    // else{
    //     cout<<"not found";
    // }

    // int m;
    // cin>>m;
    // while(m--){
    //     int x;
    //     cin>>x;
    //     int y = max_xor(x);
    //     cout<<y<<" "<<(x^y)<<endl;
    // }
    int maxxor = 0;
    for(int i = 0 ; i < n ; i++){
        maxxor = max(maxxor,max_xor(a[i]) ^ a[i]);
    }
    cout<<maxxor<<" ";
}
