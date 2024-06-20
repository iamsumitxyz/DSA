#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <set>
#include <limits>
using namespace std;
void solve(vector<vector<int>>&cost,int &ans,int curr,set<int>&S,int &value){
        S.insert(curr);
        if (S.size() == cost.size()){
            
            ans = min(ans,value+cost[curr][0]);
            return;
        }
        for(int i = 0;i<cost.size();i++){
            if (i != curr && !S.count(i)){
                value += cost[curr][i];
                S.insert(i);
                solve(cost,ans,i,S,value);
                value-=cost[curr][i];
                S.erase(i);

            }
        }
}


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */ 
    int t;
    cin>>t;  
    while(t--){
        int n;
        cin>>n;
        vector<vector<int>>cost(n,vector<int>(n));

        for(int i = 0;i<n;i++){
            for(int j = 0;j<n;j++){
                cin>>cost[i][j];
            }
        }
        int ans = INT_MAX;
        int curr = 0;
        int value_each =0;
        set<int>s;
        solve(cost,ans,curr,s,value_each);
        cout<<ans<<"\n";
    }
    
    return 0;
}
