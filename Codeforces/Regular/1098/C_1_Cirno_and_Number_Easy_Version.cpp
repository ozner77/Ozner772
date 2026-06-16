#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    ll t;
    cin>>t;
    while(t--){
        ll a,n;
        cin>>a>>n;
        vector<ll> d(n);
        for(int i=0;i<n;i++) cin>>d[i];
        sort(d.begin(),d.end());
        string sa=to_string(a);
        ll L=sa.size();
        ll ans=3e18;
        auto eval=[&](string s){
            if(s.empty()) return;
            ans=min(ans,abs(a-stoll(s)));
        };
        if(L>1){
            eval(string(L-1,'0'+d.back()));
        }else if(d[0]==0){
            eval("0");
        }
        ll mn;
        if(d[0]==0 && n>1){
            mn=d[1];
        }else{
            mn=d[0];
        }
        if(mn>0){
            eval(to_string(mn)+string(L,'0'+d[0]));
        }
        string pref="";
        for(int i=0;i<L;i++){
            ll cur=sa[i]-'0';
            for(auto x:d){
                if(i==0 && x==0 && L>1) continue;

                if(x<cur){
                    eval(pref+to_string(x)+string(L-i-1,'0'+d.back()));
                }
                else if(x>cur){
                    eval(pref+to_string(x)+string(L-i-1,'0'+d[0]));
                }
            }
            if(binary_search(d.begin(),d.end(),cur)){
                pref+=sa[i];
            }else{
                break;
            }
        }
        if(pref.size()==L){
            eval(pref);
        }
        cout<<ans<<"\n";
    }
}