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
    int n,k; cin >> n >> k;
    string s; cin >> s;
    vector<int> present(26);
    char mini = *min_element(all(s));
    if(k > n){
        for(int i = n; i < k; i++) 
            s += mini;
        cout << s << endl;
        return 0;
    }
    
    for(char c : s)
        present[c - 'a'] = 1;

    while(s.size() > k) s.pop_back();

    for(int i = k-1; i >= 0; i--){
        for(int nc = s[i] - 'a' + 1; nc < 26; nc++){
            if(present[nc]){
                s[i] = (char)('a' + nc);
                cout << s << endl; 
                return 0;
            }
        }
        s[i] = mini;
    }
    return 0;
}