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
    for(int i = 0; i < _num; i++)
    {
        for(int j = 0; j < _num-i-1; j++)
        {
            if(_arr[j] > _arr[j+1])
            {
                T tmp = _arr[j];
                _arr[j] = _arr[j+1];
                _arr[j+1] = tmp;
            }
        }
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