#include "memory.h"
namespace generic_tools {
	namespace runtime {

		int memory::WriteToMemory(void* mem_from, size_t mem_from_size, void* mem_to, size_t mem_to_size)
		{
			if (mem_to_size < mem_from_size) return -1;
			if (mem_to == 0 || mem_from == 0) return -2;

			uint8_t* to = (uint8_t*)mem_to;
			uint8_t* from = (uint8_t*)mem_from;
			uint8_t* to_end = (to + mem_to_size) - 1;

			for (; to <= to_end; ++to) {
				*to = *from;
				from++;
			}

			return 0;

		}

		void memory::InvertMemoryBytes(void* memseg, size_t seg_size)
		{
			uint8_t* first = (uint8_t*)memseg;
			uint8_t* last = (first + seg_size) - 1;
			uint8_t tmp = 0;

			while (first <= last) {
				tmp = *first;
				*first = *last;
				*last = tmp;
				first++; last--;
			}
		}

		/*Creates new memory segment with inversed backwards byte order*/
		void* memory::InvertMemoryBytesNew(void* memseg, size_t seg_size)
		{
			uint8_t* first = (uint8_t*)memseg;
			uint8_t* last = (first + seg_size) - 1;
			void* new_mem = malloc(seg_size);
			uint8_t* new_mem_counter = 0;

			if (new_mem == 0) return 0;

			new_mem_counter = (uint8_t*)new_mem;

			while (first <= last) {
				*new_mem_counter = *last;
				last--;
				new_mem_counter++;
			}

			return new_mem;
		}

		int memory::InvertInt(int a)
		{
			/* Converts ints from Little/big endian*/

			unsigned int result = 0;
			unsigned int u_a = (unsigned int)a;

			unsigned int* result_ptr = &result;

			for (int i = 0; i < sizeof(a) * 8; i += 8) {
				uint8_t current_byte = 0;
				result = result << 8;
				current_byte = current_byte | u_a;
				result = result | current_byte;
				u_a >>= 8;

			}

			return (int)result;
		}

		
	}
}