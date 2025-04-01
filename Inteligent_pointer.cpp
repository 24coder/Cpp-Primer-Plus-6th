#include <iostream>
#include <string>
#include <memory>

using namespace std;


class MyClass {
public:
    MyClass() { std::cout << "MyClass constructed\n"; }
    ~MyClass() { std::cout << "MyClass destructed\n"; }
    void greet() const { std::cout << "Hello from MyClass!\n"; }
};

int main() {
    // 使用 unique_ptr
    {
        std::unique_ptr<MyClass> uniquePtr = std::make_unique<MyClass>();
        uniquePtr->greet();
        // 不需要手动调用 delete，unique_ptr 会在离开作用域时自动释放资源
    } // MyClass destructed 输出到这里

    // 使用 shared_ptr
    {
        std::shared_ptr<MyClass> sharedPtr1 = std::make_shared<MyClass>();
        {
            std::shared_ptr<MyClass> sharedPtr2 = sharedPtr1; // 共享所有权
            sharedPtr1->greet();
            sharedPtr2->greet();
            std::cout << "sharedPtr1 use count: " << sharedPtr1.use_count() << "\n";
            std::cout << "sharedPtr2 use count: " << sharedPtr2.use_count() << "\n";
        } // sharedPtr2 离开作用域，引用计数减1，但对象不会被销毁
        std::cout << "After sharedPtr2 is out of scope, sharedPtr1 use count: " << sharedPtr1.use_count() << "\n";
    } // 当 sharedPtr1 离开作用域且引用计数为0时，MyClass 对象被销毁

    // 使用 weak_ptr 解决循环引用问题
    {
        auto sharedPtr = std::make_shared<MyClass>();
        std::weak_ptr<MyClass> weakPtr = sharedPtr; // 弱引用，不增加引用计数

        if (auto lockedPtr = weakPtr.lock()) { // 尝试锁定 weakPtr 获取 shared_ptr
            lockedPtr->greet();
        } else {
            std::cout << "The object has been destroyed.\n";
        }

        // 检查 weakPtr 是否过期
        if (weakPtr.expired()) {
            std::cout << "The object managed by weakPtr has been destroyed.\n";
        } else {
            std::cout << "The object managed by weakPtr is still alive.\n";
        }
    } // sharedPtr 离开作用域，由于没有其他 shared_ptr 持有该对象的所有权，MyClass 对象被销毁

    return 0;
}