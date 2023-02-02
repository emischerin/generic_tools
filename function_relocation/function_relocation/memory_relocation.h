#pragma once
#include <inttypes.h>
#include <cstdlib>
namespace generic_tools {
	namespace runtime {

		class memory_relocation
		{
		public:
			int InvertInt(int a);
			uint8_t* RecalculateFunctionAddr(uint8_t* addr);
			void InvertMemoryBytes(void* memseg, size_t seg_size);
			void* InvertMemoryBytesNew(void* memseg, size_t seg_size);
			int WriteToMemory(void* mem_from, size_t mem_from_size, void* mem_to, size_t mem_to_size);


		};
	}

}