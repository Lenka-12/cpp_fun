#include "tree.hpp"

void tree::create_tree(){
    std::shared_ptr<node> ptemp;
    std::shared_ptr<node> pcurr;
    int data;

    std::cout << "Enter root value: ";
    std::cin >> data;

    m_proot->set_data(data);
    m_queue.enqueue(m_proot);

    while (!m_queue.is_empty()){
        pcurr = m_queue.dequeue();
        std::cout << "Enter left child value of "<<pcurr->m_data<< " ";
        std::cin >> data;
        if (data != -1){
            ptemp = std::make_shared<node>(data);
            pcurr->m_pleft = ptemp;
            m_queue.enqueue(ptemp);
        }

        std::cout << "Enter right child value of "<<pcurr->m_data<< " ";
        std::cin >> data;
        if (data != -1){
            ptemp = std::make_shared<node>(data);
            pcurr->m_pright = ptemp;
            m_queue.enqueue(ptemp);
        }

    }
}

void tree::preorder(std::shared_ptr<node> pnode){
    if (pnode != nullptr){
        std::cout << pnode->m_data<<" ";
        preorder(pnode->m_pleft);
        preorder(pnode->m_pright);
    }
}
void tree::inorder(std::shared_ptr<node> pnode){
    if (pnode != nullptr){
        inorder(pnode->m_pleft);
        std::cout << pnode->m_data<<" ";
        inorder(pnode->m_pright);
    }
}
void tree::postorder(std::shared_ptr<node> pnode){
    if (pnode != nullptr){
        postorder(pnode->m_pleft);
        postorder(pnode->m_pright);
        std::cout << pnode->m_data<<" ";
    }
}
void tree::preorder_display(){
    preorder(m_proot);
}

void tree::inorder_display(){
    inorder(m_proot);
}

void tree::postorder_display(){
    postorder(m_proot);
}