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
    vector<int> a(n);
    for(int &i : a){
        cin>>i;
        --i;
    }
    map<int,int> f;
    vector<pair<int,int>> ops;
    for(int i = 0; i < n; i++) f[a[i]] = i;
    for(int i = 0; i < n; i++){
        if(f[i]==i) continue;
        if(f[i] < n/2){
            ops.push_back({f[i]+1,n});
            swap(a[f[i]], a[n-1]);
            f[a[f[i]]] = f[i];
            f[a[n-1]] = n-1;
            if(i < n/2){
                ops.push_back({i+1,n});
                swap(a[n-1],a[i]);
                f[a[i]] = i;
                f[a[n-1]] = n-1;
            }
            else{
                ops.push_back({i+1,1});
                swap(a[0],a[i]);
                f[a[i]] = i;
                f[a[0]] = 0;
            }
        }
        else{
            ops.push_back({f[i]+1,1});
            swap(a[f[i]], a[0]);
            f[a[f[i]]] = f[i];
            f[a[i]] = 0;
            if(i < n/2){
                ops.push_back({i+1,n});
                swap(a[n-1],a[i]);
                f[a[f[i]]] = f[i];
                f[a[n-1]] = n-1;
            }
            else{
                ops.push_back({i+1,1});
                swap(a[0],a[i]);
                f[a[f[i]]] = f[i];
                f[a[0]] = 0;
            }
        }
    }
    pra(a);
    cout<<ops.size()<<endl;
    for(auto pp : ops)
        cout<<pp.ff<<" "<<pp.ss<<endl;
    return 0;
}
