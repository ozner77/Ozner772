#include <bits/stdc++.h>
using namespace std;
#define ll long long
void solve(){
    ll n;
    cin>>n;

    vector<ll> V(n);
    for(int i=0;i<n;i++) cin>>V[i];
    vector<ll> path;
    ll x=V[0];
    while(x>2){
        path.push_back(x);
        if(x%2==0) x/=2;
        else x++;
    }
    ll m=path.size();
    vector<pair<ll,ll>> ord;
    for(int i=0;i<m;i++) ord.push_back({path[i],i});
    sort(ord.begin(),ord.end());
    vector<ll> cost(m,0),to1(m,0),to2(m,0);
    ll first1=0,first2=0;
    if(x==2){
        first2=m;
        first1=m+1;
    }else{
        first1=m;
        first2=m+1;
    }
    ll now1=(x==1?1:2);
    ll now2=(x==2?1:2);
    for(int i=m-1;i>=0;i--){
        to1[i]=now1;
        to2[i]=now2;
        now1++;
        now2++;
    }
    for(int i=0;i<m;i++) cost[i]=i;
    ll ans1=first1;
    ll ans2=first2;
    ll last=0;
    for(int i=1;i<n;i++){
        x=V[i];
        ll steps=0;
        ll pos=-1;
        while(x>2){
            auto it=lower_bound(ord.begin(),ord.end(),make_pair(x,-1LL));
            if(it!=ord.end() && it->first==x){
                pos=it->second;
                break;
            }
            if(x%2==0) x/=2;
            else x++;
            steps++;
        }
        if(pos!=-1){
            ans1+=steps+to1[pos];
            ans2+=steps+to2[pos];
            last=max(last,pos);
            for(int j=last;j<m;j++){
                cost[j]+=steps+(j-pos);
            }
        }
        else{
            if(x==2){
                ans2+=steps;
                ans1+=steps+1;
            }
            else{
                ans1+=steps;
                ans2+=steps+1;
            }
            last=m;
        }
    }
    ll ans=min(ans1,ans2);
    for(int i=last;i<m;i++){
        ans=min(ans,cost[i]);
    }
    cout<<ans<<"\n";
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll t;
    cin>>t;
    while(t--) solve();
}