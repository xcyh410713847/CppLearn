#pragma once
#include <string>
#include <cstring>
#include <unordered_map>
#include <functional>

class RTTIBase
{
public:
    virtual ~RTTIBase() = default;
    virtual const char *GetClassName() const = 0;
    virtual const char *GetBaseClassName() const = 0;
    virtual bool IsA(const char *className) const
    {
        return std::strcmp(className, GetClassName()) == 0;
    }

    template <typename T>
    T *SafeDownCast()
    {
        if (IsA(T::StaticClassName()))
        {
            return static_cast<T *>(this);
        }
        return nullptr;
    }

    // 序列化接口
    virtual std::string Serialize() const = 0;
    // 反序列化接口
    virtual void Deserialize(const std::string &data) = 0;

    // 工厂注册和创建
    using FactoryFunc = std::function<RTTIBase *()>;
    static void RegisterClass(const std::string &className, FactoryFunc func)
    {
        GetRegistry()[className] = func;
    }
    static RTTIBase *CreateInstance(const std::string &className)
    {
        auto it = GetRegistry().find(className);
        if (it != GetRegistry().end())
        {
            return it->second();
        }
        return nullptr;
    }

private:
    static std::unordered_map<std::string, FactoryFunc> &GetRegistry()
    {
        static std::unordered_map<std::string, FactoryFunc> registry;
        return registry;
    }
};
