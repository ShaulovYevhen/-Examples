#pragma once
template<class T>
class Stack
{
    T* arr = nullptr;
    int capacity = 0;
    int top = -1;
public:
    Stack();
    Stack(int c);
    Stack(const Stack& obj);
    Stack(Stack&& obj)noexcept;
    ~Stack();
    Stack<T>& operator=(const Stack& obj);
    Stack<T>& operator=(Stack&& obj)noexcept;
    void push(T val);
    T pop();
    T peek()const;
    bool is_empty()const;
    bool is_full()const;
};

template<class T>
Stack<T>::Stack()
{
    capacity = 100;
    arr = new T[capacity]{};
}

template<class T>
Stack<T>::Stack(int c)
{
    capacity = c;
    arr = new T[capacity]{};
}

template<class T>
Stack<T>::Stack(const Stack& obj)
{
    capacity = obj.capacity;
    top = obj.top;
    arr = new T[capacity]{};
    for (int i = 0; i <= top; ++i)
    {
        arr[i] = obj.arr[i];
    }
}

template<class T>
Stack<T>::Stack(Stack&& obj) noexcept
{
    capacity = obj.capacity;
    top = obj.top;
    arr = obj.arr;

    obj.capacity = 0;
    obj.top = -1;
    obj.arr = nullptr;
}

template<class T>
Stack<T>::~Stack()
{
    if (capacity)
        delete[]arr;
}

template<class T>
Stack<T>& Stack<T>::operator=(const Stack& obj)
{
    if (this == &obj)
        return *this;
    if (capacity)
        delete[]arr;
    capacity = obj.capacity;
    top = obj.top;
    arr = new T[capacity]{};
    for (int i = 0; i <= top; ++i)
    {
        arr[i] = obj.arr[i];
    }
    return *this;
}

template<class T>
Stack<T>& Stack<T>::operator=(Stack&& obj) noexcept
{
    if (this == &obj)
        return *this;
    if (capacity)
        delete[]arr;
    capacity = obj.capacity;
    top = obj.top;
    arr = obj.arr;

    obj.capacity = 0;
    obj.top = -1;
    obj.arr = nullptr;
    return *this;
}

template<class T>
void Stack<T>::push(T val)
{
    arr[++top] = val;
}

template<class T>
T Stack<T>::pop()
{
    return arr[top--];
}

template<class T>
T Stack<T>::peek() const
{
    return arr[top];
}

template<class T>
bool Stack<T>::is_empty() const
{
    return top == -1;
}

template<class T>
bool Stack<T>::is_full() const
{
    return top == capacity - 1;
}
