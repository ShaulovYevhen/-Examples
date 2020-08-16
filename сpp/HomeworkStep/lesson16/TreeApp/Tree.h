//Для класса Tree реализовать следующие методы :
// добавление элемента(insert); +
// удаление элемента(delete);
// поиск элемента(find); +
// конструктор копирования;+
// деструктор; +
// перегрузка присвоения;+
// вывод на экран содержимого дерева(print); +
// getRoot; +
// getSize. +

#pragma once

#include "Node.h"

template <class T>
class Tree
{
    Node<T>* root = nullptr;
    int size = 0;
public:
    Tree();
    ~Tree();
    Tree(const Tree& x);
    void insert(T val);
    Node<T>* findElement(Node<T>* node, T data);
    Node<T>* findElement(T data);
    Node<T>* findSuccsessor(const T& val);     /* находит элемент с ключем, следующим за данным числом */
    Node<T>* deleteNode(Node<T>* z);
    const Node<T>* getRoot()const;
    void deleteElement(T data);
    void print(const Node<T>* node)const;
    void print()const;
    int getSize()const;
    const Node<T>* findMax()const;
    const Node<T>* findMin()const;
    Node<T>* findMax(Node<T>* x);
    Node<T>* findMin(Node<T>* x);
    Tree<T>& operator=(const Tree& obj);
    Tree<T>& operator=(Tree&& obj)noexcept; 
    Node<T>* copyTree(const Node<T>* node);
    void print_Tree(const Node<T>* node, int level);
};

template<class T>
void Tree<T>::print() const
{
    print(root);
    cout << endl;
}

template<class T>
inline int Tree<T>::getSize() const
{
    return size;
}

template<class T>
const Node<T>* Tree<T>::findMax()const
{
    auto cur = root;
    while (cur->getRight() != 0)                              
    {
        cur = cur->getRight();
    }
    return cur;
}

template<class T>
const Node<T>* Tree<T>::findMin() const
{
    auto cur = root;
    while (cur->getLeft() != 0)
    {
        cur = cur->getLeft();
    }
    return cur;
}

template<class T>
inline Node<T>* Tree<T>::findMax(Node<T>* x)
{
    while (x->getRight() != 0)
    {
        x = x->getRight();
    }
    return x;
}

template<class T>
inline Node<T>* Tree<T>::findMin(Node<T>* x)
{
    while (x->getLeft() != 0)
    {
        x = x->getLeft();
    }
    return x;
}

template<class T>
inline Tree<T>& Tree<T>::operator=(const Tree& x)
{
    if (this == &x)
        return *this;
    this->root = copyTree(x.getRoot());
    this->size = x.getSize();
    return *this;
}

template<class T>
inline Tree<T>& Tree<T>::operator=(Tree&& x) noexcept
{
    if (this == &x)
        return *this;
    this->root = copyTree(x.getRoot());
    this->size = x.getSize();
    x.~Tree();
    return *this;
}

template<class T>
Node<T>* Tree<T>::copyTree(const Node<T>* node)
{
    if (node == NULL)  
        return NULL; 
    else {
        auto temp = new Node<T>(node->getData());
        temp->setLeft(copyTree(node->getLeft()));
        temp->setRight(copyTree(node->getRight()));
        return temp;
    }
}

template<class T>
inline void Tree<T>::print_Tree(const Node<T>* node, int level)
{
    if (node == nullptr)
        return;
        print_Tree(node->getLeft(), level++);
        for (int i = 0; i < level; i++) cout << "   ";
        cout << node->getData() << endl;
        print_Tree(node->getRight(), level++);
}

template<class T>
void Tree<T>::print(const Node<T>* node) const
{
    if (node == nullptr)
        return;
    print(node->getLeft());
    cout << node->getData() << " ";
    print(node->getRight());
}

template<class T>
const Node<T>* Tree<T>::getRoot() const
{
    return root;
}

