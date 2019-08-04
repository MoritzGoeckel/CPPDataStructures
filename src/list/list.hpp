#ifndef LIST_H
#define LIST_H

namespace mtl{

template<typename T>
class List{

    private:
    struct Entry{
        T value;
        Entry* next;

        Entry(T v, Entry* n) : value(v), next(n){ }
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
    class Iterator{
        friend List;

        private:
        Entry* _ptr;

        Iterator(Entry* ptr) : _ptr(ptr){ }

        public:
        T& operator*() { return _ptr->value; }

        Iterator operator++(){
            _ptr = _ptr->next;
            return *this;
        }

        bool operator==(const Iterator& rhs) const noexcept {
            return rhs._ptr == _ptr;
        }

        bool operator!=(const Iterator& rhs) const noexcept {
            return !operator==(rhs);
        }

        T* operator->() const { return &(_ptr->value); }
    };

    List() : _begin(nullptr), _end(nullptr), _size(0) { }

    size_t size() const noexcept {
        return _size;
    }

    Iterator begin() const noexcept {
        return Iterator(_begin);
    }

    Iterator end() const noexcept {
        return Iterator(nullptr);
    }

    Iterator find(T value){
        for(auto it = begin(); it != end(); ++it){
            if(*it == value)
                return it;
        }
        return Iterator(nullptr);
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

    T& operator[](size_t index) { return at(index); }

    T& at(size_t index) { return entryAt(index)->value; }

    T front() const {
        if(_size == 0)
            throw "List empty";

        return _begin->value;
    }

    T back() const {
        if(_size == 0)
            throw "List empty";

        return _end->value;
    }

    void remove(size_t index){ // TODO: with iterator
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

    void insert(size_t index, T value){ // TODO: with iterator
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

    void clear(){
        if(_begin == nullptr)
           return;

        _begin->remove();
        delete _begin;
    }

    ~List(){
        clear();
    }

    private:
    Entry* entryAt(size_t index) {
        if(index >= size())
            throw "index out of bounds";

        Entry* current = _begin;
        for(size_t i = 0; i < index; i++){
            current = _begin->next;
        }
        return current;
    }
};

} // namespace

#endif
