#include "collections/Vector.hpp"

/**
 * Creates an empty vector of the specified size
 * @param size
 */
template<class T>
Vector<T>::Vector(int size) {
    if(size < 0) {
        throw InvalidArgumentException("Vector size can't be negative");
    }
    this->_size = size;
    this->_values = new T[size];
    this->_indexes = new bool[size];
    this->_used = 0;
    for (int i = 0; i < size; i++) {
        this->_indexes[i] = false;
    }
}

/**
 * Copy a vector
 * @param orig
 */
template<class T>
Vector<T>::Vector(const Vector<T>& orig) {
    this->_size = orig._size;
    // TODO Write this
}

/**
 * Free the vector space
 */
template<class T>
Vector<T>::~Vector() {
    delete[] this->_values;
    delete[] this->_indexes;
}

/**
 * Gets the element at the specified index
 * @param index
 * @return
 */
template<class T>
T& Vector<T>::get(int index) const {
    this->validate(index);
    if(!this->_indexes[index]) {
        throw InvalidArgumentException("No element at " + StringUtils::toString(index));
    }
    return this->_values[index];
}

/**
 * Sets the element at the specified index
 * @param
 */
template<class T>
void Vector<T>::set(int index, const T& value) {
    this->validate(index);
    this->_values[index] = value;
    if(!this->_indexes[index]) {
        ++this->_used;
    }
    this->_indexes[index] = true;
}

/**
 * Removes an item from the vector, if none was there, does nothing
 */
template<class T>
void Vector<T>::remove(int index) {
    this->validate(index);
    if(this->_indexes[index]) {
        --this->_used;
        this->_indexes[index] = false;
    }
}

template<class T>
int Vector<T>::currentSize() const {
    return this->_used;
}

/**
 * Gets the size of the vector
 * @return
 */
template<class T>
int Vector<T>::maxSize() const {
    return this->_size;
}

/**
 * Returns wether the vector is empty or not
 * @return
 */
template<class T>
bool Vector<T>::isEmpty() const {
    for (int i = 0; i < this->_size; i++) {
        if(this->_indexes[i]) {
            return false;
        }
    }
    return true;
}

/**
 * Checks wether an index is valid or not
 * @return
 */
template<class T>
bool Vector<T>::isValid(int index) const {
    return index >= 0 && index < this->_size;
}

template<class T>
void Vector<T>::validate(int index) const {
    if(!this->isValid(index)) {
        throw OutOfBoundsException("Index out of bounds: " + StringUtils::toString(index));
    }
}

// Pre setting template usage
template class Vector<int>;
