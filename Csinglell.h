#pragma once
template<typename T>
class Csinglell
{
private:
	T* data_ptr;
	Csinglell* next;
	int links_num;
public:
	Csinglell<T>() :links_num(0), data_ptr(nullptr), next(nullptr) {};
	void add(T* data_ptr);

};

template<typename T>
void Csinglell<T>::add(T* data_ptr)
{
	links_num++;
	if (!links_num)
	{
		next = this;
		return;
	}
	Csinglell<T> tmp;
	tmp.data_ptr = data_ptr;
	tmp.next = this;
	Csinglell<T>* tmp2 = this;
	for (int ite = 0; ite < links_num - 1; ite++)
		tmp2 = tmp2->next;
	tmp2->next = &tmp;
	tmp.data_ptr = data_ptr;
}