#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    ll n;
    cin>>n;
    vector<ll> S;
    ll maxi=0;
    for(int i=0;i<n;i++){
        ll a;
        cin>>a;
        S.push_back(a);
        maxi=max(maxi,a);
    }
    vector<ll> E;
    vector<pair<ll,ll>> A;
    vector<pair<ll,ll>> B;
    ll ans=0;
    for(int i=0;i<n;i++){
        ll b;
        cin>>b;
        E.push_back(b);
        A.push_back({maxi-S[i],i});
        B.push_back({b-maxi,i});
        ans+=2*(maxi-S[i]);
        ans+=2*(b-maxi);
    }
    if(n==1){
        cout<<E[0];
    }else{
        sort(A.rbegin(),A.rend());
        sort(B.rbegin(),B.rend());
        if(A[0].second!=B[0].second){
            ans+=S[A[0].second];
            ans-=(A[0].first+B[0].first);
        }else{
            if((A[0].first+B[1].first-S[A[0].second])>(B[0].first+A[1].first-S[A[1].second])){
                ans+=S[A[0].second];
                ans-=(A[0].first+B[1].first);
            }else{
                ans+=S[A[1].second];
                ans-=(A[1].first+B[0].first);
            }
        }
        cout<<ans;
    }
}