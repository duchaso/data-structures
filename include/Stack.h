#ifndef STACK_H
#define STACK_H

template <typename T>
class Stack
{
    public:
        Stack(){};
        virtual ~Stack(){};
    public:
        void push_b(T el);
        T pop_b();

    private:
        int s = 1;
        T* arr = new T[s];
        int tail = -1;
};

template<typename T> T Stack<T>::pop_b()
{
    if(tail == -1)
        return "r";
    else
    {
        tail--;
        return arr[tail + 1];
    }
}

template<typename T> void Stack<T>::push_b(T el)
{
    if (++tail < s)
    {
        arr[tail] = el;
    }
    else
    {
        s *= 2;
        T* b = new T[s];
        for(int i = 0; i < s/2; ++i)
        {
            b[i] = arr[i];
        }
        delete[] arr;
        arr = b;

        arr[tail] = el;
    }

}

#endif // STACK_H
