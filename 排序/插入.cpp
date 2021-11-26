#include<iostream>
using namespace std;
template<typename T>
int compare(T _a, T _b)
{
    if(_a > _b)
    return 1;
    else if(_a == _b)
    return 0;
    else
    return -1;
}
template<typename T>
void my_sort(T* _arr, int _num)
{
    for(int i = 1; i < _num; i++)
    {
        T x = _arr[i];
        int tmp = i;
        for(int j = 0; j < i; j++)
        {
            if(_arr[j] > x)
            {
                tmp = j;
                break;
            }
        }
        for(int j = i; j > tmp; j--)
        {
            _arr[j] = _arr[j-1];
        }
        _arr[tmp] = x;
    }
    return;
}
template<typename T>
void print(T* _arr, int _num)
{
    for(int i = 0; i < _num; i++)
    {
        cout << _arr[i] << " ";
    }
    cout << endl;
    return;
}
int main()
{
    int a[] = {6,3,4,5,7,1,2,8,9};
    int length = 9;
    my_sort<int>(a,length);
    print(a,length);
    return 0;
}