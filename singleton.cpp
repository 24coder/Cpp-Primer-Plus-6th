#include <iostream>
#include <vector>
#include "singleton.h"
using namespace std;



// ��ʼ����̬��Ա����
SingletonSolution* SingletonSolution::instance = nullptr;
// ��ʼ����̬��Ա����
std::string SingletonSolution::sharedData = "";
int main() {
    int a;
    cout << "Please input a" << endl;
    std::cin >> a;
    cout << "a is " << a << endl;
    // ����Ψһʵ����
    SingletonSolution* instance1 = SingletonSolution::getInstance(42);
    SingletonSolution* instance2 = SingletonSolution::getInstance(99); // This should not change the value

    cout << "Instance 1 address: " << instance1 << endl;
    cout << "Instance 2 address: " << instance2 << endl;

    instance1->doSomething();
    instance2->doSomething();
    if (instance1 == instance2) {
        cout << "Both instances are the same." << endl;
    } else {
        cout << "Instances are different." << endl;
    }

    cout << "Instance 1 ֵ: " << instance1->getSolutionNum() << endl;
    cout << "Instance 2 ֵ: " << instance2->getSolutionNum() << endl;
    /*���Ե���ģʽ��������*/
    // ʹ�õ���ģʽ���ù�������
    instance1->setSharedData("Hello, World!");

    // ����һ���ط���ȡ��������
    std::cout << "Shared Data: " << instance2->getSharedData() << std::endl;
    // ���Գ�ʼ����ȷ��
    SingletonSolution* instance3 = SingletonSolution::getInstance(100);
    cout << "Instance 3 value: " << instance3->getSolutionNum() << endl;
    //���Ե���ģʽ���ݹ���
    instance2->setSharedData("hello kimi");
    std::cout << "Shared Data: " << instance2->getSharedData() << std::endl;
    /*���������̰߳�ȫ�ĵ���ģʽ*/
    //��mingw32��֧�ֶ��߳� windows mingw64





    system("pause");
    return 0;
}