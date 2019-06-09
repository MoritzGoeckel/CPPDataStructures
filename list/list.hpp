#ifndef list_h
#define list_h

#include <iostream>

template<typename T>
class List{

    private:
    struct Entry{
        Entry(T v, Entry* n) : value(v), next(n){ }
        Entry* next;
        T value;
        void remove() { 
            if(next == nullptr) 
                return;
            
            next->remove();
            delete next;
        }
    };
    
    Entry* _root;
    int _size;

    public:
    List() : _root(nullptr), _size(0) { }

    int size(){
        return _size;
    }

    void push_front(T value){
        _root = new Entry(value, _root);
        _size++;
    }

    T at(size_t index){
        if(index >= size())
            throw "index out of bounds";

        Entry* current = _root;
        for(size_t i = 0; i < index; i++){
            current = _root->next;
        }
        return current->value;
    }

    T front(){
        if(_root != nullptr)
            return _root->value;
        else
            throw "List empty";
    }

    // Reverse
    // Double liked
    // Insert
    // Remove

    ~List(){
        if(_root == nullptr)
           return;
        
        _root->remove(); 
        delete _root;
    }

};

#endif
