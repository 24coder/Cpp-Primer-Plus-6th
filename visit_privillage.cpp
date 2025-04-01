




int main() {
    std::cout << "Running tests..." << std::endl;
    //Base::base_public_checkAccessInClass();//无法使用类名直接访问成员函数，可以设置为静态成员函数可以访问。
    //Base::base_protected_checkAccessInClass();//私有成员函数和protect成员函数在类外无法直接调用
    Base baseInstance;
    baseInstance.base_public_checkAccessInClass(); // 测试基类内部成员访问
    /*
    base_protected_checkAccessInClass 是 Base 类的 protected 成员函数。
    protected 成员函数只能在 Base 类内部、Base 类的派生类内部以及 Base 类的友元函数中访问。
    在 main 函数中，baseInstance 是 Base 类的对象，main 函数不属于 Base 类或其派生类，因此无法访问 protected 成员函数。
    */
    //baseInstance.base_protected_checkAccessInClass();
    //baseInstance.base_private_checkAccessInClass();// 
    
    // testBaseClass(); // 测试其他类对基类成员的访问
    // testDerivedClass(); // 测试派生类对基类成员的访问
    // testDerivedObject(); // 测试派生类对象对基类成员的访问
    // testBaseObject(); // 测试基类对象对自身成员的访问
    publicDerived publicDerivedInstance;
    protectedDerived protectedDerivedInstance;
    std::cout << "................."<<protectedDerivedInstance.public_protected_publicMember <<std::endl;
    //publicDerivedInstance.base_protected_checkAccessInClass();
    privateDerived privateDerivedInstance;
    
    privateDerivedInstance.public_private_accessMembers();
    std::cout << "All tests passed successfully." << std::endl;
    return 0;
}