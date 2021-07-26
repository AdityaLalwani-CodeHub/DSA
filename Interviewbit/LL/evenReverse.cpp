/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 
//My solution - AC! on one go!
ListNode* Solution::solve(ListNode* A) {
    
    if(A == NULL)   return NULL;
    
    ListNode *Odd = A;
    ListNode *Even = A->next;
    ListNode *currOdd = A;
    ListNode *currEven = A->next;
    while(currOdd != NULL && currEven != NULL)
    {
        currOdd->next = currEven->next;
        if(currEven->next != NULL)
        currEven->next = currEven->next->next;
        
        currOdd = currOdd->next;
        currEven = currEven->next;
    }
    
    //separated even and odd
    
    //reverse the even ones
    ListNode *prevNode = Even;
    ListNode *currNode = (Even != NULL) ? Even->next :  NULL;
    prevNode->next = NULL;
    while(currNode != NULL)
    {
        ListNode *nextNode = currNode->next;
        currNode->next = prevNode;
        prevNode = currNode;
        currNode = nextNode;
    }
    
    //merge even odd ones
    Even = prevNode;    //last node becomes the start node
    
    while(Odd != NULL && Even != NULL)
    {
        ListNode *nextOdd = Odd->next;
        ListNode *nextEven = Even->next;
        Odd->next = Even;
        Even->next = nextOdd;
        Odd = nextOdd;
        Even = nextEven;
    }
    return A;
}
