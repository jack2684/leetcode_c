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
    ListNode *sortList(ListNode *head) {
        if(!head) return NULL;
        if(!head->next) return head;

        // make two linked lists
        ListNode *preMid, *head2;
        preMid = findPreMid(head);
        head2 = preMid->next;
        preMid->next = NULL;
        
        // sort separately
        head = sortList(head);
        head2 = sortList(head2);
        
        // merge them
        return mergeSortedList(head, head2);
    }
    
    ListNode *findPreMid(ListNode *head){
        ListNode *fast, *slow, *preSlow;
        preSlow = slow = fast = head;
        while(slow && fast && fast->next){
            preSlow = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        return preSlow;
    }
    
    ListNode *mergeSortedList(ListNode *left, ListNode *right){
        if(!left && !right) return NULL;
        if(!left) return right;
        if(!right) return left;
        
        ListNode *head = NULL, *p0;
        while(left && right){
            if(left->val <= right->val){
                if(!head){
                    head = p0 = left;
                }else{
                    p0->next = left;
                    p0 = left;
                }
                left = left->next;
            }else{
                if(!head){
                    head = p0 = right;
                }else{
                    p0->next = right;
                    p0 = right;
                }
                right = right->next;
            }
        }
        if(left)
            p0->next = left;
        if(right)
            p0->next = right;
            
        return head;
    }
};

/*
if you want to modify a pointer, you should either use reference, like int *&a,
or use return. CAREFUL!
it is easier to operate a link list by disconnecting it first
*/