// 225. Implement Stack using Queues
// url : https://leetcode.com/problems/implement-stack-using-queues/
class MyStack {
public:
    deque<int> q1;
    MyStack() {

    }
    
    void push(int x) {
        q1.push_back(x);
        for(int i=0;i<q1.size()-1;i++){
            q1.push_back(q1.front());
            q1.pop_front();
        }
    }
    
    int pop() {
        int d=q1.front();
        q1.pop_front();
        return d;
    }
    
    int top() {
        return q1.front();
    }
    
    bool empty() {
        return q1.empty();
    }
};
