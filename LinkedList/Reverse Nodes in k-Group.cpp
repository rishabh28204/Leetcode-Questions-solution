// iterative
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
    ListNode* reverseKGroup(ListNode* head, int k) {

        int n=0;
        ListNode*temp=head;
        while(temp!=NULL)
        {
          n++;
          temp=temp->next;
        }
        int f=0;
        ListNode*dummy=new ListNode(0);
        dummy->next=head;
        ListNode*pre=dummy,*curr=head,*next=curr->next;
        while(n>=k)
        {
           curr=pre->next;
            next=curr->next;
              for(int i=0;i<k-1;i++)
              {
                curr->next=next->next;
                next->next=pre->next;
                pre->next=next;
                next=curr->next;
                // cnt++;
              }
              pre=curr;
              n-=k;
        }
        return dummy->next;

    }
};


// recursive code
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
// int f=0;
class Solution {
public:

    ListNode* reverseKGroup(ListNode* head, int k) {  
     if(head==NULL)return NULL;
        
        ListNode*curr=head,*prev=NULL,*next=NULL,*curr2=head;
         ListNode* currCheck = head;
    
    for(int i = 0; i < k; i++)
    {
        if(currCheck == NULL)
            return head;
        
        currCheck = currCheck->next;
    }
        // int count=0,size=0;
        
        // while(curr2!=NULL)
        // {
        //     size++;
        //     curr2=curr2->next;
        // }
        for(int i=0;i<k;i++)
        {
            next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
            // count++;
        }
        // if(next!=NULL)
            head->next=reverseKGroup(curr,k);
        
        return prev;
       
        
        
    }
};
