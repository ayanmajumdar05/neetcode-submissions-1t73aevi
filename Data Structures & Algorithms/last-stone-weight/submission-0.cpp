class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        //vector<int> maxHeap = make_heap(stones.begin(),stones.end());
        priority_queue<int> maxHeap(stones.begin(),stones.end());

        int a,b;
        int n = maxHeap.size();
        while(true)
        {
            n = maxHeap.size();
            if(n == 0)
            {
                return 0;
            }
            else if(n == 1)
            {
                return maxHeap.top();
            }
            else
            {
                a = maxHeap.top(); // take highest element
                maxHeap.pop();
                b = maxHeap.top(); // take second highest element
                maxHeap.pop();
                // remove both one by one and then compare
                if(a == b)
                {
                    continue;
                }
                else
                {
                    maxHeap.push(a-b);
                }
            }
                
        }
    }
};
