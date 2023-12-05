#include <bits/stdc++.h>
using namespace std;
///#define int long long
#define ll long long
#define ln '\n'
#define u unsigned
#define f first
#define ss second

ll logg(ll base ,ll x){
    ll s=0;
    if(!x)return 1;
    while(x){
        x/=base;
        s++;
    }
    return  s;
}
const ll N=1000000007;
const  ll mod=998244353;

ll fastPow(ll x,ll y,ll mode){
    if(y==0)
        return 1;
    //
    if(y%2==1){
        ll b=x%mode;
        ll ans=fastPow(b,y/2,mode)%mode;
        ans=(ans*ans)%mode;
        return (ans*b)%mode;
    }

    else{
        ll b=x%mode;
        ll ans=fastPow(b,y/2,mode)%mode;
        ans=(ans*ans)%mode;
        return ans;
    }

}

ll power(ll x, ll y,ll mode)
{
    ll res = 1;
    x = x % mode;

    while (y > 0) {
        if (y & 1)
            res = (res * x) % mode;
        y = y >> 1;
        x = (x * x) % mode;
    }

    return res;
}
u ll GCD(u ll a, u ll b)
{
    return b == 0 ? a : GCD(b, a % b);
}
u ll lcm(u ll x,u ll y){
    return (ll)(((x/(ll)__gcd(x,y)))*y);
}
ll ceiling (ll x,ll y){
    if(x%y)return x/y +1;
    return x/y;
}
bool sortby(const pair<ll,ll>&a,const pair<ll,ll>&b){
    if(a.first==b.first)
        return a.second>b.second;
    return a.first<b.first;
}
////////////////////////////////////////
ll fact[100001],invfact[100001];
ll invMod(ll x,ll mode){
    return fastPow(x,mode-2,mode)%mode;
}
void factorial(ll mode){
    ll ff=1;
    fact[0]=1;invfact[0]=1;
    for(ll i=1;i<=100000;i++){
        ff*=i;ff%=mode;
        fact[i]=ff;
        invfact[i] = invMod(fact[i],mode);
    }
}


ll ncr(ll n,ll r,ll mode){
    return ( (fact[n]* invfact[r])%mode* invfact[n-r])%mode;
}
///////////////////////////////////////////////
bool isPrime(ll n){
    if(n == 1){
        return false;
    }
    for(ll i = 2; i*i<=n; i++){
        if(n%i == 0){
            return false;
        }
    }

    return true;
}

int on_bits(long long n){ return __builtin_popcountll(n);}
//////////////////////////////////////////////////
struct Fenwick{
    void Update(vector<ll>&B,int idx,ll val){
        while(idx<B.size()){
            B[idx]+=val;
            idx+=(idx&-idx);
        }
    }
    ll get_sum(vector<ll>&B,int l,int r){
        ll s1=0,s2=0;l=max(l-1,0);
        while(l){
            s1+=B[l];
            l-=(l&-l);
        }
        while(r){
            s2+=B[r];
            r-=(r&-r);
        }
        return s2-s1;
    }

};

//////////////////////////////////////////

bool valid(int x,int uu){
    if(x>=0 && x<uu)return 1;
    return 0;
}
vector<ll>pow2,invpow;
void power2(int y){
    ll p=1;
    pow2.assign(y+1,0);
    invpow.assign(y+1,0);
    pow2[0]=1;invpow[0]=1;
    for(int i=1;i<y;i++){
        p*=2;//p%=N;
        pow2[i]=p;
        ///invpow[i]= invMod(p,N)%N;
    }
}
ll sum_(ll l,ll r){
    l--;
    return (r*(r+1))/2-(l*(l+1))/2;
}
bool is_pal(string s){
    string s2=s;
    reverse(s2.begin(), s2.end());
    return s==s2;
}
///MiraculousN
int BS(int no,int x){
    //// max power p such that x^p divides n
    int lo=1,hi=50,mid;
    while(lo<=hi){
        mid=lo+(hi-lo)/2;
        ll p=1;
        for(int i=0;i<mid;i++){
            p*=x;
            if(p>no){
                break;
            }
        }
        if(no%p==0)lo=mid+1;
        else hi=mid-1;
    }
    return hi;
}
int fib[45];
void fibonacci(){
    fib[1]=1;fib[0]=1;
    for(int i=2;i<=44;i++)
        fib[i]=fib[i-1]+fib[i-2];
}
double fastPowd(double x,ll y){
    if(y==0)
        return 1;
    //

    if(y%2==1){
        double b=x;
        double ans=fastPowd(b,y/2);
        ans=(ans*ans);
        return (ans*b);
    }

    else{
        double b=x;
        double ans=fastPowd(b,y/2);
        ans=(ans*ans);
        return ans;
    }

}

