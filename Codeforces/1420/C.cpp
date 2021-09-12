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
        int n,q; cin>>n>>q;
        vector<ll> a(n);
        get(a);
       
        /*   My solution
            ll ans = 0;
            int cnt = 0;
            if(n==1){
                cout<<a.back()<<endl;
                continue;
            }
            else{
                if(n==2){
                    cout<<*max_element(all(a))<<endl;
                    continue;
                }
                a.push_back(-2e9);
                if(a[0]>a[1]){
                    ans += a[0];
                    cnt++;
                }
                int last = 0;
                for(int i = 1; i < n; i++){
                    if((cnt&1)&& (a[i]<a[i-1]&& a[i] < a[i+1])){ans-=a[i]; cnt++;}
                    if((cnt&1^1) && (a[i]>a[i-1] && a[i]>a[i+1])){ans += a[i]; cnt++;}
                }
                cout<<ans<<endl;

            }
        */
        /*Learning from tourist*/
        vector<ll> mx(n+1), mn(n+1);
        for(int i = n-1; i >= 0; i--){
            mx[i] = max(mx[i+1], a[i]-mn[i+1]);
            mn[i] = min(mn[i+1], a[i]-mx[i+1]);
        }
        cout<<mx.front()<<endl;
    }
    return 0;
}