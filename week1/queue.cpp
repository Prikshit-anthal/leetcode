
// https : // leetcode.com/problems/design-circular-queue/

        /*
         ---> NET LOGIC

         front se queue ke pop
         aur rear se push

         if(rear and front both -1) means empty

         else all case represent

         rear==exact rear idx
         front == exact front idx

         ///push
         rear+1 == front //problem

         ///pop
         front++
         if becomes k then 0;

        */

        class MyCircularQueue
{
    vector<int> queue;
    int k;
    int rear = -1, front = -1;

public:
    MyCircularQueue(int k)
    {
        this->k = k;
        queue.resize(k);
    }

    bool enQueue(int value)
    {

        int rear_new = rear + 1;
        if (rear_new == k)
            rear_new = 0;

        if (rear_new == front)
            return false;

        if (front == rear && rear == -1)
            front = 0;

        queue[rear_new] = value;
        rear = rear_new;
        return true;
    }

    bool deQueue()
    {

        if (front == -1) // no element
            return false;

        else if (front == rear) // only one element then becomes empty
            front = rear = -1;

        else
            front++;

        if (front == k)
            front = 0;

        return true;
    }

    int Front()
    {
        if (isEmpty())
            return -1;
        return queue[front];
    }

    int Rear()
    {
        if (isEmpty())
            return -1;
        return queue[rear];
    }

    bool isEmpty()
    {
        if (front == -1)
            return true;
        return false;
    }

    bool isFull()
    {
        int rear_new = rear + 1;
        if (rear_new == k)
            rear_new = 0;
        if (rear_new == front)
            return true;
        return false;
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