#ifndef __ARRAY_QUEUE__
#define __ARRAY_QUEUE__

#include <cstdio>
#include <memory>
struct array_queue
{
public:
    array_queue(int len);
    void enqueue(int value);
    bool is_full();
    bool is_empty();
    int dequeue();
    void display();

private:
    int m_len;    
    int m_front;
    int m_rear;
    std::unique_ptr<int[]> m_pqueue;
};
#endif