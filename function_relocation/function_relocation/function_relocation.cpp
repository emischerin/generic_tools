// function_relocation.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include "memory_relocation.h"
#define CALL_ADDR 0x00007FF6514D2334










void TestFunction(int a)
{
	std::cout << a << std::endl;
}

int main()
{
	generic_tools::runtime::memory_relocation mem_re;
	int test_inv = 0xFA453C0A;
	int test_inv_result = mem_re.InvertInt(test_inv);
	void* main_ptr = &main;
	
	uint8_t* skip_msvc_proxy = mem_re.RecalculateFunctionAddr((uint8_t*)main_ptr);
	int(*main_skipped)(void) = (int(*)(void))skip_msvc_proxy;
	main_skipped();
	
	long long* inverted_mem = (long long*)mem_re.InvertMemoryBytesNew(skip_msvc_proxy, sizeof(long long));
		
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
