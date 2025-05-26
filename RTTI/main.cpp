#include <iostream>
#include <string>
#include <memory>

class RTTIBase
{
public:
    // 获取类型名称
    virtual const std::string &getTypeName() const = 0;

    // 检查是否是特定类型
    template <typename T>
    bool isType() const
    {
        return (typeid(*this) == typeid(T));
    }

    // 安全向下转型
    template <typename T>
    T *asType()
    {
        return isType<T>() ? static_cast<T *>(this) : nullptr;
    }

    template <typename T>
    const T *asType() const
    {
        return isType<T>() ? static_cast<const T *>(this) : nullptr;
    }

    virtual ~RTTIBase() = default;
};

// 宏定义简化RTTI类的创建
#define RTTI_CLASS(className)                               \
public:                                                     \
    static const std::string &staticGetTypeName()           \
    {                                                       \
        static const std::string typeName(#className);      \
        return typeName;                                    \
    }                                                       \
    virtual const std::string &getTypeName() const override \
    {                                                       \
        return staticGetTypeName();                         \
    }                                                       \
    static std::shared_ptr<className> create()              \
    {                                                       \
        return std::make_shared<className>();               \
    }

// 示例使用
class MyClass : public RTTIBase
{
    RTTI_CLASS(MyClass)

public:
    void doSomething()
    {
        std::cout << "MyClass is doing something!" << std::endl;
    }
};

class AnotherClass : public RTTIBase
{
    RTTI_CLASS(AnotherClass)

public:
    void doAnotherThing()
    {
        std::cout << "AnotherClass is doing another thing!" << std::endl;
    }
};

int main()
{
    std::shared_ptr<RTTIBase> obj1 = MyClass::create();
    std::shared_ptr<RTTIBase> obj2 = AnotherClass::create();

    // 获取类型名称
    std::cout << "obj1 type: " << obj1->getTypeName() << std::endl;
    std::cout << "obj2 type: " << obj2->getTypeName() << std::endl;

    // 类型检查
    if (obj1->isType<MyClass>())
    {
        std::cout << "obj1 is MyClass" << std::endl;
    }

    if (!obj2->isType<MyClass>())
    {
        std::cout << "obj2 is not MyClass" << std::endl;
    }

    // 安全向下转型
    if (auto myObj = obj1->asType<MyClass>())
    {
        myObj->doSomething();
    }

    if (auto anotherObj = obj2->asType<AnotherClass>())
    {
        anotherObj->doAnotherThing();
    }

    // 尝试错误转型
    if (auto wrongCast = obj1->asType<AnotherClass>())
    {
        std::cout << "This should not print!" << std::endl;
    }
    else
    {
        std::cout << "Failed to cast obj1 to AnotherClass (as expected)" << std::endl;
    }

    return 0;
}