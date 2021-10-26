#include <iostream>
#include <cmath>
#include <stdlib.h>
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
    bool is_empty();
};
template <typename T>
bool list<T>::is_empty()
{
    if (nodeNum == 0)
        return true;
    else
        return false;
}
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
    bool is_empty();
};
template <typename T>
bool stack<T>::is_empty()
{
    return my_stack.is_empty();
}
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

int out_com(char ch)
{
    int x;
    switch (ch)
    {
    case '+':
        x = 2;
        break;
    case '-':
        x = 2;
        break;
    case '*':
        x = 4;
        break;
    case '/':
        x = 4;
        break;
    case '=':
        x = 0;
        break;
    case '(':
        x = 8;
        break;
    case '^':
        x = 6;
        break;
    case '%':
        x = 4;
        break;
    case ')':
        x = 1;
        break;
    default:
        cout << "error" << endl;
        x = -1;
        break;
    }
    return x;
}

int in_com(char ch)
{
    int x;
    switch (ch)
    {
    case '+':
        x = 3;
        break;
    case '-':
        x = 3;
        break;
    case '*':
        x = 5;
        break;
    case '/':
        x = 5;
        break;
    case '=':
        x = 0;
        break;
    case '(':
        x = 1;
        break;
    case '^':
        x = 7;
        break;
    case '%':
        x = 5;
        break;
    case ')':
        x = 1;
        break;
    default:
        cout << "error" << endl;
        x = -1;
        break;
    }
    return x;
}
int cal(int a, int b, char ch)
{
    if (ch == '+')
    {
        return a + b;
    }
    else if (ch == '-')
    {
        return b - a;
    }
    else if (ch == '*')
    {
        return a * b;
    }
    if (ch == '/')
    {
        if (a != 0)
            return b / a;
        else
        {
            cout << "error dividing zero" << endl;
            exit(EXIT_FAILURE);
        }
    }
    else if (ch == '%')
    {
        return b % a;
    }
    else if (ch == '^')
    {
        return (int)pow(b, a);
    }
    return -1;
}
int main()
{
    int ans = 0;
    stack<int> int_stack;
    stack<char> char_stack;
    char_stack.push_back('=');
    string s;
    cout << "please write the expression:";
    cin >> s;
    s = s + "=";
    bool f = false;
    int in_flag = 0;
    int num;
    int i = 0;
    char ch = s[i];
    int tmp = 0;
    while (i < s.length())
    {
        //
        // cout << "char" <<endl;
        // char_stack.print();
        // cout << "int" << endl;
        // int_stack.print();
        //
        if (ch <= '9' && ch >= '0')
        {
            f = true;
            tmp = 10 * tmp + ch - '0';
            i++;
            ch = s[i];
        }
        else if (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^' || ch == '(' || ch == ')' || ch == '=' || ch == '%')
        {
            if (f)
            {
                int_stack.push_back(tmp);
                tmp = 0;
                f = false;
            }
            if (in_flag >= 0)
            {
                if (ch == '=' && char_stack.get_end() == '=')
                {
                    char_stack.pop_back();
                    ans = int_stack.pop_back();
                    cout << "ans = " << ans << endl;
                    // int_stack.print();
                    return 0;
                }
                if (ch == '(')
                {
                    in_flag--;
                }
                if (out_com(char_stack.get_end()) < out_com(ch))
                {
                    char_stack.push_back(ch);
                    i++;
                    ch = s[i];
                }
                else
                {
                    if (char_stack.get_end() != '(' && char_stack.get_end() != ')' && char_stack.get_end() != '=')
                    {
                        char c_tmp = char_stack.pop_back();
                        int a = int_stack.pop_back();
                        int b = int_stack.pop_back();
                        int tmp_ans = cal(a, b, c_tmp);
                        int_stack.push_back(tmp_ans);
                    }
                }
            }
            else if (in_flag < 0)
            {
                // if (ch == '(')
                // {
                //     in_flag--;
                // }
                if (ch == ')' && char_stack.get_end() == '(')
                {
                    char_stack.pop_back();
                    in_flag++;
                    f = false;
                    i++;
                    ch = s[i];
                }
                if (in_com(char_stack.get_end()) < in_com(ch))
                {
                    char_stack.push_back(ch);
                    i++;
                    ch = s[i];
                }
                else
                {
                    if (char_stack.get_end() != '(' && char_stack.get_end() != ')' && char_stack.get_end() != '=')
                    {
                        char c_tmp = char_stack.pop_back();
                        int a = int_stack.pop_back();
                        int b = int_stack.pop_back();
                        int tmp_ans = cal(a, b, c_tmp);
                        int_stack.push_back(tmp_ans);
                    }
                }
            }
        }
        else
        {
            cout << "error" << endl;
            return -1;
        }
    }
    // if (int_stack.is_empty() && (char_stack.is_empty() || char_stack.get_end() == '='))
    // {
        ans = int_stack.pop_back();
        cout << ans << endl;
    // }
    // else
    // {
    // cout << "error" << endl;
    // }
    return 0;
    
}
