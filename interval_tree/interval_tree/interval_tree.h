#pragma once
namespace generic_tools {
	namespace ds {

		template<class DataType,class IntervalType>
		class interval_tree_node
		{
		public:
			interval_tree_node(DataType* data,IntervalType& min, IntervalType& max) :
				_data(data),_min(min),_max(max){}
						
			DataType* _data;
			IntervalType _min;
			IntervalType _max;
			
			
			interval_tree_node* _left = nullptr;
			interval_tree_node* _right = nullptr;


		};

		template<class DataType,class IntervalType>
		class interval_tree
		{
		public:
			interval_tree(){}
			

			void Add(DataType* data, IntervalType min, IntervalType max)
			{
				if (!_root) {
					_root = new interval_tree_node<DataType, IntervalType>(data,min, max);
					
				}
				else {
					Insert(data, min, max);
				}


			}
						

			DataType* Find(IntervalType value)
			{
				

				interval_tree_node<DataType, IntervalType>* current = _root;

				for (;;) {
					if (!current) return nullptr;

					if (value >= current->_min && value <= current->_max) {
						return current->_data;
					}
					if (value < current->_min) {
						current = current->_left;
					}
					else if (value > current->_max) {
						current = current->_right;
					}
				}
				
			}

			~interval_tree()
			{
								
				this->RecursiveDestructorImpl(_root);
				
			}
			

		private:
			interval_tree_node<DataType, IntervalType>* _root = nullptr;

			void Insert(DataType* data, IntervalType min, IntervalType max)
			{
				
				interval_tree_node<DataType, IntervalType>* current = _root;

				for (;;) {
					interval_tree_node<DataType, IntervalType>* upper_level = current;

					if (max <= current->_min) {
						current = current->_left;
						if (!current) {
							current = new interval_tree_node<DataType, IntervalType>(data,min, max);
							upper_level->_left = current;
							break;
						}
					}
					else if (min >= current->_max) {
						current = current->_right;
						if (!current) {
							current = new interval_tree_node<DataType, IntervalType>(data,min, max);
							upper_level->_right = current;
							break;
						}
					}
					
					
				}
				
			}

			void RecursiveDestructorImpl(interval_tree_node<DataType, IntervalType>* start_node)
			{
				if (start_node) {
					interval_tree_node<DataType, IntervalType>* left = start_node->_left;
					interval_tree_node<DataType, IntervalType>* right = start_node->_right;

					delete start_node;

					RecursiveDestructorImpl(left);
					RecursiveDestructorImpl(right);
				}
			}
						
			
		};
	}
}

