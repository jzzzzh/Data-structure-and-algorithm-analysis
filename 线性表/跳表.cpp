// 未完成
#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;
int getRand()
{
    srand((unsigned)time(NULL));
    return rand() % 2;
}
class listNode
{
public:
    int num;
    listNode *next;
    listNode *down;

public:
    listNode();
    listNode(int tnum, listNode *tnext);
    listNode(int tnum);
    int getNum();
    listNode *getNext();
};

class list
{
private:
    int nodeNum;
    listNode *head;
    listNode *end;

public:
    list();
    listNode *getHead();
    listNode *getEnd();
    listNode *push_end(int tnum);
    int pop_end();
    listNode *insertNode(const int i, const int n);
    listNode *find(const int i);
    listNode *insert(const int i);
    listNode *deleteNode(const int i);
    void print();
};
listNode::listNode() : num(0), next(nullptr) {}
listNode::listNode(int tnum, listNode *tnext) : num(tnum), next(tnext) {}
listNode::listNode(int tnum) : num(tnum), next(nullptr) {}
int listNode::getNum()
{
    return num;
}
listNode *listNode::getNext()
{
    return next;
}
list::list() : nodeNum(0), head(nullptr), end(nullptr) {}
listNode *list::getEnd()
{
    return end;
}
listNode *list::getHead()
{
    return head;
}
listNode *list::push_end(int tnum)
{
    listNode *temp = new listNode(tnum);
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
int list::pop_end()
{
    listNode *temp = end;
    int ans = temp->num;
    listNode *x = head;
    for (int i = 0; i < nodeNum - 2; i++) //这里是-2
    {
        x = x->next;
    }
    end = x;
    nodeNum--;
    delete temp;
    return ans;
}
listNode *list::insert(const int i)
{
    if (nodeNum == 0)
    {
        push_end(i);
        return head;
    }
    listNode *x = head;
    listNode *befx = head;
    int ii = 0;
    while (x->num < i)//!!!!这里好像有问题
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
listNode *list::find(const int i)
{
    listNode *x = head;
    while (x->num != i)
    {
        x = x->next;
    }
    if (x == end->next)
    {
        return nullptr;
    }
    else
    {
        return x;
    }
}
listNode *list::insertNode(const int i, const int n) //后插
{
    if (n == 0)
    {
        listNode *temp = new listNode(i);
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
    listNode *x = head;
    for (int i = 0; i < n - 1; i++)
    {
        x = x->next;
    }
    nodeNum++;
    listNode *in = new listNode(i);
    in->next = x->next;
    x->next = in;
    return head;
}
listNode *list::deleteNode(const int i)
{
    listNode *x = head;
    listNode *befx = head;
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
void list::print()
{
    if (nodeNum != 0)
    {
        listNode *temp = head;
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
class jumpList
{
    // 先来3层
private:
    list *firstList;
    list *secoList;
    list *thirList;
    int nums;

public:
    jumpList();
    jumpList(list *fir, list *sec, list *thir,int nums);
    void printFir();
    void printSec();
    void printThi();
    listNode *ins(int num);
    listNode *del(int num);
    listNode *sea(int num);
};

jumpList::jumpList() : firstList(nullptr), secoList(nullptr), thirList(nullptr),nums(0) {}
jumpList::jumpList(list *fir, list *sec, list *thir, int nums) : firstList(fir), secoList(sec), thirList(thir),nums(nums){}
void jumpList::printFir() { firstList->print(); }
void jumpList::printSec() { secoList->print(); }
void jumpList::printThi() { thirList->print(); }
listNode *jumpList::sea(int snum)
{
    //我这没加上安全性考量，不要乱调试
    listNode *temp = firstList->getHead();
    listNode *beftemp = temp;
    while (temp->num < snum && temp != nullptr)
    {
        beftemp = temp;
        cout << temp->num << endl;
        temp = temp->next;
    }
    temp = beftemp->down;
    while (temp->num < snum && temp != nullptr)
    {
        beftemp = temp;
        cout << temp->num << endl;
        temp = temp->next;
    }
    temp = beftemp->down;
    while (temp->num != snum && temp != nullptr)
    {
        beftemp = temp;
        cout << temp->num << endl;
        temp = temp->next;
    }
    //当然这里三个链表也可以改成数组，这样子这个就可以写成循环了
    if (temp == nullptr)
    {
        cout << "error" << endl;
        return nullptr;
    }
    else
    {
        cout << "ok" << endl;
        return temp;
    }
}
listNode *jumpList::ins(int num)
{
    if (nums == 0)
    {
        nums++;
        firstList = new list;
        secoList = new list;
        thirList = new list;
        thirList->insert(num);
        if (getRand() == 0)
        {
            secoList->insert(num);
            listNode *temp1 = thirList->find(num);
            listNode *temp2 = secoList->find(num);
            temp2->down = temp1;
            if (getRand() == 0)
            {
                firstList->insert(num);
                temp1 = firstList->find(num);
                temp1->down = temp2;
            }
        }
    }
    else
    {
        nums++;
        thirList->insert(num);
        if (getRand() == 0)
        {
            secoList->insert(num);
            listNode *temp1 = thirList->find(num);
            listNode *temp2 = secoList->find(num);
            temp2->down = temp1;
            if (getRand() == 0)
            {
                firstList->insert(num);
                temp1 = firstList->find(num);
                temp1->down = temp2;
            }
        }
    }
    return nullptr;
}
listNode *jumpList::del(int num)
{
    firstList->deleteNode(num);
    secoList->deleteNode(num);
    thirList->deleteNode(num);
    return firstList->getHead();
}

int main()
{
    jumpList j;
    j.ins(1);
    // for(int i = 0; i < 10; i++)
    // {
    //     j.ins(i);
    // }
    // j.printFir();
    // j.printSec();
    j.printThi();
    return 0;
}