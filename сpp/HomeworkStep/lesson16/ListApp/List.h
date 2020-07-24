//Создать шаблонный класс двусвязного списка List.Для этого класса
//реализовать следующие методы :
//▪ конструктор по умолчанию; +
//▪ конструктор копирования;+
//▪ конструктор перемещения;+
//▪ деструктор; +
//▪ добавление элемента в конец списка; +
//▪ добавление элемента в указанную позицию; +
//▪ удаление элемента с начала списка; +
//▪ удаление элемента из указанной позиции;+
//▪ вывод на экран содержимого списка; +
//▪ перегрузить оператор присваивания(&); +
//▪ перегрузить оператор присваивания(&&); +
//▪ сортировка списка по возрастанию(убыванию). +


#pragma once

#include "Node.h"

template<class T>
class List
{
    Node<T>* head = nullptr;
    Node<T>* tail = nullptr;
    int size = 0;
public:
    List();
    List(const initializer_list<T>& lst);
    ~List();
    List(const List& obj);
    List(List&& obj)noexcept;
    List<T>& operator=(const List& obj);
    List<T>& operator=(List&& obj)noexcept;
    void clear();
    void push_back(T val);
    void push_front(T val);
    void print_forward() const;
    void print_backward() const;
    void pop_front();
    void insert(T val, int pos);
    void erase(int pos);
    void SwapNodes(int left, int right);
    Node<T>* GetElem(int pos);
    void sort();
    void Lsort();
};

template<class T>
void List<T>::insert(T val, int pos)
{
    if (pos < 0 || pos > size)
        return;
    if (pos == 0)
    {
        push_front(val);
        return;
    }
    if (pos == size)
    {
        push_back(val);
        return;
    }
    auto tmp = new Node<T>(val);
    auto cur = head;
    for (int i = 0; i < pos - 1; ++i)
    {
        cur = cur->getNext();
    }
    tmp->setPrev(cur);
    tmp->setNext(cur->getNext());
    cur->getNext()->setPrev(tmp);
    cur->setNext(tmp);
    size++;
}

template<class T>
void List<T>::pop_front()
{
    if (size == 0)
        return;
    if (size == 1)
    {
        delete head;
        head = tail = nullptr;
        size = 0;
        return;
    }
    head = head->getNext();
    delete head->getPrev();
    head->setPrev(nullptr);
    size--;
}

template<class T>
void List<T>::print_forward() const
{
    auto cur = head;
    while (cur)
    {
        cout << cur->getData() << " ";
        cur = cur->getNext();
    }
    cout << endl;
}

template<class T>
void List<T>::print_backward() const
{
    auto cur = tail;
    while (cur)
    {
        cout << cur->getData() << " ";
        cur = cur->getPrev();
    }
    cout << endl;
}

template<class T>
void List<T>::push_front(T val)
{
    auto tmp = new Node<T>(val);
    if (size == 0)
        head = tail = tmp;
    else
    {
        tmp->setNext(head);
        head->setPrev(tmp);
        head = tmp;
    }
    size++;
}

template<class T>
void List<T>::push_back(T val)
{
    auto tmp = new Node<T>(val);
    if (size == 0)
        head = tail = tmp;
    else
    {
        tmp->setPrev(tail);
        tail->setNext(tmp);
        tail = tmp;
    }
    size++;
}

template<class T>
List<T>::List() = default;

template<class T>
List<T>::List(const initializer_list<T> & lst)
{
    for (auto item : lst)
    {
        push_back(item);
    }
}

template<class T>
List<T>::~List()
{
    while (size)
        pop_front();
}

template<class T>
List<T>::List(const List& obj)
{
    this->clear();
    auto cur = obj.head;
    while (cur != nullptr)
    {
        this->push_back(cur->getData());
        cur = cur->getNext();
    }
}

template<class T>
List<T>::List(List&& obj) noexcept
{
    this->clear();
    auto cur = obj.head;
    while (cur != nullptr)
    {
        this->push_back(cur->getData());
        cur = cur->getNext();
    }
    obj.clear();
}

template<class T>
List<T>& List<T>::operator=(const List& obj)
{
    if (this == &obj)
        return *this;
    if (obj.size)
    {
        this->clear();
        auto cur = obj.head;
        while (cur != nullptr)
        {
            this->push_back(cur->getData());
            cur = cur->getNext();
        }
    }
    return *this;
}

template<class T>
List<T>& List<T>::operator=(List&& obj) noexcept
{
    if (this == &obj)
        return *this;
    if (obj.size)
    {
        this->clear();
        auto cur = obj.head;
        while (cur != nullptr)
        {
            this->push_back(cur->getData());
            cur = cur->getNext();
        }
    }
    obj.clear();
    return *this;
}

template<class T>
void List<T>::clear()
{
    while (size)
        pop_front();
}

template<class T>
void List<T>::erase(int pos)
{
    if (pos < 1 || pos > size)
    {
        cout << "Incorrect pos!\n";
        return;
    }
    else if (pos == 1)
    {
        pop_front();
    }
    else
    {
        auto cur = head;
        for (int i = 0; i < pos - 2; ++i) 
        {
            cur = cur->getNext();
        }
        auto tmp = cur->getNext();
        cur->setNext(tmp->getNext());
        cur = cur->getNext();
        cur->setPrev(tmp->getPrev());
        delete tmp;
    }
    size--;
}

template<class T>
void List<T>::SwapNodes(int left, int right)
{
    if (left < 1 || left > size || right < 1 || right >size)
    {
        cout << "Incorrect position !!!\n";
        return;
    }
    auto tmp = this->GetElem(left)->getData();
    this->GetElem(left)->setData(this->GetElem(right)->getData());;
    this->GetElem(right)->setData(tmp);
}

template<class T>
inline Node<T>* List<T>::GetElem(int pos)
{
    if (pos < 1 || pos > size)
    {
        cout << "Incorrect position !!!\n";
        return 0;
    }
    auto temp = head;
    int i = 1;
    while (i < pos && temp != 0)
    {
        temp = temp->getNext();
        i++;
    }
    if (temp == 0)
        return 0;
    else
        return temp;
}

template<class T>
void List<T>::sort()
{
    int i = 0;
    auto cur = head;
    while(cur)
    {
        i++;
        if (GetElem(i)->getData() > GetElem(i + 1)->getData())
        {
            SwapNodes(i, i + 1);
            cur = cur->getNext();
            sort();
        }
        if (i == size-1)
            break;
        cur = cur->getNext();
    }
}

template<class T>
inline void List<T>::Lsort()
{
    int i = 0;
    auto cur = head;
    while (cur)
    {
        i++;
        if (GetElem(i)->getData() < GetElem(i + 1)->getData())
        {
            SwapNodes(i, i + 1);
            cur = cur->getNext();
            Lsort();
        }
        if (i == size - 1)
            break;
        cur = cur->getNext();
    }
}