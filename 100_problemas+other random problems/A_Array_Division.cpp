#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    ll n,k;
    vector<ll> V;
    ll sum=0;
    cin>>n>>k;
    for(int i=0;i<n;i++){
        ll a;
        cin>>a;
        V.push_back(a);
        sum+=a;
    }
    ll l=0;
    ll r=sum;
    ll res=1e18;
    while(l<r){
        ll m=(l+r+1)/2;
        ll act=k;
        bool ok=true;
        ll cur=0;
        ll ans=0;
        for(int i=0;i<n;i++){
            if(V[i]>m){
                ok=false;
                break;
            }
            cur+=V[i];
            if(cur>m){
                ans=max(ans,cur-V[i]);
                cur=V[i];
                act--;
            }
        }
        ans=max(ans,cur);
        if(act>0 && ok){
            res=min(res,ans);
            r=m-1;
        }else{
            l=m;
        }
    }
    cout<<res;

}