#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<iostream>

using namespace std;

void example001(){
	int a = 100;  
    int *p = &a;  
  
    //&a和p拥有相同地址，p保存的变量地址即是&a  
    cout<<"a的地址："<<&a<<endl;  
    cout<<"p所保存的地址："<<p<<endl;  
      
    //指针p自身的地址  
    cout<<"p自身的地址："<<&p<<endl;  
  
    //指针p中保存的地址的值，在p前面加“*”进行解引用操作，即可获得它所指针地址的值  
    cout<<"p保存的地址的值："<<*p<<endl;  
  
    //通过对指针p自身地址解引用，获得它所保存的地址  
    cout<<"p保存的地址的值："<<*&p<<endl;  
  
    //同上，得到 保存的地址后，再解引用，就可以获得保存地址里面的实际数据  
    cout<<"p保存的地址的值："<<**&p<<endl;  

}

//指针通过解引用*运算符访问并读取内存地址中的数据，并可以对数据进行修改。
void example002(){
	int a = 100;  
    int *p = &a;  
  
    //a的值也会随之而变,因为*p和a占用引用的是同一块物理地址  
    *p = 200;  
    cout<<a<<endl;  //--->200  
    cout<<*p<<endl; //--->200  
  
    //*p的值也会随之而变,理由同上  
    a = 300;  
    cout<<a<<endl;  //--->300  
    cout<<*p<<endl; //--->300  
}

//允许将一个变量的地址赋给一个已经保存了其它地址的指针变量
void example003(){
	int a = 100;  
    int b = 200;  
  
    //现在指针p中保存的是变量a的地址  
    int *p = &a;  
    cout<<"a的地址："<<&a<<endl;      //---> a = 100  
    cout<<"p所保存的地址："<<p<<endl;//---> *p = 100  
  
    //现在指针p中保存的是变量b的地址  
    p = &b;  
    cout<<"b的地址："<<&b<<endl;      //---> b = 200  
    cout<<"p所保存的地址："<<p<<endl;//---> *p = 200  
}

class MyClass  
{  
	public:  
		MyClass(){cout<<"执行构造函数"<<endl;}  
		~MyClass(){cout<<"执行析构函数"<<endl;} 
	public:  
		void set(int n){m_nVal = n;}  
	private:  
		int m_nVal;  
};  


//delete指针后，为其赋一个NULL值，以免发生难以调试的错误
void example004(){
	int *p = new int;  
    *p = 100;  
  
    //虽然delete了，但也只是说明这块空间现在谁都可以用了，不再被p独占，但是并没有对上面保存的地址进行任何修改  
    delete p;  
  
    //对p上的空间置空，否则p会变成野指针  
    //p = NULL;  
  
    //紧接着分配另一块内存空间，这块空间有可能就是编译器刚刚收回的p指针所保存的地址  
    int *p1 = new int;  
    *p1 = 200;  
  
    //因为p没有被置空，所以还可以继续使用，上面还存在以前分配的空间地址  
    //且p1也指向这块空间，所以对p的操作，会影响p1的结果  
    *p = 300;  
  
    //p1现在将会是p修改的值  
    cout<<*p1<<endl;  
}

//delete指针后，为其赋一个NULL值，以免发生难以调试的错误
void example005(){
	int *p = new int;  
    *p = 100;  
  
    //虽然delete了，但也只是说明这块空间现在谁都可以用了，不再被p独占，但是并没有对上面保存的地址进行任何修改  
    delete p;  
  
    //对p上的空间置空，否则p会变成野指针  
    p = NULL;  
  
    //紧接着分配另一块内存空间，这块空间有可能就是编译器刚刚收回的p指针所保存的地址  
    int *p1 = new int;  
    *p1 = 200;  
  
    //因为p没有被置空，所以还可以继续使用，上面还存在以前分配的空间地址  
    //且p1也指向这块空间，所以对p的操作，会影响p1的结果  
    //*p = 300;  
  
    //p1现在将会是p修改的值  
    cout<<*p1<<endl;  
}

void example006(){
	int *p1 = new int;
	int *p2 = new int;

	cout<<p1<<endl;
	cout<<p2<<endl;
	p1=p2;//p1现在保存的是p2所存储的内存地址，但是p1本身的地址并不会改变  
	cout<<p1<<endl;
	cout<<p2<<endl;
}

void example007(){
	 int *p1 = new int;  
     int *p2 = new int;  
     cout<<p2<<endl;  
    int a = p2 -p1;//计算两块内存之间的地址差  
    p1 += a;//将p1的内存单元地址加上地址差a，就等于p2的内存地址了  
    cout<<p1<<endl;  
}

//带const修饰符的指针
//常量指针：指针是常量，不能修改；它所指向的内容是非常量，可以修改
void example008(){
	//常量指针：指向的地址不能修改，指向的内容可以修改  
    MyClass *const p = new MyClass;  
  
    //指针存储的地址不能修改  
    //p++;  
  
    //指针指向的内容可以修改  
    p->set(1);  
}


//指向常量的指针：指针指向的内容是常量，不能修改；指针所存储的内存地址可以修改
void example009(){
	//指向常量的指针：指向的地址可以修改，指向的内容不能修改  
    MyClass const* p = new MyClass;  
    //const MyClass * p = new MyClass;  
  
    //指针存储的地址可以修改  
    p++;  
  
    //指向的内容不可以修改  
    //p->set(1);  
}


//指向常量的常指针：指针存储的地址和所指向的内容都不能修改
void example010(){
	//指向常量的指针：指向的地址可以修改，指向的内容不能修改  
    //const MyClass *const p = new MyClass;  
     MyClass const*const p = new MyClass;  
  
    //指针存储的地址可以修改  
    //p++;  
  
    //指向的内容不可以修改  
    //p->set(1);  
}



int main(){

	example001();
	cout<<"----------------------------------------------"<<endl;

	example002();
	cout<<"----------------------------------------------"<<endl;

	example003();
	cout<<"----------------------------------------------"<<endl;

	//堆中的对象：通过new关键字动态开辟的存储空间，生命周期和整个程序运行周期相同，需要手动delete释放
	MyClass *p = new MyClass();  
    delete p;//手动释放，否则p声明周期会一直持续到程序结束  
	cout<<"----------------------------------------------"<<endl;

	//栈上的对象：程序执行到对象所以有效区域的右大括号时被销毁，栈的生命周期随着它所在函数的执行完毕而结束
	MyClass m; 
	cout<<"----------------------------------------------"<<endl;

	example004();

	cout<<"----------------------------------------------"<<endl;

	example005();

	cout<<"----------------------------------------------"<<endl;

	example006();

	cout<<"----------------------------------------------"<<endl;

	example007();

	example008();

	cout<<"----------------------------------------------"<<endl;

	example009();

	cout<<"----------------------------------------------"<<endl;

	example010();

	return 0;
}