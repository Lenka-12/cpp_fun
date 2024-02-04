#include "tree.hpp"
#include "stack.hpp"
#include "queue.hpp"
unsigned tree::height(std::shared_ptr<node> proot){
    unsigned x = 0, y = 0;
    if (proot != nullptr){
        x = height(proot->m_plchild);
        y = height(proot->m_prchild);
        if (x > y){
            return x + 1;
        }
        else {
            return y + 1;
        }
    }
    return 0;
}
void tree::set_root(std::shared_ptr<node> proot){
    m_proot = proot;
}
std::shared_ptr<tree::node> tree::get_root(){
    return m_proot;
}
void tree::preorder(std::shared_ptr<node> proot){
    if (proot != nullptr){
        std::cout << proot->m_data << " ";
        preorder(proot->m_plchild);
        preorder(proot->m_prchild);
    }
}
void tree::inorder(std::shared_ptr<node> proot){
    if (proot != nullptr){
        inorder(proot->m_plchild);
        std::cout << proot->m_data << " ";
        inorder(proot->m_prchild);
    }
}
void tree::postorder(std::shared_ptr<node> proot){
    if (proot != nullptr){
        postorder(proot->m_plchild);
        postorder(proot->m_prchild);
        std::cout << proot->m_data << " ";
    }
}
void tree::create_tree(){
    queue<std::shared_ptr<node>> q;
    std::shared_ptr<node> ptemp;
    std::shared_ptr<node> pcurr;
    int data;
    std::cout << "Enter root value: ";
    std::cin >> data;
    m_proot = std::make_shared<node>(data);
    q.enqueue(m_proot);
    while (!q.is_empty()){
        pcurr = q.dequeue(); 
        std::cout << "Enter left child value of "<<pcurr->m_data<< " ";
        std::cin >> data;
        if (data != -1){
            ptemp = std::make_shared<node>(data);
            pcurr->m_plchild = ptemp;
            q.enqueue(ptemp);
        }
        std::cout << "Enter right child value of "<<pcurr->m_data<< " ";
        std::cin >> data;
        if (data != -1){
            ptemp = std::make_shared<node>(data);
            pcurr->m_prchild = ptemp;
            q.enqueue(ptemp);
        }
    }
}
unsigned tree::nodes(std::shared_ptr<node> proot){
    if (proot != nullptr){
        unsigned x = nodes(proot->m_plchild);
        unsigned y = nodes(proot->m_prchild);
        return x + y + 1;
    }
    return 0;
  }
 unsigned tree::leaf_nodes(std::shared_ptr<node> proot){
    if (proot != nullptr){
        unsigned x = leaf_nodes(proot->m_plchild);
        unsigned y = leaf_nodes(proot->m_prchild);
        if (proot->m_prchild == nullptr && proot->m_plchild == nullptr){
            return x + y + 1;
        }
        else {
            return x + y;
        }    
    }
    return 0;
  }
unsigned tree::internal_nodes(std::shared_ptr<node> proot){
    if (proot != nullptr){
        unsigned x = internal_nodes(proot->m_plchild);
        unsigned y = internal_nodes(proot->m_prchild);
        if (proot->m_prchild != nullptr || proot->m_plchild != nullptr){
            return x + y + 1;
        }
        else {
            return x + y;
        }    
    }
    return 0;
  }
unsigned tree::degree_two(std::shared_ptr<node> proot){
    if (proot != nullptr){
        unsigned x = degree_two(proot->m_plchild);
        unsigned y = degree_two(proot->m_prchild);
        if (proot->m_prchild != nullptr && proot->m_plchild != nullptr){
            return x + y + 1;
        }
        else {
            return x + y;
        }    
    }
    return 0;
  }
unsigned tree::degree_one(std::shared_ptr<node> proot){
    if (proot != nullptr){
        unsigned x = degree_one(proot->m_plchild);
        unsigned y = degree_one(proot->m_prchild);
        if ((proot->m_prchild != nullptr && proot->m_plchild == nullptr) || (proot->m_prchild == nullptr && proot->m_plchild != nullptr)){
            return x + y + 1;
        }
        else {
            return x + y;
        }    
    }
    return 0;
  }
void tree::it_preorder(){
    stack<std::shared_ptr<node>> s;
    std::shared_ptr<node> pcurr = m_proot;
    while (!s.is_empty() || pcurr!=nullptr)
    {
        if (pcurr != nullptr){
            std::cout << pcurr->m_data << " ";
            s.push(pcurr);
            pcurr = pcurr->m_plchild;
        }
        else{
            pcurr = s.pop();
            pcurr = pcurr->m_prchild;
        }
    }
    
}
void tree::it_inorder(){
    stack<std::shared_ptr<node>> s;
    std::shared_ptr<node> pcurr = m_proot;
    while (!s.is_empty() || pcurr!=nullptr)
    {
        if (pcurr != nullptr){
            s.push(pcurr);
            pcurr = pcurr->m_plchild;
        }
        else{
            pcurr = s.pop();
            std::cout << pcurr->m_data << " ";
            pcurr = pcurr->m_prchild;
        }
    }
    
}
void tree::it_postorder(){
    stack<std::shared_ptr<node>> s;
    std::shared_ptr<node> pcurr = m_proot;
    while (!s.is_empty() || pcurr!=nullptr)
    {
        if (pcurr != nullptr){
            s.push(pcurr);
            pcurr = pcurr->m_plchild;
        }
        else{
            std::shared_ptr<node> ptemp = s.top();
            if (ptemp->m_prchild == nullptr){
                std::cout << ptemp->m_data << " ";
                s.pop();
                while(!s.is_empty() && ptemp==s.top()->m_prchild){
                    std::cout << s.top()->m_data << " ";
                    ptemp = s.pop();
                }        
            }
            else {
                pcurr = ptemp->m_prchild;
            }
        }
    }   
}
void tree::levelorder(){
    queue<std::shared_ptr<node>> q;
    q.enqueue(m_proot);
    std::shared_ptr<node> pcurr;
    while (!q.is_empty()){
        pcurr = q.dequeue();
        std::cout << pcurr -> m_data << " ";
        if(pcurr->m_plchild != nullptr){
            q.enqueue(pcurr->m_plchild);  
        }
        if (pcurr -> m_prchild != nullptr){
            q.enqueue(pcurr->m_prchild);
        }
    }   
}