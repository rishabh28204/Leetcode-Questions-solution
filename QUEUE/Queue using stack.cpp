class MyQueue {
  stack<int> st;
  int x;
public:
    MyQueue() {
        x=0;
    }
    
    void push(int x) {
        pushhelper(x);
    }
    void pushhelper(int x)
    {
      if(st.size()==0){
      st.push(x);
      return;}
      int data=st.top();
      st.pop();
      pushhelper(x);
      st.push(data);
      return;
    }
    
    int pop() {
        int x=st.top();
        st.pop();
        return x;
    }
    
    int peek() {
        return st.top();
    }
    
    bool empty() {
        return st.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
