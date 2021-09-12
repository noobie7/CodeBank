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
    string s, t; cin >> s >> t;
    vector<int> cnt(26), req(26);
    for(char c : t){
        req[c - 'a']++;
    }
    int avail = 0;
    vector<int> location;
    int j = 0;
    for(char c : s){
        if(c == '?') {
            avail++;
            location.push_back(j);
        }
        else         cnt[c - 'a']++;
        j++;
    }

    for(int i = (int)s.size()/t.size(); i >= 0; i--){
        int spare = avail;
        for(int c = 0; c < 26; c++){
            int tot = max(req[c] * i - cnt[c],0);
            if(spare < tot){
                goto here;
            }
            spare -= tot;
        }
        spare = avail;
        for(int c = 0; c < 26; c++){
            int tot = max(req[c] * i - cnt[c],0);
            spare -= tot;
            while(tot){
                s[location.back()] = (char)('a' + c);
                location.pop_back();
                tot--;
            }
        }
        for(auto &c : s){
            if(c == '?')
                c = 'x';
        }
        cout << s << endl;
        return 0;
        here :;
    }
    return 0;
}