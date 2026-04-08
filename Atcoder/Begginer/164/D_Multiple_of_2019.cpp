#include<iostream>
using namespace std;
#include <vector>
#include <map>
#include <set>
#define ll long long
int main()
{
    string s;
    cin>>s;
    ll n=s.size();
    ll mod=2019;
    ll xd=1;
    vector<ll> prefix(n);
    ll ans=0;
    ll prev=0;
    map<ll,ll> M;
    M[0]++;
    for(int i=1;i<=n;i++){
        prefix[n-i]=(prev+(s[n-i]-'0')*xd)%mod;
        xd*=10;
        prev=prefix[n-i];
        xd%=mod;
        prev%=mod;
        ans+=M[prev];
        M[prev]++;
    }
    cout<<ans;
}