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
    vector<int> a(n), ref(n);
    for(int &i : a){cin>>i; i--;}
    vector<vector<int>> ls(n);
    for(int i = 0 ; i < n; i++){
        ls[a[i]].push_back(i);
    }
    for(int i = 0; i < n; i++){
        if(ls[i].size()<2) continue;
        else{
            int l = ls[i][ls[i].size()-2];
            int r = ls[i].back();
            ref[l]+=1;
            if(r+1<n) ref[r+1]-=1;
        }
    }
    ref[0] = 1;
    for(int i = 1; i < n; i++) ref[i] += ref[i-1];
    pra(ref);

    return 0;
}