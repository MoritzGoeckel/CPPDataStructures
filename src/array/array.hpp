template<typename T>
class Array{
    public:

    Array(size_t size) : _size(size), _array(new T[size]) {}

    size_t size(){
        return _size;
    }

    T& operator[](const size_t index) {
        if(index >= _size)
            throw "Index out of bounds";

        return _array[index];     
    }

    ~Array(){
        delete _array;
    }

    private:
    size_t _size;
    T* _array;
};
