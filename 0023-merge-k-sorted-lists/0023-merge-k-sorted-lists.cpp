class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        auto cmp = [](ListNode* a, ListNode* b) { return a->val > b->val; };
        priority_queue<ListNode*, vector<ListNode*>, decltype(cmp)> min_heap(cmp);

        for (auto l : lists) {
            if (l) min_heap.push(l);
        }

        ListNode dummy(0);
        ListNode* curr = &dummy;

        while (!min_heap.empty()) {
            ListNode* smallest = min_heap.top();
            min_heap.pop();

            curr->next = smallest;
            curr = curr->next;

            if (smallest->next) {
                min_heap.push(smallest->next);
            }
        }        

        return dummy.next;
    }
};