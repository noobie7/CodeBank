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
        int n, m; 
        cin >> n >> m;
        vector<int> a(n), b(m);
        get(a);
        get(b);
        vector<int> al, ar, bl, br;
        for(int i = 0; i < n; i++){
            if(a[i] < 0) al.push_back(-a[i]);
            else         ar.push_back(a[i]);
        }
        for(int i = 0; i < m; i++){
            if(b[i] < 0) bl.push_back(-b[i]);
            else         br.push_back(b[i]);
        }
        reverse(all(al));
        reverse(all(bl));
        auto calc = [&](vector<int> &a, vector<int> &b){
            int n = a.size();
            int m = b.size();
            vector<int> suff(n + 1);
            int r = m - 1;
            for(int i = n - 1; i >= 0; i--){
                suff[i] = suff[i + 1];
                while(r >= 0 && b[r] > a[i]) r--;
                if(r >= 0 && b[r] == a[i]) suff[i]++;
            }
            int ans = 0;
            r = 0;
            int j = 0;
            for(int i = 0; i < m; i++){
                while(j < n && a[j] <= b[i] + j) j++;
                while(r < m && b[r] -  b[i] < j) r++;
                ans = max(ans, r - i + suff[j]);
            }
            return ans;
        };
        cout << calc(al, bl) + calc(ar, br) << endl;
    }
    return 0;
}