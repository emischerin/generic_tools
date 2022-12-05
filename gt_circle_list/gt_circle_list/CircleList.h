#pragma once

//class LoopExecutor
//{
//public:
//
//	
//
//private:
//	void(*function)(void) = nullptr;
//};
//
//
//
//
//
//template<typename FunctionPtr,typename FunctionType,typename ReturnType>
//class Action
//{
//public:
//
//	Action(FunctionPtr* action) : _action(action){}
//	void SetNext(Action* action){
//		_next = action;
//	}
//	void SetPrev(Action* action) {
//		_prev = action;
//	}
//	ReturnType Invoke()
//	{
//		ReturnType rt;
//		if (_action) {
//			t = (ReturnType)((FunctionType)FunctionPtr());
//		}
//
//		return rt;
//	}
//
//	Action* Next() { return _next; }
//	
//
//private:
//	FunctionPtr* _action = nullptr;
//	Action* _next = nullptr;
//	
//};

/*Automatic memory management*/



/*Manual memory management*/
template<class T>
class Node
{


public:

	T* _data = nullptr;
	Node<T>* _next = nullptr;
};



template <class type>
class CircleList
{

	
public:

	
	
	
	
	
	void Add(Node<type>* ptr)
	{
		if (!ptr) return;

		if (_start == nullptr)
			AddFirstActionInternal(ptr);
		else
			AddActionInternal(ptr);
		++_data_count;
		
		
	}
	size_t DataCount() { return _data_count; }
private:
	size_t _data_count = 0;
	Node<type>* _start = nullptr;
	Node<type>* _current = nullptr;
	Node<type>* _last = nullptr;

	void AddFirstActionInternal(Node<type>* ptr)
	{
		
			_start = ptr;
			_current = ptr;
			_last = ptr;
			ptr->_next = ptr;
		
		
	}

	void AddActionInternal(Node<type>* ptr)
	{
		_last->_next = ptr;
		ptr->_next = _start;
		_last = ptr;

	}
};



