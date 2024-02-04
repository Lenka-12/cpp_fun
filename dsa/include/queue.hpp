#ifndef __QUEUE__
#define __QUEUE__
#include <memory>
#include <iostream>
template<typename T>
class queue{

public:
    struct node
    {
        T m_data;
        std::shared_ptr<node> m_pnext;

        node () :
        m_data{},
        m_pnext{nullptr}
        {

        }

        node(T data) :
        m_data{data},
        m_pnext{nullptr}
        {

        }
    };

    queue(){
        
    }
    void display();
    bool is_empty();
    size_t size();
    void enqueue(T data);
    T dequeue();
private:
    std::shared_ptr<node> m_pfront;
    std::shared_ptr<node> m_prear;
    size_t m_len{0};

    

};
template<typename T>
bool queue<T>::is_empty(){
    return (m_len == 0);
}

template<typename T>
void queue<T>::enqueue(T data){
    if (is_empty()){
        m_pfront = std::make_shared<node>(data);
        m_prear = m_pfront;
    }
    else {
        std::shared_ptr<node> ptemp = std::make_shared<node>(data);
        if (m_pfront == m_prear){
            m_prear = ptemp;
            m_pfront->m_pnext = m_prear;
        }

        else {
            m_prear->m_pnext = ptemp;
            m_prear = m_prear->m_pnext;
        }


    }
        m_len++;

}

template<typename T>
T queue<T>::dequeue(){
    if(is_empty()){
        throw std::runtime_error("Queue is empty!!");
    }

    else {
        T res = m_pfront->m_data;
        if (m_len == 1){
            m_pfront  = m_pfront->m_pnext;
            m_prear = m_prear;
        }
        
        else {
           m_pfront = m_pfront->m_pnext; 
        }
        m_len--;

        return res;
    }
}

template<typename T>
size_t queue<T>::size(){
    return m_len;
}

template<typename T>
void queue<T>::display(){
    node* pnode = m_pfront.get();
    std::cout << "[";
    while ( pnode != nullptr)
    {
        std::cout << pnode->m_data << ((pnode->m_pnext != nullptr) ? ", " : "");
        pnode = pnode->m_pnext.get();
        
    }
    std::cout << "]\n";

}
#endif