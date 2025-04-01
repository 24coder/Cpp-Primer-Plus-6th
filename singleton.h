#include <vector>
#include <string>
#include <mutex>
#include <memory>
using namespace std;
// 声明单例类
class SingletonSolution {
private:
    static SingletonSolution* instance;
    int Solution_num;
     // 私有的静态成员变量保存共享数据
    static std::string sharedData;

    // 私有构造函数防止外部实例化
    SingletonSolution(int value) : Solution_num(value) {
        cout << "Constructor called, sharedValue set to " << Solution_num << endl;
    }

public:

    // 删除拷贝构造函数和赋值操作符以防止复制
    SingletonSolution(const SingletonSolution&) = delete;
    SingletonSolution& operator=(const SingletonSolution&) = delete;

    // 获取单例实例的方法
    static SingletonSolution* getInstance(int value) {
        if (instance == nullptr) {
            instance = new SingletonSolution(value);
        }
        return instance;
    }
    void doSomething() const {
        std::cout << "Singleton get the number!" << Solution_num << std::endl;
    }

    // 设置共享数据的方法
    static void setSharedData(const std::string& data) {
        cout << "setting shared data:" << data << endl;
        sharedData = data;
    }

    // 获取共享数据的方法
    static std::string getSharedData() {
        return sharedData;
    }
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        if (n == 0){
            return 0;
        }
        int slow = 1, count = 1;
        for(int fast = 1; fast < nums.size(); fast++){
            if(nums[fast] == nums[fast-1]){
                count++;
            } else {
                count = 1;
            }
            if(count <= 2){
                nums[slow++] = nums[fast];
            }
        }
        return slow;
    }

    ~SingletonSolution() {
        cout << "Destructor called" << endl;
    }

    int getSolutionNum() const {
        return Solution_num;
    }
};



/*饿汉单例*/
// class EagerSingleton {
// private:
//     static EagerSingleton instance;
//     EagerSingleton() {}
// public:
//     static EagerSingleton& getInstance() {
//         return instance;
//     }
//     void doSomething() const {
//         // Simulate some work.
//     }
// };






/*懒汉单例*/
// class LazySingletonDoubleCheck {
// private:
//     static std::unique_ptr<LazySingletonDoubleCheck> instance;
//     static std::mutex mutex;
//     LazySingletonDoubleCheck() {}
// public:
//     static LazySingletonDoubleCheck* getInstance() {
//         if (instance == nullptr) {
//             std::lock_guard<std::mutex> lock(mutex);
//             if (instance == nullptr) {
//                 instance.reset(new LazySingletonDoubleCheck());
//             }
//         }
//         return instance.get();
//     }
//     void doSomething() const {
//         // Simulate some work.
//     }
// };
// std::unique_ptr<LazySingletonDoubleCheck> LazySingletonDoubleCheck::instance = nullptr;
// std::mutex LazySingletonDoubleCheck::mutex;