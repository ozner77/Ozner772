#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    ll t;
    cin>>t;
    while(t--){
        ll n,k;
        cin>>n>>k;
        map<ll,ll> M;
        for(int i=0;i<n;i++){
            ll a;
            cin>>a;
            M[a]++;
        }
        ll ans=0;
        for(int i=0;i<n;i++){
            if(M[i]>0){
                ans++;
            }else{
                break;
            }
        }
        ll xd=0;
        for(int i=0;i<k;i++){
            if(M[i]==0){
                xd++;
            }
        }
        cout<<max(xd,M[k])<<"\n";
    }
}