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
        int x; cin >> x;
        vector<ll> a(n); get(a);
        vector<deque<int>> bit_present(32);
        for(int i = 0; i < n - 1; i++){
            for(int bit = 0; bit < 32 ; bit++){
                if(a[i] &  (1LL << bit)){
                    bit_present[bit].push_back(i);
                }
            }
        }
        bool last = false;
        for(int i = 0 ; i < n - 1 && x; i++){
            for(int bit = 31; bit >= 0 && x; bit--){
                if(a[i] & (1LL << bit)){
                    bit_present[bit].pop_front();
                    int j = n - 1;
                    if(bit_present[bit].size()){
                        j = bit_present[bit].front();
                        bit_present[bit].pop_front();
                    }
                    a[i] ^= (1LL << bit);
                    a[j] ^= (1LL << bit);
                    x--;
                }
            }
        }
        x %= 2;
        if(x && n == 2){
            a[n-1] ^= 1;
            a[n-2] ^= 1;
        }
        pra(a);
    }
    return 0;
}