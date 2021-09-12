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
    test(){
        int n; cin >> n;
        vector<int> a(n);
        get(a);
        int m; cin >> m;
        vector<array<ll,2>> b(m);
        for(int i = 0; i < m; i++){
            for(int j = 1; j >= 0; j--){
                cin >> b[i][j];
            }
        }
        sort(all(b));
        vector<int> best(n+1);
        for(int i = n; i ; i--){
            while(b.size() && b.back()[0] > i) b.pop_back();
            if(b.empty()) break;
            if(b.back()[0] < i) continue;
            best[i] = b.back()[1];
        }

        int prev = -1;
        for(int i = n; i ; i--){
            best[i] = max(prev, best[i]);
            prev = best[i]; 
        }
        int pos = 0;
        int ans = 0;
        while(pos < n){
            ans++;
            int npos = pos;
            int mx = 0;
            while(npos < n){
                mx = max(mx, a[npos]);
                if(mx > best[npos - pos + 1]) break;
                ++npos;
            }
            if(pos == npos){
                cout << -1 << endl;
                goto here;
            }
            pos = npos;
        }
        cout << ans << endl;
        continue;
        here :;
    }
    return 0;
}