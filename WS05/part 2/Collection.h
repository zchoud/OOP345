#ifndef COLLECTION_H
#define COLLECTION_H
#include <string>
#include <iostream>
#include <iomanip>
namespace sdds {
	template<class T>
	class Collection
	{
		std::string c_name;
		T* c_collection = nullptr;
		size_t c_size = 0;
		void (*c_observer)(const Collection<T>& collection, const T& t) = nullptr;
	public:
		Collection(const std::string& name);
		Collection(const Collection& copy) = delete;
		Collection& operator=(const Collection& copy) = delete;
		Collection(const Collection&& copy) = delete;
		Collection& operator=(const Collection&& copy) = delete;
		~Collection();
		size_t size()const;
		void setObserver(void (*observer)(const Collection<T>&, const T&));
		Collection<T>& operator+=(const T& item);
		const std::string& name() const;
		T& operator[](size_t idx) const;
		T* operator[](const std::string& title) const;
	};
	template<typename T>
	std::ostream& operator<<(std::ostream& os, const sdds::Collection<T>& collection);
	
	template<class T>
	inline sdds::Collection<T>::Collection(const std::string& name)
	{
		if (name.size() > 0) {
			c_name = name;
		}
	}
	template<class T>
	inline sdds::Collection<T>::~Collection()
	{
		delete[] c_collection;
		c_collection = nullptr;
	}
	template<class T>
	inline size_t sdds::Collection<T>::size() const
	{
		return c_size;
	}
	template<class T>
	inline void sdds::Collection<T>::setObserver(void(*observer)(const sdds::Collection<T>&, const T&))
	{
		c_observer = observer;
	}
	template<class T>
	inline sdds::Collection<T>& sdds::Collection<T>::operator+=(const T& item)
	{
		bool isNew = true;
		for (size_t j = 0; j < c_size; j++)
		{
			if (c_collection[j].title() == item.title()) {
				isNew = false;
			}
		}
		if (isNew) {
			size_t i = 0;
			T* temp = new T[c_size + 1];
			for (; i < c_size; i++)
			{
				temp[i] = c_collection[i];
			}
			c_size++;
			temp[c_size - 1] = item;
			delete[] c_collection;
			c_collection = temp;
			if (c_observer) {
				c_observer(*this, c_collection[c_size - 1]);
			}
		}
		return *this;
	}
	template<class T>
	inline const std::string& sdds::Collection<T>::name() const
	{
		return this->c_name;
	}
	template<class T>
	inline T& sdds::Collection<T>::operator[](size_t idx) const
	{
		if (idx >= c_size) {
			std::string err = "Bad index [" + std::to_string(idx) + "]. Collection has ["
				+ std::to_string(this->c_size) + "] items.";
			throw std::out_of_range(err);
		}
		return c_collection[idx];
	}
	template<class T>
	inline T* sdds::Collection<T>::operator[](const std::string& title) const
	{
		T* search = nullptr;
		for (size_t i = 0; i < c_size; i++)
		{
			if (c_collection[i].title() == title) {
				search = &c_collection[i];
				break;
			}
		}
		return search;
	}
	template<typename T>
	std::ostream& operator<<(std::ostream& os, const sdds::Collection<T>& collection)
	{
		for (size_t i = 0; i < collection.size(); i++)
		{
			os << collection[i];
		}
		return os;
	}
}
#endif // !COLLECTION_H



