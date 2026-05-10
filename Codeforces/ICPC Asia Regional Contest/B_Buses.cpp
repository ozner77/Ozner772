#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n,m,l,v1,v2;
    cin>>n>>m>>l>>v1>>v2;
    vector<ll> val;
    vector<pair<ll,ll>> V;
    for(int i=0;i<n;i++){
        ll s,t;
        cin>>s>>t;
        val.push_back(t*(v1-v2)+v2*s);
        V.push_back({s,val.back()});
    }
    //O(n)
    sort(V.begin(),V.end());
    //O(nlogn)
    vector<ll> prefix;
    ll cur=-1e18;
    for(int i=0;i<V.size();i++){
        cur=max(cur,V[i].second);
        prefix.push_back(cur);
    }
    //O(n)
    for(int i=0;i<m;i++){
        ll p;
        cin>>p;
        ld ans=(ld)(l-p)/(ld)v2;
        auto it = upper_bound(V.begin(), V.end(), make_pair(p, LLONG_MAX));
        if(it != V.begin()){
            --it;
            ll idx =it-V.begin();
            ld can=(ld)prefix[idx];
            can-=(ld)(p*v1);
            can/=(ld)(v1*v2);
            ld newans=ans-can;
            ans=min(ans,newans);
        }
        cout << fixed << setprecision(10) << ans << "\n";
    }
}