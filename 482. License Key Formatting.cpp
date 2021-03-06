//https://leetcode.com/problems/license-key-formatting/

class Solution {
public:
    string licenseKeyFormatting(string S, int K) {
        if (S.size() == 0) return {};
        string res;
        int count = 0;
        for (int i = S.size() - 1; i >= 0; --i) {
            if (isalpha(S[i])) {
                if (count == K) {
                    res.push_back('-');
                    count = 0;
                }
                res.push_back(toupper(S[i]));
                ++count;
            } else if (isdigit(S[i])) {
                if (count == K) {
                    res.push_back('-');
                    count = 0;
                }
                res.push_back(S[i]);
                ++count;
            }
        }
        reverse(res.begin(), res.end());
        return res;
    }
};

string stringToString(string input) {
    assert(input.length() >= 2);
    string result;
    for (int i = 1; i < input.length() -1; i++) {
        char currentChar = input[i];
        if (input[i] == '\\') {
            char nextChar = input[i+1];
            switch (nextChar) {
                case '\"': result.push_back('\"'); break;
                case '/' : result.push_back('/'); break;
                case '\\': result.push_back('\\'); break;
                case 'b' : result.push_back('\b'); break;
                case 'f' : result.push_back('\f'); break;
                case 'r' : result.push_back('\r'); break;
                case 'n' : result.push_back('\n'); break;
                case 't' : result.push_back('\t'); break;
                default: break;
            }
            i++;
        } else {
          result.push_back(currentChar);
        }
    }
    return result;
}

int stringToInteger(string input) {
    return stoi(input);
}

int main() {
    string line;
    while (getline(cin, line)) {
        string S = stringToString(line);
        getline(cin, line);
        int K = stringToInteger(line);
        
        string ret = Solution().licenseKeyFormatting(S, K);

        string out = (ret);
        cout << out << endl;
    }
    return 0;
}
