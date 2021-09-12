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
        vector<ll> a(n);
        get(a);
        for(int i = 0; i < n; i++){
            if(i + 1 < n &&( a[i + 1] % a[i] == 0 || a[i] % a[i + 1] == 0 || a[i] == 1)) continue;            
            if(i + 1 < n)
                a[i] -= (a[i] & 1);
            if(i){
                if(a[i] % a[i-1] == 0 || (i + 1 < n && a[i + 1] % a[i] == 0)) continue;
                int curr;
                if(a[i] < a[i-1]){
                    curr = a[i - 1];
                    int diff = a[i - 1];
                    for(int k = 1; k * k <= a[i - 1]; k++){
                        if(a[i - 1] % k == 0){
                            if(diff > abs(k - a[i])){
                                diff = abs(k - a[i]);
                                curr = k;
                            }
                            if(diff > abs(k / a[i-1] - a[i])){
                                diff = abs(k / a[i-1] - a[i]);
                                curr = k;
                            }
                        }
                    }
                }
                else{
                    curr = a[i];
                    int diff = a[i];
                    for(int k = 1; k * k <= a[i]; k++){
                        if(a[i] % k == 0){
                            if(diff > abs(k - a[i])){
                                diff = abs(k - a[i]);
                                curr = k;
                            }
                            if(diff > abs(k / a[i] - a[i])){
                                diff = abs(k / a[i] - a[i]);
                                curr = k;
                            }
                        }
                    }
                }
                a[i] = curr;
            }
        }
        pra(a);
    }
    return 0;
}