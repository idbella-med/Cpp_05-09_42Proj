#include <iostream>
#include <stdexcept>

template <typename T>
class Array {
    private:
        T* _data;
        size_t _size;

    public:
        Array() : _data(NULL), _size(0) {}

        Array(unsigned int n) : _data(NULL), _size(n) {
            if (n > 0) {
                _data = new T[n]();
            }
        }

        Array(const Array& other) : _data(NULL), _size(other._size) {
            if (_size > 0) {
                _data = new T[_size];
                for (size_t i = 0; i < _size; i++) {
                    _data[i] = other._data[i];
                }
            }
        }

        Array& operator=(const Array& other) {
            delete[] _data;

            _size = other._size;
            _data = NULL;
            if (_size > 0) {
                _data = new T[_size];
                for (size_t i = 0; i < _size; i++) {
                    _data[i] = other._data[i];
                }
            }
            return *this;
        }


        ~Array() {
            delete[] _data;
        }

        T& operator[](size_t index) {
            if (index >= _size) {
                throw std::out_of_range("Index out of range");
            }
            return _data[index];
        }

        const T& operator[](size_t index) const {
            if (index >= _size) {
                throw std::out_of_range("Index out of range");
            }
            return _data[index];
        }

        size_t size() const {
            return _size;
        }
};