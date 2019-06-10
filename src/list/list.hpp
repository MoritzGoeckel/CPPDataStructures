#ifndef list_h
#define list_h

template<typename T>
class List{

    private:
    struct Entry{
        Entry(T v, Entry* n) : value(v), next(n){ }
        T value;
        Entry* next;
        void remove() { 
            if(next == nullptr) 
                return;
            
            next->remove();
            delete next;
        }
    };
    
    Entry* _begin;
    Entry* _end;

    size_t _size;

    public:
    List() : _begin(nullptr), _end(nullptr), _size(0) { }

    size_t size(){
        return _size;
    }

    void push_front(T value){ 
        if(_size == 0){
            Entry* n = new Entry(value, nullptr);
            _begin = n;
            _end = n;
        }
        else
            _begin = new Entry(value, _begin); 

        _size++;
    }
    
    void push_back(T value){
        Entry* n = new Entry(value, nullptr);
        if(_size == 0){
            _begin = n;
            _end = n;
        }
        else{
            _end->next = n; 
            _end = n;
        }

        _size++;
    }

    T at(size_t index){
       return entryAt(index)->value; 
    }

    T front(){
        if(_size == 0)
            throw "List empty";

        return _begin->value;
    }

    T back(){
        if(_size == 0)
            throw "List empty";

        return _end->value;
    }

    void remove(size_t index){
        if(index > _size)
            throw "Index out of bounds";

        if(index == 0){
            Entry* toDelete = _begin;
            _begin = _begin->next;
            delete toDelete;
            _size--;
            return;
        }

        Entry* before = entryAt(index-1); 
        Entry* toDelete = before->next;

        before->next = before->next->next;

        delete toDelete;
        _size--;

        if(index == _size)
            _end = before;
    }

    void insert(size_t index, T value){
        if(index > _size)
            throw "Index out of bounds";

        if(index == 0){
           return push_front(value); 
        }
        if(index == _size){
            return push_back(value);
        }

        Entry* before = entryAt(index-1);
        before->next = new Entry(value, before->next);
    }

    ~List(){
        if(_begin == nullptr)
           return;
        
        _begin->remove(); 
        delete _begin;
    }

    private:
    Entry* entryAt(size_t index){
        if(index >= size())
            throw "index out of bounds";

        Entry* current = _begin;
        for(size_t i = 0; i < index; i++){
            current = _begin->next;
        }
        return current;
    }

};

#endif
