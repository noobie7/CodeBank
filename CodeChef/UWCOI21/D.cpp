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

struct deli{
    int a, b, c, d;
};

int main(){
    Shazam;
    int n, m, k;
    cin >> n >> m >> k;
    vector<deli> a(k);
    vector<int> in[max(n, m) + 2], out[max(n, m) + 2], rin[max(n, m) + 2] , rout[max(n, m) + 2];
    ll cost = 0;
    for(int i = 0; i < k; i++){
        cin >> a[i].a >> a[i].b >> a[i].c >> a[i].d;
        if(a[i].b > a[i].d){
            swap(a[i].b, a[i].d);
            swap(a[i].a, a[i].c);
        }
        cost += 2 *( abs(a[i].a - a[i].c) + abs(a[i].b - a[i].d) );
        int det = abs(a[i].a - a[i].c) / 4;
        int l = max(0, a[i].b - det);
        int r = min(m + 1, a[i].d + det);
        
        in[l].push_back(i);
        out[r].push_back(i);
        rin[a[i].b].push_back(i);
        rout[a[i].d].push_back(i);
    }
    int incoming = 0;
    int outgoing = 0;
    int saving = 0;
    for(auto j : in[0]){
        incoming++;
        saving += abs(a[j].a - a[j].c) - 4 * (a[j].b);
    }
    int ans = 0;
    for(int i = 1; i <= m; i++){
        saving += 4 * incoming;
        saving -= 4 * outgoing;

        for(int j : in[i]){
            incoming++;
            saving += abs(a[j].a - a[j].c) - 4 * abs(i - a[j].b);
        }

        ans = max(ans, saving);

        outgoing += rout[i].size();
        incoming -= rin[i].size();

        for(int j : out[i]){
            outgoing--;
            saving -= abs(a[j].a - a[j].c) - 4 * abs(i - a[j].d);
        }

    }
    cout << cost - ans << endl;
    return 0;
}