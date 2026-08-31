/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        vector<int> indices;
        if (!head || !head->next || !head->next->next)
            return {-1, -1};

        ListNode* prev = head;
        ListNode* current = head->next;
        ListNode* nxt = current->next;
        int idx = 1;

        while (nxt != nullptr) {
            if ((current->val > prev->val && current->val > nxt->val) || 
                (current->val < prev->val && current->val < nxt->val)) {
                indices.push_back(idx);
            }
            
            prev = current;
            current = nxt;
            nxt = nxt->next;
            ++idx;
        }

        if (indices.size() < 2) {
            return {-1, -1};
        }

        int max_diff = indices.back() - indices.front();

        int min_diff = INT_MAX;
        for (size_t i = 1; i < indices.size(); ++i) {
            min_diff = min(min_diff, indices[i] - indices[i - 1]);
        }

        return {min_diff, max_diff};
    }
};