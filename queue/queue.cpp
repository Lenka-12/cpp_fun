/*
#include "queue.hpp"
#include <iostream>

void queue::enqueue(int data){
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
int queue::dequeue(){
    if(is_empty()){
        throw std::runtime_error("Queue is empty!!");
    }

    else {
        int res = m_pfront->m_data;
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
bool queue::is_empty(){
    return (m_len == 0);
}

size_t queue::size(){
    return m_len;
}

void queue::display(){
    node* pnode = m_pfront.get();
    std::cout << "[";
    while ( pnode != nullptr)
    {
        std::cout << pnode->m_data << ((pnode->m_pnext != nullptr) ? ", " : "");
        pnode = pnode->m_pnext.get();
        
    }
    std::cout << "]\n";
    
}
*/