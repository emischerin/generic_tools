#pragma once
namespace generic_tools {
	namespace ds {
		template<class DataType,class SpaceType>
		class bsp_tree_node
		{
		public:
			bsp_tree_node(size_t partition): _partition_index(partition){}

			bsp_tree_node(size_t partition, DataType* data) :
				_data(data), _partition_index(partition) {}

			bsp_tree_node(size_t partition, SpaceType dim) :
				_partition_index(partition),_dim(dim) {}

			size_t GetIndex() { return _partition_index; }
					

			~bsp_tree_node() {};
		
			DataType* _data = nullptr;
			size_t _partition_index;
			SpaceType _dim;
			bsp_tree_node<DataType, SpaceType>* _left = nullptr;
			bsp_tree_node<DataType, SpaceType>* _right = nullptr;
			
		};

		

		template<class DataType,class SpaceType>
		class bsp_tree
		{
		public:
			bsp_tree(SpaceType x, SpaceType y,size_t depth) : _x(x), _y(y),_partition_depth(depth) 
			{
				
				_root = PartitionSpace(_root,0,_x,_y);
			};

			DataType* Search(SpaceType x, SpaceType y)
			{
				bsp_tree_node<DataType, SpaceType>* current = _root;

				while (current->_left && current->_right) {
					if ((current->_partition_index % 2) == 0) {
						if (x >= current->_dim) {
							current = current->_right;
						}
						else
							current = current->_left;
					}
					else if ((current->_partition_index % 2) == 1) {
						if (y >= current->_dim) {
							current = current->_right;
						}
						else
							current = current->_left;

					}
				}

				return current->_data;
			}

			void Insert(DataType* data, SpaceType x, SpaceType y)
			{
				bsp_tree_node<DataType, SpaceType>* current = _root;

				while (current->_left && current->_right) {
					if ((current->_partition_index % 2) == 0) {
						if (x >= current->_dim) {
							current = current->_right;
						}
						else
							current = current->_left;
					}
					else if ((current->_partition_index % 2) == 1) {
						if (y >= current->_dim) {
							current = current->_right;
						}
						else
							current = current->_left;

					}
				}

				current->_data = data;
			}

		private:
			SpaceType _x, _y;
			size_t _partition_depth;
			bsp_tree_node<DataType, SpaceType>* _root = nullptr;
					

			bsp_tree_node<DataType, SpaceType>* 
				PartitionSpace(bsp_tree_node<DataType, SpaceType>* node,SpaceType depth,SpaceType x,SpaceType y)
			{
				
					
				if (!node && depth <= _partition_depth) {
					SpaceType current_x = x / 2;
					SpaceType current_y = y / 2;
					 
					if ((depth % 2) == 0) {
						
						node = new bsp_tree_node<DataType, SpaceType>(depth, current_x);

						node->_left = PartitionSpace(node->_left,depth + 1,current_x,current_y);
						node->_right = PartitionSpace(node->_right, depth + 1, current_x, current_y);
						



					}
					else if ((depth % 2) == 1) {
						node = new bsp_tree_node<DataType, SpaceType>(depth, current_y);

						node->_left = PartitionSpace(node->_left, depth + 1, current_x, current_y);
						node->_right = PartitionSpace(node->_right, depth + 1, current_x, current_y);
						
					}
				}
					
				return node;

				
			}
		};
	}
}
