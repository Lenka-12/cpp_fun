#include "bst.hpp"
#include "stack.hpp"
void bst::insert(int data){
    if (get_root() == nullptr){
        set_root(std::make_shared<node>(data));
    }
    else {
        std::shared_ptr<node> plead = get_root();
        std::shared_ptr<node> ptrail;
        while (plead != nullptr)
        {
            ptrail = plead;
            if (data < plead->m_data){
                plead = plead->m_plchild;
            }
            else if (data > plead -> m_data){
                plead = plead->m_prchild;
            }
            else {
                // No duplicates in binary search tree
                return;
            }        
        }
        if (data < ptrail->m_data){
            ptrail->m_plchild = std::make_shared<node>(data);
        } 
        else {
            ptrail->m_prchild = std::make_shared<node>(data);
        }       
    }
}
std::shared_ptr<tree::node> bst::search(int key){
    std::shared_ptr<node> pcurr = get_root();
    while (pcurr!=nullptr)
    {
        if (key == pcurr ->m_data){
            return pcurr;
        }
        else if (key < pcurr->m_data){
            pcurr = pcurr -> m_plchild;
        }
        else {
            pcurr = pcurr -> m_prchild;
        }
    }
    return nullptr;    
}
std::shared_ptr<tree::node> bst::rsearch(std::shared_ptr<node> proot,int key){
    if (proot != nullptr){
        if ( key == proot -> m_data){
            return proot;
        }
        else if (key < proot ->m_data){
            return rsearch(proot->m_plchild,key);
        }
        else {
            return rsearch(proot->m_prchild,key);
        }
    }
    return nullptr;
}
std::shared_ptr<tree::node> bst::rinsert(std::shared_ptr<node> proot,int key){
    if (proot == nullptr){
        return std::make_shared<node>(key);
    }
    if (key < proot->m_data){
        proot->m_plchild = rinsert(proot->m_plchild,key);
    }
    else if (key > proot -> m_data){
        proot -> m_prchild = rinsert(proot->m_prchild,key);
    }
    return proot;

}
std::shared_ptr<tree::node> bst::rdelete(std::shared_ptr<node> proot,int key){
    std::shared_ptr<node> ptemp;
    if (proot == nullptr){
        return nullptr;
    }
    if (proot->m_plchild == nullptr && proot->m_prchild==nullptr){
        if (get_root() == proot){
            set_root(nullptr);
        }
        proot = nullptr;
        return nullptr;
    }
    if (key < proot->m_data){
        proot->m_plchild = rdelete(proot->m_plchild,key);
    }
    else if (key > proot -> m_data){
        proot -> m_prchild = rdelete(proot->m_prchild,key);
    }

    else {
        if (height(proot->m_plchild) > height(proot->m_prchild)){
            ptemp = closest_left_leaf(proot->m_plchild);
            proot -> m_data = ptemp -> m_data;
            proot->m_plchild = rdelete(proot->m_plchild,ptemp->m_data);
        }
        else {
            ptemp = closest_right_leaf(proot->m_prchild);
            proot -> m_data = ptemp -> m_data;
            proot->m_prchild = rdelete(proot->m_prchild,ptemp->m_data); 
        }
    }
    return proot;
}
    std::shared_ptr<tree::node> bst::closest_right_leaf(std::shared_ptr<node> pnode){
        while (pnode!=nullptr && pnode->m_plchild!=nullptr)
        {
            pnode = pnode->m_plchild;
        }
        return pnode;
    }
    std::shared_ptr<tree::node> bst::closest_left_leaf(std::shared_ptr<node> pnode){
        while (pnode!=nullptr && pnode->m_prchild != nullptr)
        {
            pnode = pnode->m_prchild;
        }
        return pnode;
    }
void bst::create_from_preoder(std::vector<int>& vec){
    stack<std::shared_ptr<node>> st;
    std::vector<int>::iterator it = vec.begin();
    std::shared_ptr<node> pcurr = std::make_shared<node>(*it),ptemp;
    set_root(pcurr);
    it++;

    while (it != vec.end()){
        ptemp = std::make_shared<node>(*it);
        if (*it < pcurr->m_data){
            st.push(pcurr);
            pcurr->m_plchild = ptemp;
            pcurr = ptemp;
            it++;
        }
        else {
            if (!st.is_empty()){
                if (*it > pcurr->m_data && *it < st.top()->m_data){
                    pcurr->m_prchild = ptemp;
                    pcurr = ptemp;
                    it++;
                }
                else {
                    pcurr = st.pop();
                }
   
            }

            else {
                    pcurr->m_prchild = ptemp;
                    pcurr = ptemp;
                    it++;
            }

        }
    }
}

void bst::create_from_postoder(std::vector<int>& vec){
   stack<std::shared_ptr<node>> st;
    std::vector<int>::reverse_iterator it = vec.rbegin();
    std::shared_ptr<node> pcurr = std::make_shared<node>(*it),ptemp;
    set_root(pcurr);
    it++;

    while (it != vec.rend()){
        if (*it > pcurr->m_data){
            ptemp = std::make_shared<node>(*it);
            st.push(pcurr);
            pcurr->m_prchild = ptemp;
            pcurr = ptemp;
            it++;
        }
        else {
            if (!st.is_empty()){
                if (*it < pcurr->m_data && *it > st.top()->m_data){
                    ptemp = std::make_shared<node>(*it);
                    pcurr->m_plchild = ptemp;
                    pcurr = ptemp;
                    it++;
                }
                else {
                    pcurr = st.pop();
                }
   
            }

            else {
                    ptemp = std::make_shared<node>(*it);
                    pcurr->m_plchild = ptemp;
                    pcurr = ptemp;
                    it++;
            }

        }
    }
    
    
}