#include <iostream>
template <typename T>
class vector
{
public:
	vector() : size(0), capacity(4)
	{
		Vec = new T[capacity];
	}
	vector(T S) : size(1), capacity(4)
	{
		Vec = new T[capacity];
		for(int i = 0 ; i < size; i++)
		{
			Vec[i] = S;
		}
	}
	void push_back(T value)
	{
		if(size >= capacity){ addMemory(); }
		Vec[size++] = value;
	}
	void push_front(T value)
	{
		if(size++ >= capacity){ addMemory(); }
		if(Vec)
		{
			capacity *= 2;
			T* mass = new T[capacity];
			for(int i =0; i < size; i++)
			{
				mass[i] = Vec[i];
			}
			delete[] Vec;
			Vec = new T[capacity];  
			Vec[0] = value;
			for(int i = 0; i < size; i++)
			{
				Vec[i + 1] = mass[i];
			}
			delete[] mass;
		}
	}
	T &at(T value)
	{
		return Vec[value];
	}
	void addMemory()
	{
		capacity *= 2;
		T* mass = new T[capacity];
		for(int i = 0; i < size; i++)
		{
			mass[i] = Vec[i];
		}
		delete[] Vec;
		Vec = mass;
		delete[] mass;
	}
	int Get_size()
	{
		return size;
	}
	int Get_capacity()
	{
		return capacity;
	}
	void Get_value()
	{
		for(int i = 0; i < size; i++)
		{
			std::cout << Vec[i] << " | ";
		}
		std::cout << std::endl;
	}
	T capacitY()
	{
		return capacity;
	}
	T sizE()
	{
		return size;
	}
	void clear()
	{
		delete[] Vec;
		size = 0;
	}
	void ZeroClear()
	{
		for(int i = 0; i < size; i++)
		{
			Vec[i] = 0;
		}
	}
	void remove()
	{
		vector* ptr = new vector();
		ptr->~vector();
	}
	vector& operator=(vector& oth)
	{
		if(this != &oth)
		{
			delete[] Vec;
			Vec = new T [oth.capacity];
			for(int i = 0; i < oth.size; i++){Vec[i] = oth.Vec[i];}
			size = oth.size;
			capacity = oth.capacity;
		}
		return *this;
	}
	T& operator[](T index)
	{
		return Vec[index];
	}
	T empty()
	{
		return begin() == end();
	}
	T* begin() 
	{
		return &Vec[0];
	}
	T* end() 
	{
		return &Vec[size];
	}
	
	~vector()
	{
		delete[] Vec;
	}

private:
	T* Vec;
	int size;
	int capacity;
};

int main()
{
	int s = 15, p = 10, SS = 90;
	vector<int> S(std::move(s));
	S.push_back(std::move(p));
	S.push_back(std::move(SS));
}
