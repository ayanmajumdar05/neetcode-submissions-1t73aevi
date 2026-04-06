class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int size = nums.size();
        vector<int> res;
        
        for(int i = 0;i<size;i++)
        {
            int prod = 1;
            for(int j = 0;j<size;j++)
            {
                if(i!= j)
                {
                    prod *= nums[j];
                }
            }
            res.push_back(prod);
        }
        return res;
    }
};
