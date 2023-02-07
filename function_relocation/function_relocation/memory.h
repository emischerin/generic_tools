#pragma once
#include <cstdint>
#include <cstdlib>
namespace generic_tools {
	namespace runtime {
		class memory
		{
		public:

			int WriteToMemory(void* mem_from, size_t mem_from_size, void* mem_to, size_t mem_to_size);
			void InvertMemoryBytes(void* memseg, size_t seg_size);
			void* InvertMemoryBytesNew(void* memseg, size_t seg_size);

			int InvertInt(int a);

		private:
			uint8_t* _start_addr = nullptr;
			uint8_t* _size = 0;

		};
	}
}

