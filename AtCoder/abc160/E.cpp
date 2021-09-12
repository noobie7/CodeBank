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
    int x,y,a,b,c;
    cin>>x>>y>>a>>b>>c;
    vector<int> r(a), g(b), w(c);
    get(r);
    get(g);
    get(w);
    sort(all(r));
    sort(all(g));
    sort(all(w));
    priority_queue<int, vector<int>, greater<int>> bestReds;
    priority_queue<int, vector<int>, greater<int>> bestGreens;
    priority_queue<int> bestWhites;
    for(int i = a-1; i>=max(0,a-x); i--) bestReds.push(r[i]);
    for(int i = b-1; i>=max(0,b-y); i--) bestGreens.push(g[i]);
    for(int i : w) bestWhites.push(i);
    while(bestWhites.size() > 0 && (bestReds.top() < bestWhites.top() || bestGreens.top()< bestWhites.top())){
        int transfering = bestWhites.top();
        bestWhites.pop();
        if(bestGreens.top() < bestReds.top()){
            bestGreens.pop();
            bestGreens.push(transfering);
        }
        else{
            bestReds.pop();
            bestGreens.push(transfering);
        }
    }
    ll tot = 0;
    while(bestReds.size()){
        tot += bestReds.top();
        bestReds.pop();
    }
    while(bestGreens.size()){
        tot+= bestGreens.top();
        bestGreens.pop();
    }
    cout<<tot<<endl;
    return 0;
}