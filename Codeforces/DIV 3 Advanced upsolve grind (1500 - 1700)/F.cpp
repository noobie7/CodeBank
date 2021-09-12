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

struct Segtree{
    int size;
    vector<int> count;
    char c;
    void init(int n, char rn){
        size = 1;
        c = rn;
        while(size < n) size *= 2;
        count.assign(2 * size,0);
    }
    void build(string &s){
        build(s, 0, 0, size);
    }
    void build(string &s, int x, int l, int r){
        if(r - l == 1){
            if(l < s.size())
               count[x] = (s[l] == c);      
            return;
        }
        int m = (l + r) / 2;
        build(s, x * 2 + 1, l , m);
        build(s, x * 2 + 2, m , r);
        count[x] = count[x * 2 + 1] + count[2 * x + 2];
    }
    void set(int pos, int val){
        set(pos, val, 0, 0, size);
    }
    void set(int pos, int val, int x, int l, int r){
        if(r - l == 1){
            count[x] = val;
            return;
        }
        int m = (l + r) / 2;
        if(pos < m){
            set(pos, val, x * 2 + 1, l, m);
        }
        else{
            set(pos, val, x * 2 + 2, m, r);
        }
        count[x] = count[x * 2 + 1] + count[x * 2 + 2];
    }
    int query(int l, int r){
        return query(0, 0, size, l, r);
    }
    int query(int x, int lx, int rx, int l, int r){
        if(rx <= l || r <= lx) return 0;
        if(l <= lx && rx <= r) return count[x];
        int m = (lx + rx) / 2;
        int c1 = query(x * 2 + 1, lx, m, l, r);
        int c2 = query(x * 2 + 2, m, rx, l, r);
        return c1 + c2;
    }
};

int main(){
    Shazam;
    string s; cin >> s;
    int q; cin >> q;
    int n = s.size();
    // range query - > (l,r) searches for (l, r - 1)
    vector<Segtree> uni(26);
    for(int i = 0; i < 26; i++){
        uni[i].init(n, (char)('a' + i));
    }
    for(int i = 0; i < 26; i++){
        uni[i].build(s);
    }
    for(int i = 0; i < q; i++){
        int t; cin >> t;
        if(t == 1){
            int pos; cin >> pos;
            pos--;
            char c; cin >> c;
            char old = s[pos];
            uni[old - 'a'].set(pos, 0);
            s[pos] = c;
            uni[c - 'a'].set(pos, 1);
        }
        else{
            int l, r; cin >> l >> r;
            l--;
            int ans = 0;
            for(int i = 0; i < 26; i++){
                ans += (uni[i].query(l,r) > 0);
            }
            cout << ans << endl;
        }
    }
    
    return 0;
}