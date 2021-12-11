#ifndef __LIST_HEADER__
#define __LIST_HEADER__

#include "node.h"

namespace DataStructure
{
    template<typename T>
    class List{
    public:
        class Iterator{
        private:
            Node<T>* __node;
        public:
            explicit Iterator(Node<T>* cursor) : __node(cursor){
            }

            Iterator& operator++(){
                __node = __node->getNext();
                return *this;
            }

            Iterator operator++(int){
                ++(*this);
                return Iterator(__node);
            }

            Iterator& operator--(){
                __node = __node->getPrev();
                return *this;
            }

            Iterator operator--(int){
                --(*this);
                return Iterator(__node);
            }

            const T& operator*() const {
                return __node->getValue();
            }
            
            bool operator==(const Iterator& iter) const{
                return __node == iter.__node;
            }

            bool operator!=(const Iterator& iter) const{
                return !(*this == iter);
            }
        };

    private:
        using NodeT = Node<T>;

        NodeT* head = nullptr;
        NodeT* tail = nullptr;
        
        uint32_t size = 0;
    public:

        List()
        {
            head = new Node<T>(T());
            tail = new Node<T>(T());

            head->setNext(tail);
            tail->setPrev(head);
        }

        void push_front(T value){
            NodeT* tmp = new NodeT(value);

            tmp->setNext(head->getNext());
            tmp->setPrev(head);
            
            head->getNext()->setPrev(tmp);
            head->setNext(tmp);
            
            size++;
        }

        void push_back(T value){
            NodeT* tmp = new NodeT(value);

            tmp->setPrev(tail->getPrev());
            tmp->setNext(tail);

            tail->getPrev()->setNext(tmp);
            tail->setPrev(tmp);

            size++;
        }

        void pop_front(){
            
            if(size == 0)
                return;

            NodeT* tmp = head->getNext();

            head->setNext(tmp->getNext());
            tmp->getNext()->setPrev(head);

            delete tmp;
            size--;
        }
        void pop_back(){
            if(size == 0)
                return;

            NodeT* tmp = tail->getPrev();

            tail->setPrev(tmp->getPrev());
            tmp->getPrev()->setNext(tail);

            delete tmp;
            size--;
        }

        void clear(){
            while(head->getNext() != tail){
                pop_back();
            }
        }

        const T& front() const {
            return head->getNext()->getValue();
        }

        const T& back() const {
            return tail->getPrev()->getValue();
        }

        Iterator begin() const {
            return Iterator(head->getNext());
        }

        Iterator end() const{
            return Iterator(tail);
        }

        uint32_t Size() const{
            return size;
        }
    };
} // namespace DataSturctor

#endif