class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        if(edges.size() != n-1)
        {
            return false; // number of edges is greater than n-1
        }

        vector<vector<int>> adj(n);
        for(const auto& edge: edges) // add all node's adjacencies
        {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        unordered_set<int> visited;
        if(!dfs(0,-1,visited,adj))
        {
            return false;
        }

        return visited.size() == n;

    }
    bool dfs(int node,int parent, unordered_set<int>& visited,vector<vector<int>>& adj)
    {
        if(visited.count(node))
        {
            return false; // already visited element is found
        }
        visited.insert(node);
        for(int nei:adj[node])
        {
            if(nei == parent)
            {
                continue; // neighbouring node is checked
            }
            if(!dfs(nei,node,visited,adj))
            {
                return false;
            }
        }
        return true;
    }
};
