#include <iostream>
using namespace std;
class listNode
{
public:
    int num;
    listNode *next;

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
        end->next = head;
    }
    else
    {
        end->next = temp;
        nodeNum++;
        end = temp;
        end->next = head;
    }
    return head;
}
int list::pop_end()
{
    listNode *temp = end;
    int ans = temp->num;
    listNode *x = head;
    for (int i = 0; i < nodeNum - 2; i++)//这里是-2
    {
        x = x->next;
    }
    end = x;
    nodeNum--;
    delete temp;
    end->next = head;
    return ans;
}
listNode *list::insertNode(const int i, const int n) //后插
{
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
    //
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
        cout << temp->num << endl<<endl;
        return;
    }
    else
    {
        cout << "error" << endl;
    }
}
int main()
{
    list test;
    test.push_end(1);
    test.push_end(2);
    test.print();
    listNode* t = test.getHead();
    for(int i = 0; i < 4; i++)
    {
        cout << t->num << endl;
        t=t->next;
    }
    return 0;
}