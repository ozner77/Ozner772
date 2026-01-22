#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    ll t;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;
        vector<ll> V(n,0);
        for(int i=0;i<n;i++){
            cin>>V[n-1-i];
        }
        vector<ll> Prefix,rPrefix;
        Prefix.push_back(0);
        rPrefix.push_back(0);
        for(int i=0;i<n;i++){
            rPrefix.push_back(rPrefix[i]+V[i]);
        }
        reverse(V.begin(),V.end());
        for(int i=0;i<n;i++){
            Prefix.push_back(Prefix[i]+V[i]);
        }


        unordered_map<ll, vector<int>> pos;
        for(int i = 0; i < n; i++){
            pos[V[i]].push_back(i);
        }
        vector<ll> prevl(n,-1),prevr(n,-1);
        for(int i=1;i<n;i++){
            if(V[i]!=V[i-1]){
                prevl[i]=i-1;
            }else{
                prevl[i]=prevl[i-1];
            }
        }
        for(int i=n-2;i>=0;i--){
            if(V[i]!=V[i+1]){
                prevr[i]=i+1;
            }else{
                prevr[i]=prevr[i+1];
            }
        }
        vector<ll> ans(n);
        for(int i=0;i<n;i++){
            auto it1=upper_bound(rPrefix.begin(),rPrefix.end(),V[i]+rPrefix[n-i]);
            ll xd,uwu;
            if(it1!=rPrefix.end()){
                xd=it1-rPrefix.begin();
                xd-=n;
                xd+=i;
            }else{
                xd=100000000000000000;
            }
            auto it2=upper_bound(Prefix.begin(),Prefix.end(),V[i]+Prefix[i+1]);
            if(it2!=Prefix.end()){
                uwu=it2-Prefix.begin();
                uwu-=i;
                uwu--;
            }else{
                uwu=100000000000000000;
            }
            if(uwu!=1 && uwu!=100000000000000000){
                auto &v = pos[V[i+1]];
                int cnt = upper_bound(v.begin(), v.end(),i+uwu)- lower_bound(v.begin(), v.end(), i+1);
                if(cnt==uwu){
                    ll odiotodo=prevr[i+1];
                    if(odiotodo!=-1){
                        uwu=odiotodo-i;
                    }else{
                        uwu=100000000000000000;
                    }
                }
            }
            if(xd!=1 && xd!=100000000000000000){
                auto &v = pos[V[i-1]];
                int cnt = upper_bound(v.begin(), v.end(),i-1)- lower_bound(v.begin(), v.end(), i-xd);
                if(cnt==xd){
                    ll odiotodo=prevl[i-1];
                    if(odiotodo!=-1){
                        xd=i-odiotodo;
                    }else{
                        xd=100000000000000000;
                    }
                }
            }
            ans[i]=min(xd,uwu);
            if(ans[i]==100000000000000000){
                ans[i]=-1;
            }
        }
        for(auto x:ans){
            cout<<x<<" ";
        }
        cout<<"\n";
    }
}
//BASURA DE CODIGO PERO DA AC