/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 //my sol
int Solution::solve(ListNode* A, int B) {
    
    int len = 0;
    ListNode *temp = A;
    while(temp != NULL)
    {
        len++;
        temp = temp->next;
    }
    
    int mid = (len/2) + 1;
    
    int index = mid - B;
    
    if(index <= 0)
    return -1;
    
    int i = 1;
    temp = A;
    while(i < index)
    {
        temp = temp->next;
        i++;
    }
    
    return temp->val;
}
