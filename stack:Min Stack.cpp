class MinStack {
private:
    stack<int> sta1;
    stack<int> sta2;
public:
    void push(int x) {
        sta1.push(x);
        if(sta2.size()==0){
            sta2.push(x);
        }
        else{
            sta2.push(min(sta2.top(),x));
        }
    }

    void pop() {
        sta1.pop();
        sta2.pop();
    }

    int top() {
        return sta1.top();
    }

    int getMin() {
        return sta2.top();
    }
};
