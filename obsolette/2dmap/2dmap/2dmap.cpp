﻿// 2dmap.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include "2dmap.h"

void TestMap()
{
    generic_tools::ds::spacemap<int, int> sp_map(800, 600, 800, 600);

    int a = 777;
    int b = 888;

    sp_map.Add(300, 300, 50, 50, &a);

    sp_map.Add(400, 400, 20, 20, &b);

    int* ptr = sp_map.Search(325, 325);
    int* ptr2 = sp_map.Search(410, 415);

    int debug = 10;

}

int main()
{
    TestMap();
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
