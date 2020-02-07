#include <iostream>
#include <string>

template<class T>
class MyArray {
public:
	explicit MyArray(int capacity) {
		this->capacity_ = capacity;
		this->size_ = 0;
		this->pAddress_ = new T[this->capacity_];
	}
	MyArray(const MyArray & ma) {
		this->capacity_ = ma.capacity_;
		this->size_ = ma.size_;
		this->pAddress_ = new T[this->capacity_];
		for (int i = 0; i < this->size_; i++) {
			this->pAddress_[i] = ma.pAddress_[i];
		}
	}
	~MyArray()
	{
		if (this->pAddress_ != NULL) {
			delete[] this->pAddress_;
			this->pAddress_ = NULL;
		}
	}

	// =重载
	MyArray & operator=(MyArray & ma) {
		if (this->pAddress_ != NULL) {
			delete[] this->pAddress_;
			this->pAddress_ = NULL;
		}
		this->capacity_ = ma.capacity_;
		this->size_ = ma.size_;
		this->pAddress_ = new T[this->capacity_];
		for (int i = 0; i < this->size_; i++) {
			this->pAddress_[i] = ma.pAddress_[i];
		}
		return *this;
	}
	// [] 重载
	T & operator[](int index) {
		return this->pAddress_[index];
	}
	//尾插法
	void PushBack(T value) {
		this->pAddress_[this->size_] = value;
		this->size_++;
	}
	//获取大小
	int GetSize(void) {
		return this->size_;
	}
	int GetCapacity(void) {
		return this->capacity_;
	}

private:
	T *pAddress_;//指向堆区指针
	int capacity_;//容量
	int size_;
};
