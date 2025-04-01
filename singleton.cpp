#include <iostream>
#include <vector>
#include "singleton.h"
using namespace std;



// 初始化静态成员变量
SingletonSolution* SingletonSolution::instance = nullptr;
// 初始化静态成员变量
std::string SingletonSolution::sharedData = "";
int main() {
    int a;
    cout << "Please input a" << endl;
    std::cin >> a;
    cout << "a is " << a << endl;
    // 测试唯一实例性
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

    cout << "Instance 1 值: " << instance1->getSolutionNum() << endl;
    cout << "Instance 2 值: " << instance2->getSolutionNum() << endl;
    /*测试单例模式共享数据*/
    // 使用单例模式设置共享数据
    instance1->setSharedData("Hello, World!");

    // 从另一个地方读取共享数据
    std::cout << "Shared Data: " << instance2->getSharedData() << std::endl;
    // 测试初始化正确性
    SingletonSolution* instance3 = SingletonSolution::getInstance(100);
    cout << "Instance 3 value: " << instance3->getSolutionNum() << endl;
    //测试单例模式数据共享
    instance2->setSharedData("hello kimi");
    std::cout << "Shared Data: " << instance2->getSharedData() << std::endl;
    /*测试三种线程安全的单例模式*/
    //因mingw32不支持多线程 windows mingw64





    system("pause");
    return 0;
}