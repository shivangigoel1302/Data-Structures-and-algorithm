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
    ListNode* merge(ListNode* a, ListNode* b){
        if(a== NULL){
            return b;
        }
        if(b == NULL){
            return a;
        }
        if(a->val <= b->val){
            a->next = merge(a->next,b);
            return a;
        }
        else{
            b->next = merge(a,b->next);
            return b;
        }

    }
    ListNode* findmid(ListNode* head){
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast && fast->next && fast->next->next != NULL){
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
    ListNode* mergesort(ListNode* a){
        if( a == NULL || a->next == NULL){
            return a;
        }
        ListNode* mid = findmid(a);
        ListNode* b = mid->next;
        mid->next = NULL;
        a = mergesort(a);
        b = mergesort(b);
        ListNode* c = merge(a,b);
        return c;
    }
    ListNode* sortList(ListNode* head) {
        head = mergesort(head);
        return head;
    }
};
