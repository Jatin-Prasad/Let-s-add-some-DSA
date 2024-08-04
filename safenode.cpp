class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n  = graph.size();
        vector<int>indegree(n,0);
        vector<vector<int>>adjrev(n);
       //kuch nhi bs sb ke connection reverse kr diya 
        for(int i = 0 ;i< n;i++)
        {
            for(auto it : graph[i]){
                adjrev[it].push_back(i);
                indegree[i]++;

            }
        }
        //step 0 indegree walo ko daal do queue mai
        queue<int>q;
        for(int i =0 ;i<n;i++)
        {
            if(indegree[i]==0)
             q.push(i);
        }
        vector<int> safenode;
        //bfs
        while(!q.empty())
        {
        int node=q.front();
        q.pop();
        safenode.push_back(node);

        for(auto it: adjrev[node])
        {
            indegree[it]--;
            if(indegree[it]==0)q.push(it);

        }


        }

    sort(safenode.begin(),safenode.end());
    return safenode;

    }
};
