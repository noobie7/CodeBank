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
    int n; cin >> n;
    int m; cin >> m;
    map<int, set<int>> g, f;
    for(int i = 0; i < m; i++){
        int a, b; cin >> a >> b;
        a--;
        b--;
        g[b].insert(a);
        g[a].insert(b);
    }
    for(int i = 0; i < m; i++){
        int a, b; cin >> a >> b;
        a--;
        b--;
        f[a].insert(b);
        f[b].insert(a);
    }
    vector<int> order(n);
    iota(all(order), 0);
    do{
        bool ok = 1;
        for(auto pp : g){
            for(int i : pp.ss){
                ok &= f[order[pp.ff]].find(order[i]) != f[order[pp.ff]].end();
            }
        }
        if(ok){
            cout << "Yes" << endl;
            return 0;
        }
    }while(next_permutation(all(order)));
    cout << "No" << endl; 
    return 0;
}