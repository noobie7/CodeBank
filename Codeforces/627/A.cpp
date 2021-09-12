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
    ll s, x; 
    cin >> s >> x;
    //sum = 9 => 1001;
    //xor = 5 => 0101;
    //need = 9 - 5 = 4;
    //0100 - > 0010 and 0010 (process of decomposition) 
    // a = 0111
    // b = 0010
    // lemma 1 -    the bit ON in x can be a part of  a or b; 
    //              this implies that if "bits" is the number of bits in x
    //              then we can have (1 << x) combinations of (a,b) giving xor equal to x
    // handling the difference
    // if we can't decompose the difference without disturbing the xor value then the answer is zero
    // 
    // lemma 2 - if difference is non zero then we can have (a' or b' == 0)
    // the pos where the bit is ON for the difference the bit 1 less than that should be off in x;
    if(x > s){
        cout << 0 << endl;
        return 0;
    }

    bool integral_only = !(s - x);
    if((s - x) & 1){
        cout << 0 << endl;
        return 0;
    }

    ll bitcnt = __builtin_popcountll(x);

    ll cnt = (1LL << (bitcnt ));

    if(integral_only){
        cnt -= 2;
    }
    
    ll diff = s - x;
    for(int bit = 1; bit <= 63; bit++){
        if(diff & ( 1LL << bit)){
            if((x & (1LL << (bit - 1)))){
                cout << 0 << endl;
                return 0;
            }
        }
    }
    cout << cnt << endl;
    return 0;
}