#include "function.h"
namespace generic_tools {
	namespace runtime {

		function::function(void* function_ptr)
		{
			if (!function_ptr) return;
			_first_opcode_ptr = function_ptr;

			ParseFunction(_first_opcode_ptr);
		}

		/*use for jmp opcodes*/
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


		/*
		* 
		* 
		* Release configuration machine code not necesserely contains function, 
		* moreover,function does not necessary ends with ret opcodes,so there is no way
		* to detect function end....(((
		* 
		* 
		*/
		void function::ParseFunction(void* function)
		{
			uint8_t* firstopcode = (uint8_t*)function;
			size_t size = 1;
			
			uint8_t* tmp_addr = firstopcode;

			for (;;) {
				uint8_t tmp_opcode = (uint8_t)(*tmp_addr);
				
				auto is_ret = _return_opcodes.find(tmp_opcode);
				auto is_call = _call_opcodes.find(tmp_opcode);
				auto is_jump = _jmp_opcodes.find(tmp_opcode);
				

				if (is_ret != _return_opcodes.cend()) {
					_size = size;
					_last_opcode_ptr = tmp_addr;
					break;
				}
				else if (is_call != _call_opcodes.cend()) {
					++size;
					_calls.push_back(tmp_addr);
					_calls_set.insert(tmp_addr);
				}
				else if (is_jump != _jmp_opcodes.cend()) {
					++size;
					_jumps.push_back(tmp_addr);
					_jumps_set.insert(tmp_addr);
				}

				++tmp_addr;
				
				
			}
			

		}

		function::~function(){}
	}
}