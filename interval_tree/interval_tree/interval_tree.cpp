// interval_tree.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <string>

#include "interval_tree.h"

void TestSearch()
{
    generic_tools::ds::interval_tree<std::string, int> tree;


    std::string s1("HELLO!");
    std::string s2("TREE");
    std::string s3("DATA STRUCTURE");
    std::string s4("STRANGE TEST");

    tree.Add(&s1, 75, 100);
    tree.Add(&s2, 50, 60);
    tree.Add(&s3, 120, 130);
    tree.Add(&s4, 105,110);

    std::string* s1_ptr = tree.Find(80);
    std::string* s2_ptr = tree.Find(125);
    std::string* s3_ptr = tree.Find(55);
    std::string* s4_ptr = tree.Find(107);

    std::cout << *s1_ptr << std::endl;
    std::cout << *s2_ptr << std::endl;
    std::cout << *s3_ptr << std::endl;
}

int main()
{
    TestSearch();


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
