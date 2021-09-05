#include <iostream>
using namespace std;
int findSize(int cake[100][100], int i, int j,int n, bool visited[100][100]){
    if(j<0 || j>n || i<0 || i>n || cake[i][j] == 0 || visited[i][j] == true){
        return 0;
    }
    visited[i][j] = true;
    int right = findSize(cake,i , j+1, n, visited);
    int bottom = findSize(cake, i+1, j, n, visited);
    int left  = findSize(cake, i, j-1, n, visited);
    int top = findSize(cake, i-1, j, n, visited);
    return left+ right+ top+ bottom+1;
}
int largestPiece(int cake[100][100], int n){
    int maxSize = 0;
    for( int i =0 ;i < n; i++){
        for ( int j =0 ;j < n; j++){
            if(cake[i][j] == 1){
                bool visited[100][100] ={false};

                int size = findSize(cake, i, j, n, visited);
                maxSize= max(maxSize, size);
            }
        }
    }
    return maxSize;
}
int main() {
    int n;
    cin>>n;
   int cake[100][100];
    for( int i = 0 ;i < n ; i++){
        for( int  j  = 0 ; j < n; j ++){
            cin>>cake[i][j];
        }
    }
    int ans =largestPiece(cake,n);
    cout<<ans<<" ";
}
