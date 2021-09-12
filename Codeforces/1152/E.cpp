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
    vector<int> a(n-1);
    vector<int> b(n-1);
    get(a);
    get(b);
    for(int i = 0 ; i < n - 1; i++){
        if(b[i] < a[i]){
            cout << -1 << endl;
            return 0;
        }
    }
    map<int, int> f;
    vector<int> recover(1e6 + 5);
    {
        int c = 0;
        for(int i : a){
            if(f.find(i) == f.end()){
                recover[c] = i;
                f[i] = c++;
            }
        }
        for(int i : b){
            if(f.find(i) == f.end()){
                recover[c] = i;
                f[i] = c++;
            }
        }
    }
    vector<multiset<int>> g(1e6 + 5);
    vector<int> degree(1e6 + 5);
    for(int i = 0 ; i < n - 1; i++){
        g[f[a[i]]].insert(f[b[i]]);
        g[f[b[i]]].insert(f[a[i]]);
        degree[f[a[i]]]++;
        degree[f[b[i]]]++;
    }    
    int x = -1, y = -1;
    bool cant = 0;
    for(int i = 0; i < 1e6 + 5 ; i++){
        if(degree[i] & 1){
            if(x == -1){
                x = i;
            }
            else if(y == -1){
                y = i;
            }
            else{
                cant = true;
            }
        }
    }
    if(cant ){
        cout << -1 << endl;
        return 0;
    }
    
    stack<int> st;
    vector<int> path;
    st.push((x != -1 ? x : 0));
    while(!st.empty()){
        int tp = st.top();
        if(g[tp].size() == 0){
            st.pop();
            path.push_back(tp);
        }
        else{
            int v = *g[tp].begin();
            g[tp].erase(g[tp].find(v));
            g[v].erase(g[v].find(tp));
            st.push(v);
            degree[tp]--;
            degree[v]--;
        }
    }

    for(int i = 0; i < 1e6 + 5; i++){
        if(g[i].size()){
            cout << -1 << endl;
            return 0;
        }
    }
    for(int i = 0; i < path.size(); i++){
        cout << recover[path[i]] << " ";
    }
    cout << endl;
    return 0;
}