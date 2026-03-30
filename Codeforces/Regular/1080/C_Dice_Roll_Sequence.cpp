#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    ll t;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;
        vector<ll> V;
        for(int i=0;i<n;i++){
            ll a;
            cin>>a;
            V.push_back(a);
        }
        ll ans=0;
        vector<bool> visited(n,false);
        for(int i=0;i<n-1;i++){
            if(!visited[i]){
                visited[i]=true;
                if(V[i]+V[i+1]==7 || V[i]==V[i+1]){
                    visited[i+1]=true;
                    ans++;
                }
            }
        }
        cout<<ans<<"\n";
    }
}