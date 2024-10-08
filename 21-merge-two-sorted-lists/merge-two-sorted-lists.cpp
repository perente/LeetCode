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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(list1 == nullptr)
        return list2;

        if(list2 == nullptr)
        return list1;

        ListNode* merged = nullptr;

        if(list1->val > list2->val)
        {
            merged = list2;
            merged->next = mergeTwoLists(list1, list2->next);
        }
        else
        {
            merged = list1;
            merged->next = mergeTwoLists(list1->next, list2);
        }
        return merged;
    }
};