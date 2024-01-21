#pragma once
#include <memory>
#include <utility>
#include <iostream>

template<typename T>
class slist {
public:
    struct  Node
    {
        T m_idata;
        std::unique_ptr<Node> m_pnext;
        Node(T idata) 
        : m_idata{idata},
        m_pnext{nullptr}
        {

        }

    };

    class Iterator {
    public:
        Iterator(Node* node) 
        : m_pcurrent{node}
        {

        } 

        Iterator& operator++() {
            m_pcurrent = m_pcurrent->m_pnext.get();
            return *this;
        }
        
        Iterator& operator--() {
            // its a linked list so it does nothing significant
            return *this;
        }

        bool operator!= (const Iterator& it) const {
            return m_pcurrent != it.m_pcurrent;

        }

        T& operator*() const {
            return m_pcurrent->m_idata;
        }

    private:
        Node* m_pcurrent;

    };
    slist() 
    : m_phead{nullptr}
    {

    }

    Iterator begin() const {
        return Iterator(m_phead.get());
    }

    Iterator end() const {
        return Iterator(nullptr);
    }
    bool isempty(){
        return (m_phead == nullptr);
    }

    void append(const T& value);
    T prepend();
    T remove(unsigned index);
    size_t size();
    void reverse();
    void insert(unsigned index, T value);
    void display();
private:
    std::unique_ptr<Node> m_phead;
    

};

template<typename T>
  void slist<T>::append(const T& value) {
        Node* pnode = new Node(value);

        if (isempty()) {
            m_phead = std::unique_ptr<Node>(pnode);
        }

        else {
            Node* pcurrent = m_phead.get();
            while (pcurrent->m_pnext != nullptr)
            {
                pcurrent = pcurrent->m_pnext.get();
            }
            pcurrent->m_pnext =  std::unique_ptr<Node>(pnode);
            
        }

  }

  template<typename T>
  size_t slist<T>::size(){
    Node* pcurrent = m_phead.get();
    size_t len = 0;

    while (pcurrent!=nullptr)
    {
        len++;
        pcurrent = pcurrent->m_pnext.get();
    }

    return len;
    
  }

  template<typename T>
  T slist<T>::prepend() {
    T value{};

    if (isempty()){
        throw std::runtime_error("List empty, nothing to delete");
    }

    else if (size() == 1){
        value = m_phead->m_idata;
        m_phead = nullptr;


    }

    else {
        Node* pcurrent = m_phead.get();
        while(pcurrent->m_pnext->m_pnext != nullptr){
            pcurrent = pcurrent->m_pnext.get();
        }
        value = pcurrent->m_pnext->m_idata;
        pcurrent->m_pnext = nullptr;

    }

    return value;
  }

  template<typename T>
  T slist<T>::remove(unsigned index){
    T value{};
    if (index >= size()){
        std::cout << "whichcraft\n";
        throw std::runtime_error("Index out of bound.");
    }
    else {
        Node* pcurrent = m_phead.get();
        if (index==0){
            value = pcurrent->m_idata;
            m_phead = std::move(m_phead->m_pnext);
        }

        else {

            for (unsigned i=0; i<(index-1); i++){
                pcurrent = pcurrent->m_pnext.get();
            }

            value = pcurrent->m_pnext->m_idata;
            pcurrent->m_pnext = std::move(pcurrent->m_pnext->m_pnext);
        }

    }

    return value;


  }

  template<typename T>
  void slist<T>::display(){
    for (const int& value : *this) {
        std::cout << value << " ";
    } 
    std::cout << "\n";
  }

  template<typename T>
  void slist<T>::reverse() {
    if (isempty() || size()==1 ){
        return;
    }

    else {
        std::unique_ptr<Node> ptemp     = nullptr;
        std::unique_ptr<Node> ptrailing = std::move(m_phead);
        m_phead = std::move(ptrailing->m_pnext);
        ptrailing->m_pnext = nullptr;
        while (m_phead->m_pnext != nullptr)
        {
            ptemp  = std::move(m_phead->m_pnext);
            m_phead->m_pnext = std::move(ptrailing);
            ptrailing = std::move(m_phead);
            m_phead = std::move(ptemp);
        }
        m_phead->m_pnext = std::move(ptrailing);
        
    }
  }

template<typename T>
void slist<T>::insert(unsigned index, T value){
    if  (index > size()){
            throw std::runtime_error("Index is out of bound.");
    }
    else{
        Node* ptemp = new Node(value);

        if(index == 0){
            std::unique_ptr<Node> pnode = std::move(m_phead);
            ptemp->m_pnext = std::move(pnode);
            m_phead = std::unique_ptr<Node>(ptemp);


        }

        else {
            Node* pcurrent = m_phead.get();


            for(unsigned i=0; (i<index-1); i++) {
                pcurrent = pcurrent->m_pnext.get();
            }
            std::unique_ptr<Node> pnode = std::move(pcurrent->m_pnext);
            ptemp->m_pnext = std::move(pnode);
            pcurrent->m_pnext = std::unique_ptr<Node>(ptemp);



        }

    }
    
  }