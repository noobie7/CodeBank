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

const int nag = 1e5 + 5;

vector<vector<int>> g(nag);
vector<int> par(nag);
vector<int> dia;
vector<int> branch;
int lowest = -1, root = 1, maxDep = -1;
int x = 0;

void dfs(int u, int p, int dep){
	if(dep > maxDep){
		lowest = u;
		maxDep = dep;
	}
	for(int v : g[u]){
		if(v == p) continue;
		par[v] = u;
		dfs(v, u, dep + 1);
	}
} 

void special(int u, int p, set<int> &dep){
	if(g[u].size() == 1){
        if(!binary_search(dia.begin(), dia.end(), u)){
    	    branch.push_back(dep.size());
    	    x -= (int)dep.size();
    	    dep.clear();
        }
	}

	for(int v : g[u]){
		if(v != p){
		   if(!binary_search(dia.begin(), dia.end(), v))
		    	dep.insert(v);
			special(v, u, dep);
			
		}
	}
	

}

int main(){
    Shazam;
    test(){
        int n; cin >> n;
        int k; cin >> k;
        root = 1;
        lowest = -1;
        maxDep = -1;
        for(int i = 0; i <= n + 4; i++){
            g[i].clear();
            par[i] = -1;
        }
        dia.clear();
        branch.clear();
        for(int i = 1; i <= n - 1; i++){
            int a, b; cin >> a >> b;
            g[a].push_back(b);
            g[b].push_back(a);
        }
        dfs(root, -1, 0);

		root = lowest;
        lowest = -1;

		for(int i = 0; i <= n; i++){
		    par[i] = -1;
		}
		
		maxDep = -1;
		
		dfs(root, -1, 0);
		
		while(lowest != -1){

			dia.push_back(lowest);
			lowest = par[lowest];
		}
		int ans = min(k, 2);
		int cnt = dia.size();
		x = n - cnt;
		if(dia.size() < k){

			sort(dia.begin(), dia.end());
			set<int> bag;
			special(root, -1, bag);
			sort(branch.begin(), branch.end());
			while(cnt < k && branch.size()){
				cnt += branch.back();
				branch.pop_back();
				ans++;
			}
			assert(x == 0);
		
		}

		cout << ans << endl;
    }
    return 0;
}