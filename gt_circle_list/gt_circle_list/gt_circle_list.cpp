// gt_circle_list.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include "CircleList.h"

void Print3()
{
    std::cout << "I AM THREE!" << std::endl;
}
void Print2()
{
    std::cout << "I AM TWO!" << std::endl;
}
void Print1()
{
    std::cout << "I AM ONE!" << std::endl;
}

void TestLoopExecutor()
{
    generic_tools::ds::loop_executor_void loop;

    loop.Add(&Print1);
    loop.Add(&Print2);
    loop.Add(&Print3);

    int count = loop.Count();

    for (int i = 0; i < 13; ++i) {
        loop.Execute();
    }

    
}

void TestOnePtrCase()
{
    generic_tools::ds::loop_executor_void loop;

    loop.Add(&Print1);
    

    int count = loop.Count();

    for (int i = 0; i < 3; ++i) {
        loop.Execute();
    }
}

int main()
{
    TestOnePtrCase();
    TestLoopExecutor();
    generic_tools::ds::Node<int> n1;
    n1._data = new int(0x29a);

    generic_tools::ds::Node<int> n2;
    n2._data = new int(0x309);

    generic_tools::ds::Node<int> n3;
    n3._data = new int(999);

    generic_tools::ds::CircleList<int> cl;

    

    cl.Add(&n1);
    cl.Add(&n2);
    cl.Add(&n3);
    int debug = 10;
    


    
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
