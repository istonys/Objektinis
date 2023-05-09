#include <iostream>
#include <vector>
#include <chrono>

template <typename T> class manoVector {
private:
	int size;
	int capacity;
	T* elements;
public:
	// konstruktorius
	manoVector(int pradinisCapacity = 10) {
		size = 0;
		capacity = pradinisCapacity;
		elements = new T[capacity];
	}

	// destruktorius
	~manoVector() {
		delete[] elements;
	}

	// copy constructor
	manoVector(const manoVector& other) {
		size = other.size;
		capacity = other.capacity;
		elements = new T[capacity];
		std::copy(other.elements, other.elements + other.size, elements);
	}

	// copy assignment operator
	manoVector& operator=(const manoVector& other) {
		if (this != &other) {
			delete[] elements;
			size = other.size;
			capacity = other.capacity;
			elements = new T[capacity];
			std::copy(other.elements, other.elements + other.size, elements);
		}
		return *this;
	}

	// move constructor
	manoVector(manoVector&& other) noexcept {
		size = other.size;
		capacity = other.capacity;
		elements = other.elements;
		other.size = 0;
		other.capacity = 0;
		other.elements = nullptr;
	}

	// move assignment operator
	manoVector& operator=(manoVector&& other) noexcept {
		if (this != &other) {
			delete[] elements;
			size = other.size;
			capacity = other.capacity;
			elements = other.elements;
			other.size = 0;
			other.capacity = 0;
			other.elements = nullptr;
		}
		return *this;
	}

	// metodai
	void push_back(const T& element) {
		if (size == capacity) {
			reserve(capacity == 0 ? 10 : capacity * 2);
		}
		elements[size++] = element;
	}

	void pop_back() {
		if (size > 0) {
			size--;
		}
	}

	bool empty() const {
		return size == 0;
	}

	void reserve(int newCapacity) {
		if (newCapacity > capacity) {
			T* newElements = new T[newCapacity];
			std::copy(elements, elements + size, newElements);
			delete[] elements;
			elements = newElements;
			capacity = newCapacity;
		}
	}

	void resize(int newSize) {
		if (newSize < 0) {
			throw std::out_of_range("New size must be non-negative.");
		}
		if (newSize > capacity) {
			reserve(newSize);
		}
		for (int i = size; i < newSize; i++) {
			elements[i] = T();
		}
		size = newSize;
	}

	void clear() {
		size = 0;
		capacity = 0;
		delete[] elements;
		elements = nullptr;
	}

	void erase(T* position) {
		if (position >= elements && position < elements + size) {
			position->~T();
			std::move(position + 1, elements + size, position);
			size--;
		}
	}

	void erase(T* first, T* last) {
		if (first < last && first >= elements && last <= elements + size) {
			std::move(last, elements + size, first);
			size -= (last - first);
		}
	}

	void print() {
		std::cout << "Size: " << size << std::endl;
		std::cout << "Capacity: " << capacity << std::endl;
		std::cout << "Elements: ";
		for (int i = 0; i < size; i++) {
			std::cout << elements[i] << " ";
		}
		std::cout << std::endl;
	}

	// getter'iai

	T& operator[](int index) {
		return elements[index];
	}

	T& front() {
		return elements[0];
	}

	T& back() {
		return elements[size - 1];
	}

	T* begin() {
		return elements;
	}

	T* end() {
		return elements + size;
	}

	int getSize() const {
		return size;
	}

	int getCapacity() const {
		return capacity;
	}
};


int main() {

	std::vector<int> v1;
	manoVector<int> v2;

	v1.push_back(1);
	v1.push_back(2);
	v1.push_back(3);
	v1.push_back(4);

	v2.push_back(1);
	v2.push_back(2);
	v2.push_back(3);
	v2.push_back(4);
	std::cout << "std::vector elementai po push_back(): ";
	for (int i = 0; i < v1.size(); i++) {
		std::cout << v1[i] << " ";
	}
	std::cout << std::endl;
	std::cout << "manoVector elementai po push_back(): ";
	for (int i = 0; i < v2.getSize(); i++) {
		std::cout << v2[i] << " ";
	}
	std::cout << std::endl << std::endl;
	v1.pop_back();
	v2.pop_back();

	std::cout << "std::vector elementai po pop_back(): ";
	for (int i = 0; i < v1.size(); i++) {
		std::cout << v1[i] << " ";
	}
	std::cout << std::endl;

	std::cout << "manoVector elementai po pop_back(): ";
	for (int i = 0; i < v2.getSize(); i++) {
		std::cout << v2[i] << " ";
	}
	std::cout << std::endl << std::endl;

	std::cout << "std::vector front(): " << v1.front() << std::endl;
	std::cout << "manoVector front(): " << v2.front() << std::endl << std::endl;

	std::cout << "std::vector back(): " << v1.back() << std::endl;
	std::cout << "manoVector back(): " << v2.back() << std::endl << std::endl;


	std::cout << "std::vector size ir capacity pries resize(50): " << v1.size() << " " << v1.capacity() << std::endl;
	v1.resize(50);
	std::cout << "std::vector size ir capacity po resize(50): " << v1.size() << " " << v1.capacity() << std::endl;

	std::cout << "manoVector size ir capacity pries resize(50): " << v2.getSize() << " " << v2.getCapacity() << std::endl;
	v2.resize(50);
	std::cout << "manoVector size ir capacity po resize(50): " << v2.getSize() << " " << v2.getCapacity() << std::endl << std::endl;

	v1.clear();
	std::cout << "std::vector size ir capacity po clear(): " << v1.size() << " " << v1.capacity() << std::endl;

	v2.clear();
	std::cout << "manoVector size ir capacity po clear(): " << v2.getSize() << " " << v2.getCapacity() << std::endl;
	//auto start = std::chrono::high_resolution_clock::now();
	//unsigned int sz = 100000;  // 100000, 1000000, 10000000, 100000000
	//std::vector<int> v1;
	//for (int i = 1; i <= sz; ++i) {
	//	v1.push_back(i);
	//}
	//auto stop = std::chrono::high_resolution_clock::now();
	//auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(stop - start);
	//std::cout << "std::vector uztruko: " << duration.count() / 1000.0 << " s" << std::endl;

	//auto start1 = std::chrono::high_resolution_clock::now();
	//manoVector<int> v2;
	//for (int i = 1; i <= sz; ++i) {
	//	v2.push_back(i);
	//}
	//auto stop1 = std::chrono::high_resolution_clock::now();
	//auto duration1 = std::chrono::duration_cast<std::chrono::milliseconds>(stop1 - start1);
	//std::cout << "manoVector uztruko: " << duration1.count() / 1000.0 << " s" << std::endl << std::endl;
	//std::cout << "std::vector parametrai: " << std::endl;
	//std::cout << "Size: " << v1.size() << std::endl;
	//std::cout << "Capacity: " << v1.capacity() << std::endl;
	////std::cout << "Elements: ";
	////for (int i = 0; i < v1.size(); i++) {
	////	std::cout << v1[i] << " ";
	////}
	//std::cout << std::endl << std::endl;
	//std::cout << "manoVector parametrai: " << std::endl;
	//v2.print();

	return 0;
}