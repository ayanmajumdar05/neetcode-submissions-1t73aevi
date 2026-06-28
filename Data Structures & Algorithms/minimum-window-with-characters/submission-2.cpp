class Solution {
public:
    string minWindow(string s, string t) {
        
        if(t == "") return ""; // edge case where required string is empty
        int n = s.size();
        unordered_map<char,int> countT; // store required elements and their frequency
        for(char c:t)
        {
            countT[c]++;
        }
        unordered_map<char,int> window; // store the frequencies of elements present in the current window
        int have = 0;
        int need = countT.size();

        pair<int,int> res = {-1,-1}; // store indices of L and R for min window output
        int resLen = INT_MAX; // initialize resLen as maximum possible to minimize later
        int l = 0;
        //int r = 0;
        for(int r = 0;r<n;r++)
        {
            char c = s[r];
            window[c]++;
            if(countT.count(c) && window[c] == countT[c]) //when number of one required element is present increase have count
            {
                have++;
            }
            while(have == need) // satisfactory window case -> start minimization
            {
                if((r-l +1) < resLen) // new min window found which is smaller than currently known resLen
                {
                    resLen = r-l + 1;
                    res = {l,r};
                }
                window[s[l]]--; // reduce window from left
                if(countT.count(s[l]) && window[s[l]] < countT[s[l]]) // if required element is removed from window while shrinking reduce have count
                {
                    have--;
                }
                l++;
            }
        }
        return resLen == INT_MAX ? "" : s.substr(res.first,resLen);


    }
};
