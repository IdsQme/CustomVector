#ifndef VECTOR_H
#define VECTOR_H
#include <stdexcept>
#include <iostream>


template <class T>
class vector {
public:
	T* data;
	size_t m_size; // conflicts with size() if size
	size_t capacity;

	// Core
	vector();
	//	vector(size_t size);
	~vector();
	vector(const vector& other); // Copy constructor
	//	vector(vector&&); // Move constructor

		// Memory
	T* alloc(size_t n);
	T* ralloc(size_t n);
	T* resize(size_t n);

	// Acces
	T& at(size_t index);
	T& front();
	T& back();
	T* data_ptr() const;

	// Cop. Manage
	size_t size() const { return size; };
//	size_t capacity() const { return capacity; };
	bool empty();

	// Mod
	void p_back(const T& val);
	void pop_back();
	void clear();
	void insert(size_t index, const T& val);
	void erase(size_t index);


	//operator overloads
	T& operator[](size_t index);
	vector<T> operator+(const vector<T>& param);
	vector<T> operator-(const vector<T>& param);

};



template <class T>
vector<T>::vector() : m_size(0), capacity(0), data(nullptr) {}

template <class T>
vector<T>::vector(const vector& other)
{
	capacity = other.capacity;
	data = new T[capacity];

	m_size = other.m_size;
	for (size_t i = 0; i < m_size; ++i)
	{
		data[i] = other.data[i];
	}
}

template <class T>
T* vector<T>::alloc(size_t n)
{
	if (n <= capacity) return data;

	T* ndata = new T[n];

	for (size_t i = 0; i < m_size; ++i)
	{
		ndata[i] = std::move(data[i]);
	}

	delete[] data;
	data = ndata;
	capacity = n;

	return data;
}

template <class T>
T* vector<T>::resize(size_t n)
{
	if (n == 0) return nullptr;

	if (n <= capacity) return data;

	T* ndata = new T[n];

	for (size_t i = 0; i < m_size; ++i)
	{
		ndata[i] = data[i];
	}

	delete[] data;
	capacity = n;
	return ndata;
}
template <class T>
vector<T>::~vector()
{
	delete[] data;
	data = nullptr;
}

template <class T>
bool vector<T>::empty()
{
	return m_size == 0;
}

template <class T>
void vector<T>::erase(size_t index)
{
	if (index >= m_size) throw std::out_of_range("index out range");

	for (size_t i = index; i < m_size - 1; ++i)
	{
		data[i] = data[i + 1];
	}

	--m_size;
}

template <class T>
void vector<T>::p_back(const T& val)
{
	if (m_size == capacity) data = resize((capacity == 0 ? 1 : capacity * 2)); // for mem efficiency

	data[m_size++] = val;
}

template <class T>
void vector<T>::pop_back()
{
	if (m_size > 0) --m_size; // just act like it doesnt exist 
}

template <class T>
void vector<T>::clear()
{
	delete[] data;
	data = nullptr;
	m_size = 0;
	capacity = 0;
}

template <class T>
void vector<T>::insert(size_t index, const T& val)
{
	if (index >= m_size) throw std::out_of_range("index out of range"); // Temp exception
	if (m_size == capacity) data = resize((capacity == 0 ? 1 : capacity * 2));



	for (size_t i = m_size; i > index; --i)
	{
		data[i] = data[i - 1];
	}
	data[index] = val;

	++m_size;
}

// Operators
template <class T>
T& vector<T>::operator[] (size_t index)
{
	if (index >= m_size) throw std::out_of_range("index out of range"); // Temp exception
	return data[index];
}

template <class T>
vector<T> vector<T>::operator+(const vector<T>& param)
{
	vector<T> result;
	size_t n = (m_size >= param.m_size) ? param.m_size : m_size;
	for (size_t i = 0; i < n; ++i)
	{
		result.p_back(data[i] + param.data[i]);
	}

	return result;
}

template <class T>
vector<T> vector<T>::operator-(const vector<T>& param)
{
	vector<T> result;
	size_t n = (m_size >= param.m_size) ? param.m_size : m_size;
	for (size_t i = 0; i < n; ++i)
	{
		result.p_back(data[i] - param.data[i]);
	}

	return result;
}
#endif