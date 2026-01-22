#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    long long maximizeSquareArea(int m, int n, vector<int>& hFences, vector<int>& vFences) {
        long long ans=-1;
        int MOD=1e9+7;
        hFences.push_back(m);
        vFences.push_back(n);
        hFences.push_back(1);
        vFences.push_back(1);
        for(int i=0;i<hFences.size();i++){
            hFences[i]--;
        }
        for(int i=0;i<vFences.size();i++){
            vFences[i]--;
        }
        sort(hFences.begin(),hFences.end());
        sort(vFences.begin(),vFences.end());
        vector<int> V1,V2;
        for(int i=1;i<hFences.size();i++){
            for(int j=0;j<i;j++){
                V1.push_back(hFences[i]-hFences[j]);
            }
        }
        for(int i=1;i<vFences.size();i++){
            for(int j=0;j<i;j++){
                V2.push_back(vFences[i]-vFences[j]);
            }
        }
        sort(V1.rbegin(),V1.rend());
        unordered_set<int> S(V2.begin(), V2.end());
        for(auto x:V1){
            if(S.count(x)!=0){
                long long uwu=x;
                ans=(uwu%MOD)*(uwu%MOD);
                ans%=MOD;
                break;
            }
        }
        return  ans;
    }
};