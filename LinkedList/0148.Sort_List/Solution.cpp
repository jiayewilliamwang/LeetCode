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
    ListNode* sortList(ListNode* head) {
        int n = list_size(head);
        if (!n) {
            return NULL;
        }
        if (n == 1) {
            return head;
        }
        int mid = n / 2;
        ListNode* second_half = head;
        for (int i = 0; i < mid - 1; i++) {
            second_half = second_half->next;
        }
        ListNode* temp = second_half;
        second_half = second_half->next;
        temp->next = NULL;
        
        head = sortList(head);
        second_half = sortList(second_half);
        
        return merge(head, second_half);
    }
    
    int list_size(ListNode* head) {
        ListNode* pointer = head;
        int res = 0;
        while (pointer) {
            res++;
            pointer = pointer->next;
        }
        return res;
    }
    
    ListNode* merge(ListNode* lst1, ListNode* lst2) {
        ListNode* temp = NULL;
        if (!lst1) {
            return lst2;
        } else if (!lst2) {
            return lst1;
        } else if (lst1->val <= lst2->val) {
            temp = lst1;
            temp->next = merge(lst1->next, lst2);
        } else {
            temp = lst2;
            temp->next = merge(lst1, lst2->next);
        }
        return temp;
    }
};
