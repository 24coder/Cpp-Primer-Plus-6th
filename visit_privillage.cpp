




int main() {
    std::cout << "Running tests..." << std::endl;
    //Base::base_public_checkAccessInClass();//�޷�ʹ������ֱ�ӷ��ʳ�Ա��������������Ϊ��̬��Ա�������Է��ʡ�
    //Base::base_protected_checkAccessInClass();//˽�г�Ա������protect��Ա�����������޷�ֱ�ӵ���
    Base baseInstance;
    baseInstance.base_public_checkAccessInClass(); // ���Ի����ڲ���Ա����
    /*
    base_protected_checkAccessInClass �� Base ��� protected ��Ա������
    protected ��Ա����ֻ���� Base ���ڲ���Base ����������ڲ��Լ� Base �����Ԫ�����з��ʡ�
    �� main �����У�baseInstance �� Base ��Ķ���main ���������� Base ����������࣬����޷����� protected ��Ա������
    */
    //baseInstance.base_protected_checkAccessInClass();
    //baseInstance.base_private_checkAccessInClass();// 
    
    // testBaseClass(); // ����������Ի����Ա�ķ���
    // testDerivedClass(); // ����������Ի����Ա�ķ���
    // testDerivedObject(); // �������������Ի����Ա�ķ���
    // testBaseObject(); // ���Ի������������Ա�ķ���
    publicDerived publicDerivedInstance;
    protectedDerived protectedDerivedInstance;
    std::cout << "................."<<protectedDerivedInstance.public_protected_publicMember <<std::endl;
    //publicDerivedInstance.base_protected_checkAccessInClass();
    privateDerived privateDerivedInstance;
    
    privateDerivedInstance.public_private_accessMembers();
    std::cout << "All tests passed successfully." << std::endl;
    return 0;
}