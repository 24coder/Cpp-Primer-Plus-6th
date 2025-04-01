#include <iostream>
#include <vector>
#include <algorithm>  // 包含 std::remove
#include "singleton.h"
using namespace std;

// 定义观察者接口
class Observer {
public:
    virtual void Update() = 0; // 纯虚函数，使类成为抽象类
    virtual ~Observer() {} // 虚析构函数
};

// 定义主题接口
class Subject {
private:
    vector<Observer*> observers; // 使用 std::vector 存储观察者

public:
    // 增加观察者    Observer* observer 父类指针指向子类对象  这是多态实现的关键点 调用虚函数时
    void Attach(Observer* observer) {
        observers.push_back(observer);
    }

    // 移除观察者
    void Detach(Observer* observer) {
        // 使用 std::remove 和 erase 组合来删除元素
        observers.erase(remove(observers.begin(), observers.end(), observer), observers.end());
    }

    // 通知所有观察者
    void Notify() {
        for (Observer* observer : observers) {
            observer->Update();
        }
    }

    virtual ~Subject() {} // 虚析构函数
};

// 具体主题类
class ConcreteSubject : public Subject {
private:
    string subjectState;

public:
    string GetSubjectState() const {
        return subjectState;
    }

    void SetSubjectState(const string& value) {
        subjectState = value;
    }
};




//添加另外一个具体主题类   //添加另外一个具体观察者类  自定义相关update的内容来灵活实现自定义主题功能
class AnotherConcreteSubject : public Subject {
private:
    string AnothersubjectState;

public:
    string AnotherGetSubjectState() const {     
        return AnothersubjectState;
    }

    void AnotherSetSubjectState(const string& value) {
        AnothersubjectState += value;
    }
};






// 具体观察者类
class ConcreteObserver : public Observer {
private:
    string name;
    string observerState;
    ConcreteSubject* subject;

public:
    ConcreteObserver(ConcreteSubject* subject, const string& name)
        : subject(subject), name(name) {}

    void Update() override {
        observerState = subject->GetSubjectState();
        cout << "观察者" << name << "的新状态是" << observerState << endl;
    }
};

//添加另外一个具体观察者类  自定义相关update的内容来灵活实现自定义观察者功能
class AnotherConcreteObserver : public Observer {
private:
    string Anothername;
    string AnotherobserverState;
    AnotherConcreteSubject* Anothersubject;

public:
    AnotherConcreteObserver(AnotherConcreteSubject* subject, const string& name)
        : Anothersubject(subject), Anothername(name) {}

    void Update() override {
        AnotherobserverState = Anothersubject->AnotherGetSubjectState();
        cout << "另一个观察者" << Anothername << "的新状态是" << AnotherobserverState << endl;
    }
};






int main() {
    ConcreteSubject cs;

    // ConcreteObserver* observerX = new ConcreteObserver(&cs, "X");
    // ConcreteObserver* observerY = new ConcreteObserver(&cs, "Y");
    // ConcreteObserver* observerZ = new ConcreteObserver(&cs, "Z");
    // // 相当于selling加个更新
    // cs.Attach(observerX);
    // cs.Attach(observerY);
    // cs.Attach(observerZ);
    // cs.SetSubjectState("ABC");
    // cs.Notify();

    // cs.Detach(observerZ);
    // cs.SetSubjectState("ttr");
    // cs.Notify();

    // cs.Detach(observerY);
    // cs.SetSubjectState("tree");
    // cs.Notify();
    // cs.SetSubjectState("另外一个主题");
    // cout<<endl<<endl;
    // //自定义另外一个主题 
    AnotherConcreteSubject Anothercs;
    //创建绑定的观察者   这些观察者到时候被通知的都是相应的对象
    ConcreteObserver* AnotherobserverX = new ConcreteObserver(&cs, "X");
    ConcreteObserver* AnotherobserverY = new ConcreteObserver(&cs, "Y");
    ConcreteObserver* AnotherobserverZ = new ConcreteObserver(&cs, "Z");
    // 相当于selling加个更新
    Anothercs.Attach(AnotherobserverX);
    Anothercs.Attach(AnotherobserverY);
    Anothercs.Attach(AnotherobserverZ);
    Anothercs.AnotherSetSubjectState("AAAAAAAAAAAA");
    Anothercs.Notify();

    Anothercs.Detach(AnotherobserverZ);
    Anothercs.AnotherSetSubjectState("BBBBBBBBBBBB");
    Anothercs.Notify();

    Anothercs.Detach(AnotherobserverY);
    Anothercs.AnotherSetSubjectState("CCCCCCCCCCCC");
    Anothercs.Notify();
    // // 等待用户输入
    // cin.get();

    cout<<endl<<endl;


    //使用另外一个主题和观测者
    AnotherConcreteSubject Anothercss;

    AnotherConcreteObserver* AnotherobserverXs = new AnotherConcreteObserver(&Anothercss, "X");
    AnotherConcreteObserver* AnotherobserverYs = new AnotherConcreteObserver(&Anothercss, "Y");
    AnotherConcreteObserver* AnotherobserverZs = new AnotherConcreteObserver(&Anothercss, "Z");
    // 相当于selling加个更新
    Anothercss.Attach(AnotherobserverXs);
    Anothercss.Attach(AnotherobserverYs);
    Anothercss.Attach(AnotherobserverZs);
    Anothercss.AnotherSetSubjectState("AAAAAAAAAAAA");
    Anothercss.Notify();

    Anothercss.Detach(AnotherobserverZs);
    Anothercss.AnotherSetSubjectState("BBBBBBBBBBBB");
    Anothercss.Notify();

    Anothercss.Detach(AnotherobserverYs);
    Anothercss.AnotherSetSubjectState("CCCCCCCCCCCC");
    Anothercss.Notify();
    // 等待用户输入
    cin.get();

    return 0;
}