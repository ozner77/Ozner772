#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    ll t;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;
        vector<ll> V;
        ll sumatotal=0;
        for(int i=0;i<n;i++){
            ll a;
            cin>>a;
            V.push_back(a);
            sumatotal+=a;
        }
        ll sumar=0;
        ll suma=0;
        ll ansi=sumatotal;
        ll ansid=-1;
        for(int i=0;i<n;i++){
            if(V[i]>0){
                if(suma + (sumatotal - sumar - V[i]) - V[i]>ansi){
                    ansi=suma + (sumatotal - sumar - V[i]) - V[i];
                    ansid=i;
                }
            }
            sumar+=V[i];
            suma+=abs(V[i]);
        }
        if(ansid!=-1){
            reverse(V.begin(),V.end());
            vector<ll> ans;
            bool swapped=false;
            for(int i=(n-ansid);i<n;i++){
                if(swapped){
                    if(-V[i]>0){
                        ans.push_back(i);
                        swapped=false;
                    }
                }else{
                    if(V[i]>0){
                        ans.push_back(i);
                        swapped=true;
                    }
                }
            }
            cout<<ans.size()+1<<"\n";
            for(auto x:ans){
                cout<<(n-x)<<" ";
            }
            cout<<ansid+1<<" ";
        }else{
            cout<<0<<"\n";
        }
        cout<<endl;
    }
}