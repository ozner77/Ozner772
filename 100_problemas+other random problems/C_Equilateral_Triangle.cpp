#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    map<ll,ll> M;
    M[0]++;
    ll n,m;
    cin>>n>>m;
    if(m%3!=0){
        cout<<0;
        return 0;
    }
    ll xd=m/3;
    ll suma=0;
    for(int i=0;i<n-1;i++){
        ll a;
        cin>>a;
        suma+=a;
        M[suma%m]++;
    }
    ll ans=0;
    for(int i=0;i<m;i++){
        if(M[i]>0){
            if(M[i+xd]>0){
                if(M[i+xd+xd]>0){
                    ans+=(M[i]*M[i+xd]*M[i+xd+xd]);
                }
            }
        }
    }
    cout<<ans;
}