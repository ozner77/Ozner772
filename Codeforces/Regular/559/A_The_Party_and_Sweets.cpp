#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    ll n,m;
    cin>>n>>m;
    ll maxi=0;
    ll maxi2=0;
    ll suma=0;
    for(int i=0;i<n;i++){
        ll a;
        cin>>a;
        suma+=a;
        if(a>maxi){
            maxi2=maxi;
            maxi=a;
        }else if(a>maxi2){
            maxi2=a;
        }
    }
    ll ans=0;
    bool ok=false;
    for(int i=0;i<m;i++){
        ll a;
        cin>>a;
        if(a<maxi){
            cout<<-1;
            return 0;
        }
        if(a==maxi){
            ok=true;
        }
        ans+=a;
        ans+=(suma-maxi);
    }
    if(!ok){
        ans+=maxi;
        ans-=maxi2;
    }
    cout<<ans;
}