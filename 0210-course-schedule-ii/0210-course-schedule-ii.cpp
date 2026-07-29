class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> adjList[numCourses];
        vector<int> indegree(numCourses, 0);
        for(auto edge : prerequisites){
            int u = edge[0];
            int v = edge[1];

            adjList[v].push_back(u);
            indegree[u]++;
        }

        queue<int> q;
        vector<int> ans;
        for(int i=0; i<numCourses; i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }

        while(!q.empty()){
            int node = q.front();
            ans.push_back(node);
            q.pop();

            for(auto neighbour : adjList[node]){
                indegree[neighbour]--;
                if(indegree[neighbour]==0){
                    q.push(neighbour);
                }
            }
        }

        if(ans.size()==numCourses){
            return ans;
        }else{
            return {};
        }
    }
};