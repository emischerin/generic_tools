#pragma once
#include <cstdint>
#include <cstdlib>
namespace generic_tools {
	namespace runtime {

		int InvertInt(int a);

		int WriteToMemory(void* mem_from, size_t mem_from_size, void* mem_to, size_t mem_to_size);

		void InvertMemoryBytes(void* memseg, size_t seg_size);

		void* InvertMemoryBytesNew(void* memseg, size_t seg_size);

		class memory
		{
		public:

			memory(size_t size);
			memory(memory* mem);

			bool was_allocated();
			size_t memsize();

			void* getstartaddr();
			~memory();
		private:
			uint8_t* _start_addr = nullptr;
			uint8_t* _last_addr = nullptr;
			size_t _size = 0;
			bool _was_allocated = false;
		};
	}
}

