#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    ll t;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;
        vector<pair<ll,ll>> V;
        for(int i=0;i<n;i++){
            ll l,r;
            cin>>l>>r;
            V.push_back({l,r});
        }
        sort(V.begin(),V.end());
        ll ind=0;
        priority_queue<ll,vector<ll>,greater<ll>> pq;
        ll x;
        bool bad=false;
        while(ind<n){
            x=V[ind].first;
            pq.push(V[ind].second);
            ind++;
            while(!pq.empty()){
                for(int i=ind;i<n;i++){
                    if(V[i].first<=x){
                        pq.push(V[i].second);
                    }else{
                        ind=i;
                        break;
                    }
                }
                if(V.back().first<=x){
                    ind=n;
                }
                ll valor=pq.top();
                pq.pop();
                if(valor<x){
                    bad=true;
                    break;
                }
                x++;
            }
            if(bad){
                break;
            }
        }
        if(bad){
            cout<<"No\n";
        }else{
            cout<<"Yes\n";
        }
    }
}