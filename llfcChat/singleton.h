#ifndef SINGLETON_H
#define SINGLETON_H

#include "global.h"

template <typename T>

class SingleTon{

protected:
    SingleTon() = default;
    SingleTon(const SingleTon<T>&) = delete;
    SingleTon& operator = (const SingleTon<T>& st) = delete;
    static std::shared_ptr<T> _instance;
public:
    static std::shared_ptr<T> GetInstance(){
        static std::once_flag s_flag;
        std::call_once(s_flag,[&](){
            //不能使用make_shared  因为底层会调用构造函数，而构造函数是私有的
            _instance = std::shared_ptr<T>(new T);
        });

        return _instance;
    }
    ~SingleTon(){
        std::cout<<"this is singleton destruct"<<std::endl;
    }

    void PrintAddress(){
        std::cout << _instance.get() << std::endl;
    }
};

template <typename T>
std::shared_ptr<T> SingleTon<T>::_instance = nullptr;

#endif // SINGLETON_H
