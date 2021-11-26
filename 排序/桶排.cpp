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

void my_sort(int* _arr, int _num)
{
    int a[100] = {0};
    for(int i = 0; i < _num; i++)
    {
        a[_arr[i]]++;
    }
    int n = 0;
    for(int i = 0; i < 100; i++)
    {
        for(int j = 0; j < a[i]; j++)
        {
            _arr[n++] = i;
        }
    }
    return;
}
void print(int* _arr, int _num)
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
    my_sort(a,length);
    print(a,length);
    return 0;
}