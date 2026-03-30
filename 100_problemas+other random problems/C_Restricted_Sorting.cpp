#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    ll t;
    cin>>t;
    while(t--){
        ll mini=1e18;
        ll maxi=0;
        ll n;
        cin>>n;
        vector<ll> V;
        vector<ll> L;
        ll diff=0;
        for(int i=0;i<n;i++){
            ll a;
            cin>>a;
            V.push_back(a);
            L.push_back(a);
            maxi=max(maxi,a);
            mini=min(mini,a);
        }
        map<ll,vector<ll>> M;
        sort(L.begin(),L.end());
        for(int i=0;i<n;i++){
            if(V[i]!=L[i]){
                M[L[i]].push_back(V[i]);
                diff++;
            }
        }
        if(diff==0){
            cout<<-1<<"\n";
            continue;
        }
        vector<ll> ans;
        for(auto x:M){
            for(auto y:x.second){
                ll n1=abs(x.first-y);
                ll n2=min(abs(x.first-mini),abs(mini-y));
                ll n3=min(abs(x.first-maxi),(maxi-y));
                ll n4=min(abs(x.first-mini),abs(mini-maxi));
                n4=min(n4,abs(maxi-y));
                ll n5=min(abs(x.first-maxi),abs(mini-maxi));
                n5=min(n5,abs(mini-y));
                n1=max(n1,n2);
                n1=max(n1,n3);
                n1=max(n1,n4);
                n1=max(n1,n5);
                ans.push_back(n1);
            }
        }
        ll res=1e18;
        for(auto x:ans){
            res=min(res,x);
        }
        cout<<res<<"\n";
    }
}