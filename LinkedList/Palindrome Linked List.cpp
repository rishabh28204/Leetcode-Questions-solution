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
    ListNode*helper(ListNode*head)
    {
      ListNode*curr=head,*prev=NULL,*next=NULL;
      while(curr!=NULL)
      {
        next=curr->next;
        curr->next=prev;
        prev=curr;
        curr=next;
      }
      return prev;
    }
    bool isPalindrome(ListNode* head) {
          if(head==NULL||head->next==NULL)return true;
          
          if(head->next->next==NULL)
          {
            if(head->val==head->next->val)
            return true;
            return false;
          }
        ListNode*fast=head,*slow=head;
        while(fast->next!=NULL&&fast->next->next!=NULL)
        {
          slow=slow->next;
          fast=fast->next->next;
        }
        ListNode*temp=helper(slow->next);
        slow->next=temp;
        slow=slow->next;
        temp=head;
        while(slow!=NULL)
        {
          if(temp->val!=slow->val)
          return false;
          temp=temp->next;
          slow=slow->next;
        }
        
        return true;
        

    }
};
