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
    int c = 1;
    test(){
        int d, n, k; 
        cin >> d >> n >> k;
        vector<vector<ll> > a(n, vector<ll>(3));
        for(int i = 0; i < n; i++){
            cin >> a[i][2] >> a[i][0] >> a[i][1];
        }
        sort(all(a));
        ll ans = -INF;
        ll curr = 0;
        ll minele;
        multiset<ll> bag;
        auto add = [&](ll x){
            bag.insert(x);
        };
        auto pop = [&](){
            curr -= *bag.begin();
            bag.erase(bag.begin());
        };
        int last = -1;
        for(int i = 0; i < n; ){
            int d_curr = a[i][0];
            int j = i;
            while(j < n && a[j][0] == d_curr){
                add(a[i][2]);
                curr += a[i][2];
                if(bag.size() > k){
                    pop();
                }
                j++;
            }
            for(int g = last + 1; g < j; g++){
                if(a[g][1] <= d_curr ){
                    if(bag.find(a[g][2]) != bag.end()){
                        bag.erase(bag.find(a[g][2]));
                        curr -= a[g][2];
                    }
                    last = g;
                }
            }
            ans = max(ans, curr);
            i = j;
        }
        cout<<"Case #"<<c<<": "<< ans << endl;;
        c++;
    }
    return 0;
}