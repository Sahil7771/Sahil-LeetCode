#include<bits/stdc++.h>
using namespace std;
typedef pair<int,pair<int,int>> ppi;
struct compare{
    bool operator()(ppi below,ppi above){
        return below.second.second > above.second.second;
    }
};
int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<pair<int,int>>adj[n];
        vector<int>dist(n,1e9);
        for(auto it : flights){
            int u = it[0];
            int v = it[1];
            int price = it[2];
            adj[u].push_back({v,price});
        }
        priority_queue<ppi,vector<ppi>,compare> q;
        dist[src] = 0;
        // { price , { node , stops } }
        q.push({0,{src,0}});
        while(!q.empty()){
            auto it = q.top();
            q.pop();
            int priceTillNow = it.first;
            int node = it.second.first;
            int stopsTillNow = it.second.second;
            cout<<node<<"  "<<priceTillNow<<"  "<<  stopsTillNow<<" and dist of dst is "<<dist[dst]<<endl;
            for(auto it :adj[node]){
                int neighNode = it.first;
                int price = it.second;
                int stopsNow = stopsTillNow + 1 ;
                if(neighNode == dst){
                    if(priceTillNow + price < dist[neighNode] ){
                        dist[neighNode] = priceTillNow + price;
                    }
                }

                if(stopsNow <= k ){
                    if(priceTillNow + price < dist[neighNode] ){
                        // cout<<node<<" -> "<<neighNode<<"  "<<  stopsNow<<endl;
                        dist[neighNode] = priceTillNow + price;
                        q.push({priceTillNow + price , {neighNode ,stopsNow}});
                    }
                }
            } 
        }
        if(dist[dst] < 1e9) return dist[dst];
        return -1;
}
int main(){
    int n = 11;
    vector<vector<int>>flights ={{0,3,3},{3,4,3},{4,1,3},{0,5,1},{5,1,100},{0,6,2},{6,1,100},{0,7,1},{7,8,1},{8,9,1},{9,1,1},{1,10,1},{10,2,1},{1,2,100}};
    int src =0;
    int dst = 2;
    int k = 4;
    cout<<findCheapestPrice(n,flights,src,dst,k)<<endl;
    return 0;

}