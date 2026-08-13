#include<iostream>
using namespace std;
    void swap (int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

int main ()
{
    int x,y;
    cout<<"Enter Two Numbers : ";
    cin>>x>>y;
    cout<<"Before Swapping : x = " << x << ", y = " << y << endl;
    swap(x,y);
    cout<<"After Swapping: y = " << x << ", y = " << y << endl;
    return 0;
}
