#ifndef __BST__
#define __BST__
#include "tree.hpp"
#include <vector>
class bst : public tree{
public:
    /// @brief Inserts a node on the binary search tree using iteration
    /// @param data node data
    void insert(int data);
    /// @brief Inserts a node on the binary search tree using recursion
    /// @param proot shared pointer to root node
    /// @param key node data
    /// @return    shared pointer of the inserted node, if node already exists returns nullptr
    std::shared_ptr<node> rinsert(std::shared_ptr<node> proot, int key);
    /// @brief Searches a key in a binary search tree using iteration
    /// @param key value of the node to search for
    /// @return shared pointer to the node if found, otherwise returns nullptr
    std::shared_ptr<node> search(int key);
    /// @brief Searches a key in a binary search tree using recursion
    /// @param proot shared pointer to root node
    /// @param key value of the node to search for
    /// @return shared pointer to the node if found, otherwise returns nullptr
    std::shared_ptr<node> rsearch(std::shared_ptr<node> proot,int key);
    /// @brief deletes a node of a binary search tree
    /// @param proot shared pointer to root node
    /// @param key  data of the node to be deleted
    /// @return   shared pointer to the deleted node, or nullptr if node does not exist
    std::shared_ptr<node> rdelete(std::shared_ptr<node> proot,int key);
    std::shared_ptr<node> closest_right_leaf(std::shared_ptr<node> pnode);
    std::shared_ptr<node> closest_left_leaf(std::shared_ptr<node> pnode);
    /// @brief Creates a binary search tree from preoder traversals
    /// @param vec, vector containing the data of the nodes in the order in which they are visited
    void create_from_preoder(std::vector<int>& vec);
    /// @brief Creates a binary search tree from postoder traversals
    /// @param vec, vector containing the data of the nodes in the order in which they are visited
    void create_from_postoder(std::vector<int>& vec);
    
 
    
};
#endif