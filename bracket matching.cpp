#include<iostream>
#include<string.h>
#include<stdlib.h>
#define SIZE 30
using namespace std;
class mystack
{
     int top;
     char arr[SIZE];
     int capacity;
 public:
     mystack()
    {
        top=-1;
        capacity=SIZE;
    }
     void push(char);
     char pop();
     int check(char []);
};
int mystack::check(char exp[] )
{
  int i;
  char temp;
  for(i=0;i<strlen(exp);i++)
{
  if(exp[i]=='(' || exp[i]=='{' || exp[i]=='[')
      push(exp[i]);
  if(exp[i]==')' || exp[i]=='}' || exp[i]==']')
    if(top==-1)
{
  cout<<"Right parentheses are more than left parentheses\n";
       return 0;
}
 else
{
    temp=pop();
    if(!(temp=='[' && exp[i]==']'||temp=='{' && exp[i]=='}'||temp=='(' && exp[i]==')'))
    {
        cout<<"Mismatched parentheses are";
        cout<<temp<<exp[i];
         return 0;

    }
}
}
    if(top==-1)
    {
        cout<<"Balanced Parentheses\n";
       return 1;
    }
    else
    {
                cout<<"Left parentheses more than right parentheses\n";
            return 0;
    }
}
void mystack::push(char item)
{
        if(top==(capacity-1))
        {
                cout<<"Stack Overflow\n";
                return;
        }
        top=top+1;
        arr[top]=item;
}
char mystack:: pop()
{
        if(top==-1)
        {
                cout<<"Stack Underflow\n";
                exit(1);
        }
        return(arr[top--]);
}

int main()
{
        char exp[SIZE];
        int valid;
        mystack m;
        cout<<"Enter an algebraic expression ";
        cin>>exp;
        valid= m.check(exp);
        if(valid==1)
               cout<<"Valid expression\n";
        else
        cout<<"Invalid expression\n";
                return 0;

}
