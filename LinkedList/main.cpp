#include "slist.hpp"
#include <iostream>
int main() {
        // Create a linked list
    slist<int> myList;
    myList.append(1);
    std::cout << myList.prepend()  << std::endl;
    myList.append(2);
    myList.append(3);
    myList.display();
    std::cout << "\n";
    std::cout << myList.prepend()  << std::endl;
    std::cout << myList.prepend()  << std::endl;

    
    for (int i=0; i<= 10; i+=1){
        myList.append(i);
    }
    myList.display();
    myList.insert(1,19);
    myList.insert(4,33);
    myList.insert(0,25);
    myList.insert(myList.size(),1011);
    myList.display();
    myList.reverse();
    myList.display();
    

    return 0;
}