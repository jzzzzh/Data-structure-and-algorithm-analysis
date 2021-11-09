#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;
void Next(int a[], int n, string s)
{
    int i = 0, ans = -1;
    a[0] = ans;
    while (i < s.length() - 1)
    {
        if (ans == -1 || s[i] == s[ans])
        {
            i++;
            ans++;
            a[i] = ans;
        }
        else
        {
            ans = a[ans];
        }
    }
    return;
}
bool KMP(string standard, string s)
{
    const int length = standard.length();
    int next[length];
    Next(next, length, standard);
    int start = 0;
    bool flag = false;
    for (int i = 0; i < s.length(); i++)
    {
        while (start != standard.length() && i != s.length()) // compare
        {
            if (standard[start] == s[i]) // same
            {
                i++;
                start++;
            }
            else if (start != 0) //different
            {
                start = next[start];
            }
            else if (start == 0) //different
            {
                i++;
            }
        }
        if (start == standard.length())
        {
            flag = true;
            std::cout << "yes" << endl;
            std::cout << "from " << i - start + 1 << " to " << i << endl;
            break;
        }
        else
        {
            std::cout << "no" << endl;
        }
    }
    return true;
}
class my_string
{
public:
    vector<string> s;
    my_string();
    my_string(string _string);
    ~my_string();
    bool read_in_terminal();
    bool read_in_text(string _txt_name);
    bool insert(int _row, int _col, string _insert_things);
    bool remove(int _row, int _col, int _nums);
    bool remove(int _row, string _remove_things);
    bool remove(string _remove_things);
    bool exchange(int _row, int _col, int _nums, string _exchange_strings);
    bool exchange(int _row, string _remove_things, string _exchange_strings);
    bool exchange(string _remove_things, string _exchange_strings);
    void searsh(int _row, string _search_things);
    void KMPsearsh(int _row, string _search_things);
    void searsh(string _search_things);
    void show();
    my_string operator=(my_string _string);
    bool operator==(my_string _string);
    bool operator!=(my_string _string);
    my_string operator+=(my_string _string);
    my_string operator+(my_string _string);
    bool write_in_text(string _txt_name);
};
my_string::my_string() : s() {}
my_string::my_string(string _txt_name)
{
    s.push_back(_txt_name);
}
my_string::~my_string() {}
bool my_string::read_in_terminal()
{
    cout << "if you want to quit please write the 'quit' in the new end row" << endl;
    string in_s;
    while (cin >> in_s)
    {
        if (in_s == "quit")
        {
            break;
        }
        s.push_back(in_s);
    }
    return true;
}
bool my_string::read_in_text(string _txt_name)
{
    ifstream myfile(_txt_name);
    string temp;
    if (!myfile.is_open())
    {
        cout << "error" << endl;
    }
    while (getline(myfile, temp))
    {
        s.push_back(temp);
    }
    return true;
}
bool my_string::insert(int _row, int _col, string _insert_things)
{
    _col = _col - 1;
    string s_tmp = s[_row - 1];
    s_tmp.insert(_col, _insert_things);
    s[_row - 1] = s_tmp;
    return true;
}
bool my_string::remove(int _row, int _col, int _nums)
{
    string s_tmp = s[_row - 1];
    string ss;
    for (int i = 0; i < s_tmp.length(); i++)
    {
        if (i < _col || i > _col + _nums - 1)
            ss = ss + s_tmp[i];
    }
    s[_row - 1] = ss;
    return true;
}
bool my_string::remove(int _row, string _remove_things)
{
    string s_tmp = s[_row - 1];
    bool flag = false;
    for (int i = 0; i < s_tmp.length() - _remove_things.length() + 1; i++)
    {
        string ss(s_tmp, i, _remove_things.length());
        if (ss == _remove_things)
        {
            flag = true;
            remove(_row, i, _remove_things.length());
            break;
        }
    }
    return flag;
}
bool my_string::remove(string _remove_things)
{
    bool flag = false;
    for (int i = 1; i <= s.size(); i++)
    {
        flag = remove(i, _remove_things);
        if (flag)
            break;
    }
    return flag;
}
bool my_string::exchange(int _row, int _col, int _nums, string _exchange_strings)
{
    remove(_row, _col, _nums);
    insert(_row, _col, _exchange_strings);
    return true;
}
bool my_string::exchange(int _row, string _remove_things, string _exchange_strings)
{
    string s_tmp = s[_row - 1];
    bool flag = false;
    for (int i = 0; i < s_tmp.length() - _remove_things.length() + 1; i++)
    {
        string ss(s_tmp, i, _remove_things.length());
        if (ss == _remove_things)
        {
            flag = true;
            remove(_row, i, _remove_things.length());
            insert(_row, i, _exchange_strings);
            break;
        }
    }
    return true;
}
bool my_string::exchange(string _remove_things, string _exchange_strings)
{
    bool flag = false;
    for (int i = 1; i <= s.size(); i++)
    {
        flag = exchange(i, _remove_things, _exchange_strings);
        if (flag)
            break;
    }
    return flag;
}
void my_string::searsh(int _row, string _search_things)
{
    string s_tmp = s[_row - 1];
    bool flag = false;
    for (int i = 0; i < s_tmp.length() - _search_things.length() + 1; i++)
    {
        string ss(s_tmp, i, _search_things.length());
        if (ss == _search_things)
        {

            cout << "in " << _row << " row " << i + 1 << " column" << endl;
            flag = true;
            break;
        }
    }
    return;
}
void my_string::KMPsearsh(int _row, string _search_things)
{
    string s_tmp = s[_row - 1];
    bool flag = false;
    KMP(_search_things, s_tmp);
    return;
}
void my_string::searsh(string _search_things)
{
    for (int i = 1; i <= s.size(); i++)
    {
        searsh(i, _search_things);
    }
    return;
}
void my_string::show()
{
    for (auto i = 0; i != s.size(); i++)
    {
        cout << i + 1 << ":    " << s[i] << endl;
    }
    return;
}
my_string my_string::operator=(my_string _string)
{
    if (this->s == _string.s)
    {
        return _string;
    }
    else
    {
        this->s = _string.s;
        return _string;
    }
}
bool my_string::operator==(my_string _string)
{
    if (this->s == _string.s)
    {
        return true;
    }
    else
    {
        return false;
    }
}
bool my_string::operator!=(my_string _string)
{
    if (this->s != _string.s)
        return true;
    else
        return false;
}
my_string my_string::operator+=(my_string _string)
{
    for (int i = 0; i < _string.s.size(); i++)
    {
        string tmp = _string.s[i];
        this->s.push_back(tmp);
    }
    return *this;
}
my_string my_string::operator+(my_string _string)
{
    return *this + _string;
}
bool my_string::write_in_text(string _txt_name)
{
    ofstream outfile(_txt_name, ios::app);
    string temp;
    for (int i = 0; i < s.size(); i++)
    {
        outfile << s[i];
        outfile << endl;
    }
    outfile.close();
    return true;
}

