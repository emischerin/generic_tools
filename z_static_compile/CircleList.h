#pragma once
#include<vector>
namespace generic_tools {

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

		Node<type>* GetCurrent()
		{
			return _current;
		}

		Node<type>* GetCurrentAndMoveNext()
		{
			Node<type>* old_current = _current;
			_current = _current->_next;
			return old_current;
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

	struct function_list
	{
		void* _action = nullptr;
		function_list* _next = nullptr;
	};

	class loop_executor_void
	{
	public:

		

		void Add(void* function)
		{
			if (!function) return;

			if (!_start->_action)
				AddFirstActionInternal(function);
			else
				AddActionInternal(function);
			++functions_count;


		}

		void Execute()
		{
			if (_current) {
				void(*_function)(void) = (void(*)(void))_current->_action;
				_function();
			}

			_current = _current->_next;
		}

		size_t Count() { return functions_count; }

		~loop_executor_void()
		{
			
			function_list* current = _start;
			
			do {
				
				function_list* tmp = current->_next;

				delete current;

				

				current = tmp;
			} while (current != _start);

		}

	private:
		function_list* _start = new function_list();
		function_list* _current = _start;
		function_list* _last = _start;
		
		size_t functions_count = 0;

		void AddFirstActionInternal(void* function)
		{

			_start->_action = function;
			_start->_next = _start;


		}

		void AddActionInternal(void* function)
		{
			_last->_next = new function_list();

			function_list* tmp = _last->_next;

			tmp->_action = function;

			_last = tmp;

			_last->_next = _start;


			



		}
	};
	
}



