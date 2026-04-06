class Solution {
public:
    bool isPalindrome(string s) {
        int n = s.length();
        int l = 0;
        int r = n-1;

        while(l<r)
        {
            //skip Left non alphanumeric
            while(l<r && !isalnum(static_cast<unsigned char>(s[l]))) l++;

            //skip Right non alphanumeric
            while(l<r && !isalnum(static_cast<unsigned char>(s[r]))) r--;

            char cl = static_cast<char>(tolower(static_cast<unsigned char>(s[l])));
            char cr = static_cast<char>(tolower(static_cast<unsigned char>(s[r])));

            if(cl != cr)
            {
                return false;
            }
            l++;
            r--;
        }
        return true; // skipped everything and so positive case
    }
};
