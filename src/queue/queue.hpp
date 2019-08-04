#ifndef QUEUE_H
#define QUEUE_H

namespace mtl{

#define MIN_CAPACITY 3
#define GROWTH_RATE 1.5
#define SHRINK_THRESHOLD 0.7

template<typename T>
class Queue{
    private:
    T* _array;
    size_t _front;
    size_t _capacity;
    size_t _size;

    bool isFull() const noexcept {
        return size() == capacity();
    }

    void resize(size_t capacity){
        if(capacity < _size)
            throw "Resizing not possible because new capacity < size";

        T* array = new T[capacity];
        for(size_t i = 0u; i < _size; i++){
            array[i] = _array[(_front + i) % _capacity];
        }

        _front = 0u;
        _capacity = capacity;

        delete[] _array;
        _array = array; // TODO: Maybe use swap
    }

    public:
    Queue() : _front(0), _capacity(MIN_CAPACITY), _size(0){
        _array = new T[_capacity];
    }

    ~Queue(){
        delete[] _array;
    }

    size_t size() const noexcept {
        return _size;
    }

    size_t capacity() const noexcept {
        return _capacity;
    }

    bool isEmpty() const noexcept {
        return size() == 0u;
    }

    void enqueue(T value){
        if(isFull())
            resize(_capacity * GROWTH_RATE);

        _array[(_front + _size) % _capacity] = value; // TODO: Check with valgrind. There seems to be a invalid write here. After dequeue
        _size++;
    }

    T dequeue(){
        if(isEmpty())
            throw "Queue is empty";

        size_t index = _front;
        _front = (_front + 1) % _capacity;
        _size--;

        T value = _array[index];

        if(_capacity * SHRINK_THRESHOLD > MIN_CAPACITY && _size < _capacity * SHRINK_THRESHOLD)
            resize(_size);

        return value;
    }

    T front() const {
        if(isEmpty())
            throw "Queue is empty";

        return _array[_front];
    }

    T back() const {
        if(isEmpty())
            throw "Queue is empty";

        return _array[((_front + _size) % _capacity) - 1];
    }

    // T operator[](size_t index) { } // TODO
    // Queue& operator=(const Queue& rhs) {} // TODO
};

#undef GROWTH_RATE
#undef MIN_CAPACITY
#undef SHRINK_THRESHOLD

} // namespace

#endif
