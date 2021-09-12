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
    int n; cin>>n;
    int k; cin>>k;
    vector<ll> a(n);
    vector<ll> p(n);
    get(a);
    for(int i = 0 ; i < n; i++){
        p[i] = a[i];
        if(i)
            p[i] += p[i-1];
    }
    auto ok = [&](long long x){
        int i = 0;
        ll last = 0;
        int cnt = 0;
        while(i<n && cnt < k-1){
            if(i && p[i]-last>x){
                last = p[i-1];
                cnt++;
                i--;
            }
            else if(!i && p[i]>x){
                return false;
            }
            i++;
        }
       
       // cout<<" cnt "<<cnt<<endl;
        return ( p[n-1] - last <=x);
    };
    
    auto bs = [&](long long lo, long long hi){
        while(hi-lo > 1){
            long long mid = (lo + hi)/2.0;
            if(ok(mid))
           //     lo = mid;
                hi = mid;
            else 
         //       hi = mid;
                lo = mid;
        }
       // return lo;
        return hi;
    };
    cout<<bs(-1, p[n-1]+1)<<endl;
    return 0;
}