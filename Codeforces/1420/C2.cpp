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
        int q; cin>>q;
        vector<int> a(n);
        get(a);
        ll ans = 0;

        auto calc = [&](int i){
            if(i<0||i>n-1)
                return 0;
            return max(0,a[i] - ((i<n-1)?a[i+1]:0));
        };

        for(int i = 0 ; i < n; i++){
            ans += calc(i);
        }
        cout<<ans<<endl;
        for(int i = 0; i < q ; i++){
            int l,r; cin>>l>>r;
            l--; r--;
            if(l<r){
                ans-=calc(l);
                ans-=calc(l-1);
                if(r>l+1){
                    ans-=calc(r-1);
                }
                ans-=calc(r);
                
                swap(a[l],a[r]);

                ans+=calc(l);
                ans+=calc(l-1);
                if(r>l+1){
                    ans+=calc(r-1);
                }
                ans+=calc(r);
            }
            cout<<ans<<endl;
        }

    }

    return 0;
}