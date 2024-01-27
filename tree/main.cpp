#include "tree.hpp"

int main(){

    tree t{};
    t.create_tree();
    t.preorder_display();
    std::cout << "\n";

    t.inorder_display();
    std::cout << "\n";

    t.postorder_display();
    std::cout << "\n";

    return 0;
}