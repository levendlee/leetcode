class Solution {
public:
    bool checkRecord(string s) {
        const int n = s.size();
        int cnt_a = 0, cnt_l = 0;
        for (int i = 0; i < n; ++i) {
            if (s[i] == 'A') {
                cnt_a += 1;
                if (cnt_a > 1) {
                    return false;
                }
            }
            if (s[i] == 'L') {
                cnt_l += 1;
                if (cnt_l > 2) {
                    return false;
                }
            } else {
                cnt_l = 0;
            }
        }
        return true;
    }
};