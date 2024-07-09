/*************************************************************************
**文件: Class\ClassInherit\ClassInherit.cpp
**作者: shyfan
**日期: 2024/07/09 17:08:09
**功能: 类继承
*************************************************************************/

#include <iostream>

class Base
{
private:
    int privateParam;
    void BasePrivateMethod()
    {
        std::cout << "Base::privateMethod" << std::endl;
    }

protected:
    int protectedParam;
    void BaseProtectedMethod()
    {
        std::cout << "Base::protectedMethod" << std::endl;
    }

public:
    int publicParam;
    void BasePublicMethod()
    {
        std::cout << "Base::publicMethod" << std::endl;
    }
};

/*
 * 私有继承
 * 基类的公有成员和保护成员都被派生类继承下来之后变成私有成员
 * 派生类的新增成员可以访问基类的公有成员和保护成员
 * 派生类的对象不能访问派生类继承基类的公有成员，保护成员和私有成员
 */
class DerivedPrivate : private Base
{
protected:
    void protectedMethod()
    {
        BaseProtectedMethod();
    }

public:
    void publicMethod()
    {
        BasePublicMethod();
    }
};

/*
 * 受保护继承
 * 基类的公有成员和保护成员被派生类继承后变成保护成员
 * 派生类的新增成员可以访问基类的公有成员和保护成员
 * 派生类的对象不能访问派生类继承基类的公有成员，保护成员和私有成员
 */
class DerivedProtected : protected Base
{
protected:
    void protectedMethod()
    {
        BaseProtectedMethod();
    }

public:
    void publicMethod()
    {
        BasePublicMethod();
    }
};

/*
 * 公有继承
 * 基类的公有成员和保护成员的访问属性不变
 * 派生类的新增成员可以访问基类的公有成员和保护成员
 * 派生类的对象只能访问派生类的公有成员（包括继承的公有成员）
 */
class DerivedPublic : public Base
{
protected:
    void protectedMethod()
    {
        BaseProtectedMethod();
    }

public:
    void publicMethod()
    {
        BasePublicMethod();
    }
};

int main()
{
    // 私有继承
    DerivedPrivate derivedPrivate;
    // derivedPrivate.BaseProtectedMethod();		// 不能使用基类的受保护函数，私有继承会将基类的受保护变为私有
    // derivedPrivate.BasePublicMethod();		// 不能使用基类的公有函数，私有继承会将基类的公有变为私有
    derivedPrivate.publicMethod();
    // derivedPrivate.protectedMethod();			// 对象无法访问受保护

    // 受保护继承
    DerivedProtected derivedProtected;
    // derivedProtected.BaseProtectedMethod();	// 不能使用基类的受保护函数，受保护继承会将基类的受保护变为受保护
    // derivedProtected.BasePublicMethod();	// 不能使用基类的公有函数，受保护继承会将基类的公有变为受保护
    derivedProtected.publicMethod();
    // derivedProtected.protectedMethod();		// 对象无法访问受保护

    // 公有继承
    DerivedPublic derivedPublic;
    // derivedPublic.BaseProtectedMethod();	// 不能使用基类的受保护函数，公有继承基类访问属性不变
    derivedPublic.BasePublicMethod(); // 可以使用基类的公有函数，公有继承基类访问属性不变
    derivedPublic.publicMethod();
    // derivedPublic.protectedMethod();			// 对象无法访问受保护
}
