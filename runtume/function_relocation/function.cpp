#include "function.h"
namespace generic_tools {
	namespace runtime {

		function::function(){}

		uint8_t* function::RecalculateFunctionAddr(uint8_t* addr)
		{
			uint8_t* current_addr = (addr + 1);
			uint8_t* instruction_end = current_addr + sizeof(int);
			uint8_t* tmp = current_addr;
			uint8_t bit_step = 0;
			uint32_t instruction_args = 0;
			uint8_t* result = 0;

			while (tmp < instruction_end) {
				uint32_t tmp_val = *tmp;
				tmp_val = tmp_val << bit_step;
				instruction_args = instruction_args | tmp_val;
				bit_step += 8;
				tmp++;
			}

			result = current_addr + instruction_args + 4;

			return result;
		}

		function::~function(){}
	}
}