#include <iostream>
using namespace std;
class listNode
{
public:
    int num;
    listNode *next;
    listNode *before;

public:
    listNode();
    listNode(int tnum, listNode *tnext, listNode *tbefore);
    listNode(int tnum);
    int getNum();
    listNode *getNext();
    listNode *getbefore();
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
listNode::listNode() : num(0), next(nullptr), before(nullptr) {}
listNode::listNode(int tnum, listNode *tnext, listNode *tbefore) : num(tnum), next(tnext), before(tbefore) {}
listNode::listNode(int tnum) : num(tnum), next(nullptr), before(nullptr) {}
int listNode::getNum()
{
    return num;
}
listNode *listNode::getNext()
{
    return next;
}
listNode *listNode::getbefore()
{
    return before;
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
    if (nodeNum == 0) //first
    {
        head = temp;
        end = temp;
        nodeNum++;
    }
    else
    {
        end->next = temp;
        nodeNum++;
        temp->before = end;
        end = temp;
    }
    return head;
}
int list::pop_end()
{
    listNode *temp = end;
    int ans = temp->num;
    listNode *befEnd = end->before;
    end = befEnd;
    nodeNum--;
    delete temp;
    return ans;
}
listNode *list::insertNode(const int i, const int n)
{
    if (n > nodeNum)
    {
        return nullptr;
    }
    listNode* x = head;
    for (int i = 0; i < n - 1; i++)
    {
        x = x->next;
    }
    nodeNum++;
    listNode *in = new listNode(i);
    in->before = x;
    in->next = x->next;
    x->next = in;
    x->next->before = in;
    return head;
}
listNode *list::deleteNode(const int i)
{
    listNode* x = head;
    while(x->num!=i)
    {
        x = x->next;
    }
    if(x==nullptr)
    {
        return nullptr;
    }
    else if(x == head)
    {
        head = x->next;
        nodeNum--;
        delete x;
        return head;
    }
    else
    {
        listNode* b = x->before;
        b->next = x->next;
        x->next->before = x->before;
        delete x;
        nodeNum--;
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
int main()
{
    list test;
    test.push_end(1);
    test.push_end(2);
    test.print();
    int num = test.pop_end();
    cout << num << endl << endl;
    test.print();
    test.push_end(2);
    test.push_end(3);
    test.push_end(4);
    test.print();
    test.deleteNode(3);
    test.print();
    test.insertNode(1,2);
    test.print();
    return 0;
}