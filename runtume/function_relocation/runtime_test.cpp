// function_relocation.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include "memory.h"
#include "function.h"
#define CALL_ADDR 0x00007FF6514D2334










void TestFunction(int a)
{
	std::cout << a << std::endl;
}

void TestMemoryDestrutor()
{
	generic_tools::runtime::memory m(12);
}

void TestFunction()
{
	std::cout << "HELLO,LOW,LEVEL!" << std::endl;
}

void TestFunctionParsing()
{
	void(*test)(void) = TestFunction;
	generic_tools::runtime::function f(((void*)test));

}

void TestInliningDisabled()
{
	void(*test)(void) = TestFunction;
	generic_tools::runtime::function ft(((void*)test));

	std::vector<uint8_t>* opcodes = ft.GetRawBytes();

	int debug = 10;
}

int main()
{
	TestInliningDisabled();
	void(*test)(void) = TestFunction;
	generic_tools::runtime::function ft(((void*)test));


	
	TestMemoryDestrutor();
	generic_tools::runtime::memory mem_re(12);
	generic_tools::runtime::function f(nullptr);
	int test_inv = 0xFA453C0A;
	int* tinv_ptr = &test_inv;
	int test_inv_result = generic_tools::runtime::InvertInt(test_inv);
	int* result_ptr = &test_inv_result;
	void* main_ptr = &main;
	


	uint8_t* skip_msvc_proxy = f.RecalculateFunctionAddr((uint8_t*)main_ptr);
	int(*main_skipped)(void) = (int(*)(void))skip_msvc_proxy;
	//std::cout << (int)*skip_msvc_proxy;
	//main_skipped();
	
	long long* inverted_mem = (long long*)generic_tools::runtime::InvertMemoryBytesNew(skip_msvc_proxy, sizeof(long long));
		
	void(*TestFPtr)(int) = TestFunction;
	TestFPtr(10);
	//uint32_t* new_mem = (uint32_t*)InvertMemoryBytesNew();
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
