class Solution {
public:
    int maxArea(vector<int>& heights) {
        int n = heights.size();
        int l=0,r = n-1;
        vector<int> res(n);
        int val = 0;
        for(int i=0;i<n;i++)
        {
            if(l<r){
                if((min(heights[l],heights[r]) * abs(r-l) ) > val)// new maximum is found then change in val
                {
                    val = (min(heights[l],heights[r]) * abs(r-l)) ;
                }
                if(heights[l]>heights[r]) // left bigger than right shift right pointer
                {
                    r--;
                }
                else // right bigger than left shift left pointer
                {
                    l++;
                }
            }
        }
        return val;
        
    }
};
