#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    ll t;
    cin>>t;
    while(t--){
        ll n,ax,ay,bx,by;
        cin>>n>>ax>>ay>>bx>>by;
        vector<ll> X;
        vector<ll> Y;
        vector<vector<ll>> dp;
        ll ans=0;
        vector<ll> maxiy;
        vector<ll> miniy;
        set<ll> S;
        ll MAXIMAXI=-1;
        for(int i=0;i<n;i++){
            ll x;
            cin>>x;
            X.push_back(x);
            S.insert(x);
            MAXIMAXI=max(MAXIMAXI,x);
        }
        for(int i=0;i<n;i++){
            ll y;
            cin>>y;
            Y.push_back(y);
        }
        maxiy.assign(S.size(),-1);
        miniy.assign(S.size(),1e18);
        map<ll,ll> compress;
        ll con=0;
        for(auto x:S){
            compress[x]=con;
            con++;
        }
        for(int i=0;i<n;i++){
            maxiy[compress[X[i]]]=max(Y[i],maxiy[compress[X[i]]]);
            miniy[compress[X[i]]]=min(miniy[compress[X[i]]],Y[i]);
        }
        ll curx=ax;
        ll jaja=abs(*S.begin()-ax);
        vector<ll> uwu(2,-1);
        dp.assign(S.size(),uwu);
        dp[0][1]=abs(maxiy[0]-ay)+(maxiy[0]-miniy[0]);
        dp[0][0]=abs(ay-miniy[0])+(maxiy[0]-miniy[0]);
        ll cnt=0;
        ll prev=*S.begin();
        for(auto x:S){
            if(cnt>0){
                ll dist=x-prev;
                dp[cnt][0]=min(dp[cnt-1][0]+abs(maxiy[cnt-1]-miniy[cnt])+(maxiy[cnt]-miniy[cnt]),dp[cnt-1][1]+abs(miniy[cnt-1]-miniy[cnt])+(maxiy[cnt]-miniy[cnt]))+dist;
                dp[cnt][1]=min(dp[cnt-1][0]+abs(maxiy[cnt-1]-maxiy[cnt])+(maxiy[cnt]-miniy[cnt]),dp[cnt-1][1]+abs(miniy[cnt-1]-maxiy[cnt])+(maxiy[cnt]-miniy[cnt]))+dist;
            }
            prev = x;
            cnt++;
        }
        ll lol=bx-MAXIMAXI;
        lol+=min(abs(miniy.back()-by)+dp[S.size()-1][1],abs(maxiy.back()-by)+dp[S.size()-1][0]);
        cout<<lol+jaja<<"\n";
        cout<<"";
    }
}