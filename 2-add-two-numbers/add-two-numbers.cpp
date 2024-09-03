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
    int listSize(ListNode* head)
    {
        int size = 0;
        ListNode* current = head;

        while(current != nullptr)
        {
            size++;
            current = current->next;
        }
        return size;
    }

    ListNode* addZeros(ListNode* head, int zeros)
    {
        ListNode* current = head;
        while(current->next != nullptr)
        current = current->next;

        for(int i = 0; i < zeros; i++)
        {
            current->next = new ListNode(0);
            current = current->next;
        }

        return head;
    }

    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if(l1 == nullptr)
        return l2;
        else if(l2 == nullptr)
        return l1;
        
        int size1 = listSize(l1);
        int size2 = listSize(l2);

        if(size1 > size2)
        l2 = addZeros(l2, size1 - size2);
        else if(size2 > size1)
        l1 = addZeros(l1, size2 - size1);

        ListNode* sum = new ListNode(0);
        ListNode* current = sum;
        int carry = 0;

        while(l1 != nullptr || l2 != nullptr)
        {
            int sum = l1->val + l2->val + carry;
            carry = sum / 10;
            current->next = new ListNode(sum % 10);
            current = current->next;

            l1 = l1->next;
            l2 = l2->next;
        }
        if(carry > 0) 
        current->next = new ListNode(carry);

        return sum->next;
    }
};

//check sizes of lists, if not equal add zeros in reverse order(next)
//basic sum, focus on carry