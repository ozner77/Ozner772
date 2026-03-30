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
        s+=s;
        ll ans=0;
        for(int i=0;i<n;i++){
            string a="";
            for(int j=i;j<i+n;j++){
                a+=s[j];
            }
            ll cur=0;
            for(int j=1;j<n;j++){
                if(a[j]!=a[j-1]){
                    cur++;
                }
            }
            cur++;
            ans=max(ans,cur);
        }
        cout<<ans<<"\n";
    }
}