#include <iostream>
#include <thread>
using namespace std;

void myPrint()
{
	cout << "�߳̿�ʼ" << endl;

}

class TA
{
public:
	void operator()() // ���ܴ�����
	{
		cout << "�߳̿�ʼ" << endl;
		cout << "�߳̽���" << endl;
	}
};


int main()
{
	// �����߳�
	// 1������
	// 2���ɵ��ö���
	// 3��lambda ���ʽ
	thread mythread(myPrint);  // �������̣߳�����ʼִ��
	mythread.join();   // �������̣߳������̵߳ȴ����߳�ִ����ϣ����߻��
	mythread.detach();  // ���̺߳����̲߳��ٻ��
	// detach ֮�����thread ����ʧȥ�����̵߳Ĺ�������ʱ���̻߳�פ���ں�ִ̨��
	
	TA ta;
	thread mythread2(ta);   // thread ������ʱ����ÿ������캯��������ʵ���Ͻ���������Ƶ��߳��У�������һ���µĶ��󣬼����ݵ�ֵ��ֻҪta��û�����ã���ôʹ��ʱ��û������
	mythread2.join();
	
	auto mylambda = [] {
		cout << "��ʼ";
		cout << "����";
	};

	thread mythread3(mylambda);
	mythread3.join();
	
	cout << "end";

	return 0;
}
