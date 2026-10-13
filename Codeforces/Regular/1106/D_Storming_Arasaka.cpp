#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    ll t;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;
        ll ans1=0;
        ll ans2=0;
        set<ll> S;
        vector<ll> V;
        ll sqrn=sqrt(n);
        sqrn++;
        vector<ll> factors;
        for(int i=2;i<=sqrn;i++){
            while(n%i==0){
                S.insert(i);
                n/=i;
                ans1++;
            }
        }
        ans2=S.size();
        if(n>1){
            ans1++;
            ans2++;
        }
        cout<<ans1+ans2-1<<"\n";
    }
}