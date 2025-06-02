#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    bool hasCircularDependency(int n, vector<vector<int>>& edges){
        vector<int> indegree(n, 0);
        vector<int> adj[n];
        for(int i = 0; i < edges.size(); i++){
            int u = edges[i][1];
            int v = edges[i][0];
            if(u == v) return true;           // self-loop is a cycle
            indegree[v]++;
            adj[u].push_back(v);
        }
        
        int cnt = 0;
        queue<int> q;
        for(int i = 0; i < n; i++){
            if(indegree[i] == 0) q.push(i);
        }
        
        while(!q.empty()){
            int current = q.front();
            q.pop();
            cnt++;
            for(auto next : adj[current]){
                indegree[next]--;
                if(indegree[next] == 0) q.push(next);
            }
        }
        
        return cnt != n;  // true if cycle exists
    }
};

int main(){
    int n;
    vector<vector<int>> edges;
    Solution S;
    bool ans = S.hasCircularDependency(n, edges);
    cout << ans << "\n";  // prints 0 for no cycle, 1 if there is a cycle
    return 0;
}
