class Solution {
public:
    string longestPalindrome(string s) {
        string t = "#";
        for (char c : s) {
            t += c;
            t += '#';
        }
        int n = t.size();
        vector<int> p(n, 0);
        int c = 0;
        int r = 0;
        for(int i=0;i<n;i++){
            if(i<r){
                int mirror = 2*c-i;
                p[i] = min(r-i-1,p[mirror]);

            }
            while (i - p[i] - 1 >= 0 && i + p[i] + 1 < n &&
                t[i - p[i] - 1] == t[i + p[i] + 1]) {
                p[i]++;
            }
            if (i + p[i] + 1 > r) {
                c = i;
                r = i + p[i] + 1;
            }
        }
        int maxLen = 0;
        int center = 0;

        for (int i = 0; i < n; i++) {
            if (p[i] > maxLen) {
                maxLen = p[i];
                center = i;
            }
        }

        int start = (center - maxLen) / 2;
        return s.substr(start, maxLen);

    }
};
