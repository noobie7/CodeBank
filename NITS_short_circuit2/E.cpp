/*
"Won't stop until I'm phenomenal."
- Phenomenal, Eminem
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
const int nag = 1e5 + 5;

vector<ll> alldepths;
vector<vector<int>> g(nag);

void dfs(int u, int p , int depth, int id){
    if(g[u].size()==1 && p!=-1){
        alldepths[id] = max(alldepths[id], (long long)depth);
    }
    
    for(int v : g[u]){
        if(v==p) continue;

        dfs(v,u,depth+1, id);
        if(p==0) id++;
    }
}

int main(){
    Shazam;
    test(){
        int n; cin>>n;
        for(int i = 0; i < n+1; i++) g[i].clear();
        
        for(int i = 1; i < n ; i++){
            int a,b; cin>>a>>b;
            g[a].push_back(b);
            g[b].push_back(a);
        }

        auto getans = [&](vector<ll> & a){
            sort(all(a));
            int n = a.size();
            ll ans = 0;

            if(n<2) return 0;

            if(n==2){
                return (int)a.back()*(int)a.front();
            }
            if(n==3){
                ll tot = a[n-1] + a[n-2] + a[n-3];
                
                for(int i = n-3; i < n; i++){
                    ans = max(ans, a[i]*(tot-a[i]));
                }
            }
            else{
                
            }
            return (int)ans;
        };

        for(int i = 1 ; i < n + 1 ; i++){
            if(g[i].size()==1){cout<<0<<" "; continue;}
            alldepths.assign(g[i].size(),0);
            dfs(i, 0 , 0, 0);
            cout<<getans(alldepths)<<" ";
        }
        cout<<endl;

    }
    return 0;
}