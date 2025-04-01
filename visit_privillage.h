#include <iostream>
#include <cassert>

// 基类定义
class Base {
public:
    int publicMember;
protected:
    int protectedMember;
private:
    int privateMember;

public:
    Base() : publicMember(0), protectedMember(0), privateMember(0) {}

    void base_public_checkAccessInClass() {
        publicMember = 1; // 正确：public成员可以从类内部访问
        std::cout << "checking class  inner function  visit class number "<<"--publicMember is :"<< publicMember <<std::endl;
        protectedMember = 2; // 正确：protected成员也可以从类内部访问
        std::cout << "checking class  inner function  visit class number "<<"--protectedMember is :"<< protectedMember <<std::endl;
        privateMember = 3; // 正确：private成员可以从类内部访问
        std::cout << "checking class  inner function  visit class number "<<"--privateMember is :"<< privateMember <<std::endl;
        //类内访问私有成员函数 并通过私有成员函数访问私有和保护变量
        base_protected_checkAccessInClass();
        base_private_checkAccessInClass();
    }
protected:

    void base_protected_checkAccessInClass() {
        publicMember = 4; // 正确：public成员可以从类内部访问
        std::cout << "checking class  inner function  visit class number "<<"--publicMember is :"<< publicMember <<std::endl;
        protectedMember = 5; // 正确：protected成员也可以从类内部访问
        std::cout << "checking class  inner function  visit class number "<<"--protectedMember is :"<< protectedMember <<std::endl;
        privateMember = 6; // 正确：private成员可以从类内部访问
        std::cout << "checking class  inner function  visit class number "<<"--privateMember is :"<< privateMember <<std::endl;
        base_private_checkAccessInClass();
    }

private:
    void base_private_checkAccessInClass() {
        publicMember = 7; // 正确：public成员可以从类内部访问
        std::cout << "checking class  inner function  visit class number "<<"--publicMember is :"<< publicMember <<std::endl;
        protectedMember = 8; // 正确：protected成员也可以从类内部访问
        std::cout << "checking class  inner function  visit class number "<<"--protectedMember is :"<< protectedMember <<std::endl;
        privateMember = 9; // 正确：private成员可以从类内部访问
        std::cout << "checking class  inner function  visit class number "<<"--privateMember is :"<< privateMember <<std::endl;
    }

    int getPrivateMember() const { return privateMember; } // 仅用于测试目的
    /*
    友元类：一个类可以声明另一个类为友元类，这样友元类的所有成员函数都可以访问原类的私有和保护成员。
    友元类（friend class）是一种允许一个类访问另一个类的<私有和保护"""成员""">的机制.
    */
    friend class privateDerived;
    
    //friend class Derived; // 允许派生类访问私有成员（如果需要）
};

// 派生类定义
class publicDerived : public Base {
public:
    int public_public_publicMember;
protected:
    int protected_public_protectedMember;
private:
    int private_public_privateMember;
public:
    void public_public_accessMembers() {
        publicMember = 40; // 正确：public成员可以从派生类访问
        std::cout << "派生类公有制继承之后public函数访问public成员 "<<"--publicMember is :"<< publicMember <<std::endl;
        protectedMember = 50; // 正确：protected成员也可以从派生类访问
        std::cout << "派生类公有制继承之后public函数访问protect成员 "<<"--protectedMember is :"<< protectedMember <<std::endl;
        // privateMember = 60; // 错误：private成员不能从派生类访问
        base_protected_checkAccessInClass();
        //base_private_checkAccessInClass();派生类只能调用protect级别的函数，不能调用protect级别的函数。
        /*
        为了访问父类中的成员函数，可以使用继承和访问控制：
        1、在派生类中可以直接调用基类的保护成员函数。
        2、私有成员函数仍然不能在派生类中直接调用，但可以通过在基类中提供公共接口来间接调用。    
        */
        base_protected_checkAccessInClass();
        //base_private_checkAccessInClass();
    }
protected:
    void protected_public_accessMembers() {
        publicMember = 40; // 正确：public成员可以从派生类访问
        std::cout << "派生类公有制继承之后public函数访问public成员 "<<"--publicMember is :"<< publicMember <<std::endl;
        protectedMember = 50; // 正确：protected成员也可以从派生类访问
        std::cout << "派生类公有制继承之后public函数访问protect成员 "<<"--protectedMember is :"<< protectedMember <<std::endl;
        // privateMember = 60; // 错误：private成员不能从派生类访问
    }
private:
    void private_public_accessMembers() {
        publicMember = 40; // 正确：public成员可以从派生类访问
        std::cout << "派生类公有制继承之后public函数访问public成员 "<<"--publicMember is :"<< publicMember <<std::endl;
        protectedMember = 50; // 正确：protected成员也可以从派生类访问
        std::cout << "派生类公有制继承之后public函数访问protect成员 "<<"--protectedMember is :"<< protectedMember <<std::endl;
        // privateMember = 60; // 错误：private成员不能从派生类访问

    }
};



