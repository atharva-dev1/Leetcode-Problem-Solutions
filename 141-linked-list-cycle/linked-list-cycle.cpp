/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
       unordered_set <ListNode*> visit;
       while(head != NULL){
        if (visit.find(head)!= visit.end()){
            return true;
        }
        visit.insert(head);
        head= head-> next;
       }
        return false;
       }
};