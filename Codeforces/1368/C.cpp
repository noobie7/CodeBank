/*
"An anomaly, I'm Muhammad Ali
  Cause I know one day I'm gonna be the"
                - Greatest, Eminem
*/
#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
#include<bits/stdc++.h>
using namespace std;
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
const ll INF = 2e18;
const int inf = 2e9;
const int mod1 = 1e9 + 7;



int main(){
    Shazam;
    int n; cin>>n;
    vector<pair<int,int>> pts;
    ll sx = 0;
    ll sy = 0;
    for(int i = 0; i < n+2; i++){
        pts.push_back({sx,sy});
        sx+=2;
        sy+=2;
    }
    vector<int> dx = {1,0,-1,0};
    vector<int> dy = {0,1,0,-1};
    set<pair<int,int>> ans;
    for(int i = 0; i < n + 2; i++){
        int x = pts[i].ff;
        int y = pts[i].ss;
        ans.insert({x,y});
        if(i==0 || i == n+1){
            int coff;
            if(i == n+1) coff = -1;
            else         coff =  1;

            for(int move = 0; move < 2; move++){
                for(int k = 0; k < 2; k++){
                    int x_ = x + coff*(move + 1)*dx[k];
                    int y_ = y + coff*(move + 1)*dy[k]; 
                    ans.insert({x_, y_});
                }
            }
            continue;
        }
        for(int move = 0; move < 2; move++ ){
            for(int k = 0; k < 4; k++){
                int x_ = x + (move + 1)*dx[k];
                int y_ = y + (move + 1)*dy[k];
                ans.insert({x_,y_});
            }
        }
    }
    cout << (int)ans.size() << endl;
    for( auto pp : ans){
        cout << pp.ff << " " << pp.ss << endl;
    }
    
    return 0;
}