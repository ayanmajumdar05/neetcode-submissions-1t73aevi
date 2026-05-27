class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        
        priority_queue<pair<int, pair<int,int>>> maxHeap;

        for(auto& point: points) // add pair of distance and points into maxHeap
        {
            int dist = point[0] * point[0] + point[1] * point[1];
            maxHeap.push({dist, {point[0],point[1]} });
            if(maxHeap.size() > k)
            {
                maxHeap.pop();
            }
        }
        vector<vector<int>> res;
        while(!maxHeap.empty()) // inserting pair of points indices into result array 
        {
            res.push_back({maxHeap.top().second.first,
                            maxHeap.top().second.second});
            maxHeap.pop();
        }
        return res;


    }
};
