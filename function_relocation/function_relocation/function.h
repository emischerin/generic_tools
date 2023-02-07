#pragma once
#include <cstdint>
#include <unordered_set>

namespace generic_tools {
	namespace runtime {
		class function
		{
		public:

			function();


			void SetFirstOpcode(void* function_ptr);

			void Execute();

			size_t GetFunctionSize();

			std::vector<uint8_t>& GetFunctionOpcodes(void* function_ptr);


			~function();

			uint8_t* RecalculateFunctionAddr(uint8_t* addr);

		private:
			void ParseFunction();
			enum opcodes {
				_RET = 0xC3,
				_RET_IMM16 = 0xC2,
				_RETF = 0xCA,
				_RETF_IMM16 = 0xCB


			};

			enum legacy_escape_sequence {
				_ONE_BYTE = 0xF,
				_3DNOW = 0xF0F,
				_0F38_OPCODE_M = 0xF38,
				_0F3A_OPCODE_M = 0xF3A
			};

			const std::unordered_set<uint8_t> _return_opcodes = { 0xC3,0xC2,0xCA,0xCB };
			const std::unordered_set<uint8_t> _legacy_opcodes = { 0x66,0xF2,0xF3 };

			void* _first_opcode_ptr = nullptr;
			std::vector<uint8_t> _data;
		};
	}
}


