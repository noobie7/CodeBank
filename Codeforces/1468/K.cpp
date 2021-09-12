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
#define pra(a) fl(i,0,a.size()) cout<<a[i]<<" ";	cout<<endl;
#define pr(a,n) fl(i,0,n) cout<<a[i]<<" ";	cout<<endl;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
const ll INF = 2e18;
const int inf = 2e9;
const int mod1 = 1e9 + 7;



int main(){
    Shazam;
    test(){
        string s; cin >> s;
        int n = s.size();
        int x = 0;
        int y = 0;
        auto update = [&](int i, int &x, int &y){
            if(s[i] == 'L')
                x--;
            if(s[i] == 'R')
                x++;
            if(s[i] == 'U')
                y++;
            if(s[i] == 'D')
                y--;
        };
        int a = 0;
        int b = 0;
        for(int i = 0; i < n; i++){
            update(i, x, y);
            int x_ = 0, y_ = 0;
            for(int j = 0; j < n; j++){
                int tx = x_;
                int ty = y_;
                update(j, x_, y_);
                if(x_ == x && y_ == y){
                    x_ = tx;
                    y_ = ty;
                }
            }
            if(x_ == 0 && y_ == 0){
                a = x;
                b = y;
                break;
            } 
        }
        cout << a << " " << b << endl;
    }
    return 0;
}