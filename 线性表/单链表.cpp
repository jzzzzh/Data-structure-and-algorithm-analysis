#include <iostream>
using namespace std;
template <typename T>
class listNode
{
public:
    T num;
    listNode<T> *next;

public:
    listNode();
    listNode(T tnum, listNode<T> *tnext);
    listNode(T tnum);
    T getNum();
    listNode<T> *getNext();
};
template <typename T>
class list
{
private:
    // public:
    int nodeNum;
    listNode<T> *head;
    listNode<T> *end;

public:
    list();
    listNode<T> *getHead();
    listNode<T> *getEnd();
    listNode<T> *push_end(T tnum);
    T pop_end();
    listNode<T> *insert(const T i);
    listNode<T> *insertNode(const T i, const int n);
    listNode<T> *deleteNode(const T i);
    void print();
};
template <typename T>
listNode<T>::listNode() : num(0), next(nullptr) {}
template <typename T>
listNode<T>::listNode(T tnum, listNode *tnext) : num(tnum), next(tnext) {}
template <typename T>
listNode<T>::listNode(T tnum) : num(tnum), next(nullptr) {}
template <typename T>
T listNode<T>::getNum()
{
    return num;
}
template <typename T>
listNode<T> *listNode<T>::getNext()
{
    return next;
}
template <typename T>
list<T>::list() : nodeNum(0), head(nullptr), end(nullptr) {}
template <typename T>
listNode<T> *list<T>::getEnd()
{
    return end;
}
template <typename T>
listNode<T> *list<T>::getHead()
{
    return head;
}
template <typename T>
listNode<T> *list<T>::push_end(T tnum)
{
    listNode<T> *temp = new listNode<T>(tnum);
    if (nodeNum == 0)
    {
        head = temp;
        end = temp;
        nodeNum++;
    }
    else
    {
        end->next = temp;
        nodeNum++;
        end = temp;
    }
    return head;
}
template <typename T>
T list<T>::pop_end()
{
    listNode<T> *temp = end;
    int ans = temp->num;
    listNode<T> *x = head;
    for (int i = 0; i < nodeNum - 2; i++) //这里是-2
    {
        x = x->next;
    }
    end = x;
    nodeNum--;
    delete temp;
    return ans;
}
template <typename T>
listNode<T> *list<T>::insertNode(const T i, const int n) //后插
{
    if (n == 0)
    {
        listNode<T> *temp = new listNode<T>(i);
        temp->next = head;
        head = temp;
        return head;
    }
    if (n == nodeNum)
    {
        return push_end(i);
    }
    if (n > nodeNum)
    {
        return nullptr;
    }
    listNode<T> *x = head;
    for (int i = 0; i < n - 1; i++)
    {
        x = x->next;
    }
    nodeNum++;
    listNode<T> *in = new listNode<T>(i);
    in->next = x->next;
    x->next = in;
    return head;
}
template <typename T>
listNode<T> *list<T>::insert(const T i)
{
    if (nodeNum == 0)
    {
        push_end(i);
        return head;
    }
    listNode<T> *x = head;
    listNode<T> *befx = head;
    int ii = 0;
    while (x->num < i)
    {
        befx = x;
        x = x->next;
        ii++;
    }
    if (x == head)
    {
        insertNode(i, 0);
    }
    else if (x == nullptr)
    {
        insertNode(i, nodeNum);
    }
    else
    {
        insertNode(i, ii);
    }
    return head;
}
template <typename T>
listNode<T> *list<T>::deleteNode(const T i)
{
    listNode<T> *x = head;
    listNode<T> *befx = head;
    while (x->num != i)
    {
        befx = x;
        x = x->next;
    }
    if (x == end->next)
    {
        return nullptr;
    }
    else if (x == head)
    {
        head = head->next;
        delete x;
        nodeNum--;
        return head;
    }
    else
    {
        befx->next = x->next;
        nodeNum--;
        delete x;
        return head;
    }
}
template <typename T>
void list<T>::print()
{
    if (nodeNum != 0)
    {
        listNode<T> *temp = head;
        while (temp != end)
        {
            cout << temp->num << endl;
            temp = temp->next;
        }
        cout << temp->num << endl
             << endl;
        return;
    }
    else
    {
        cout << "error" << endl;
    }
}
template <typename T>
class stack
{
public:
    list<T> my_stack;
    void push_back(T i);
    T pop_back();
    void print();
    T get_end();
};

template <typename T>
void stack<T>::push_back(T i)
{
    my_stack.push_end(i);
    return;
}

template <typename T>
T stack<T>::pop_back()
{
    T tmp = my_stack.pop_end();
    return tmp;
}
template <typename T>
void stack<T>::print()
{
    my_stack.print();
    return;
}

template <typename T>
T stack<T>::get_end()
{
    T tmp = my_stack.pop_end();
    my_stack.push_end(tmp);
    return tmp;
}
int main()
{
    list<int> test;
    // test.push_end(1);
    // test.push_end(2);
    // test.print();
    // int num = test.pop_end();
    // cout << num << endl << endl;
    // test.print();
    // test.push_end(2);
    // test.push_end(3);
    // test.push_end(4);
    // test.print();
    // test.deleteNode(3);
    // test.print();
    // test.insertNode(3,3);
    test.insert(3);
    // cout << test.nodeNum << endl;
    test.print();
    return 0;
}