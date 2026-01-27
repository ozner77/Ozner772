#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    ll t;
    cin>>t;
    while(t--){
        ll n,q;
        cin>>n>>q;
        vector<ll> A,B;
        for(int i=0;i<n;i++){
            ll a;
            cin>>a;
            A.push_back(a);
        }
        for(int i=0;i<n;i++){
            ll b;
            cin>>b;
            B.push_back(b);
        }
        vector<pair<ll,ll>> C;
        unordered_map<ll,ll> maxi;
        for(ll i=0;i<n;i++){
            A[i]=max(A[i],B[i]);
            maxi[A[i]]=max(maxi[A[i]],i);
            C.push_back({A[i],i});
        }
        sort(C.rbegin(),C.rend());
        ll cur=-1;
        for(int i=0;i<n;i++){
            ll xd=C[i].first;
            ll lol=C[i].second;
            if(lol>cur){
                if(lol==maxi[xd]){
                    for(int j=cur+1;j<=lol;j++){
                        A[j]=xd;
                    }
                    cur=lol;
                }
            }
        }   
        vector<ll> pA;
        pA.push_back(0);
        for(int i=0;i<n;i++){
            pA.push_back(pA[i]+A[i]);
        }
        for(int i=0;i<q;i++){
            ll l,r;
            cin>>l>>r;
            cout<<pA[r]-pA[l-1]<<" ";
        }
        cout<<"\n";
    }
}