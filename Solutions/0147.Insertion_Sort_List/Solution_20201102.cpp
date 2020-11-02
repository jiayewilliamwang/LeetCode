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
    ListNode* insertionSortList(ListNode* head) {
        if (!head) {
            return head;
        }
        
        ListNode *res = new ListNode();
        res->val = head->val;
        
        ListNode *pointer = head->next;
        while (pointer) {
            ListNode *newNode = new ListNode(pointer->val);
            if (newNode->val <= res->val) {
                newNode->next = res;
                res = newNode;
            } else {
                ListNode *pointer2 = res;
                while (pointer2->next && pointer2->next->val < newNode->val) {
                    pointer2 = pointer2->next;
                }
                newNode->next = pointer2->next;
                pointer2->next = newNode;
            }
            pointer = pointer->next;
        }
        
        return res;
    }
};
