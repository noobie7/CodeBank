/*
"An anomaly, I'm Muhammad Ali
  Cause I know one day I'm gonna be the"
                - Greatest, Eminem
*/
#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
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
    vector<int> a(n);
    get(a);
    sort(all(a));


    vector<int> dummy;


    auto ok = [&](long long x){
        if(x*2 + 1 > n) return false;
        int pa = 0;
        int pb = n-x-1;
        dummy.clear();
        for(int i = 0; i < 2*x + 1 ; i++){
            if(i&1^1){
                dummy.push_back(a[pb++]);
            }
            else{
                dummy.push_back(a[pa++]);
            }
        }
        for(int i = 1; i < 2*x + 1; i+=2){
            if(dummy[i] >= dummy[i-1] || dummy[i] >= dummy[i+1])
                return false;
        }
        return true;
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
    
    int ans = bs(0, n/2+1);
    cout<<ans<<endl;
    ok(ans);
    for(int i = ans; i < n-ans-1; i++)
        dummy.push_back(a[i]);
    pra(dummy);
    

    return 0;
}