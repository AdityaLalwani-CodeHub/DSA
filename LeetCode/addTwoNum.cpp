/*
Add Two Numbers II

You are given two non-empty linked lists representing two non-negative integers. The most significant digit comes first and each of their nodes contains a single digit. Add the two numbers and return the sum as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.

 

Example 1:


Input: l1 = [7,2,4,3], l2 = [5,6,4]
Output: [7,8,0,7]
Example 2:

Input: l1 = [2,4,3], l2 = [5,6,4]
Output: [8,0,7]
Example 3:

Input: l1 = [0], l2 = [0]
Output: [0]
 

Constraints:

The number of nodes in each linked list is in the range [1, 100].
0 <= Node.val <= 9
It is guaranteed that the list represents a number that does not have leading zeros.
 

Follow up: Could you solve it without reversing the input lists?
*/

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
    
    ListNode* reverseList(ListNode *head)
    {
        ListNode *currNode = head;
        ListNode *prevNode = NULL;
        while(currNode != NULL)
        {
            ListNode *nextNode = currNode->next;
            currNode->next = prevNode;
            prevNode = currNode;
            currNode = nextNode;
        }
        return prevNode;
    }
    
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        l1 = reverseList(l1);
        l2 = reverseList(l2);
        
        ListNode *l3 = new ListNode();
        ListNode *temp = l3;
        
        int carry = 0;
        while(l1 != NULL || l2 != NULL)
        {
            int a = (l1 != NULL) ? l1->val : 0;
            int b = (l2 != NULL) ? l2->val : 0;
            int sum = a + b + carry;
            
            ListNode *newNode = new ListNode(sum%10);
            carry = sum / 10;
            temp->next = newNode;
            temp = newNode;
            
            if(l1 != NULL) l1 = l1->next;
            if(l2 != NULL) l2 = l2->next;
        }
        
        if(carry > 0)
        {
            ListNode *newNode = new ListNode(carry);
            temp->next = newNode;
        }
        
        return reverseList(l3->next);
    }
};