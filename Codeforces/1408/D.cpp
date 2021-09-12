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
    int m; cin>>m;
    vector<int> a(n), b(n), c(m), d(m);
    pair<int,int> left = {1e9,1e9};
    pair<int,int> bott = {1e9,1e9};
    for(int i = 0 ; i < n; i++){
        cin>> a[i] >> b[i];
    }
    for(int i = 0 ; i < m; i++){
        cin>> c[i] >> d[i];
    }
    left.ff = *min_element(all(a));
    for(int i = 0 ; i < n; i++){
        if(a[i]==left.ff){
            left.ss  = min(left.ss, b[i]);
        }
    } 
    bott.ss = *min_element(all(b));
    for(int i = 0 ; i < n; i++){
        if(b[i]==bott.ss){
            bott.ff = min(bott.ff, a[i]);
        }
    }
    vector<int> height(1e6+5, 0);
    for(int i = 0 ; i < m; i++){
        height[c[i]] = max(height[c[i]], d[i]);
    }
    for(int i = 1e6 + 4; i >= 0; i--){
        height[i] = max(height[i],height[i+1]);
    }
    int ans = INT_MAX;
    for(int i = 0 ; i < 1e6 + 4; i++){
        if(height[i+1]<height[i])
            ans = min(ans, max(abs(i-left.ff  ) + abs(height[i]-left.ss ) + 1, abs(i-bott.ff) + abs(height[i]-bott.ss) + 1 ));
                 
    }
    
    cout<<ans<<endl;
    return 0;
}