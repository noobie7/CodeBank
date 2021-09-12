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
        vector<int> a(n);
        ll sum = 0;
        for(int &i : a){
            cin>>i;
            sum += i;
        }
        if(sum%n){
            cout<<-1<<endl;
            continue;
        }
        
        vector<array<int,3>> ans;

        auto execute = [&](int i, int j, int x){
            a[i] -= x*(i+1);
            a[j] += x*(i+1);
            ans.push_back({i+1,j+1, x});
        };

        for(int i = 1; i < n; i++){
            if(a[i]%(i+1)){
                execute(0, i, i+1 - (a[i]%(i+1)));
            }
            execute(i, 0 , a[i]/(i+1));
        }
        for(int i = 1; i < n; i++){
            execute(0, i, sum/n);
        }
        cout<<ans.size()<<endl;
        for(auto v : ans){
            for(int i : v){
                cout<<i<<" ";
            }
            cout<<endl;
        }
    }
    return 0;
}