template<class T>
void Tree<T>::deleteElement(T data)
{
    if (findElement(data) != nullptr)
    {
        deleteNode(findElement(data));
    }
    else
    {
        return;
    }
}

template<class T>
Tree<T>::Tree() = default;

template<class T>
inline Tree<T>::~Tree()
{
    while(root!= nullptr)
    {
        deleteNode(root);
    }
    size = 0;
}

template<class T>
inline Tree<T>::Tree(const Tree& x)
{
    this->root = copyTree(x.getRoot());
    this->size = x.getSize();
}

template<class T>
void Tree<T>::insert(T val)
{
    if (root == nullptr)
    {
        root = new Node<T>(val);
        return;
    }
    auto cur = root, prev = root;
    while (cur)
    {
        prev = cur;
        if (val == cur->getData())
            return;
        if (val < cur->getData())
            cur = cur->getLeft();
        else
            cur = cur->getRight();
    }
    auto tmp = new Node<T>(val);
    tmp->setParent(prev);
    if (val < prev->getData())
        prev->setLeft(tmp);
    else
        prev->setRight(tmp);
    size++;
}

template<class T>
Node<T>* Tree<T>::findElement(Node<T>* node, T data)
{
    if ((node == NULL) || (data == node->getData()))
    {
        return node;
    }                                                                       
    else if (data < node->getData())
    {
        if (findElement(node->getLeft(), data) != nullptr)
        {
            return findElement(node->getLeft(), data);
        }
        else
        {
            return nullptr;
        }
    }
    else if (data > node->getData())
    {
        if (findElement(node->getRight(), data)!=nullptr)
        {
            return findElement(node->getRight(), data);
        }
        else
        {
            return nullptr;
        }
    } 
    return nullptr;
}

template<class T>
Node<T>* Tree<T>::findElement(T data)
{
    if ((this->getRoot() == NULL) || (this->getRoot()->getData() == data))
    {
        return root;
    }
    else if (data < root->getData())
    {
        if (findElement(root->getLeft(), data) != nullptr)
        {
            return findElement(root->getLeft(), data);
        }
        else
        {
            return nullptr;
        }
    }
    else if (data > root->getData())
    {
        if (findElement(root->getRight(), data) != nullptr)
        {
            return findElement(root->getRight(), data);
        }
        else
        {
            return nullptr;
        }
    }
    return nullptr;
}

template<class T>
inline Node<T>* Tree<T>::findSuccsessor(const T& val)
{
    auto x = findElement(root, val);                     /* получим указатель на ноду с ключем val */
    Node<T>* y;
    if (x == 0)
        return 0;
    if (x->getRight() != 0)                         /* если у нее есть правые дети, то следующий элемент - минимальный в правом поддереве */
        return findMin(x->getRight());
    y=x->getParent();
    while (y != 0 && x == y->getRight())             /* иначе - идем вверх и ищем первый элемент, являющийся левым потомком своего родителя */
    {
        x = y;
        y = y->getParent();
    }
    return y;
}

template<class T>
inline Node<T>* Tree<T>::deleteNode(Node<T>* z)
{
    Node<T>* y;
    Node<T>* x;
    if (z->getLeft() == 0 || z->getRight() == 0)               /* в этой и следующих двух строках ищем вершину y, которую мы потом вырежем из дерева. Это либо z, либо следующий за z */
        y = z;
    else
        y = findSuccsessor(z->getData());
    if (y->getLeft() != 0)                                  /* x - указатель на существующего ребенка y или 0 если таковых нет */
        x = y->getLeft();
    else
        x = y->getRight();
    if (x != 0)                                        /* эта и следующие 9 строк - вырезание y */
        x->setParent(y->getParent());
    if (y->getParent() == 0)
        root = x;
    else
    {
        if (y == (y->getParent())->getLeft())
            (y->getParent())->setLeft(x);
        else
            (y->getParent())->setRight(x);
    }
    if (y != z)                                        /* если мы вырезали вершин, отличную от z, то ее данные перемещаем в z */
        z->setData(y->getData());
    size--;
    return y;
}


