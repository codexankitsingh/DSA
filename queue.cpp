/*first in first out for eg: line at the ticket counter
  --> like stack Push and Pop in queue we ues enqueue(x) to push the element from frontn and dequeue() for remove form back;
  -->  peek() is used to check the fornt element;
  --> empty() is used to check weather the queue is empty or not
  --> in start front and back both are set to -1;
  --> then after the addition of the first element front and back =1; then after each addition the back is incremented by 1
  -->




  */

#include <bits/stdc++.h>
#include<iostream>
using namespace std;
#define size 10
class myqueue
{
    int* arr;
    int front;
    int back;

public:
    myqueue()
    {
        arr = new int[size];
        front = -1;
        back = -1;
    }

    void push(int x)
    {
        if (back == size-1)
        {
            cout << "Overflow occured" << endl;
            return;
        }
        else
        {
            back++;
            arr[back] = x;

        }
        if (front == -1)
        {
            front++;
        }
        return ;
    }
    void pop()
    {
        if (front == -1 || front > back)
        {
            cout << "No element present" << endl;
            return;
        }
        else
        {
            front++;
        }
    }

    int peek()
    {
        if (front == -1 || front > back)
        {
            cout << "No element present" << endl;
            return 0;
        }
        else
        {
            return arr[front];
        }
    }
    bool empty()
    {
        if (front == -1 || front > back)
            return true;
        return false;
    }
};

int main()
{
    myqueue q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);
    
    cout<<q.peek()<<endl;
    q.pop();
    cout<<q.peek()<<endl;
    q.pop();
    cout<<q.peek()<<endl;
    q.pop();
    cout<<q.peek()<<endl;
    q.pop();
    cout<<q.peek()<<endl;
    q.pop();

    return 0;
}