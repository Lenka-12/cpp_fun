#ifndef __TREE__
#define __TREE__
#include <memory>
class tree{
public:
    struct node
    {
        int m_data;
        std::shared_ptr<node> m_plchild;
        std::shared_ptr<node> m_prchild;

        node() :
        m_data{INT32_MIN},
        m_plchild{nullptr},
        m_prchild{nullptr} {

        }

        node(int data) :
        m_data{data},
        m_plchild{nullptr},
        m_prchild{nullptr} {
            
        }
    };
    tree() :
    m_proot{nullptr}
    {

    }
    void set_root(std::shared_ptr<node> proot);
    void preorder(std::shared_ptr<node> proot);
    void postorder(std::shared_ptr<node> proot);
    void inorder(std::shared_ptr<node> proot);
    void it_preorder();
    void it_inorder();
    void it_postorder();
    void create_tree();
    void levelorder();
    unsigned height(std::shared_ptr<node> proot);
    unsigned nodes(std::shared_ptr<node> proot);
    unsigned leaf_nodes(std::shared_ptr<node> proot);
    unsigned internal_nodes(std::shared_ptr<node> proot);
    unsigned degree_one(std::shared_ptr<node> proot);
    unsigned degree_two(std::shared_ptr<node> proot);
    std::shared_ptr<node> get_root();

    


private:
    std::shared_ptr<node> m_proot;
};
#endif