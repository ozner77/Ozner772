#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
int main(){
    int n;
    cin>>n;
    vector<pair<ll,ll>> p(n);
    for(auto &i:p)
        cin>>i.first>>i.second;
    ld ans=0;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            ll dx=p[i].first-p[j].first;
            ll dy=p[i].second-p[j].second;
            ld dist=sqrt(dx*dx+dy*dy);
            ans = max(ans, dist);
        }
    }
    cout << fixed << setprecision(10) << ans;
}