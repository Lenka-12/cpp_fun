#ifndef __STACK__
#define __STACK__
#include <memory>
#include <iostream>
template<typename T>
class stack{
public:
    struct node{
        T m_data;
        std::shared_ptr<node> m_pnext;

        node():
        m_data{},
        m_pnext{nullptr}
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
    T pop();
    void push(T data);
    bool is_empty();
    T top();
private:
    std::shared_ptr<node> m_ptop;
    size_t m_len{0};
};
template<typename T>
void stack<T>::push(T data){
    if (is_empty()){
        m_ptop = std::make_shared<node>(data);
    }

    else {
        std::shared_ptr<node> ptemp = std::make_shared<node>(data);
        ptemp -> m_pnext = m_ptop;
        m_ptop = ptemp;
    }
    m_len++;

}
template<typename T>
bool stack<T>::is_empty(){
    return (m_len == 0);
}

template<typename T>
T stack<T>::top(){
    if (!is_empty()){
        return m_ptop->m_data;
    }
    else {
        throw std::runtime_error("Stack is empty!!");
    }
}

template<typename T>
T stack<T>::pop(){
    if (!is_empty()){
        T res = m_ptop->m_data;
        m_ptop = m_ptop->m_pnext;
        m_len--;

        return res;
    }
    else {
        throw std::runtime_error("Stack is empty!!");
    }
}
#endif
