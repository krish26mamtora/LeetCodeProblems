class CustomStack {
public:
        int size;
        int top;
        int *arr;

    CustomStack(int maxSize) {
       this->size = maxSize;
        this->arr = new int[maxSize];
        top = -1;
    }

    void push(int x) {
         if (top < size - 1) {  
            top++;
            arr[top] = x;
        }
    }

    int pop() {
          if (top >= 0) {
            int poppedElement = arr[top];  
            top--;  
            return poppedElement; 
        }
        return -1;  
    }

    void increment(int k, int val) {
        for (int i = 0; i < min(k, top + 1); i++) {
            arr[i] += val;
        }
    }
};