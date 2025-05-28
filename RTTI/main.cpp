#include <iostream>
#include "MyClass.h"

int main()
{
    // 创建并序列化
    MyClass *obj = new MyClass();
    obj->value = 42;
    obj->name = "Hello";
    std::string data = obj->Serialize();
    std::cout << "Serialized: " << data << std::endl;
    std::string className = obj->GetClassName();

    // 反序列化
    RTTIBase *baseObj = RTTIBase::CreateInstance(className);
    if (baseObj)
    {
        baseObj->Deserialize(data);
        MyClass *newObj = baseObj->SafeDownCast<MyClass>();
        if (newObj)
        {
            std::cout << "Deserialized: " << newObj->name << ", " << newObj->value << std::endl;
        }
    }
    delete obj;
    delete baseObj;
    return 0;
}