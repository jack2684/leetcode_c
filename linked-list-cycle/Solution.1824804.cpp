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
        if(head == NULL ||
            head->next == NULL ||
            head->next->next == NULL){
            return false;
        }
        
        ListNode *p = head, *q = head;
        while(true){
            p = p->next;
            if(p == NULL)
                return false;
                
            q = q->next;
            if(q == NULL)
                return false;
            q = q->next;
            if(q == NULL)
                return false;
                
            if(p == q)
                return true;
        }
    }
};