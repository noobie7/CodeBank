/*
"Won't stop untill I'm Phenomenal"
- Phenomenal, EMINEM
*/
#include<bits/stdc++.h>
using namespace std;
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
const ll INF = 2e18;
const int inf = 2e9;
const int mod1 = 1e9 + 7;

void rad_sort(vector<pair<pair<int,int>,int>>  &a){
    int n = a.size();
    vector<pair<pair<int,int>,int>> a_new(n);
    vector<int> cnt(n), pos(n);   
    for(auto ppp : a){
        cnt[ppp.ff.ss]++;
    }
    pos[0] = 0 ;
    for(int i = 1; i< n; i++){
        pos[i] = pos[i-1] + cnt[i-1];
    }
    for(int i = 0; i < n; i++){
        a_new[pos[a[i].ff.ss]++] = a[i];
    }
    a.swap(a_new);
    cnt.assign(n,0);
    pos.assign(n,0);
    for(auto ppp : a){
        cnt[ppp.ff.ff]++;
    }
    pos[0] = 0;
    for(int i = 1; i < n; i++){
        pos[i] = pos[i-1] + cnt[i-1];
    }
    for(int i = 0 ;i < n ; i++){
        a_new[pos[a[i].ff.ff]++] = a[i];
    }
    a.swap(a_new);
}
int main(){
    Shazam;
    string s; cin>>s;
    s+="$";
    int n = s.size();
    vector<pair<int,int>> a(n);
    vector<int> c(n), p(n);
    for(int i =0 ; i < n; i++){
        a[i] = {s[i],i};
    }
    sort(all(a));
    for(int i  = 0 ; i < n ; i++){
        p[i] = a[i].ss;
    }
    c[p[0]] = 0;
    for(int i =1; i < n; i++){
        if(a[i].ff==a[i-1].ff)
            c[p[i]] = c[p[i-1]];
        else
            c[p[i]] = c[p[i-1]] + 1;
    }
    int k = 0;
    vector<pair<pair<int,int>,int>> combine(n);
    while((1<<k) < n){
      
        for(int i = 0 ; i < n; i++){
            combine[i] = {{c[i], c[(i + (1<<k))%n]}, i};
        }
        rad_sort(combine);
        for(int i = 0 ; i < n; i++){
            p[i] = combine[i].ss;
        }
        c[p[0]] = 0;
        for(int i = 1; i < n; i++){
            if(combine[i].ff==combine[i-1].ff)
                c[p[i]] = c[p[i-1]];
            else{
                c[p[i]] = c[p[i-1]] + 1;
            }
        }
        k++;
    }
    int q; cin>>q;
    string look;
    while(q--){
        cin>>look;
        bool got_it = false;
        int q = look.size();
        int lo = 0; 
        int hi = n;

        while(hi-lo>1){
            int mid = (hi+lo)/2;
            if(s.substr(p[mid], min(n-p[mid],q)) <= look )
                lo = mid;
            else
                hi = mid;
        }
        if(s.substr(p[lo], min(n-p[lo],q))== look)
            got_it = true;
        cout<<((got_it)?"Yes":"No")<<endl;
    }
    return 0;
}