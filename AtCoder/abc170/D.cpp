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
    int n; cin>>n;
    
    vector<int> a;

    for(int i =0 ; i < n; i++){
        int k; cin>>k;
        a.push_back(k);
    }
  	sort(all(a));
    vector<int> present(a.back()+1);
    int cnt = 0;
    for(int i : a){
        for(int j = i; j <=a.back(); j+=i){
            present[j]++;
        }
    }
    for(int i : a){
        cnt += (present[i]==1);
    }

    cout<<cnt<<endl;
    return 0;
}