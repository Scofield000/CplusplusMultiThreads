#include <iostream>
#include <thread>
using namespace std;

void myPrint()
{
	cout << "线程开始" << endl;

}

class TA
{
public:
	void operator()() // 不能带参数
	{
		cout << "线程开始" << endl;
		cout << "线程结束" << endl;
	}
};


int main()
{
	// 创建线程
	// 1，函数
	// 2，可调用对象
	// 3，lambda 表达式
	thread mythread(myPrint);  // 创建了线程，并开始执行
	mythread.join();   // 阻塞主线程，让主线程等待子线程执行完毕，两者汇合
	mythread.detach();  // 主线程和子线程不再汇合
	// detach 之后，这个thread 对象失去与主线程的关联，此时子线程会驻留在后台执行
	
	TA ta;
	thread mythread2(ta);   // thread 创建的时候调用拷贝构造函数，这里实际上将这个对象复制到线程中，创建了一个新的对象，即传递的值，只要ta中没有引用，那么使用时就没有问题
	mythread2.join();
	
	auto mylambda = [] {
		cout << "开始";
		cout << "结束";
	};

	thread mythread3(mylambda);
	mythread3.join();
	
	cout << "end";

	return 0;
}
