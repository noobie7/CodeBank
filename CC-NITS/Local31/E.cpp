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
    int n; cin >> n;
    string s; cin >> s;
    vector<int> d1(n);
    vector<int> d2(n);
    vector<ll> st(n), en(n);
    for (int i = 0, l = 0, r = -1; i < n; i++) {
        int k = (i > r) ? 1 : min(d1[l + r - i], r - i + 1);
        while (0 <= i - k && i + k < n && s[i - k] == s[i + k]) {
            k++;
        }
        d1[i] = k--;
        if (i + k > r) {
            l = i - k;
            r = i + k;
        }
    }
    
    for (int i = 0, l = 0, r = -1; i < n; i++) {
        int k = (i > r) ? 0 : min(d2[l + r - i + 1], r - i + 1);
        while (0 <= i - k - 1 && i + k < n && s[i - k - 1] == s[i + k]) {
            k++;
        }
        d2[i] = k--;
        if (i + k > r) {
            l = i - k - 1;
            r = i + k ;
        }
    }
    for(int i = 0; i < n; i++){
        int l = i - d1[i] + 1;
        int r = i + d1[i] - 1;
        st[l] += 1;
        if(i + 1 < n) {
            st[i + 1] -= 1;
        } 
        if(i - 1 >= 0){
            en[i-1] -= 1;
        }
        en[r] += 1;

        if(!d2[i]) continue;
        l = i - d2[i];
        r = i + d2[i]-1; 

        st[l] += 1;
        if(i  < n){
            st[i] -= 1;
        }
        if(i - 1 >= 0){
            en[i-1] -= 1;
        }
        en[r] += 1;
    }

    for(int i = 0; i + 1 < n; i++){
        st[i+1] += st[i];
    }   
    for(int i = n-2; i >= 0; i--){
        en[i] += en[i+1];
    }

    ll ans = 0;
    for(int i = 0; i < n-1; i++){
        ans += en[i] * st[i+1];
    }
    cout << ans << endl;
    return 0;
}