// 派生类定义
class protectedDerived : protected Base {
public:
    int public_protected_publicMember;
protected:
    int protected_protected_protectedMember;
private:
    int private_protected_privateMember;
public:
    void public_protected_accessMembers() {
        publicMember = 40; // 正确：public成员可以从派生类访问
        std::cout << "派生类公有制继承之后public函数访问public成员 "<<"--publicMember is :"<< publicMember <<std::endl;
        protectedMember = 50; // 正确：protected成员也可以从派生类访问
        std::cout << "派生类公有制继承之后public函数访问protect成员 "<<"--protectedMember is :"<< protectedMember <<std::endl;
        // privateMember = 60; // 错误：private成员不能从派生类访问
    }
protected:
    void protected_protected_accessMembers() {
        publicMember = 40; // 正确：public成员可以从派生类访问
        std::cout << "派生类公有制继承之后public函数访问public成员 "<<"--publicMember is :"<< publicMember <<std::endl;
        protectedMember = 50; // 正确：protected成员也可以从派生类访问
        std::cout << "派生类公有制继承之后public函数访问protect成员 "<<"--protectedMember is :"<< protectedMember <<std::endl;
        // privateMember = 60; // 错误：private成员不能从派生类访问
    }
private:
    void private_protecte_daccessMembers() {
        publicMember = 40; // 正确：public成员可以从派生类访问
        std::cout << "派生类公有制继承之后public函数访问public成员 "<<"--publicMember is :"<< publicMember <<std::endl;
        protectedMember = 50; // 正确：protected成员也可以从派生类访问
        std::cout << "派生类公有制继承之后public函数访问protect成员 "<<"--protectedMember is :"<< protectedMember <<std::endl;
        // privateMember = 60; // 错误：private成员不能从派生类访问
    }
};






// 派生类定义
class privateDerived : private Base {

public:
    int public_private_publicMember;
protected:
    int protected_private_protectedMember;
private:
    int private_private_privateMember;

public:
    int public_publicMember;
protected:
    int public_protectedMember;
private:
    int public_privateMember;
public:
    void public_private_accessMembers() {
        publicMember = 40; // 正确：public成员可以从派生类访问
        std::cout << "private inherited inner public function visit public number "<<"--publicMember is :"<< publicMember <<std::endl;
        protectedMember = 50; // 正确：protected成员也可以从派生类访问
        std::cout << "private inherited inner public function visit protected number "<<"--protectedMember is :"<< protectedMember <<std::endl;
        // privateMember = 60; // 错误：private成员不能从派生类访问
        base_public_checkAccessInClass();
        std::cout <<"友元函数访问私有成员函数statting..."<<std::endl;
        base_private_checkAccessInClass();//友元函数访问私有成员函数
        std::cout <<"友元函数访问私有成员函数endding..."<<std::endl;
        privateMember = 60; // 添加此类为基类的you元类之后 都可以访问基类中的保护和私有变量了
        std::cout << "friend class private inherited inner public function visit private number "<<"--privateMember is :"<< privateMember <<std::endl;
    }
protected: 
    void protected_private_accessMembers() {
        publicMember = 40; // 正确：public成员可以从派生类访问
        std::cout << "private inherited inner protected function visit public number "<<"--publicMember is :"<< publicMember <<std::endl;
        protectedMember = 50; // 正确：protected成员也可以从派生类访问
        std::cout << "private inherited inner protected function visit protected number "<<"--protectedMember is :"<< protectedMember <<std::endl;
        // privateMember = 60; // 错误：private成员不能从派生类访问
        
    }
private:
    void private_private_accessMembers() {
        publicMember = 40; // 正确：public成员可以从派生类访问
        std::cout << "private inherited inner private function visit public number "<<"--publicMember is :"<< publicMember <<std::endl;
        protectedMember = 50; // 正确：protected成员也可以从派生类访问
        std::cout << "private inherited inner private function visit protected number "<<"--protectedMember is :"<< protectedMember <<std::endl;
        // privateMember = 60; // 错误：private成员不能从派生类访问
    }
};





// // 测试函数定义
// void testBaseClass() {
//     Base baseObj;
//     baseObj.publicMember = 10; // 正确：public成员可以通过对象访问
//     assert(baseObj.getPrivateMember() == 0); // 确认私有成员未被外部修改
// }



// void testDerivedClass() {
//     Derived derivedObj;
//     derivedObj.accessMembers();
//     assert(derivedObj.publicMember == 40); // 验证public成员值
//     //assert(derivedObj.protectedMember == 50); // 注意：这里会失败，因为protected成员无法直接通过派生类对象访问
// }

// void testDerivedObject() {
//     Derived derivedObj;
//     derivedObj.publicMember = 70; // 正确：public成员可以通过派生类对象访问
//     // derivedObj.protectedMember = 80; // 错误：protected成员不能通过派生类对象访问
//     assert(derivedObj.publicMember == 70);
// }

// void testBaseObject() {
//     Base baseObj;
//     baseObj.publicMember = 90; // 正确：public成员可以通过对象访问
//     assert(baseObj.publicMember == 90);
// }