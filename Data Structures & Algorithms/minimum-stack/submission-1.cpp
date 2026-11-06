class MinStack {
private:
    int *stack;
    int *minstack;
    int tp;
    int cap;
    int mintop;
    int mincap;
public:

    MinStack() {
        cap = 10000;
        mincap = 10000;
        stack = (int*)malloc(cap*sizeof(int));
        minstack = (int*)malloc(mincap*sizeof(int));
        tp = -1;
        mintop=-1;
        
    }
    
    void push(int val) {
        tp++;
        stack[tp] = val;
        if(mintop==-1){
            mintop++;
            minstack[mintop] = val;
        }else{
            if(val<=minstack[mintop]){
                mintop++;
                minstack[mintop] = val;
            }
        }
        if(tp==cap-10){
            cap +=10000;
            int* temp = (int*)realloc(stack,  cap* sizeof(int));
            stack = temp;
        }
        if(mintop==mincap-10){
            mincap +=10000;
            int* temp = (int*)realloc(minstack,  mincap* sizeof(int));
            minstack = temp;
        }
        
    }
    
    void pop() {
        if(minstack[mintop]==stack[tp]){
            mintop--;
        }
        if(tp>=0){
            tp--;
        }
    }
    
    int top() {
        if(tp>=0)return stack[tp];
      
    }
    
    int getMin() {
        if(mintop>=0) return minstack[mintop];

    }
};
