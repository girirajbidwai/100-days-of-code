#include<bits/stdc++.h>
#define FIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define endl "\n"
using namespace std;
typedef long long ll;
typedef long double ld;
void test_case()
{
    ll n,m,tot;
    cin>>n>>m>>tot;
    ll dist[15][15];
    for(int i=0;i<=10;i++)
    {
        for(int j=0;j<=10;j++)
        {
            dist[i][j]=4e18;
        }
    }
    for(int i=0;i<=10;i++)dist[i][i]=0;
    string s;
    cin>>s;
    deque<char>r;
    while(m--)
    {
        ll a,b,c;
        cin>>a>>b>>c;
        dist[a][b]=min(dist[a][b],c);
    }
    for(int k=0;k<=10;k++)
    {
        for(int i=0;i<=10;i++)
        {
            for(int j=0;j<=10;j++)
            {
                dist[i][j]=min(dist[i][j],dist[i][k]+dist[k][j]);
            }
        }
    }
    ll ptr1=(n-1)/2;
    ll sum=0;
    while(ptr1!=-1)
    {
        ll ptr2=n-1-ptr1;
        ll a=s[ptr1]-'0';
        ll b=s[ptr2]-'0';
        ll mn=1e18;
        char ch='a';
        for(int i=0;i<=9;i++)
        {
            if(dist[a][i]+((ptr1!=ptr2)*dist[b][i])<mn)
            {
                mn=dist[a][i]+((ptr1!=ptr2)*dist[b][i]);
                ch='0'+i;
            }
        }
        if(sum+mn>tot)
        {
            cout<<-1<<endl;
            return;
        }
        sum+=mn;
        r.push_back(ch);
        if(ptr1!=ptr2)r.push_front(ch);
        ptr1--;
    }
    string tmp="";
    for(auto x:r)tmp.push_back(x);
    for(int i=0;i<=(n-1)/2;i++)
    {
        ll j=n-1-i;
        ll a=s[i]-'0';
        ll b=s[j]-'0';
        ll c=tmp[i]-'0';
        sum-=dist[a][c];
        if(i!=j)sum-=dist[b][c];
        bool took=false;
        for(int k=9;k>c;k--)
        {
            if(sum+dist[a][k]+((i!=j)*dist[b][k])<=tot)
            {
                tmp[i]='0'+k;
                tmp[n-i-1]='0'+k;
                sum+=(dist[a][k]);
                if(i!=j)sum+=(dist[b][k]);
                took=true;
                break;
            }
        }
        if(!took)
        {
            sum+=dist[a][c];
            if(i!=j)sum+=dist[b][c];
        }
    }
    cout<<tmp<<endl;
}
int main()
{
    FIO
//  freopen("input.txt","rt",stdin);
//  freopen("output.txt","wt",stdout);
    ll t;
    t=1;
    cin>>t;
    while(t--)
    {
        test_case();
    }
}
