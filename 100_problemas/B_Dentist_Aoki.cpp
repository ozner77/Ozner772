#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    ll n,k;
    cin>>n>>k;
    vector<ll> V(n,1);
    ll ans=n;
    for(int i=0;i<k;i++){
        ll a;
        cin>>a;
        if(V[a-1]==1){
            ans--;
            V[a-1]=0;
        }else{
            ans++;
            V[a-1]=1;
        }
    }
    cout<<ans;
}