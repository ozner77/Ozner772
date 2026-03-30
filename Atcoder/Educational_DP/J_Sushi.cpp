#include <bits/stdc++.h>
using namespace std;
#define ll long double
ll n;
vector<vector<vector<ll>>> dp;
ll solve(long long c1,int c2,int c3){
    if(c1<0 || c2<0 || c3<0){
        return 0;
    }
    if(c1==0 && c2==0 && c3==0){
        return 0;
    }
    ll memo=dp[c1][c2][c3];
    if(memo>-0.9){
        return memo;
    }
    long long s=c1+c2+c3;
    ll res=n;
    if(c1>0){
        res+=c1*solve(c1-1,c2,c3);
    }
    if(c2>0){
        res+=c2*solve(c1+1,c2-1,c3);
    }
    if(c3>0){
        res+=c3*solve(c1,c2+1,c3-1);
    }
    res/=s;
    dp[c1][c2][c3]=res;
    return res;
}
int main(){
    cin>>n;
    dp=vector<vector<vector<long double>>>(n+1,vector<vector<long double>>(n+1,vector<long double>(n+1,-1)));
    dp[0][0][0]=0;
    ll x=0,y=0,z=0;
    ll a;
    for(int i=0;i<n;i++){
        cin>>a;
        if(a==1){
            x++;
        }else if(a==2){
            y++;
        }else{
            z++;
        }
    }
    cout<<fixed<<setprecision(10)<<solve(x,y,z);
}