#include <bits/stdc++.h>
using namespace std;
#define ll long long
map<ll,ll> memo;
ll a,b;
ll solve(ll x){
    if(memo[x]!=0){
        return memo[x];
    }
    if(x==b){
        return 1;
    }
    if(x==1){
        return 100000;
    }
    ll ans=min(solve(x/2),solve(x-(x/2)));
    memo[x]=ans+1;
    return memo[x];
}
int main(){
    ll t;
    cin>>t;
    while(t--){
        memo.clear();
        cin>>a>>b;
        if(a==b){
            cout<<0<<"\n";
        }else{
            if(b>a){
                cout<<-1<<"\n";
            }else{
                ll jaja=solve(a);
                if(jaja>=100000){
                    cout<<-1<<"\n";
                }else{
                    cout<<jaja-1<<"\n";
                }
            }
        }
    }
}