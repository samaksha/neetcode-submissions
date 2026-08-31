using namespace std;

class MinStack {
public:
    vector<long> stack;
    long minimum = 0;

    MinStack() {
    }
    
    void push(int val) {
        if(stack.size() == 0) {
            minimum = val;
            stack.push_back(0);
        }
        else {
            stack.push_back(val - minimum);
            minimum = min(minimum, (long)val);
        }
    }
    
    void pop() {
        long val = stack.back();
        if(val + minimum < minimum) {
            minimum = minimum - val;
        }
        stack.pop_back();   
    }
    
    int top() {
        long val = stack.back();
        if(val + minimum < minimum) {
            return minimum;
        }
        return val + minimum;
    }
    
    int getMin() {
        return minimum;
    }
};
