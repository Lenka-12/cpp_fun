#include  "array_queue.hpp"
#include <iostream>

array_queue::array_queue(int len) :
m_len{len},
m_front{-1},
m_rear{-1},
m_pqueue{std::make_unique<int[]>(len)}
{

}

void array_queue::enqueue(int value){
    if (is_full()){
        throw std::runtime_error("Queue is full");
    }
    else {
        m_rear++;
        m_pqueue[m_rear] = value;
    }
}

int array_queue::dequeue(){
    if(is_empty()){
        throw std::runtime_error("Queue is empty!!");
    }

    else {
        int ret = INT32_MIN;
        m_front++;
        ret = m_pqueue[m_front];

        return ret;
    }
}

bool array_queue::is_empty(){
    return (m_rear == m_front);
}

bool array_queue::is_full(){
    return (m_rear == (m_len-1));
}

void array_queue::display(){
    int i = m_front+1;
    std::cout << "[";
    for( ; i<=m_rear; i++){
        std::cout << m_pqueue[i] <<((i!=m_rear) ?  ", " : "");
    }
    std::cout << "]\n";
}
