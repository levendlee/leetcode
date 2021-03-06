// 932 Beautiful Array
// https://leetcode.com/problems/beautiful-array

// version: 1; create time: 2019-12-18 22:37:49;
class Solution {
public:

    vector<int> beautifulArray(int N) {
        vector<int> res = {1};
        while (res.size() < N) {
            vector<int> tmp;
            for (int i : res) {
                if (2 * i - 1 <= N) {
                    tmp.push_back(2 * i - 1);
                }
            }
            for (int i : res) {
                if (2 * i <= N)  {
                    tmp.push_back(2 * i);
                }
            }
            res = std::move(tmp);
        }
        return res;
    }
};
