class Solution {
public:
    struct Node {
        int len;
        int max_len;
        int prefix_len;
        int suffix_len;
        char left_char;
        char right_char;
    };
    Node combine(Node L, Node R) {
        Node P;
        P.len = L.len + R.len;
        P.left_char = L.left_char;
        P.right_char = R.right_char;

        P.prefix_len = L.prefix_len;
        if (L.prefix_len == L.len && L.right_char == R.left_char)
            P.prefix_len += R.prefix_len;

        P.suffix_len = R.suffix_len;

        if (R.suffix_len == R.len && L.right_char == R.left_char)
            P.suffix_len += L.suffix_len;

        P.max_len = max({L.max_len, R.max_len, 0});
        if (L.right_char == R.left_char) {
            P.max_len = max(P.max_len, L.suffix_len + R.prefix_len);
        }
        return P;
    }
    vector<Node> tree;
    void build(int node, int l, int r, const string& s) {
        if (l == r) {
            tree[node] = {1, 1, 1, 1, s[l], s[l]};
            return;
        }

        int mid = l + (r - l) / 2;
        build(2 * node, l, mid, s);
        build(2 * node + 1, mid + 1, r, s);
        tree[node] = combine(tree[2 * node], tree[2 * node + 1]);
    }

    void update(int node, int l, int r, int idx, char ch) {
        if (l == r) {
            tree[node] = {1, 1, 1, 1, ch, ch};
            return;
        }
        int mid = l + (r - l) / 2;

        if (idx <= mid) {
            update(2 * node, l, mid, idx, ch);
        }
        else {
            update(2 * node + 1, mid + 1, r, idx, ch);
        }

        tree[node] = combine(tree[2 * node], tree[2 * node + 1]);
    }
    vector<int> longestRepeating(string s, string queryCharacters, vector<int>& queryIndices) {
        int n = s.size();
        tree.resize(4 * n);

        build(1, 0, n - 1, s);

        vector<int> ans;
        int k = queryIndices.size();

        for (int i = 0; i < k; ++i) {
            update(1, 0, n - 1, queryIndices[i], queryCharacters[i]);

            ans.push_back(tree[1].max_len);
        }

        return ans;
    }
};