struct DSU{
    vector<int>leader,edges,Gsize;
    void init(int n){
        leader.assign(n+10,0);
        Gsize.assign(n+10,1);
        edges.assign(n+10,0);

    }
    int get_leader(int node){
        return (leader[node]==node)?node:leader[node]=get_leader(leader[node]);
    }
    void union_find(int a,int b){
        if(get_leader(a)== get_leader(b)){
            edges[get_leader(b)]++;
            return;
        }
        int l_a=get_leader(a);
        int l_b=get_leader(b);
        edges[l_b]+=1+edges[l_a];
        Gsize[l_b]+=Gsize[l_a];
        leader[l_a]=l_b;

    }

};
struct SegTree{
    vector<int>tree;
    void get_node(DSU & dsu,int n,int node){
        if(!node)return ;
        int c=tree[node];
        if(c!=1e8)
            dsu.union_find(c,n);
        get_node(dsu,dsu.get_leader(n),node/2);
    }
    void range(DSU &dsu,int node,int l,int r,int q1,int q2,int val){
        if(l>q2 || r<q1)return;
        if(l>=q1 && r<=q2){
            if(tree[node]!=1e8)
                dsu.union_find(val,tree[node]);
            tree[node]=dsu.get_leader(val);
            return;
        }
        range(dsu,node*2,l,(l+r)/2,q1,q2,val);
        range(dsu,node*2+1,(l+r)/2+1,r,q1,q2,val);
    }
};
struct Trie{
    Trie *v[5];
    bool x;
};
int n,p,k;
vector<pair<ll,int>>v;
ll player[100005][1<<7];
ll dp[100005][1<<7];
bool cmp(pair<ll,int>&a,pair<ll,int>&b){
    return a.f>b.f;
}
ll bst(int idx,int mask){
    if(idx==n){
        if(!mask)return 0;
        return -1e16;
    }
    if(!mask && (idx-p)>=k)return 0;
    if(dp[idx][mask]!=-1)return dp[idx][mask];
    ll ans=0;
    for(int i=0;i<p;i++){
        if(mask & (1<<i))
            ans=max(ans,player[v[idx].ss][i]+bst(idx+1,mask^(1<<i)));
    }
    if(idx+1-(p-(__builtin_popcount(mask)))<=k)
        ans=max(ans,v[idx].f+bst(idx+1,mask));
    else ans=max(ans,bst(idx+1,mask));
    return dp[idx][mask]=ans;
}
void solve(){
    cin>>n>>p>>k;
    v.assign(n,pair<ll,int>());
    memset(dp,-1,sizeof(dp));
    for(int i=0;i<n;i++){
        cin>>v[i].f;
        v[i].ss=i;
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<p;j++)
            cin>>player[i][j];
    }
    sort(v.begin(),v.end(),cmp);
    int m=(1<<(p))-1;
    cout<<bst(0,m)<<ln;


}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T=1;///cin>>T;
    /// map_pow();
    ///power2(31);
    ///factorial(N);
    while(T--){
        solve();
    }
    return 0;
}

