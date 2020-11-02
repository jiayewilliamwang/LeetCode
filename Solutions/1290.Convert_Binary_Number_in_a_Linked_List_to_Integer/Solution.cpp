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
    int getDecimalValue(ListNode* head) {
        int size = 0;
        ListNode* pointer = head;
        while (pointer) {
            size++;
            pointer = pointer->next;
        }
        int res = 0;
        pointer = head;
        while (size--) {
            res += (pointer->val * pow(2, size));
            pointer = pointer->next;
        }
        
        return res;
    }
};
