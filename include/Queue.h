#ifndef QUEUE_H
#define QUEUE_H


class Queue
{
public:
    Queue(){};
    virtual ~Queue(){};
public:
    void push_b(int el);
    int pop_f();
private:
    int head = 0, tail = -1;
    int s = 1;
    int* arr = new int[s];

};

int Queue::pop_f()
{
    if (head <= tail)
        return arr[head++];
    else
        return -1;
}

void Queue::push_b(int el)
{
    if (++tail < s)
    {
        arr[tail] = el;
    }
    else
    {
        s *= 2;
        int* b = new int[s];
        for(int i = 0; i < s/2; ++i)
        {
            b[i] = arr[i];
        }
        delete[] arr;
        arr = b;

        arr[tail] = el;
    }
}

#endif // QUEUE_H
