#include "tree.hpp"
#include "bst.hpp"
#include <iostream>
#include <vector>

int main(){
    std::vector<int> vec;
    bst b1;
    std::cout << "Creating from post order.....\n";
    vec = {6,9,8,18,12,30,43,50,44,34,24};
    b1.create_from_postoder(vec);
    b1.it_inorder();
    std::cout << "\n";
 
    std::cout << "tree...\n";
    b1.it_postorder();
    std::cout << "\n";

    std::cout << "Vector..\n";
    for (const int& i: vec){
        std::cout << i << " "; 
    }
    std::cout << "\n";

    return 0;
}