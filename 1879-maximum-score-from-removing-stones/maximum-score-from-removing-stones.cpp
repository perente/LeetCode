//Rampia Perente

class Solution {
public:
    int maximumScore(int a, int b, int c) {
        priority_queue<int> max_heap;
        max_heap.push(a);
        max_heap.push(b);
        max_heap.push(c);

        int score = 0;

        while(max_heap.size() > 1)
        {
            int first = max_heap.top();
            max_heap.pop();
            int second = max_heap.top();
            max_heap.pop();

            if(first == 0 || second == 0)
            break;

            first--;
            second--;
            score++;

            max_heap.push(first);
            max_heap.push(second);
        }
        return score;
    }
};