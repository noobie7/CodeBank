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
        vector<int> req(4);
        get(req);
        for(int mask = 0; mask <= (1 << 4); mask++){
            vector<int> curr = req;
            for(int bit = 0; bit < 4; bit++){
                if(mask & (1 << bit)){
                    if(curr[bit] && curr[(bit + 1) % 4]){
                        curr[bit]--;
                        curr[(bit + 1) % 4]--;
                    }
                }
            }
            if(*max_element(all(curr)) <= n - 2 && *min_element(all(curr)) >= 0){
                cout << "YES" << endl;
                goto here;
            }
        }
        cout << "NO" << endl;
        continue;
        here :;
    } 
    return 0;
}