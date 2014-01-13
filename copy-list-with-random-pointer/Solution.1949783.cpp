/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        if(!head) return NULL;
        
        unordered_map<RandomListNode*, RandomListNode*> old2new;
        RandomListNode *p0 = head, *prev = new RandomListNode(p0->label), *curr;
        old2new[head] = prev;
        while(p0->next){
            p0 = p0->next;
            curr = new RandomListNode(p0->label);
            prev->next = curr;
            prev = curr;
            old2new[p0] = curr;
        }
        
        p0 = head;
        while(p0){
            old2new[p0]->random = old2new[p0->random];
            p0 = p0->next;
        }
        
        return old2new[head];
    }
};