///1 2 3
///2 3 1
///3
/*
4
1 2 3 4
6
3 5 6 7 1 2

10
7 10 1 2 1 7 1 5 9 9
9
6 2 5 6 7 7 5 5 2

2
6 10
3
6 3 3

 */#include <bits/stdc++.h>
using namespace std;
///#define int long long
#define ll long long
#define ln '\n'
#define u unsigned
#define f first
#define ss second

ll logg(ll base ,ll x){
    ll s=0;
    if(!x)return 1;
    while(x){
        x/=base;
        s++;
    }
    return  s;
}
const ll N=1000000007;
const  ll mod=998244353;

ll fastPow(ll x,ll y,ll mode){
    if(y==0)
        return 1;
    //
    if(y%2==1){
        ll b=x%mode;
        ll ans=fastPow(b,y/2,mode)%mode;
        ans=(ans*ans)%mode;
        return (ans*b)%mode;
    }

    else{
        ll b=x%mode;
        ll ans=fastPow(b,y/2,mode)%mode;
        ans=(ans*ans)%mode;
        return ans;
    }

}

ll power(ll x, ll y,ll mode)
{
    ll res = 1;
    x = x % mode;

    while (y > 0) {
        if (y & 1)
            res = (res * x) % mode;
        y = y >> 1;
        x = (x * x) % mode;
    }

    return res;
}
u ll GCD(u ll a, u ll b)
{
    return b == 0 ? a : GCD(b, a % b);
}
u ll lcm(u ll x,u ll y){
    return (ll)(((x/(ll)__gcd(x,y)))*y);
}
ll ceiling (ll x,ll y){
    if(x%y)return x/y +1;
    return x/y;
}
bool sortby(const pair<ll,ll>&a,const pair<ll,ll>&b){
    if(a.first==b.first)
        return a.second>b.second;
    return a.first<b.first;
}
////////////////////////////////////////
ll fact[100001],invfact[100001];
ll invMod(ll x,ll mode){
    return fastPow(x,mode-2,mode)%mode;
}
void factorial(ll mode){
    ll ff=1;
    fact[0]=1;invfact[0]=1;
    for(ll i=1;i<=100000;i++){
        ff*=i;ff%=mode;
        fact[i]=ff;
        invfact[i] = invMod(fact[i],mode);
    }
}


ll ncr(ll n,ll r,ll mode){
    return ( (fact[n]* invfact[r])%mode* invfact[n-r])%mode;
}
///////////////////////////////////////////////
bool isPrime(ll n){
    if(n == 1){
        return false;
    }
    for(ll i = 2; i*i<=n; i++){
        if(n%i == 0){
            return false;
        }
    }

    return true;
}

int on_bits(long long n){ return __builtin_popcountll(n);}
//////////////////////////////////////////////////
struct Fenwick{
    void Update(vector<ll>&B,int idx,ll val){
        while(idx<B.size()){
            B[idx]+=val;
            idx+=(idx&-idx);
        }
    }
    ll get_sum(vector<ll>&B,int l,int r){
        ll s1=0,s2=0;l=max(l-1,0);
        while(l){
            s1+=B[l];
            l-=(l&-l);
        }
        while(r){
            s2+=B[r];
            r-=(r&-r);
        }
        return s2-s1;
    }

};

//////////////////////////////////////////

