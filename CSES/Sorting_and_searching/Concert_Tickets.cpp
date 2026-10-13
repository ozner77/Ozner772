#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    ll n,m;
    cin>>n>>m;
    multiset<ll> S;
    for(int i=0;i<n;i++){
        ll a;
        cin>>a;
        S.insert(a);
    }
    for(int i=0;i<m;i++){
        ll a;
        cin>>a;
        auto it=S.upper_bound(a);
        if(it==S.begin()){
            cout<<-1<<"\n";
        }else{
            it--;
            cout<<*it<<"\n";
            S.erase(it);
        }
    }
}