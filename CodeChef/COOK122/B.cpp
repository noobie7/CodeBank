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
        int n,k; cin>>n>>k;
        string s; cin>>s;
        vector<pair<int,int>> lencnt;
        int i = 0;
        while(i < n && s[i]=='0') i++;
        if(i){
            lencnt.push_back({i,1});
        }
        int j = n-1;
        while( j >= i && s[j]=='0') j--;
        if(j!=i){
            lencnt.push_back({n-1-j,1});
        }
        int cnt = 0;
        for(int k = i; k <j ; k++){
            if(s[k]=='0'){cnt++; continue;}
            if(cnt){
                lencnt.push_back({cnt,2});
                cnt = 0;
            }
        }
        if(cnt){
            lencnt.push_back({cnt,2});
        }
        sort(lencnt.rbegin(), lencnt.rend());

        int ans = 0;
        for(int i = 0 ; i < lencnt.size() ; i++){
            if(lencnt[i].ss <=k){
                k-=lencnt[i].ss;
            }
            else{
                ans += lencnt[i].ff;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}