bool valid(int x,int uu){
    if(x>=0 && x<uu)return 1;
    return 0;
}
vector<ll>pow2,invpow;
void power2(int y){
    ll p=1;
    pow2.assign(y+1,0);
    invpow.assign(y+1,0);
    pow2[0]=1;invpow[0]=1;
    for(int i=1;i<y;i++){
        p*=2;//p%=N;
        pow2[i]=p;
        ///invpow[i]= invMod(p,N)%N;
    }
}
ll sum_(ll l,ll r){
    l--;
    return (r*(r+1))/2-(l*(l+1))/2;
}
bool is_pal(string s){
    string s2=s;
    reverse(s2.begin(), s2.end());
    return s==s2;
}
///MiraculousN
int BS(int no,int x){
    //// max power p such that x^p divides n
    int lo=1,hi=50,mid;
    while(lo<=hi){
        mid=lo+(hi-lo)/2;
        ll p=1;
        for(int i=0;i<mid;i++){
            p*=x;
            if(p>no){
                break;
            }
        }
        if(no%p==0)lo=mid+1;
        else hi=mid-1;
    }
    return hi;
}
int fib[45];
void fibonacci(){
    fib[1]=1;fib[0]=1;
    for(int i=2;i<=44;i++)
        fib[i]=fib[i-1]+fib[i-2];
}
double fastPowd(double x,ll y){
    if(y==0)
        return 1;
    //

    if(y%2==1){
        double b=x;
        double ans=fastPowd(b,y/2);
        ans=(ans*ans);
        return (ans*b);
    }

    else{
        double b=x;
        double ans=fastPowd(b,y/2);
        ans=(ans*ans);
        return ans;
    }

}

struct DSU{
    vector<int>leader,edges,Gsize;
    void init(int n){
        leader.assign(n+10,0);
        Gsize.assign(n+10,1);
        edges.assign(n+10,0);

    }
    int get_leader(int node){
        return (leader[node]==node)?node:leader[node]=get_leader(leader[node]);
    }
    void union_find(int a,int b){
        if(get_leader(a)== get_leader(b)){
            edges[get_leader(b)]++;
            return;
        }
        int l_a=get_leader(a);
        int l_b=get_leader(b);
        edges[l_b]+=1+edges[l_a];
        Gsize[l_b]+=Gsize[l_a];
        leader[l_a]=l_b;

    }

};
struct SegTree{
    vector<int>tree;
    void get_node(DSU & dsu,int n,int node){
        if(!node)return ;
        int c=tree[node];
        if(c!=1e8)
            dsu.union_find(c,n);
        get_node(dsu,dsu.get_leader(n),node/2);
    }
    void range(DSU &dsu,int node,int l,int r,int q1,int q2,int val){
        if(l>q2 || r<q1)return;
        if(l>=q1 && r<=q2){
            if(tree[node]!=1e8)
                dsu.union_find(val,tree[node]);
            tree[node]=dsu.get_leader(val);
            return;
        }
        range(dsu,node*2,l,(l+r)/2,q1,q2,val);
        range(dsu,node*2+1,(l+r)/2+1,r,q1,q2,val);
    }
};
struct Trie{
    Trie *v[5];
    bool x;
};
int n,p,k;
vector<pair<ll,int>>v;
ll player[100005][1<<7];
ll dp[100005][1<<7];
bool cmp(pair<ll,int>&a,pair<ll,int>&b){
    return a.f>b.f;
}
ll bst(int idx,int mask){
    if(idx==n){
        if(!mask)return 0;
        return -1e16;
    }
    if(!mask && (idx-p)>=k)return 0;
    if(dp[idx][mask]!=-1)return dp[idx][mask];
    ll ans=0;
    for(int i=0;i<p;i++){
        if(mask & (1<<i))
            ans=max(ans,player[v[idx].ss][i]+bst(idx+1,mask^(1<<i)));
    }
    if(idx+1-(p-(__builtin_popcount(mask)))<=k)
        ans=max(ans,v[idx].f+bst(idx+1,mask));
    else ans=max(ans,bst(idx+1,mask));
    return dp[idx][mask]=ans;
}
void solve(){
    cin>>n>>p>>k;
    v.assign(n,pair<ll,int>());
    memset(dp,-1,sizeof(dp));
    for(int i=0;i<n;i++){
        cin>>v[i].f;
        v[i].ss=i;
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<p;j++)
            cin>>player[i][j];
    }
    sort(v.begin(),v.end(),cmp);
    int m=(1<<(p))-1;
    cout<<bst(0,m)<<ln;


}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T=1;///cin>>T;
    /// map_pow();
    ///power2(31);
    ///factorial(N);
    while(T--){
        solve();
    }
    return 0;
}
