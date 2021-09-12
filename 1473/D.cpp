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
        int n, k; cin >> n >> k;
        string s; cin >> s;
        vector<int> val(n + 1);
        vector<int> mx(n + 1);
        vector<int> mn(n + 1);
        int curr = 0;
        mn[0] = mx[0] = 0;
        for(int i = 0; i < n; i++){
            curr += (s[i] == '+'? 1 : -1);
            val[i + 1] = curr;
            mx[i + 1] = max(mx[i ] , val[i + 1]);
            mn[i + 1] = min(mn[i ] , val[i + 1]);
        }
        vector<vector<int>> rmxq(n + 1, vector<int> (32,-inf)), rmnq(n + 1, vector<int> (32, inf));

        for(int i = 1; i <= n; i++){
            rmxq[i][0] = val[i];
            rmnq[i][0] = val[i];
        }
        for(int bit = 1; bit < 32 ; bit++){
            for(int i = 1; i <= n + 1 - (1 << bit) ; i++){
                rmxq[i][bit] = max(rmxq[i][bit - 1], rmxq[i + (1 << (bit - 1))][bit - 1]);
                rmnq[i][bit] = min(rmnq[i][bit - 1], rmnq[i + (1 << (bit - 1))][bit - 1]);
              
            }
            
        }
        for(int i = 0; i < k; i++){
            int l, r; cin >> l >> r;
            if(r == n){
                cout << mx[l-1] - mn[l-1] + 1 << endl;
                continue;
            }
            int bit = ( n - r  == 0 ? -1 : 31 - __builtin_clz(n - r ));
            
            int MX = max(mx[l-1], val[l-1]  + max(rmxq[min(n,r + 1)][bit], rmxq[n + 1 - (1 << bit)][bit]) - val[r ]);
            int MN = min(mn[l-1], val[l-1]  + min(rmnq[min(n,r + 1)][bit], rmnq[n + 1 - (1 << bit)][bit]) - val[r ]);
       //     cout << MX << " " << MN << endl;
            cout << MX - MN + 1<< endl;
        }

        
    }
    return 0;
}