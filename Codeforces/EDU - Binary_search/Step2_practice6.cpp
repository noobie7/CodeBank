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

struct custom {
    static uint64_t splitmix64(uint64_t x)
    {
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }
    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};

int main(){
    Shazam;
    string s,t; 
    cin>>s>>t;
    if(s==t){
        cout<<0<<endl;
        return 0;
    }
    int n = (int)s.size();
    int m = (int)t.size();
    vector<int> a(n);
    get(a);
    vector<int> forbidden(n);

    auto ok = [&](long long x){
        forbidden.assign(n,0);
        for(int i = 0 ; i < x; i++ ) forbidden[a[i]-1] = 1;
        int j = 0;
        int i = 0;
        while(i < n && forbidden[i]) i++;
        while(i<n&&j<m){
            if(s[i]==t[j]){
                i++;
                j++;
            }
            else{
                i++;   
            }
            while(i<n && forbidden[i]) i++;
        }
        if(j==m) return true;
            
        
        return false;
    };
    
    auto bs = [&](long long lo, long long hi){
        while(hi-lo > 1){
            long long mid = (lo + hi)/2.0;
            if(ok(mid))
                lo = mid;
                //hi = mid;
            else 
                hi = mid;
                //lo = mid;
        }
        return lo;
        //return hi;
    };      
    cout<<bs(0, n+1)<<endl;
    
    return 0;
}