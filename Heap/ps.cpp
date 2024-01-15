#include<bits/stdc++.h>
using namespace std;
template <class T>
class heap{
    public:
        deque<T> v;
        void push(T x){
            v.push_back(x);
            sort(v.begin(),v.end());
        }
        int top(){
            return v.front();
        }
        void pop(){
            v.pop_front();
        }
};
int main()
{
    heap<int> h;
    h.push(10);
    h.push(20);
    h.push(5);
    h.push(3);
    cout<<"top element in heap ="<<h.top();
    h.pop();
    cout<<"top element in heap ="<<h.top();
    return 0;
}
/*
 3 5 10 20
*/