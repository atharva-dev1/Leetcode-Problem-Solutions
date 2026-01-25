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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        vector<int> values;
        while (list1) {
            values.push_back(list1->val);
            list1 = list1->next;
        }
        while (list2) {
            values.push_back(list2->val);
            list2 = list2->next;
        }
        sort(values.begin(), values.end());
        ListNode* dummy = new ListNode();
        ListNode* current = dummy;

        for(int val : values){
            current-> next = new ListNode(val);
            current = current -> next;       
             }
        return dummy-> next;
    }
};