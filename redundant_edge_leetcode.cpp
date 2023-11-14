#include<bits/stdc++.h>
using namespace std;
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        vector<pair<int,int>>adj[n];
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                int x1 = points[i][0];
                int y1 = points[i][1];
                int x2 = points[j][0];
                int y2 = points[j][1];
                int dist = abs(x1-x2)+ abs(y1-y2);
                adj[i].push_back({j,dist});
                adj[j].push_back({i,dist});
            }
        }
        // for(int i=0;i<n;i++){
        //     for(auto it : adj[i]){
        //         cout<<i<<" -> "<<it.first<<" "<<it.second<<endl;
        //     }
        // }
        vector<int>vis(n,0);
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> q;
        // {dist , node}
        q.push({0,0});
        vis[0] = 1;
        int sum = 0;
        while(!q.empty()){
            auto it = q.top();
            q.pop();
            int node = it.second;
            int dist = it.first;
            vis[node] = 1;
            sum += dist;
            for(auto nei : adj[node]){
                int neiNode = nei.second;
                int neiDis = nei.first;
                if(vis[neiNode] == 0){
                    q.push({neiDis , neiNode});
                }

            }
        }
        return sum;
    }
int main(){
    vector<vector<int>> points = {{0,0},{2,2},{3,10},{5,2},{7,0}};
    cout<<minCostConnectPoints(points)<<endl;
    
    return 0;
}