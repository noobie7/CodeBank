/*
"Won't stop until I'm phenomenal."
- Phenomenal, Eminem
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



int main(){
    Shazam;
    test(){
        int n; cin>>n;

        vector<int> a(n);
        
        get(a);
        
        int m; cin>>m;
        
        vector<int> p(m),s(m);
        
        for(int i = 0; i < m; i++){
            cin>>p[i]>>s[i];
        }
        
        vector<int> best(n+2);
        
        for(int i = 0; i < m; i++){
            best[s[i]] = max(best[s[i]], p[i]);
        }
        
        for(int i = n; i>=0; i--)
            best[i] = max(best[i],best[i+1]);
        
        int ans = 0;
        int pos = 0;
        bool can = true;
        
        while(pos < n ){
            ans++;
            int npos = pos;
            int mx = 0;
            while(npos<n){
                mx = max(mx,a[npos]);
                if(mx > best[npos-pos+1]){ break;}
                npos++;
            }
            if(npos == pos) {can = false; break;}
            pos = npos;
        }
        
        if(!can){cout<<-1<<endl; continue;}
        
        cout<<ans<<endl;
    }
    return 0;
}