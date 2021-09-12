/*
"An anomaly, I'm Muhammad Ali
  Cause I know one day I'm gonna be the"
                - Greatest, Eminem
*/
#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef long long int ll;
#define ff first
#define Shazam ios_base::sync_with_stdio(false);   cin.tie(NULL); cout.tie(NULL);
#define ss second
#define all(c) c.begin(),c.end()
#define endl "\n"
#define test() int t; cin>>t; while(t--)
#define fl(i,a,b) for(int i = a ; i <b ;i++)
#define get(a) fl(i,0,a.size())  cin>>a[i];
#define pra(a) fl(i,0,a.size()) cout<<a[i];	cout<<endl;
#define pr(a,n) fl(i,0,n) cout<<a[i]<<" ";	cout<<endl;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
const ll INF = 2e18;
const int inf = 2e9;
const int mod1 = 1e9 + 7;



int main(){
    Shazam;
    test(){
        int n; cin >> n;
        vector<string> a(n);
        get(a);
        int cnt = 0;
        int move = 0;
        for(auto v : a){
            move += count(all(v), 'X');
        }
        
        auto doit = [&](int x, int y){
            int f = 0;
            for(int i = x; i < min(x + 3, n) ; i++){
                for(int j = y; j < min(y + 3,n); j++){
                    f += (a[i][j] == 'X');
                }
            }
            if(f == 9){
                a[x][y] = a[x+1][y+1] = a[x+2][y+2] = 'O';
                cnt += 3;
                return;
            }
            { //upper left corner for L
                f = 0;
                for(int i = x; i < min(n, x + 3) ; i++){
                    f += (a[i][y] == 'X');
                }
                for(int j = y + 1; j < min(n, y + 3); j++){
                    f += (a[x][j] == 'X');
                }
                if(f == 5){
                    a[x][y] = '0';
                    cnt++;
                }
                
            }
            { //center for +
                f = 0;
                if(x + 1 < n && y + 1 < n){
                    for(int i = x; i < min(n, x + 3) ; i++){
                        f += (a[i][y+1] == 'X');
                    }
                    for(int j = y + 1; j < min(n, y + 3); j++){
                        f += (a[x+1][j] == 'X');
                    }
                    if(f == 5){
                        a[x+1][y+1] = '0';
                        cnt++;
                    }
                }
               
            }
            { //lower left corner for L
                f = 0;
                if(x + 2 < n && y + 2 < n){
                    for(int i = x; i < min(n, x + 3) ; i++){
                        f += (a[i][y+2] == 'X');
                    }
                    for(int j = y + 1; j < min(n, y + 3); j++){
                        f += (a[x+2][j] == 'X');
                    }
                    if(f == 5){
                        a[x+2][y+2] = '0';
                        cnt++;
                    }
                }
                
            }
            { //lower left corner for L
                f = 0;
                if(x + 2 < n && y + 2 < n){
                    for(int i = x; i < min(n, x + 3) ; i++){
                        f += (a[i][y] == 'X');
                    }
                    for(int j = y + 1; j < min(n, y + 3); j++){
                        f += (a[x+2][j] == 'X');
                    }
                    if(f == 5){
                        a[x+2][y] = '0';
                        cnt++;
                    }
                }
            }
            { //upper right corner for L
                f = 0;
                if(x + 2 < n && y + 2 < n){
                    for(int i = x; i < min(n, x + 3) ; i++){
                        f += (a[i][y+2] == 'X');
                    }
                    for(int j = y + 1; j < min(n, y + 3); j++){
                        f += (a[x][j] == 'X');
                    }
                    if(f == 5){
                        a[x][y+2] = '0';
                        cnt++;
                    }
                }
            }
            if(x + 1 < n){  //left bar
                
                f = 0;
                for(int i = x; i < min(n , x + 3); i++){
                    f += (a[i][y] == 'X');
                }
                if(f == 3){
                    a[x+1][y] = '0';
                    cnt++;
                }
            }
            if(x + 1 < n && y + 2 < n){ //right bar
                f = 0;
                for(int i = x; i < min(n , x + 3); i++){
                    f += (a[i][y+2] == 'X');
                }
                if(f == 3){
                    a[x+1][y + 2] = '0';
                    cnt++;
                }
            }
            if(y + 1 < n){ //top bar
                f = 0;
                for(int i = y; i < min(n , y + 3); i++){
                    f += (a[x][i] == 'X');
                }
                if(f == 3){
                    a[x][y + 1] = '0';
                    cnt++;
                }
            }
            if(x + 2 < n){ //bottom bar
                f = 0;
                for(int i = y; i < min(n , y + 3); i++){
                    f += (a[x+2][i] == 'X');
                }
                if(f == 3){
                    a[x+2][y + 1] = '0';
                    cnt++;
                }
            }
            if(x + 1 < n && y + 1){ //middle V bar
                f = 0;
                for(int i = x; i < min(n , x + 3); i++){
                    f += (a[i][y + 1] == 'X');
                }
                if(f == 3){
                    a[x+1][y + 1] = '0';
                    cnt++;
                }
            }
            if(x + 1 < n && y + 1 < n){ //middle h bar
                f = 0;
                for(int i = y; i < min(n , y + 3); i++){
                    f += (a[x+1][i] == 'X');
                }
                if(f == 3){
                    a[x+1][y + 1] = '0';
                    cnt++;
                }
            }

        };


        for(int i = 0; i < n ; i++){
            for(int j = 0; j < n; j++){
                doit(i,j);                
            }
        }
        for(auto v : a){
            pra(v);
        }
    }
    return 0;
}