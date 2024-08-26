//dynamic resize
template<typename T>
class DynamicVector {
private:
    T* data;
    size_t size;
    size_t capacity;

    void resize() {
        capacity = capacity == 0 ? 1 : capacity * 2;
        T* new_data = new T[capacity];
        for (size_t i = 0; i < size; ++i) {
            new_data[i] = data[i];
        }
        delete[] data;
        data = new_data;
    }

public:
    DynamicVector() : data(nullptr), size(0), capacity(0) {}

    ~DynamicVector() {
        delete[] data;
    }

    void push_back(const T& value) {
        if (size == capacity) {
            resize();
        }
        data[size] = value;
        size++;
    }

    T& operator[](size_t index) {
        if (index < size) {
            return data[index];
        } else {
            throw std::out_of_range("Index out of bounds");
        }
    }
};