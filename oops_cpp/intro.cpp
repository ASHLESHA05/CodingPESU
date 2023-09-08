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
void add(float x,float y){
    cout<<x+y;
}
void add(int x,int y){
    cout<<x+y;
}

int main()
{
    //cout<<::a<<endl; //:: a is given to specify standard 
    //cout<<first::a<<endl;
    //cout<<second::a<<endl;
    ssss add(5,6.2);

}

