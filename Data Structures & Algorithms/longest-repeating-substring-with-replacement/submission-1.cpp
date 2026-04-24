class Solution {
public:
    int characterReplacement(std::string s, int k) {
        unordered_map<char,int> count;
        int l = 0; int maxf = 0;
        int res = 0;
        for(int r = 0;r<s.size();r++)
        {
            count[s[r]]++;
            
            maxf = max(maxf,count[s[r]]); // get maximum freq

            while((r-l+1) - maxf > k ) // check window validity
            {
                count[s[l]]--; // reduce freq of leftmost element
                l++; // shift window L to right SHRINK
            }
            res = max(res,r-l+1); // store max size of window according to current window

        }
        return res;
    }
};
