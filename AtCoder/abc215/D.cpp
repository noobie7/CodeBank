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
    int n, m; cin >> n >> m;
    vector<int> a(n);
    get(a);
    vector<int> is(m + 5, 1);
    is[0] = is[1] = 0;
    for(int i = 2; i * i <= m; i++){
        for(int j = i * 2; j <= m; j += i){
            is[j] = 0;
        }
    }
    for(int num : a){
        int x = num;
        for(int i = 2; i * i <= x; i++){
            if(x % i == 0){
                if(i <= m)
                    is[i] = 0;
                while(x % i == 0){
                    x /= i;
                }
            }
        }
        if(x <= m)
            is[x] = 0;
        
    }
    vector<int> ans;
    for(int num = 1; num <= m; num++){
        int x = num;
        for(int i = 2; i * i <= x; i++){
            if(x % i == 0){
                if(i <= m && is[i] == 0)
                    goto here;
                while(x % i == 0){
                    x /= i;
                }
            }
        }
        if(x >= 2 && x <= m){
            if(is[x] == 0) 
                goto here;
        }
        ans.push_back(num);
        here:;

    }
    cout << ans.size() << endl;
    for(int i : ans){
        cout << i << endl;
    }
    return 0;
}
