class Solution {
public:
    int findMin(vector<int> &nums) {
        int res = nums[0];
        int l = 0;
        int r = nums.size() - 1;

        while(l <= r)
        {
            if(nums[l] < nums[r])
            {
                res = min(res,nums[l]);
                break;
            }
            
            int m = (l + r) / 2;
            res = min(res, nums[m]);
            if(nums[m] >= nums[l]) // right portion case
            {
                l = m + 1; // left pointer is right portion's lowest element except mid pointer
            }
            else // left portion case
            {
                r = m - 1; // right pointer is left portion's highest element
            }
        }
        return res;
    }
};
