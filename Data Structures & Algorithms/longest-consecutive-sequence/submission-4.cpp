class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> numSet(nums.begin(),nums.end());
        int maxLength = 0;
        for(int num:numSet)
        {
            if(numSet.count(num-1) == 0)
            {
                int length = 1;
                while(numSet.count(num+length) != 0 )
                {
                    length++;
                }
                maxLength = max(length,maxLength);
            }
        }
        return maxLength;      

        
    }
};
