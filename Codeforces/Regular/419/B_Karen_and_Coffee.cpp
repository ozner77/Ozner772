#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    ll n,k,q;
    cin>>n>>k>>q;    
    vector<ll> V(5e5,0),L(5e5,0);
    for(int i=0;i<n;i++){
        ll l,r;
        cin>>l>>r;
        V[l]++;
        V[r+1]--;
    }
    vector<ll> pV,pL;
    pV.push_back(0);
    pL.push_back(0);
    for(int i=1;i<5e5;i++){
        pV.push_back(pV[i-1]+V[i]);
    }
    for(int i=1;i<5e5;i++){
        if(pV[i]>=k){
            L[i]=1;
        }
    }
    for(int i=1;i<5e5;i++){
        pL.push_back(pL[i-1]+L[i]);
    }
    for(int i=0;i<q;i++){
        ll p,d;
        cin>>p>>d;
        cout<<pL[d]-pL[p-1]<<"\n";
    }
}