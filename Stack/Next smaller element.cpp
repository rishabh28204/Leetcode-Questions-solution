// https://www.interviewbit.com/problems/nearest-smaller-element/

vector<int> Solution::prevSmaller(vector<int> &arr) {
     stack<int> st;
    st.push(-1);
    vector<int> ans;
    int n=arr.size();
    for(int i=0;i<n;i++)
    {
        if(st.top()<arr[i])
        {
            ans.push_back(st.top());
            st.push(arr[i]);
        }
        else
        {
            while(st.top()>=arr[i])
            {
                st.pop();
            }
            ans.push_back(st.top());
            st.push(arr[i]);
        }
    }
//    reverse(ans.begin(),ans.end());
    return ans;
}
