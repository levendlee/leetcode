// Segment Tree -> Array Implementation
int constructSegmentTree(std::vector<int>& st, const std::vector<int>& nums, int begin, int end, int idx) {
    if ( st.size() <= idx ) st.resize( idx + 1 );
    if ( begin == end ) return st[idx] = nums[begin];
    int mid = begin + (end - begin) / 2;
    st[idx] = constructSegmentTree(st, nums, begin, mid, 2*idx+1 ) + \
        constructSegmentTree(st, nums, mid+1, end, 2*idx+2 );
    return st[idx];
}

void updateSegmentTree(std::vector<int>& st, int begin, int end, int idx, int target, int diff) {
    if ( target < begin || target > end ) return;
    int mid = begin + (end - begin) / 2;
    st[idx] += diff;
    if ( begin == end ) return;
    updateSegmentTree(st, begin, mid, 2*idx+1, target, diff);
    updateSegmentTree(st, mid+1, end, 2*idx+2, target, diff);
}

int querySegmentTree(std::vector<int>& st, int begin, int end, const int qbegin, const int qend, int idx) {
    if ( qend < begin || qbegin > end ) return 0;
    if ( (begin >= qbegin) && (end <= qend) ) {
        return st[idx];
    }
    int mid = begin + (end - begin) / 2;
    int res = querySegmentTree(st, begin, mid, qbegin, qend, 2*idx+1) + \
        querySegmentTree(st, mid+1, end, qbegin, qend, 2*idx+2);
    return res;
}

class NumArray {
private:
    std::vector<int> nums_;
    std::vector<int> segment_tree_;
public:
    NumArray(vector<int>& nums) : nums_(nums) {
        if ( !nums.empty() )
            constructSegmentTree(segment_tree_, nums_, 0, nums_.size()-1, 0 );
    }
    
    void update(int i, int val) {
        int diff = val - nums_[i];
        updateSegmentTree(segment_tree_, 0, nums_.size()-1, 0, i, diff);
        nums_[i] = val;
    }
    
    int sumRange(int i, int j) {
        return querySegmentTree(segment_tree_, 0, nums_.size()-1, i, j, 0);
    }
};
