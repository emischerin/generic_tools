#pragma once
namespace generic_tools {
	namespace ds {

		template<class SpaceType, class DataType>
		class spacemap
		{
		public:

			spacemap(SpaceType x, SpaceType y,SpaceType width,SpaceType height)
			{
				_x = x;
				_y = y;
				_width = width;
				_height = height;
				_resolution = x * y;
				_data = new DataType*[_resolution];
				InitData();
			}

			void Add(SpaceType x, SpaceType y, SpaceType width, SpaceType height,DataType* data)
			{
				
				_data[0] = data;
				SpaceType y_step = y;
				
				SpaceType current_row = y_step * width + x; /*column step*/
				
				SpaceType last_row = ((y + height) * width + x); /*In fact this is more than last row. Last row = 
				last_row - 1*/
				while (current_row < last_row) {
					for (SpaceType y = width; y > 0; y--) {
						_data[current_row] = data;
						current_row++;
						
					}
					++y_step;
					current_row = y_step * width + x;

				}
								
			}
			
			DataType* Search(SpaceType x, SpaceType y)
			{
				SpaceType location = y * _width + x;

				if (location >= _resolution) return nullptr;

				return _data[location];
			}

			~spacemap()
			{
				delete []_data;
			}

		private:
			SpaceType _x, _y, _width, _height;
			SpaceType _resolution;
			DataType** _data;

			void InitData()
			{
				for (size_t i = 0; i < _resolution; ++i) {
					_data[i] = nullptr;
				}
			}

		};
	}

}

