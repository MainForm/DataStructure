#ifndef __NODE_HEADER__
#define __NODE_HEADER__

namespace DataStructor{
    template<typename T>
    class Node{
    private:
        Node* next = nullptr;
        Node* prev = nullptr;
        T value;
    public:
        Node(T value):value(value){}

        void setNext(Node* node){
            next = node;
        }

        Node* getNext() const{
            return next;
        }

        void setPrev(Node* node){
            prev = node;
        }

        Node* getPrev() const{
            return prev;
        }

        const T& getValue() const{
            return value;
        }
        
        void setValue(T value){
            this.value = value;
        }
    };
}

#endif