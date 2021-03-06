// 946 Validate Stack Sequences
// https://leetcode.com/problems/validate-stack-sequences

// version: 1; create time: 2020-01-26 16:24:01;
class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        if (pushed.size() != popped.size()) return false;
        const int n = pushed.size();
        if (n == 0) return true;

        std::stack<int> stk;
        int i = 0, j = 0;
        while (i < n || j < n) {
            if (stk.empty() || stk.top() != popped[j]) {
                if (i >= n) {
                    return false;
                }
                stk.push(pushed[i++]);
            } else {
                stk.pop();
                ++j;
                if (!stk.empty() && j >= n) {
                    return false;
                }
            }
        }
        return true;
    }
};
