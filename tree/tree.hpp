#ifndef __TREE__
#define __TREE__
#include "queue/queue.hpp"
class tree {
public:
    struct node{
        std::shared_ptr<node> m_pleft;
        std::shared_ptr<node> m_pright;
        int m_data;

        node():
        m_pleft{nullptr},
        m_pright{nullptr},
        m_data{INT32_MIN}
        {

        }

        node(int data):
        m_pleft{nullptr},
        m_pright{nullptr},
        m_data{data}
        {

        }
        void set_data(int data){
            m_data = data;
        }


    };
    tree()

    {
        m_proot = std::shared_ptr<node>{new node()};

    }
    void create_tree();
    void preorder(std::shared_ptr<node> pnode);
    void postorder(std::shared_ptr<node> pnode);
    void inorder(std::shared_ptr<node> pnode);
    void preorder_display();
    void postorder_display();
    void inorder_display();
private:
    queue<std::shared_ptr<node>> m_queue;
    std::shared_ptr<node> m_proot;


};

#endif