/*
//g++ -o hello file_name.cpp
#include<iostream>
using namespace std;

class hello
{
    int a,b;
    public:
     void insert();
     void print();
      
};
void hello::insert()
{
 cout<<"enter any 2 number"<<endl;
 cin>>a>>b;
};
void hello::print()
{
    cout<<a+b;
};

int main()
{
    class hello o;
    o.insert();
    o.print();
}
*/
#include<iostream>
using namespace std;
namespace first
{
    int a=1;
}
int a=5;
namespace second
{ 
    int a=10;
}
void add(double x,double y=1.0){
    cout<<x+y;
}
void add(int x){
    cout<<x;
}
int& ret()
{
    static int x=10;  //using static it allows us to acess through the variables ..
    return x;
}
int main()
{
    //cout<<::a<<endl; //:: a is given to specify standard 
    //cout<<first::a<<endl;
    //cout<<second::a<<endl;
    add(6.2);
    int &a=ret();
    //NOTE : is we pass value to a function where a function parameter is of type address then address of a gets copied to the parameter.

}

