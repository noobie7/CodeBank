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
    int n,c,k; cin>>n>>k>>c;
    string s; cin>>s;
    vector<int> a,b;
    for(int i = 0 ; i < n ; i++) if(s[i]=='o'){a.push_back(i); i+=c;}
    for(int i = n-1; i >=0; i--) if(s[i]=='o'){b.push_back(i); i-=c;}
    for(int i = 0 ; i < k ; i++) {if(a[i]==b[k-1-i]) cout<<a[i]+1<<endl;}
    return 0;
}