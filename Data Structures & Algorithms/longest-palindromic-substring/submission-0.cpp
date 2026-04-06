class Solution {
public:
    string longestPalindrome(string s) {

        string res = "";
        int resLen = 0;
        if(s.length() <= 1) // single character edgecase early exit
        {
            return s;
        }
        for (int i = 0; i < s.length();i++)
        {
            // for Odd case
            int l = i;
            int r = i;

            while(l>=0 && r<s.length() && s[l] == s[r])
            {
                if((r-l + 1) > resLen)
                {
                    res = s.substr(l,r-l+1);
                    resLen = r - l + 1;
                }
                l--;
                r++;
            }

            // for even case;
            l = i;
            r = i+1;
            while(l>=0 && r<s.length() && s[l] == s[r])
            {
                if((r-l + 1) > resLen)
                {
                    res = s.substr(l,r-l+1);
                    resLen = r - l + 1;
                }
                l--;
                r++;
            }
        }
        return res;
        
    }
};
