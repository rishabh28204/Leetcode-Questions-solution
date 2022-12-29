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
        if(l1==NULL)return l2;
        if(l2==NULL)return l1;
        ListNode*temp1=l1,*temp2=l2,*prev=l1,*prev2=l2;
        int carry=0;
        while(temp1!=NULL&&temp2!=NULL)
        {
              int x=temp1->val+temp2->val+carry;
              if(x>=10){
                carry=1;
                temp1->val=x%10;
                prev=temp1;
                prev2=temp2;
                temp1=temp1->next;
                temp2=temp2->next;

              }
              else
              {
                carry=0;
                 temp1->val=x%10;
                 prev=temp1;
                 prev2=temp2;
                temp1=temp1->next;
                temp2=temp2->next;
              }
        }
        while(temp1!=NULL)
        {
          int x=temp1->val+carry;
           if(x>=10){
                carry=1;
                prev=temp1;
                temp1->val=x%10;
                temp1=temp1->next;
                // temp2=temp2->next;

              }
              else
              {
                carry=0;
                prev=temp1;
                 temp1->val=x%10;
                temp1=temp1->next;
                // temp2=temp2->next;
              }

        }
        while(temp2!=NULL)
        {
           int x=temp2->val+carry;
           if(x>=10){
                carry=1;
                // prev=temp1;
                // temp1->val=x%10;
                ListNode*temp=new ListNode(x%10);
                prev->next=temp;
                prev=temp;
                temp2=temp2->next;

              }
              else
              {
                carry=0;
                // prev=temp1;
                 ListNode*temp=new ListNode(x%10);
                prev->next=temp;
                prev=temp;
                // temp1=temp1->next;
                temp2=temp2->next;
              }
        }
        if(carry!=0){
        ListNode*newNode=new ListNode(carry);
        prev->next=newNode;
        }
        return l1;
    }
};
