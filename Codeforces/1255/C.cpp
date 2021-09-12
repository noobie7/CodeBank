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
    vector<vector<int>> g(n+1);
    vector<int> cnt(n+1);
    vector<vector<ll>> a(n-2, vector<ll>(3));
    for(int i = 0; i < n-2; i++){
        for(int j = 0; j < 3; j++){
            cin>>a[i][j];
            g[a[i][j]].push_back(i);
            cnt[a[i][j]]++;
        }
    }
    vector<vector<int>> st(2);
    for(int i = 1; i <= n; i++){
        if(cnt[i]==1){
            st[0].push_back(i);
        }
        if(cnt[i]==2){
            st[1].push_back(i);
        }
    }
    int x = st[0][0];
    int y = st[1][0];
    if(g[y][0] != g[x][0] && g[y][1] != g[x][0])
        y = st[1][1];
    vector<int> vis(n+1);
    vector<int> ans;
    ans.push_back(x);
    ans.push_back(y);
    int c = 2;
    while(c < n){
        int k = 0;
        for(int i : g[x]){
            k = 0;
            for(int j : g[y]){
                if(i==j && !vis[i]){
                    ll s = 1;
                    for(ll p : a[i]) s *= p;
                    s /= x;
                    s /= y;
                    x = y;
                    y = s;
                    ans.push_back(y);
                    vis[i]++;
                    c++;
                    k = 1;
                    break;
                }
            }
            if(k==1) break;
        }
    }
    pra(ans);
    cout<<endl;
    return 0;
}