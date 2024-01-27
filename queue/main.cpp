#include <iostream>
#include "queue.hpp"

int main(){
    queue<int> q;
    std::cout << std::boolalpha;
    std::cout << "is_empty at beginning "<< q.is_empty() << "\n";
    for (int i = 0; i<10; i++){
        q.enqueue(i);
    }
    q.display();
    std::cout << q.dequeue() << "\n";
    std::cout << q.dequeue() << "\n";
    q.display();
    return 0;

}