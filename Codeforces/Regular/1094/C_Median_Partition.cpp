#include <bits/stdc++.h>
using namespace std;
#define ll long long
bool check(ll a,ll b,ll c){
    if(b>=abs(a-c)){
        return true;
    }
    return false;
}
int main() {
    ll t;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;
        vector<ll> V,A;
        for(int i=0;i<n;i++){
            ll x;
            cin>>x;
            V.push_back(x);
            A.push_back(x);
        }
        sort(A.begin(),A.end());
        ll median=A[n/2];
        vector<ll> dp(n+1,-1);
        dp[0]=0;
        vector<ll> l,r,mid;
        ll prevl=0,prevr=0;
        ll prevm=0;
        l.push_back(0);
        r.push_back(0);
        mid.push_back(0);
        for(int i=0;i<n;i++){
            l.push_back(prevl);
            r.push_back(prevr);
            mid.push_back(prevm);

            if(V[i]<median){
                prevl++;
                l.back()++;
            }else if(V[i]>median){
                prevr++;
                r.back()++;

            }else{
                prevm++;
                mid.back()++;
            }
        }
        for(int i=1;i<=n;i++){
            for(int j=0;j<=i;j++){
                ll a=l[i]-l[j];
                ll b=r[i]-r[j];
                ll c=mid[i]-mid[j];
                if((i-j)%2==1 && c>0 && dp[j]!=-1){
                    if(check(a,c-1,b)){
                        dp[i]=max(dp[i],dp[j]+1);
                    }
                }
            }
        }
        cout<<dp[n]<<"\n";
    }
}