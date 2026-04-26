class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int l = 1;
        int r = *max_element(piles.begin(),piles.end());
        int res = r; // initialize res to max instead of 0 since minimize condition

        while(l <= r) // binary search loop
        {
            int k = int((l+r) / 2);
            long long hours = 0;
            for(int p : piles)
            {
                //hours += ceil(p/k);
                hours += (p+k-1) / k;
            }
            if(hours <= h)
            {
                res = min(res,k);
                r = k-1;//search left now since rate might be too high
            }
            else
            {
                l = k+1;
            }
        }
        return res;
    }
};
