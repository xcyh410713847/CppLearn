#pragma once
#include "RTTIBase.h"

// 基类用
#define RTTI_DECL(BaseClass)                                                        \
public:                                                                             \
    static const char *StaticClassName() { return #BaseClass; }                     \
    virtual const char *GetClassName() const override { return StaticClassName(); } \
    virtual const char *GetBaseClassName() const override { return nullptr; }       \
    virtual bool IsA(const char *className) const override                          \
    {                                                                               \
        return std::strcmp(className, StaticClassName()) == 0;                      \
    }

// 派生类用（含序列化注册）
#define RTTI_IMPL(Class, Parent)                                                                    \
public:                                                                                             \
    static const char *StaticClassName() { return #Class; }                                         \
    static const char *StaticBaseClassName() { return #Parent; }                                    \
    virtual const char *GetClassName() const override { return StaticClassName(); }                 \
    virtual const char *GetBaseClassName() const override { return StaticBaseClassName(); }         \
    virtual bool IsA(const char *className) const override                                          \
    {                                                                                               \
        return std::strcmp(className, StaticClassName()) == 0 || Parent::IsA(className);            \
    }                                                                                               \
    struct AutoRegister                                                                             \
    {                                                                                               \
        AutoRegister()                                                                              \
        {                                                                                           \
            RTTIBase::RegisterClass(StaticClassName(), []() -> RTTIBase * { return new Class(); }); \
        }                                                                                           \
    };                                                                                              \
    static AutoRegister _autoRegisterInstance_;
