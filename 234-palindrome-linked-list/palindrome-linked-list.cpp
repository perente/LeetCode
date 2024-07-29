//Rampia Perente

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
    bool isPalindrome(ListNode* head) {
        stack<int> paldom;
        ListNode* current = head;

        while(current != NULL)
        {
            paldom.push(current->val);
            current = current->next;
        }

        current = head;
        while(current != NULL)
        {
            if(current->val != paldom.top())
            return false;

            paldom.pop();
            current = current->next;
        }
        return true;
    }
};