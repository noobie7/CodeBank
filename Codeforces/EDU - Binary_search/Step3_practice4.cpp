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
    int n, m, d; cin >> n >> m >> d;
    vector<vector<pair<int,int>>> g(n);
    for(int i = 0; i < m; i++){
        int a, b, c; 
        cin >> a >> b >> c;
        a--;
        b--;
        g[min(a,b)].push_back({max(a, b), c});
    }
    vector<int> dis(n), par(n), ans;
    auto ok = [&](long long x){
        queue<int> q;
        dis.assign(n, inf);
        par.assign(n, -1);
        q.push(0);
        dis[0] = 0;
        while(!q.empty()){
            int top = q.front();
            q.pop();
            int tillnow = dis[top];
            if(tillnow >= d) continue;
            for(auto pp : g[top]){
                int v = pp.ff;
                int w = pp.ss;
                if(dis[v] == inf && w <= x){
                    dis[v] = tillnow + 1;
                    par[v] = top;
                    q.push(v);
                }
            }
        }
        if(dis[n - 1] < inf){
            ans.clear();
            int curr = n - 1;
            while(par[curr] != -1){
                ans.push_back(curr + 1);
                curr = par[curr];
            }
            ans.push_back(1);
            return true;
        }    
        return false;
        
    };
    


    auto bs = [&](long long lo, long long hi){
        while(hi-lo > 1){
            long long mid = lo + (hi - lo)/2.0;
            if(ok(mid))
//                lo = mid;
                hi = mid;
            else 
//                hi = mid;
                lo = mid;
        }
        return hi;
    };
    bs(-1, 1e9 + 5);
    if(ans.size() == 0){
        cout << -1 << endl;
        return 0;
    }
    cout << ans.size() - 1 << endl;
    reverse(all(ans));
    pra(ans);

    return 0;
}