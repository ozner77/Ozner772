#include <bits/stdc++.h>
using namespace std;
#define ll long long
vector<bool> taken;
priority_queue<pair<ll,ll>> pq;
vector<ll> V;
ll ind=0;
int main(){
    ll n;
    cin>>n;
    taken.assign(n,false);
    priority_queue <ll,vector<ll>,greater<ll>> pq;
    for(int i=0;i<n;i++){
        ll a;
        cin>>a;
        pq.push(a);
        if(i%2==1){
            pq.pop();
        }
    }
    ll ans=0;
    while(!pq.empty()){
        ans+=pq.top();
        pq.pop();
    }
    cout<<ans;
}