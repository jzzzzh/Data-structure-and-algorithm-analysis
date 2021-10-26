#include <iostream>
#include <string>
#include <cstdlib>
#include <sstream>
#include <cstring>
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
    // public:
    int nodeNum;
    listNode *head;
    listNode *end;

public:
    int getNum() { return nodeNum; }
    list();
    listNode *getHead();
    listNode *getEnd();
    listNode *push_end(int tnum);
    int pop_end();
    listNode *insert(const int i);
    listNode *insertNode(const int i, const int n);
    listNode *deleteNode(const int i);
    void print();
    void reserveprint();
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
listNode *list::insertNode(const int i, const int n) //后插
{
    if (nodeNum == 0)
    {
        push_end(i);
        return head;
    }
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
            cout << temp->num << "  ";
            temp = temp->next;
        }
        cout << temp->num << "  ";
        return;
    }
    else
    {
        cout << "error" << endl;
    }
}
void list::reserveprint()
{
    string s = "";
    if (nodeNum != 0)
    {
        listNode *temp = head;
        while (temp != end)
        {
            s = to_string(temp->num)+s;
            temp = temp->next;
        }
        s = to_string(temp->num)+s;
        cout << s;
        return;
    }
    else
    {
        cout << "error" << endl;
    }
}
int main()
{
    list a;
    list b;
    int num1 = 0;
    int num2 = 0;
    cout << "please enter the number of x:" << endl;
    cin >> num1;
    int tmp = 0;
    for (int i = 0; i < num1; i++)
    {
        cin >> tmp;
        a.insertNode(tmp, 0);
    }
    // a.print();
    // cout << endl;
    cout << "please enter the number of y:" << endl;
    cin >> num2;
    // int tmp = 0;
    for (int i = 0; i < num2; i++)
    {
        cin >> tmp;
        b.insertNode(tmp, 0);
    }
    // b.print();
    // cout << endl;
    list c;
    listNode *a1 = a.getHead();
    listNode *b1 = b.getHead();
    int sum = 0;
    int add = 0;
    while (a1 != nullptr && b1 != nullptr)
    {
        sum = a1->getNum() + b1->getNum() + add;
        add = sum / 10;
        sum = sum % 10;
        c.push_end(sum);
        a1 = a1->getNext();
        b1 = b1->getNext();
    }
    while (a1 == nullptr && b1 != nullptr)
    {
        sum = 0 + b1->getNum() + add;
        add = sum / 10;
        sum = sum % 10;
        c.push_end(sum);
        b1 = b1->getNext();
    }
    while (b1 == nullptr && a1 != nullptr)
    {
        sum = 0 + a1->getNum() + add;
        add = sum / 10;
        sum = sum % 10;
        c.push_end(sum);
        a1 = a1->getNext();
    }
    if (add != 0)
    {
        c.push_end(add);
    }
    cout << "the answer is:" << endl;
    a.reserveprint();
    cout << " + ";
    b.reserveprint();
    cout << " = ";
    c.reserveprint();
    cout << endl;

    return 0;
}