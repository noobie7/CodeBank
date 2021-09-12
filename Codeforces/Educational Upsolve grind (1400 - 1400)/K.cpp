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
    int a,b,c; cin >> a >> b >> c;
    int ca = a, cb = b, cc = c;
    priority_queue<int> usb, ps, both;
    int n; cin >> n;
    for(int i = 0;i < n; i++){
        int k; cin >> k;
        k *= -1;
        string s; cin >> s;
        if(s == "USB"){
            usb.push(k);
            both.push(k);
        }
        else{
            ps.push(k);
            both.push(k);
        }
    }
    priority_queue<int> cusb = usb, cps = ps, cboth = both;
    int ans = 0;
    ll val = 0;
    while(c && (usb.size() || ps.size())){
        c--;
        if(!usb.size()){
            ans++;
            val += -ps.top();
            ps.pop();
            both.pop();
            continue;
        }
        if(!ps.size()){
            ans++;
            val += -usb.top();
            usb.pop();
            both.pop();
            continue;
        }
        if(-ps.top() < -usb.top()){
            ans++;
            val += -ps.top();
            ps.pop();
            both.pop();
        }
        else{
            ans++;
            val += -usb.top();
            usb.pop();
            both.pop();
        }
    }
    while(a && usb.size()){
        ans++;
        val += -usb.top();
        usb.pop();
        a--;
    }
    while(b && ps.size()){
        ans++;
        val += -ps.top();
        ps.pop();
        b--;
    }
    int altans = 0;
    ll altval = 0;
    a = ca;
    b = cb;
    c = cc;
    ps = cps;
    usb = cusb;
    both = cboth;
    while(a && usb.size()){
        altans++;
        altval += -usb.top();
        usb.pop();
        a--;
    }
    while(b && ps.size()){
        altans++;
        altval += -ps.top();
        ps.pop();
        b--;
    }
    while(c && (usb.size() || ps.size())){
        c--;
        if(!usb.size()){
            altans++;
            altval += -ps.top();
            ps.pop();
            both.pop();
            continue;
        }
        if(!ps.size()){
            altans++;
            altval += -usb.top();
            usb.pop();
            both.pop();
            continue;
        }
        if(-ps.top() < -usb.top()){
            altans++;
            altval += -ps.top();
            ps.pop();
            both.pop();
        }
        else{
            altans++;
            altval += -usb.top();
            usb.pop();
            both.pop();
        }
    }
    if(altans == ans){
        cout << ans << " " << min(altval, val) << endl;
    }
    else if(altans < ans){
        cout << ans << " " << val << endl;
    }
    else{
        cout << altans << " " << altval << endl;
    }
    return 0;
}