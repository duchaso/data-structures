#ifndef VECTOR_H
#define VECTOR_H

template <typename T>
class Vector
{
    private:
        int sz = 1;
        int tail = -1;
        T* arr = new T[sz];

    public:
        void push_b(T el);
        void pop_b();
        T _back();
        int& operator[](int i);
        int siz();
        void print();

};

template<typename T> void Vector<T>::print()
{
    for(int i = 0; i < tail + 1; i++)
        std::cout << arr[i] << " ";
}

template<typename T> int& Vector<T>::operator[](int index)
{
    return arr[index];
}
template<typename T> int Vector<T>::siz()
{
    return tail;
}
template<typename T> void Vector<T>::push_b(T el)
{
    if(++tail < sz)
    {
        arr[tail] = el;
    }
    else
    {
        sz *= 2;
        T* buf = new T[sz];
        for(int i = 0; i < sz/2; ++i)
            buf[i] = arr[i];
        delete[] arr;
        arr = buf;
        arr[tail] = el;
    }
}

#endif // VECTOR_H
