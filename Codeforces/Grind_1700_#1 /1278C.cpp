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
        vector<int> a(2*n);
        for(int &i : a) cin>>i;
        int c = 0, d = 0;
        map<int,int> diff;
        diff[0] = 0;
        for(int i = n; i < 2*n; i++){
            (a[i]==1)?c++: d++;
            
            if(!diff.count(c-d))
                diff[c-d] = i-(n-1);
        }
        int ans = 2*n;
        int k = count(all(a),1) - count(all(a),2);
        c = 0;
        d = 0;
        for(int i = n-1 ; i >=0 ; i--){
            (a[i]==1)?c++:d++;
            if(diff.count(k-(c-d))){
                ans = min(ans, n-i + diff[k-(c-d)]);
            }
        }
        if(diff.count(k))
            ans = min(ans, diff[k]);
        cout<<ans<<endl;
    }
    return 0;
}
