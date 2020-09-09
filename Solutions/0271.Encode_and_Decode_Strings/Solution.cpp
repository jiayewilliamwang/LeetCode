class Codec {
public:

    // Encodes a list of strings to a single string.
    string encode(vector<string>& strs) {
        string res = "";
        for (string str: strs) 
            res += to_string(str.size()) + "#" + str;
        return res;
    }

    // Decodes a single string to a list of strings.
    vector<string> decode(string s) {
        vector<string> res;
        int i = 0, n = s.size();
        while (i < n) {
            int cur_size = 0;
            while (s[i] != '#')
                cur_size = cur_size * 10 + (s[i++] - '0');
            res.push_back(s.substr(++i, cur_size));
            i += cur_size;
        }
        return res;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.decode(codec.encode(strs));
