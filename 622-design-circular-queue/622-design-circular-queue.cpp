class MyCircularQueue {
  int curr_size = 0;
  int curr_index = 0;
  int front_index = 0;
  vector<int> temp;
  int k = 0;
public:
    MyCircularQueue(int K) {
        temp = vector<int>(K,-1);
      k = K;
    }
    
    bool enQueue(int value) {
        if (curr_size < k)
        {
          curr_size++;
          temp[curr_index++] = value;
          curr_index = curr_index % temp.size();
          return true;
        }
      return false;
    }
    
    bool deQueue() {
        if (curr_size)
        {
          curr_size--;
          front_index++;
          front_index = front_index % temp.size();
          return true;
        }
      return false;
    }
    
    int Front() {
        if (curr_size)
        {
          int temp_value = temp[front_index];
          return temp_value;
        }
      return -1;
    }
    
    int Rear() {
        if (curr_size)
        {
          int temp_index = curr_index;
          if (!temp_index)
            temp_index = k;
          return temp[temp_index-1];
        }
      return -1;
    }
    
    bool isEmpty() {
        return (curr_size) ?  false : true;
    }
    
    bool isFull() {
        return (curr_size == temp.size()) ?  true : false;
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