#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    ll t;
    cin>>t;
    while(t--){
        ll n,h,k;
        cin>>n>>h>>k;
        vector<ll> V;
        multiset<ll> S;
        ll suma=0;
        for(int i=0;i<n;i++){
            ll a;
            cin>>a;
            suma+=a;
            S.insert(a);
            V.push_back(a);
        }
        ll ans=0;
        ll xd=h/suma;
        ans+=(xd)*n;
        ans+=(xd*k);
        if(h%suma==0){
            ans-=k;
            cout<<ans<<"\n";
        }else{
            ll obj=h%suma;
            ll mini=1e10;
            ll sumi=0;
            for(int i=0;i<n;i++){
                sumi+=V[i];
                ll originalsumi=sumi;
                S.erase(S.find(V[i]));
                mini=min(mini,V[i]);
                sumi-=mini;
                if(S.size()>0){
                    if(*S.rbegin()>mini){
                        sumi+=*S.rbegin();
                    }else{
                        sumi+=mini;
                    }
                }else{
                    sumi+=mini;
                }
                if(sumi>=obj){
                    ans+=(i+1);
                    break;
                }
                sumi=originalsumi;
            }
            cout<<ans<<"\n";
        }
    }
}