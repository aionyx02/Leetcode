class Solution {
public:
    int longestBalanced(vector<int>& nums) {
        int n = nums.size();

        struct Node {
            int mn, mx, lazy;

            void apply(int x) {
                mn += x;
                mx += x;
                lazy += x;
            }
        }tree[(n + 1) * 4 + 20];

        auto merge = [&](Node nl, Node nr) {
            return Node {
                min(nl.mn, nr.mn),
                max(nl.mx, nr.mx),
                0
            };
        };

        auto build = [&](this auto &&build, int id, int l, int r) -> void{
            if (l == r) tree[id] = Node {0, 0, 0};
            else{
                int nxt = id << 1, mid = (l + r) >> 1;
                build(nxt, l, mid); build(nxt | 1, mid + 1, r);
                tree[id] = merge(tree[nxt], tree[nxt | 1]);
            }
        };

        auto down = [&](int id) {
            if (tree[id].lazy == 0) return;
            int nxt = id << 1;
            tree[nxt].apply(tree[id].lazy);
            tree[nxt | 1].apply(tree[id].lazy);
            tree[id].lazy = 0;
        };

        auto modify = [&](this auto &&modify, int id, int l, int r, int ql, int qr, int qv) -> void {
            if (ql <= l && r <= qr) tree[id].apply(qv);
            else {
                down(id);
                int nxt = id << 1, mid = (l + r) >> 1;
                if (ql <= mid) modify(nxt, l, mid, ql, qr, qv);
                if (qr > mid) modify(nxt | 1, mid + 1, r, ql, qr, qv);
                tree[id]  =merge(tree[nxt], tree[nxt | 1]);
            }
        };

        auto query = [&](this auto &&query, int id, int l, int r, int qv) -> int {
            if (l == r) return l;
            down(id);
            int nxt = id << 1, mid = (l + r) >> 1;
            if (tree[nxt].mn <= qv && qv <= tree[nxt].mx) return query(nxt, l, mid, qv);
            return query(nxt | 1, mid + 1, r, qv);
        };

        build(1, 0, n);
        int ans = 0, now = 0;
        unordered_map<int, int> mp;
        for (int i = 1; i <= n; i++) {
            int x = nums[i - 1];
            int det = (x & 1 ? 1: -1);
            if (mp.count(x)) {
                modify(1, 0, n, mp[x], n, -det);
                now -= det;
            }

            mp[x] = i;
            modify(1, 0, n, i, n, det);
            now += det;
            int pos = query(1, 0, n, now);
            ans = max(ans, i - pos);
        }
        return ans;
    }
};