#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll MOD=1e9+7;
pair<ll,ll> fib(ll n){
    if(n == 0) return {0, 1};
    pair<ll,ll> XD = fib(n / 2);
    ll a=XD.first;
    ll b=XD.second;
    a%=MOD;
    b%=MOD;
    ll c = a * ((2*b % MOD - a + MOD) % MOD) % MOD;
    ll d=(a*a)%MOD+(b*b)%MOD;   
    d%=MOD;
    if(n%2==0)
        return {c,d};
    else
        return {d,(c+d)%MOD};
}
ll solve(ll n){
    return fib(n).first;
}

string binary(ll x){
    string ans="";
    while(x!=0){
        ans+=to_string(x%2);
        x/=2;
    }
    string res;
    for(int i=ans.size()-1;i>=0;i--){
        res+=ans[i];
    }
    return res;
}
int main(){
    ll n,p;
    cin>>n>>p;
    vector<ll> V,L;
    map<ll,ll> M;
    ll ans=0;
    for(int i=0;i<n;i++){
        ll a;
        cin>>a;
        V.push_back(a);
        M[a]++;
    }
    for(int i=0;i<n;i++){
        ll xd=V[i];
        bool ok=true;
        while(true){
            if(xd!=1){
                if(xd%2!=0){
                    xd--;
                    xd/=2;
                }else if(xd%4==0){
                    xd/=4;
                }else{
                    break;
                }
            }else{
                break;
            }
            if(M[xd]>0){
                M[V[i]]--;
                ok=false;

                break;
            }
        }
        if(ok){
            L.push_back(V[i]);
        }
    }
    for(auto x:L){
        ll uwu=p-binary(x).size();
        if(uwu>=0){
            uwu+=3;
            ans=(ans+solve(uwu))%MOD;
            ans=(ans-1+MOD)%MOD;
        }
    }
    cout<<ans%MOD;
}