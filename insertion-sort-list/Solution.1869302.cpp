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
    ListNode *insertionSortList(ListNode *head) {
        if(!head) return NULL;
        ListNode *root, *p0, *tmp;
        root = new ListNode(0);
        while(head){
            p0 = root;
            while(p0->next && p0->next->val <= head->val)
                p0 = p0->next;
            tmp = head;
            head = head->next;
            tmp->next = p0->next;
            p0->next = tmp;
        }
        tmp = root;
        root = root->next;
        delete tmp;
        return root;
    }
};

/*
申明多个指针时总时，后面几个变量总是忘了指针符号
*/