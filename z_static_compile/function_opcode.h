#pragma once
#include <unordered_set>
#include <vector>

namespace generic_tools {
	namespace runtime {
		class function_opcode
		{
		public:
			function_opcode();


			void SetFirstOpcode(void* function_ptr);

			void Execute();

			size_t GetFunctionSize();

			std::vector<uint8_t>& GetFunctionOpcodes(void* function_ptr);


			~function_opcode();




		private:

			void ParseFunction();

			enum opcodes {
				_RET = 0xC3,
				_RET_IMM16 = 0xC2,
				_RETF = 0xCA,
				_RETF_IMM16 = 0xCB


			};
			
			const std::unordered_set<uint8_t> _return_opcodes = { 0xC3,0xC2,0xCA,0xCB };
			const std::unordered_set<uint8_t> _legacy_opcodes = { 0x66,0xF2,0xF3 };
			
			void* _first_opcode_ptr;
			std::vector<uint8_t> _data;
			
			
		};
	}
}

