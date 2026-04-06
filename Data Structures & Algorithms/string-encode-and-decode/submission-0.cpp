class Solution {
public:

    string encode(vector<string>& strs) {
        if(strs.empty())
        {
            return "";
        }
        vector<int> sizes;
        string res = "";
        for(string s:strs)
        {
            sizes.push_back(s.size());
        }
        for(int sz: sizes)
        {
            res += to_string(sz) + ",";
        }
        res += "#";
        for(string sn:strs)
        {
            res+=sn;
        }
        return res;
    }

    vector<string> decode(string s) {
        if(s.empty())
        {
            return {};
        }
        vector<int> sizes;
        vector<string> strings;
        int i = 0;
        while(s[i] != '#')
        {
            string cursor = "";
            while(s[i] != ',')
            {
                cursor += s[i];
                i++;
            }
            sizes.push_back(stoi(cursor));
            i++;
        }
        i++;
        for(int sz:sizes)
        {
            strings.push_back(s.substr(i,sz));
            i+=sz;
        }
        return strings;

    }
};
