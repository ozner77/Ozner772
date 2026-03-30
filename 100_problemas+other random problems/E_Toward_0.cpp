#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll a,b,x,y;
map<ll,long double> memo;
long double solve(ll num){
    if(memo[num]>0){
        return memo[num];
    }
    if(num==0){
        return 0;
    }
    long double xd=min(solve(num/b)+x,(6*y+solve(num/2)+solve(num/3)+solve(num/4)+solve(num/5)+solve(num/6))/5);
    memo[num]=xd;
    return memo[num];
}
int main(){
    cin>>a>>b>>x>>y;
    ll num=a;
    long double ans=min(solve(a/b)+x,(6*y+solve(num/2)+solve(num/3)+solve(num/4)+solve(num/5)+solve(num/6))/5);
    cout<<fixed<<setprecision(7)<<ans;
}