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
    int n, m, q;
    cin >> n >> m >> q;
    vector<pair<int,int>> a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i].ff >> a[i].ss;
    }
    vector<int> x(m);
    get(x);

    auto solve = [&](int l, int r){
        vector<int> options;
        ll ans = 0;
        for(int i = 0; i < m; i++){
            if(l <= i && i <= r) continue;
            options.push_back(x[i]);
        }
        if(options.size() == 0) return 0LL;
        sort(options.begin(), options.end());
        vector<int> taken(n);
        for(int upper_limit : options){
            int best = -1;
            int highest_in_the_room = 0;
            for(int i = 0; i < n; i++){
                if(!taken[i]){
                    if(a[i].ff <= upper_limit){
                        if(highest_in_the_room <= a[i].ss){
                            highest_in_the_room = a[i].ss;
                            best = i;
                        }
                    }
                }
            }
            if(best >= 0){
                ans += highest_in_the_room;
                taken[best] = 1;
            }
        }
        return ans;
    };

    for(int i = 0; i < q; i++){
        int l, r; cin >> l >> r;
        l--, r--;
        cout << solve(l, r) << endl;
    }


    return 0;
} 