int main()
{
    my_string s;
    int num1;
    cout << "welcome to the txt" << endl;
    cout << "where do you want to read the text?" << endl;
    cout << "1.terminal" << endl
         << "2. txt" << endl
         << "3. exit" << endl;
    cout << ":";
    cin >> num1;
    if (num1 == 1)
    {
        cout << "print 'quit' can exit" << endl;
        s.read_in_terminal();
    }
    else if (num1 == 2)
    {
        cout << "what is the document's name:";
        string document_name;
        cin >> document_name;
        document_name += ".txt";
        s.read_in_text(document_name);
    }
    else
    {
        cout << "bye" << endl;
        return 0;
    }
    cout << "the word is:" << endl;
    s.show();
    while (1)
    {
        cout << "what do you want to do?" << endl;
        cout << "1.insert" << endl
             << "2.remove" << endl
             << "3.exchange" << endl
             << "4.search" << endl
             << "5.show" << endl
             << "6.save" << endl
             << "7. exit" << endl
             << ":";
        cin >> num1;
        if (num1 == 1)
        {
            cout << "what row?" << endl;
            int row;
            cin >> row;
            cout << "what colunm?" << endl;
            int col;
            cin >> col;
            cout << "what string?" << endl;
            string str;
            cin >> str;
            s.insert(row, col, str);
            cout << "ok the ans is" << endl;
            s.show();
        }
        else if (num1 == 2)
        {
            cout << "remove what?" << endl;
            string str;
            cin >> str;
            s.remove(str);
            cout << "ok the ans is" << endl;
            s.show();
        }
        else if (num1 == 3)
        {
            cout << "what do u want to exchange?" << endl;
            string str1;
            cin >> str1;
            cout << "what do u want to change it into?" << endl;
            string str2;
            cin >> str2;
            s.exchange(str1, str2);
            cout << "ok the ans is" << endl;
            s.show();
        }
        else if (num1 == 4)
        {
            cout << "1.in a row" << endl
                 << "2. in the whole passage" << endl
                 << ":";
            int tt;
            cin >> tt;
            if (tt == 1)
            {
                cout << "what line"<<endl;
                int t_line;
                cin >>t_line;
                cout << "search what?" << endl;
                string s_sear;
                cin >> s_sear;
                s.KMPsearsh(t_line,s_sear);
            }
            else
            {
                cout << "search what?" << endl;
                string s_sear;
                cin >> s_sear;
                s.searsh(s_sear);
            }
        }
        else if (num1 == 5)
        {
            s.show();
        }
        else if (num1 == 6)
        {
            cout << "save in what name?" << endl;
            cout << ":";
            string name;
            cin >> name;
            name += ".txt";
            s.write_in_text(name);
        }
        else
        {
            cout << "bye" << endl;
            return 0;
        }
    }
}
