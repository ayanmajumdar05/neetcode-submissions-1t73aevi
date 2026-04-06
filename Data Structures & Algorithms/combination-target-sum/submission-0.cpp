class Solution {
public:
    vector<vector<int>> res;
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        
        dfs(0,{},0,nums,target);
        return res;
    }

    void dfs(int i, vector<int> cur,int total,vector<int>& nums,int target)
    {
        if(total == target)
        {
            vector<int> cur_copy = cur;
            res.push_back(cur_copy);
            return;
        }
        if((i >= nums.size() ) || (total > target)) // CASES TO SKIP overshot level length or total val is greater than target 
        {
            return;
        }

        nums[i];

        cur.push_back(nums[i]);
        dfs(i, cur, total + nums[i],nums,target); // DO include Candidate
        cur.pop_back();
        dfs(i + 1, cur, total,nums,target);
    }
};
