#ifndef __STACK__
#define __STACK__
#include <memory>
template<typename T>
class stack{
public:
    struct node{
        T m_data;
        std::unique_ptr<node> m_pnext;

        node():
        m_data{},
        m_pnext{nullptr};
        {

        }
        node(T data) :
        m_data{data},
        m_pnext{nullptr}
        {

        }
        void set_data(T data){
            m_data = data;
        }

    };
};
#endif

