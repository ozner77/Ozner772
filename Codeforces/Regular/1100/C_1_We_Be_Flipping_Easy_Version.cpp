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
        for(int i=0;i<n;i++){
            ll a;
            cin>>a;
            V.push_back(a);
        }
        reverse(V.begin(),V.end());
        vector<ll> ans;
        bool swapped=false;
        for(int i=0;i<n;i++){
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
        cout<<ans.size()<<"\n";
        for(auto x:ans){
            cout<<(n-x)<<" ";
        }
        cout<<endl;
    }    
}