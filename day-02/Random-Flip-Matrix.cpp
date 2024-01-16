class Solution {
    std::unordered_set<int> usedSet;
    int rows;
    int cols;
    int total;
public:
    Solution(int n_rows, int n_cols)
        : rows(n_rows), cols(n_cols), total(n_rows * n_cols) {}

    std::vector<int> flip() {
        if (usedSet.size() == total)
            return {};
        int index = rand() % total;
        while (usedSet.count(index))
            index = ++index % total;
        usedSet.insert(index);
        return {index / cols, index % cols};
    }

    void reset() {
        usedSet.clear();
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(m, n);
 * vector<int> param_1 = obj->flip();
 * obj->reset();
 */