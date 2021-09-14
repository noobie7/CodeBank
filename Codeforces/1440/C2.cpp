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
#define pra(a) fl(i,0,a.size()) cout<<a[i] + 1<<" ";	cout<<endl;
#define pr(a,n) fl(i,0,n) cout<<a[i]<<" ";	cout<<endl;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
const ll INF = 2e18;
const int inf = 2e9;
const int mod1 = 1e9 + 7;



int main(){
    Shazam;
    test(){
        int n, m; cin >> n >> m;
        vector<string> ip(n);
        get(ip);
        vector<vector<int>> a(n, vector<int> (m));
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                a[i][j] = ip[i][j] - '0';
            }
        }
        vector<vector<int>> op;

        auto solve1 = [&](int r, int c){
            vector<int> ze, on;
            for(int i = r ; i <= r + 1; i++){
                for(int j = c ; j <= c + 1; j++){
                    if(a[i][j]){
                        on.push_back(i);
                        on.push_back(j);
                    }
                    else{
                        ze.push_back(i);
                        ze.push_back(j);
                    }
                }
            }      
            vector<int> ops;
            ze.pop_back();
            ze.pop_back();
            for(int i : on) ops.push_back(i);
            for(int i : ze) ops.push_back(i);
            op.push_back(ops);             
            for(int i = 0; i < 6; i+=2){
                a[ops[i]][ops[i+1]] = !a[ops[i]][ops[i+1]];
            }
        };
        auto solve2 = [&]( int r, int c){
            vector<int> ze, on;
            for(int i = r ; i <= r + 1; i++){
                for(int j = c ; j <= c + 1; j++){
                    if(a[i][j]){
                        on.push_back(i);
                        on.push_back(j);
                    }
                    else{
                        ze.push_back(i);
                        ze.push_back(j);
                    }
                }
            }      
            vector<int> ops;
            on.pop_back();
            on.pop_back();
            for(int i : on) ops.push_back(i);
            for(int i : ze) ops.push_back(i);
            op.push_back(ops);      
            for(int i = 0; i < 6; i+=2){
                a[ops[i]][ops[i+1]] = !a[ops[i]][ops[i+1]];
            }  
        };
        auto solve3 = [&]( int r, int c){
            vector<int> ze, on;
            for(int i = r ; i <= r + 1; i++){
                for(int j = c ; j <= c + 1; j++){
                    if(a[i][j]){
                        on.push_back(i);
                        on.push_back(j);
                    }
                    else{
                        ze.push_back(i);
                        ze.push_back(j);
                    }
                }
            }      
            vector<int> ops;
            if(ze.size()){
                ze.pop_back();
                ze.pop_back();
            }
            for(int i : on) ops.push_back(i);
            for(int i : ze) ops.push_back(i);
            while(ops.size() > 6) ops.pop_back(); 
            op.push_back(ops); 
            for(int i = 0; i < 6; i+=2){
                a[ops[i]][ops[i+1]] = !a[ops[i]][ops[i+1]];
            }        
        };
        for(int i = 0; i + 1 < n; i+=2){
            for(int j = 0; j + 1 < m; j+=2){
               int cnt = a[i][j] + a[i][j+1] + a[i+1][j] + a[i+1][j+1];
             
               if(cnt == 1){
                   solve1(i,j);
                   solve2(i,j);
                   solve3(i,j);
               }
               else if(cnt == 2){
                   solve2(i,j);
                   solve3(i,j);
               }
               else if(cnt == 3){
                   solve3(i,j);
               }
               else{
                   solve3(i,j);
                   solve1(i,j);
                   solve2(i,j);
                   solve3(i,j);
               }
            }
        }
        for(int i = 0; i + 1 < n; i+=2){
               int  j = m-2;
               int cnt = a[i][j] + a[i][j+1] + a[i+1][j] + a[i+1][j+1];
               if(cnt == 1){
                   solve1(i,j);
                   solve2(i,j);
                   solve3(i,j);
               }
               else if(cnt == 2){
                   solve2(i,j);
                   solve3(i,j);
               }
               else if(cnt == 3){
                   solve3(i,j);
               }
        }
        for(int j = 0; j + 1 < m; j+=2){
            int i = n-2;
            int cnt = a[i][j] + a[i][j+1] + a[i+1][j] + a[i+1][j+1];
            if(cnt == 1){
                solve1(i,j);
                solve2(i,j);
                solve3(i,j);
            }
            else if(cnt == 2){
                solve2(i,j);
                solve3(i,j);
            }
            else if(cnt == 3){
                solve3(i,j);
            }
        }
        cout << op.size() << endl;
        for(auto v : op){
            pra(v);
        }
    }
   
    return 0;
}