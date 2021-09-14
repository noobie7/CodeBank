/*
"Won't stop untill I'm Phenomenal"
- Phenomenal, EMINEM
*/
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
    ll k; cin>>k;
    vector<int> p(n);
    for(int &i : p) cin>>i, --i;
    vector<int> path;
    int v = 0;
    int cnt = 0;
    set<int> vis;
    int start;
    while(true){
        path.push_back(v);
        vis.insert(v);
        cnt++;
        v = p[v];
        start = v;
        if(vis.count(v))
            break;
        
    }
    if(k<cnt){
        cout<<path[k]+1<<endl;
        return 0;
    }

    int off = 0;
    for(int i = 0; i < cnt; i++){
        off = i;
        if(start == path[i])
            break;
    }
    
    k-=off;

    cout<<path[off + k%(cnt-off)]+1<<endl;
    
    return 0;
}