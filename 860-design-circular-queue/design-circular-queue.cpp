class MyCircularQueue {
    int currsize;
    int front,rear,capacity;
    int * arr;
public:
    MyCircularQueue(int k) {
        front=0;
        rear=-1;
        capacity=k;
        currsize=0;
        arr= new int[capacity];
    }
    
    bool enQueue(int value) {
        if(currsize==capacity){
            return false;
        }
      rear= (rear+1)%capacity;
      arr[rear]=value;
      currsize++;
      return true;
        
    }
    
    bool deQueue() {
        if(currsize==0){
            return false;
        }
        front=(front+1)%capacity;
        currsize--;
        return true;
        
    }
    
    int Front() {
        if(currsize==0){
            return -1;
        }
        return arr[front];
        
    }
    
    int Rear() {
        if(currsize==0){
            return -1;
        }
        return arr[rear];
        
    }
    
    bool isEmpty() {
        return currsize==0;
        
    }
    
    bool isFull() {
        return currsize==capacity;
        
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */