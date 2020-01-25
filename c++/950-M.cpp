class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        const int n = deck.size();
        std::sort(deck.begin(), deck.end());
        if (n <= 2) return deck;

        list<int> res;
        res.push_back(deck[n-2]);
        res.push_back(deck[n-1]);
        for (int i = n - 3; i >= 0; --i) {
            res.push_front(res.back());
            res.push_front(deck[i]);
            res.pop_back();
        }

        vector<int> res_vec(res.begin(), res.end());
        return res_vec;
    }
};