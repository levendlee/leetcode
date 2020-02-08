class Solution {
public:
    bool isMonotonic(vector<int>& A) {
        const int n = A.size();
        if (n == 1) return true;
        int increase = A[1] >= A[0];
        int decrease = A[1] <= A[0];
        for (int i = 2; i < n; ++i) {
            increase += A[i] >= A[i-1];
            decrease += A[i] <= A[i-1];
            if (increase != i && decrease != i) return false;
        }
        return true;
    }
};