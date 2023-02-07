#pragma once
#include <cstdint>
namespace generic_tools {
	namespace runtime {
		class function
		{
		public:
			uint8_t* RecalculateFunctionAddr(uint8_t* addr);
		};
	}
}


