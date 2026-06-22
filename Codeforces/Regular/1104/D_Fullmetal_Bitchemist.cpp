#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    ll t;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;
        string s;
        cin>>s;
        ll ans=0;
        map<ll,ll> M;
        ll sumi=0;
        ll var=0;
        M[0]=1;
        for(int i=0;i<n;i++){
            if(s[i]=='0'){
                sumi++;
            }else{
                sumi--;
            }
            ll uwu=(sumi%3+3)%3;
            ll xd=M[uwu];
            ans+=(i+1-xd);
            M[uwu]++;
        }
        int i=0;
        while(i<n){
            int j=i+1;
            while(j<n && s[j]!=s[j-1]){
                j++;
            }
            ll l=j-i;
            if(l>=3){
                ll e=(l+1)/2;
                ll o=l/2;
                ll x=e*(e+1)/2+o*(o+1)/2;
                ans-=x-l;
            }
            i=j;
        }
        cout<<ans<<"\n";
    }
}