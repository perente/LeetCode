//Rampia Perente

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> next_greater_element;
        stack<int> st;

        for(int i = nums2.size() - 1; i >= 0; i--)
        {
            int num = nums2[i];
            while(!st.empty() && st.top() <= num)
            st.pop();

            if(st.empty())
            next_greater_element[num] = -1;
            else
            next_greater_element[num] = st.top();

            st.push(num);
        }

        vector<int> answer(nums1.size());
        for(int i = 0; i < nums1.size(); i++)
        answer[i] = next_greater_element[nums1[i]];

        return answer;
    }
};