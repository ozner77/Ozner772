#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    ll t;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;
        vector<ll> V,L;
        for(int i=0;i<n;i++){
            ll a;
            cin>>a;
            V.push_back(a);
        }
        for(int i=0;i<n-1;i++){
            L.push_back(V[i]-V[i+1]);
        }
        vector<ll> ans(n);
        for(int i=0;i<n-2;i++){
            ans[i+1]=L[i]-L[i+1];
            ans[i+1]/=2;
        }
        ll suma=0;
        ll suma2=0;
        ll ind=0;
        int ind2=n-1;
        for(auto x:ans){
            suma+=x*ind;
            suma2+=x*ind2;
            ind++;
            ind2--;
        }
        ans[n-1]=V[0]-suma;
        ans[n-1]/=(n-1);
        ans[0]=V[n-1]-suma2;
        ans[0]/=(n-1);
        for(auto x:ans){
            cout<<x<<" ";
        }
        cout<<"\n";
    }
}