/*
"Won't stop untill I'm Phenomenal"
- Phenomenal, EMINEM
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
        int ans = 0;
        vector<int> a(n);
        get(a);
        vector<int> cnt(104,-1);
        for(int i : a){
            if(cnt[i]==-1) cnt[i] = 0;
            cnt[i]++;
        }
        
        bool got1 = false;
        int last = -1;
        bool got2 = false;
        for(int i = 0 ; i < 104; i++){
            if(cnt[i]==-1){
                if(!got1){
                    ans+=i;
                    got1=true;
                }
            }
            if(cnt[i]&1){
                if(!got1){
                    ans+=i;
                    got1=true;
                    continue;
                   
                }
                if(i!=last+1){
                    got2 = true;
                    ans+=last+1;
                    break;
                }
                else{
                    last = i;
                }
            }
        }
        if(!got2&&last!=103)
            ans+=last+1;
        cout<<ans<<endl;
    }
    return 0;
}