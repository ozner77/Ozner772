#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    ll n;
    cin>>n;
    set<ll> S;
    unordered_map<ll,ll> M;
    for(int i=0;i<n;i++){
        ll a;
        cin>>a;
        if(a==1){
            ll b;
            cin>>b;
            S.insert(b);
            M[b]++;
        }else{
            cout<<*S.begin()<<"\n";
            M[*S.begin()]--;
            if(M[*S.begin()]==0){
                S.erase(*S.begin());
            }
        }
    }
}