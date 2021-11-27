//by jzh
//2021.11.25
//请注意，这里没有delete，可能会造成内存泄漏
#include <iostream>
#include <string>
#include <fstream>
#define MAXN 99999
using namespace std;
template <typename T>
class node
{
public:
    T val;
    node *leftSon;
    node *rightSon;

public:
    node() : val(), leftSon(nullptr), rightSon(nullptr) {}
    T getVal()
    {
        return val;
    }
    node *getLeftSon()
    {
        return leftSon;
    }
    node *getRightSon()
    {
        return rightSon;
    }
};

class asc
{
public:
    char ch;
    int nums;
    bool flag;
    string s;
    asc() : nums(0), flag(true), s(""), ch() {}
};
void printTree(node<asc> *fa)
{
    cout << (fa->val.ch) << fa->val.s << endl;
    if (fa->leftSon != nullptr)
        printTree(fa->leftSon);
    if (fa->rightSon != nullptr)
        printTree(fa->rightSon);
    return;
}
void encode(node<asc> *fa, string s)
{
    if (fa->leftSon == nullptr && fa->rightSon == nullptr)
    {
        fa->val.s = s;
    }
    else
    {
        if (fa->leftSon != nullptr)
        {
            string s1 = s + "0";
            encode(fa->leftSon, s1);
        }
        if (fa->rightSon != nullptr)
        {
            string s2 = s + "1";
            encode(fa->rightSon, s2);
        }
    }
    return;
}
int searchMin(node<asc> *Asc, int length)
{
    int tmp = -1;
    int min = MAXN;
    for (int i = 0; i < length; i++)
    {
        if (Asc[i].val.nums < min && Asc[i].val.flag)
        {
            min = Asc[i].val.nums;
            tmp = i;
        }
    }
    if (tmp != -1)
    {
        Asc[tmp].val.flag = false;
        return tmp;
    }
    else
    {
        return tmp;
    }
}
int main()
{
    //init
    node<asc> Asc[256];
    for (int i = 0; i < 128; i++)
    {
        Asc[i].val.ch = (char)(i);
    }
    int length = 128;
    int n = 0;
    //read
    ifstream infile;
    infile.open("in.txt", ios::in);
    if (!infile.is_open())
    {
        cout << "读取文件失败" << endl;
        return 0;
    }
    char c;
    while ((c = infile.get()) != EOF)
    {
        // cout << c;
        Asc[(int)(c)].val.nums++;
    }
    infile.close();
    // for(int i = 0; i < 128; i++)
    // {
    //     cout << Asc[i].nums<< endl;
    // }
    //create
    node<asc> *a;
    node<asc> *b;
    node<asc> *fa;
    while (n < length-1)
    {
        a = new node<asc>;
        b = new node<asc>;
        fa = new node<asc>;
        int t1 = searchMin(Asc, length);
        int t2 = searchMin(Asc, length);
        // cout << t1 << t2 << endl;
        a = &Asc[t1];
        b = &Asc[t2];
        // cout << Asc[t1].val.nums<< endl <<Asc[t2].val.nums << endl << endl;
        Asc[length].val.flag = true;
        Asc[length].val.nums = Asc[t1].val.nums + Asc[t2].val.nums;
        Asc[length].val.s = "";
        Asc[length].leftSon = a;
        Asc[length].rightSon = b;
        fa->val = Asc[length++].val;
        fa->leftSon = a;
        fa->rightSon = b;
        n += 2;
    }
    string s = "";
    //encode
    encode(fa, s);
    //test
    // printTree(fa);
    ofstream output;
    //write
    //print
    output.open("out.txt", ios::out);
    infile.open("in.txt", ios::in);
    if (!infile.is_open())
    {
        cout << "读取文件失败" << endl;
        return 0;
    }
    cout << "encoding..." << endl
         << "the result is:" << endl;
    string encodeS; 
    while ((c = infile.get()) != EOF)
    {
        // cout << c;
        encodeS += Asc[(int)(c)].val.s;
    }
    output<<encodeS;
    cout << encodeS;
    infile.close();
    output.close();
    cout << endl
         << endl
         << "decoding..." << endl
         << "the result is :" << endl;

    //decode
    int num = 0;
    string sTmp;
    node<asc>* p = fa;
    while(num < encodeS.length())
    {
        if(p->leftSon==nullptr&&p->rightSon==nullptr)
        {
            sTmp += p->val.ch;
            p = fa;
        }
        else
        {
            char tmp = encodeS[num++];
            if(tmp == '0')
            p = p->leftSon;
            else
            p = p->rightSon;
        }
    }
    cout << sTmp << endl;
    return 0;
}
