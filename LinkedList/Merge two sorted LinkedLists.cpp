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
        if(list1==NULL)return list2;
        if(list2==NULL)return list1;
        ListNode*head=new ListNode();
      

        ListNode*temp1=list1,*temp2=list2;
        ListNode*temp3=head;
        while(temp1!=NULL&&temp2!=NULL)
        {
          if(temp1->val<temp2->val)
          {
            ListNode* newNode=new ListNode(temp1->val);
            temp1=temp1->next;
            temp3->next=newNode;
            temp3=newNode;

          }
          else
          {
            ListNode* newNode=new ListNode(temp2->val);
            temp2=temp2->next;
            temp3->next=newNode;
            temp3=newNode;
          }

        }
        while(temp1!=NULL)
        {
          ListNode* newNode=new ListNode(temp1->val);
            temp1=temp1->next;
            temp3->next=newNode;
            temp3=newNode;
        }
        while(temp2!=NULL)
        {
          ListNode* newNode=new ListNode(temp2->val);
            temp2=temp2->next;
            temp3->next=newNode;
            temp3=newNode;
        }
        return head->next;
    }
};
