// bsp_tree.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include "bsp_tree.h"

void TestSpacePartition()
{
    generic_tools::ds::bsp_tree<int, int> tree(1000, 1000, 4);
    int debug = 10;

}

void TestInserting()
{
    generic_tools::ds::bsp_tree<int, int> tree(1000, 1000, 4);
    int test_data = 600;
    tree.Insert(&test_data, 100, 100);
    tree.Insert(&test_data, 900, 900);

    int debug = 10;
}

void TestSearching()
{
    generic_tools::ds::bsp_tree<int, int> tree(1000, 1000, 8);
    int test_data = 600;
    int test_data2 = 999;
    int test_data3 = 777;
    tree.Insert(&test_data, 100, 100);
    tree.Insert(&test_data2, 900, 900);
    tree.Insert(&test_data3, 20, 20);

    int* data_ptr = tree.Search(15, 15);
    int* data_ptr2 = tree.Search(900, 900);
    int* data_ptr3 = tree.Search(100, 100);

    int debug = 10;
}

int main()
{
    TestSearching();
    TestInserting();
    TestSpacePartition();
    std::cout << "Hello World!\n";
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
