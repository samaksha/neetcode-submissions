using namespace std;

class MinStack {
public:
    vector<int> stack;
    vector<int> mins;

    MinStack() {
    }
    
    void push(int val) {
        if(stack.size() == 0 || mins.back() >= val) {
            mins.push_back(val);
        }
        stack.push_back(val);
    }
    
    void pop() {
        int last = stack.back();
        stack.pop_back();
        if(last == mins.back()) {
            mins.pop_back();
        }
    }
    
    int top() {
        return stack.back();
    }
    
    int getMin() {
        return mins.back();
    }
};
