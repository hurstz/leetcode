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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        // Initialize current nodes of both lists
        ListNode* p1 = l1;
        ListNode* p2 = l2;
        
        // Initialize the dummy head of the resulting list
        ListNode dummy(0);
        ListNode* current = &dummy;
        
        // Initialize carry
        int carry = 0;
        
        // Loop through both lists until the end of both
        while (p1 != nullptr || p2 != nullptr) {
            // Get the values from the current nodes of both lists
            int x = (p1 != nullptr) ? p1->val : 0;
            int y = (p2 != nullptr) ? p2->val : 0;
            
            // Calculate the sum of the values and the carry
            int sum = carry + x + y;
            
            // Update the carry for the next step
            carry = sum / 10;
            
            // Create a new node with the digit value of the sum
            current->next = new ListNode(sum % 10);
            
            // Move the current pointer to the next node
            current = current->next;
            
            // Move the list pointers to the next nodes
            if (p1 != nullptr) p1 = p1->next;
            if (p2 != nullptr) p2 = p2->next;
        }
        
        // If there's a carry left after the final step, add a new node with the carry
        if (carry > 0) {
            current->next = new ListNode(carry);
        }
        
        // Return the next node of the dummy head, which is the start of the resulting list
        return dummy.next;
    }
};
