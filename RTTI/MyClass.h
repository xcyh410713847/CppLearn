#pragma once
#include "RTTIMacro.h"
#include <sstream>

class MyClass : public RTTIBase
{
    RTTI_IMPL(MyClass, RTTIBase)
public:
    int value = 0;
    std::string name;

    virtual std::string Serialize() const override
    {
        // 用长度前缀法，先序列化 value，再 name 长度和内容
        std::ostringstream oss;
        oss << value << '\n'
            << name.size() << '\n'
            << name;
        return oss.str();
    }
    virtual void Deserialize(const std::string &data) override
    {
        std::istringstream iss(data);
        size_t nameLen;
        iss >> value;
        iss.ignore(); // 跳过换行
        iss >> nameLen;
        iss.ignore(); // 跳过换行
        name.resize(nameLen);
        iss.read(&name[0], nameLen);
    }
};
