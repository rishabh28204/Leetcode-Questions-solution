// https://leetcode.com/problems/lru-cache/description/

class LRUCache {
  int cap;
  struct Node{
    int key;
    int data;
    struct Node*prev,*next;
   Node(int x,int y)
    {
      key=x;
      data =y;
      prev=NULL;
      next=NULL;
    }
  };
  unordered_map<int,Node*> mp;
     
        
public:
          Node*head=new Node(0,0);
        Node*tail=new Node(0,0);
       
    LRUCache(int capacity) {
        cap=capacity;
        head->next=tail;
        tail->prev=head;
    }
    Node* createNode(int key,int val)
    {
      Node*newNode=new Node(key,val);
        newNode->next=head->next;
            head->next->prev=newNode;
            head->next=newNode;
            newNode->prev=head;
            return newNode;
    }
    int get(int key) {
      if(mp.find(key)!=mp.end())
      {
          auto it=mp.find(key);
          int ans=it->second->data;
          Node*newNode=createNode(it->second->key,it->second->data);
          deleteNode(it->second);
          mp.erase(key);
          mp[key]=newNode;
          return newNode->data;

      }
      return -1;
    }
    void deleteNode(Node* x)
    {
      Node*temp=x;
      temp->prev->next=temp->next;
      temp->next->prev=temp->prev;
      temp->next=NULL;
      temp->prev=NULL;
      delete temp;
      
    }
    void put(int key, int value) {
       if(mp.find(key)==mp.end())
       {
         if(mp.size()<cap)
         {
            Node*newNode=new Node(key,value);
            newNode->next=head->next;
            head->next->prev=newNode;
            head->next=newNode;
            newNode->prev=head;
            mp[key]=newNode;
          }
          else
          {
              Node*x=tail->prev;
              int y=x->key;
              deleteNode(x);
              mp.erase(y);
              Node*newNode=new Node(key,value);
            newNode->next=head->next;
            head->next->prev=newNode;
            head->next=newNode;
            newNode->prev=head;
            mp[key]=newNode;
          }
       }
       else
       {
         auto it=mp.find(key);
         Node*x=it->second;
              int y=x->key;
              deleteNode(x);
              mp.erase(y);
               Node*newNode=new Node(key,value);
            newNode->next=head->next;
            head->next->prev=newNode;
            head->next=newNode;
            newNode->prev=head;
            mp[key]=newNode;
       } 
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
