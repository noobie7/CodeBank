/*
"Do I really belong in this game I ponder, I just wanna play my part."
- Guts over fear, Eminem
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
    string s; cin>>s;
    vector<vector<int>> old(26), res(26);
    for(int i = 0 ; i < n; i++){
        old[s[i]-'a'].push_back(i);
    }
    reverse(all(s));
    for(int i = 0 ; i < n; i++){
        res[s[i]-'a'].push_back(i);
    }
    ll ans = 0;
    vector<int> change(n);
    for(int ch = 0; ch < 26; ch++){
        for(int i = 0; i < res[ch].size(); i++){
            change[old[ch][i]] = (old[ch][0] - res[ch][0]);
        }
    }
    pra(change);
    vector<int> incs(n);
    for(int i = n-1; i >= 0; i--){
        if(change[i]>0){
            incs[i-change[i]]+=1;
            incs[i]-=1; 
        }
    }
    for(int i = 1; i < n; i++) incs[i]+=incs[i-1];
    for(int i = 0; i < n; i++) if(change[i]>0) incs[i]-=change[i];
    pra(incs);
    cout<<ans<<endl;
    return 0;
}