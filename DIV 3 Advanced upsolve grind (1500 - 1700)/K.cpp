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
    int n; cin >> n;
    int m; cin >> m;
    set<pair<int,int>> edges;
    vector<int> deg(n);
    vector<vector<int>> g(n);
    for(int i = 0; i < m; i++){
        int a, b; cin >> a >> b;
        a--, b--;
        if(a > b) swap(a,b);
        edges.insert({a,b});
        g[a].push_back(b);
        g[b].push_back(a);
        deg[a]++;
        deg[b]++;
    }
    int mx = *max_element(all(deg));
    int best = -1;
    for(int i = 0; i < n; i++){
        if(deg[i] == mx){
            best = i;
            break;
        }
    }
    vector<int> leader(n);
    iota(all(leader),0);
    vector<list<int>> index(n);
    for(int i = 0 ; i < n; i++){
        index[i].push_back(i);
    }
    auto unite = [&](int a, int b){
        // making a go in b
        a = leader[a];
        b = leader[b];
        if(a == b) return 0;
        if(index[a].size() > index[b].size() ){
            swap(a, b);
        }
        for(int i : index[a]){
            index[b].push_back(i);
            leader[i] = b;
        }
        return 1;
    };

    for(int v : g[best]){
        unite(v,best);
        int a = best;
        int b = v; 
        cout << a + 1 << " " << b + 1 << endl;
    }
    for(auto pp : edges){
        int a = pp.ff, b = pp.ss;
        if(unite(a, b)){
            cout << a + 1 << " " << b + 1 << endl;
        }
    }
    
    return 0;
}