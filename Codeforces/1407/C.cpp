    // /*"Won't stop untill I'm Phenomenal" - Phenomenal, EMINEM*/
    // #pragma GCC target ("avx2")
    // #pragma GCC optimization ("O3")
    // #pragma GCC optimization ("unroll-loops")
    // #include<bits/stdc++.h>
    // using namespace std;
    // typedef long long int ll;
    // #define llpow(a,b) (ll)(pow(a,b)+0.5)
    // #define lb(a,val) min((int)a.size()-1, (int)(lower_bound(a.begin(),a.end(),val)-a.begin()))
    // #define lbs(a,val) (int)(lower_bound(a.begin(),a.end(),val)-a.begin())
    // #define ub(a,val) min((int)a.size()-1, (int)(upper_bound(a.begin(),a.end(),val)-a.begin()))
    // #define ubs(a,val)  (int)(upper_bound(a.begin(),a.end(),val)-a.begin())
    // #define f first
    // #define up(a,b) max(a,b)
    // #define s second
    // #define INF 1e18
    // /*All the macros below are copied from nik_y(OG)*/
    // #define test() int t; cin>>t; while(t--)
    // #define fl(i,a,b) for(int i = a ; i <b ;i++)
    // #define Shazam ios_base::sync_with_stdio(false);   cin.tie(NULL); cout.tie(NULL);
    // #define all(c) c.begin(),c.end()
    // //#define endl "\n"
    // #define get(a,n) fl(i,0,n)  cin>>a[i];
    // #define pr(a) fl(i,0,a.size()) cout<<a[i]<<" ";	cout<<endl;
    // /*---------------------------------------------*/
    // const int mod = 998244353;
    // const int nag = 3e5 + 5;
    // template <typename T> void add(T& a, T b){a+=b;while(a>=mod)a-=mod;while(a<0)a+=mod;}
    // template <typename T> void mul(T& a, T b){ a = a*b%mod;}
    // template <typename T> void up_self(T& a, T b){a = up(a,b);}
    // template <typename T> void min_self(T& a, T b){a = min(a,b);}
    // /*Some cool functions I'm too lazy to write again in a Contest :) */
    // string find_largest_pref_palindrome(const string& a){string s = a;reverse(s.begin(),s.end());s = a+"%"+s;int c = 0;vector<int> pref(2*((int)a.size()) +2);for(int i = 1; i< s.size() ; i++ ){while(c!=0&&s[i]!=s[c])c = pref[c-1];if(s[i]==s[c])c++;pref[i] = c;}return s.substr(0,c);}
    // ll binexpomodulo(ll x, ll y){ll res =1;x%=mod;if(!x)return 0;while(y){if(y&1){mul(res, x);}mul(x,x);y>>=1;}return res;}
    // ll nCrInOr(ll n, ll r){ll res = 1;if(r>n-r)r = n-r;ll rin = 1;for(ll i = 1; i <=r ; i++)rin = (rin*i)%mod;rin = binexpomodulo(rin,mod-2);for(ll i = 1; i <= r; i++)res = (res*(n-i+1))%mod;res = (res*rin)%mod;return res;}
    // vector<ll> fac, ifac; void precompute(ll n){fac.resize(n+1,1);ifac.resize(n+1);for(ll i = 2; i<=n;i++){	fac[i] = (fac[i-1]*i)%mod;}ifac[n] = binexpomodulo(fac[n],mod-2);for(ll i = n-1; i>=0; i--)ifac[i] = (ifac[i+1]*(i+1))%mod;}ll nCr(ll n, ll r){return fac[n]*(ifac[n-r])%mod * (ifac[r])%mod;}
    // int msb_pos(ll n){int ans;for(int i = 0 ; i < 64;  i++)if(n&(1LL<<i))ans = i+1;return ans;}
    // ll totient(ll n){ ll ans = n; for(ll i = 2; i*i<= n; i++){if(n%i==0){ans-=(ans/i);while(n%i==0){n/=i;}}}if(n>=2){ans -= ans/n;}return ans;}
    // int lis(vector<ll> a, int n){ vector<ll> dp(n+1,INF); dp[0] = -INF;for(int i = 0 ; i < n ; i++){int p = lbs(dp,a[i]);if(dp[p-1]<a[i]&&a[i]<dp[p])dp[p] = a[i];}int ans = 0;for(int i = 1; i <= n ; i++){if(dp[i]!=INF)ans = i;}return ans;}
    // bool is_prime(int n){if(n==2) return true; if(n&1^1) return false; for(int i = 2; i*i<= n; i++){if(n%i==0) return false;}return true;}
     
    // ll get_(vector<ll>& a, int pos){ll res = 0;for(; pos>=0; pos = (pos&(pos+1))-1){res+=a[pos];}return res;}
    // void upd(vector<ll>& a, int pos, int val){	for(; pos< a.size();pos = (pos|(pos+1)))a[pos]+= val;}
    // /*---------------------------------------------*/

    // int main()
    // {
    // 	Shazam;
    //     int n; cin>>n;
    //     vector<int> ans(n);
    //     vector<int> vis(n);
    //     int mx = 0;
    //     for(int i = 1; i <n; i++){
    //         int res1, res2;
    //         cout<<"? "<<mx+1<<" "<<i+1<<endl;
    //         cin>>res1;
    //         cout<<"? "<<i+1<<" "<<mx+1<<endl;
    //         cin>>res2;
    //         if(res1>res2){
    //             ans[mx] = res1;
    //             mx = i;
    //         }
    //         else{
    //             ans[i] = res2;
    //         }
    //     }
    //     ans[mx] = n;
    //     cout<<"! ";
    //     pr(ans);
    // 	return 0;
    // }
        /*"Won't stop untill I'm Phenomenal" - Phenomenal, EMINEM*/
    #pragma GCC target ("avx2")
    #pragma GCC optimization ("O3")
    #pragma GCC optimization ("unroll-loops")
    #include<bits/stdc++.h>
    using namespace std;
    typedef long long int ll;
    #define llpow(a,b) (ll)(pow(a,b)+0.5)
    #define lb(a,val) min((int)a.size()-1, (int)(lower_bound(a.begin(),a.end(),val)-a.begin()))
    #define lbs(a,val) (int)(lower_bound(a.begin(),a.end(),val)-a.begin())
    #define ub(a,val) min((int)a.size()-1, (int)(upper_bound(a.begin(),a.end(),val)-a.begin()))
    #define ubs(a,val)  (int)(upper_bound(a.begin(),a.end(),val)-a.begin())
    #define f first
    #define up(a,b) max(a,b)
    #define s second
    #define INF 1e18
    /*All the macros below are copied from nik_y(OG)*/
    #define test() int t; cin>>t; while(t--)
    #define fl(i,a,b) for(int i = a ; i <b ;i++)
    #define Shazam ios_base::sync_with_stdio(false);   cin.tie(NULL); cout.tie(NULL);
    #define all(c) c.begin(),c.end()
    //#define endl "\n"
    #define get(a,n) fl(i,0,n)  cin>>a[i];
    #define pr(a) fl(i,0,a.size()) cout<<a[i]<<" ";	cout<<endl;
    /*---------------------------------------------*/
    const int mod = 998244353;
    const int nag = 3e5 + 5;
    template <typename T> void add(T& a, T b){a+=b;while(a>=mod)a-=mod;while(a<0)a+=mod;}
    template <typename T> void mul(T& a, T b){ a = a*b%mod;}
    template <typename T> void up_self(T& a, T b){a = up(a,b);}
    template <typename T> void min_self(T& a, T b){a = min(a,b);}
    /*Some cool functions I'm too lazy to write again in a Contest :) */
    string find_largest_pref_palindrome(const string& a){string s = a;reverse(s.begin(),s.end());s = a+"%"+s;int c = 0;vector<int> pref(2*((int)a.size()) +2);for(int i = 1; i< s.size() ; i++ ){while(c!=0&&s[i]!=s[c])c = pref[c-1];if(s[i]==s[c])c++;pref[i] = c;}return s.substr(0,c);}
    ll binexpomodulo(ll x, ll y){ll res =1;x%=mod;if(!x)return 0;while(y){if(y&1){mul(res, x);}mul(x,x);y>>=1;}return res;}
    ll nCrInOr(ll n, ll r){ll res = 1;if(r>n-r)r = n-r;ll rin = 1;for(ll i = 1; i <=r ; i++)rin = (rin*i)%mod;rin = binexpomodulo(rin,mod-2);for(ll i = 1; i <= r; i++)res = (res*(n-i+1))%mod;res = (res*rin)%mod;return res;}
    vector<ll> fac, ifac; void precompute(ll n){fac.resize(n+1,1);ifac.resize(n+1);for(ll i = 2; i<=n;i++){	fac[i] = (fac[i-1]*i)%mod;}ifac[n] = binexpomodulo(fac[n],mod-2);for(ll i = n-1; i>=0; i--)ifac[i] = (ifac[i+1]*(i+1))%mod;}ll nCr(ll n, ll r){return fac[n]*(ifac[n-r])%mod * (ifac[r])%mod;}
    int msb_pos(ll n){int ans;for(int i = 0 ; i < 64;  i++)if(n&(1LL<<i))ans = i+1;return ans;}
    ll totient(ll n){ ll ans = n; for(ll i = 2; i*i<= n; i++){if(n%i==0){ans-=(ans/i);while(n%i==0){n/=i;}}}if(n>=2){ans -= ans/n;}return ans;}
    int lis(vector<ll> a, int n){ vector<ll> dp(n+1,INF); dp[0] = -INF;for(int i = 0 ; i < n ; i++){int p = lbs(dp,a[i]);if(dp[p-1]<a[i]&&a[i]<dp[p])dp[p] = a[i];}int ans = 0;for(int i = 1; i <= n ; i++){if(dp[i]!=INF)ans = i;}return ans;}
    bool is_prime(int n){if(n==2) return true; if(n&1^1) return false; for(int i = 2; i*i<= n; i++){if(n%i==0) return false;}return true;}
     
    ll get_(vector<ll>& a, int pos){ll res = 0;for(; pos>=0; pos = (pos&(pos+1))-1){res+=a[pos];}return res;}
    void upd(vector<ll>& a, int pos, int val){	for(; pos< a.size();pos = (pos|(pos+1)))a[pos]+= val;}
    /*---------------------------------------------*/

    int main()
    {
    	Shazam;
        int n; cin>>n;
        vector<int> ans(n);
        vector<int> vis(n);
        int i = 1;
        int j = 2;
        int cnt = 0;
        for(int k = 1; k < n; k++){
            int res1, res2;
            cout<<"? "<<i<<" "<<j<<endl;
            cin>>res1;
            cout<<"? "<<j<<" "<<i<<endl;
            cin>>res2;
            if(res2>res1){
                ans[j-1] = res2;
                vis[j-1] = 1;
                 j = min_element(all(vis)) - vis.begin() + 1;
                if(j==i){
                    vis[j-1] = 1;
                     j = min_element(all(vis)) - vis.begin() + 1;
                    vis[i-1] = 0;
                }
            }
            else{
                ans[i-1] = res1;
                vis[i-1] = 1;
                 i = min_element(all(vis)) - vis.begin() + 1;
                if(j==i){
                    vis[i-1] = 1;
                     i = min_element(all(vis)) - vis.begin() + 1;
                    vis[j-1] = 0;
                }
            }
           
        }
        for(int i = 0 ; i < n; i++){
            if(ans[i]==0)
                ans[i] = n;
        }
        cout<<"! ";
        pr(ans);
    	return 0;
    }