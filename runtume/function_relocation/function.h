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
			const std::unordered_set<uint8_t> _call_opcodes = {0xE8};
			const std::unordered_set<uint8_t> _jmp_opcodes = 
			{
				0x70, /*JO Jb*/
				0x71,/*JNO Jb*/
				0x72,/*JB/JNAE/JC Jb*/
				0x73,/*JNB/JAE/JNC Jb*/
				0x74,/*JZ/JE Jb*/
				0x75,/*JNZ/JNE Jb*/
				0x76,/*JBE/JNA Jb*/
				0x77,/*JNBE/JA Jb*/
				0x78,/*JS Jb*/
				0x79,/*JNS Jb*/
				0x7A,/*JP/JPE Jb*/
				0x7B,/*JNP/JPO Jb*/
				0x7C,/*JL/JNGE Jb*/
				0x7D,/*JNL/JGE Jb*/
				0x7E,/*JLE/JNG Jb*/
				0x7F,/*JNLE/JG Jb*/
				0xE9, /**/
				0xEA,/**/
				0xEB,/**/
			};
			void* _first_opcode_ptr = nullptr;
			std::vector<uint8_t> _data;
		};
	}
}


