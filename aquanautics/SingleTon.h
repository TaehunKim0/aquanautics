#pragma once

template <class T>
class SingleTon
{
private:
	static T* instance;

public:
	SingleTon()
	{

	}

	virtual ~SingleTon()
	{
		if (instance)
			delete instance;
	}

	static T* GetInstance()
	{
		if (instance == nullptr)
			instance = new T();

		return instance;
	}
};

template<class T>
T* SingleTon<T>::instance = nullptr; //정적 변수는 외부에서 초기화한다.