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
    int q; cin>>q;
    vector<int> a(n);
    set<int> c;
    multiset<int> d;

    auto add = [&](int x){
        auto ret = c.insert(x);
        assert(ret.ss);
        auto it = ret.ff;
        if(it!=c.begin() && it!=prev(c.end())){
            int del = *next(it) - *prev(it);
            d.erase(d.find(del));
        }
       if(it!=prev(c.end())){
            d.insert(*next(it) - x);
        }
        if(it != c.begin()){
            d.insert(x - *prev(it));
        }
    };
    
    auto Remove = [&](int v){
        auto it = c.find(v);
        assert(it!=c.end());
        if(it != prev(c.end()))
            d.erase(d.find(*next(it)-*it));
        if(it != (c.begin()))
            d.erase(d.find(*it - *prev(it)));
        if(it != prev(c.end()) && it != c.begin())
            d.insert(*next(it) - *prev(it));
        c.erase(it);
    };
    for(int i = 0 ; i < n; i++){
        int k; cin>>k;
        add(k);
    }

    for(int i = 0; i <= q; i++){

        if(d.size()==0)cout<<0<<endl;
        else{
            cout<< *prev(c.end())  -*c.begin()  - *prev(d.end()) <<endl;
        }
        if(i==q) break;
        int op; cin>>op;
        int val; cin>>val;
        if(op){
            add(val);
        }
        else{
            Remove(val);
        }
    }


    return 0;
}