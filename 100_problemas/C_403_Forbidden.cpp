#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    ll n,m,q;
    cin>>n>>m>>q;
    unordered_map<ll,unordered_map<ll,ll>> M;
    unordered_map<ll,ll> all;
    for(int i=0;i<q;i++){
        ll a,b,c;
        cin>>a;
        if(a==1){
            cin>>b>>c;
            M[b][c]++;
        }else if(a==2){
            cin>>b;
            all[b]++;
        }else{
            cin>>b>>c;
            if(all[b]){
                cout<<"Yes\n";
            }else if(M[b][c]){
                cout<<"Yes\n";
            }else{
                cout<<"No\n";
            }
        }
    }
}