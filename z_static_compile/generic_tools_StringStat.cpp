// generic_tools_StringStat.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <string>
#include <unordered_set>
#include <vector>
#include "string_stat.h"




void TestReference()
{
    const std::string& s("");

    bool b = s.empty();

    

    std::cout << b << std::endl;
}

void USetTest()
{
    std::unordered_multiset<int> us;

    int t1 = 222;
    int t2 = 222;

    
    us.insert(t1);
    us.insert(t2);

    for (auto i = us.begin(); i != us.end(); ++i) {
        std::cout << (*i) << std::endl;
    }

    std::cout << "COUNT:" << us.count(222) << std::endl;
}

void TestStringContains()
{
    std::basic_string<char> line_5("hello\nmy name is\negor\nhow are you?\nbye"); // 5,16
    generic_tools::string_stat<char> ss(&line_5);
    ss.ProcessString();
    std::basic_string<char> pattern("gor");
    std::vector<std::basic_string<char>*>* all_lines = ss.GetAllLines();

    std::vector<size_t>* lc = ss.FindStringsContain(all_lines, &pattern);
    std::vector<size_t>* lc_rval = ss.FindStringsContain(all_lines, "gor");
    std::vector<std::basic_string<char>*>* ptr_contains = ss.GetStringsContain(all_lines, &pattern);
    std::vector<std::basic_string<char>*>* ptr_contains_rval = ss.GetStringsContain(all_lines, "gor");
    int debug = 0;
}

void TestSS()
{
    //std::basic_string<char> bs("hello\nmy friend");
    std::basic_string<char> line_5("hello\nmy name is\negor\nhow are you?\nbye"); // 5,16
    generic_tools::string_stat<char> ss(&line_5);
    ss.ProcessString();

    std::vector<std::basic_string<char>*>* all_lines = ss.GetAllLines();

    std::basic_string<char>* _line_number2 = ss.GetLine(2);
    std::basic_string<char>* first_line = ss.GetLine(1);
    std::basic_string<char>* zero_line = ss.GetLine(0);
   
    
    std::basic_string<char>* last_line = ss.GetLine(5);
    std::cout << *first_line << std::endl;
    std::cout << *last_line << std::endl;


    int d = 0;
}

void SMTest()
{
    std::basic_string<wchar_t> s(L"HELLO!MY NAME IS EGORKA!");
    std::basic_string<wchar_t> p(L"A!");
    std::basic_string<wchar_t> o(L"HELLO");
    std::basic_string<wchar_t> egorka(L"EGORKA");
    std::basic_string<wchar_t> u(L"u");
    std::basic_string<wchar_t> sorry(L"sorrY");
    generic_tools::string_stat<wchar_t> ss;

    bool result = ss.StringMatcher(&s, &u);

    int debug = 0;
}

void StrTest()
{
    std::basic_string<wchar_t>* s = new std::basic_string<wchar_t>(L"HELLO!");

    wchar_t c = (*s)[1];


    int debug = 0;
}

void TestConcatStrings()
{
    generic_tools::string_stat<wchar_t> ss;
    std::basic_string<wchar_t> s1 = L"HELLO!";
    std::basic_string<wchar_t> s2 = L"WORLD";
    std::basic_string<wchar_t> s3 = L"CONCATENATED!";
    std::basic_string<wchar_t>* sn = nullptr;

    std::vector<std::basic_string<wchar_t>*> v;
    v.push_back(&s1);
    v.push_back(&s2);
    v.push_back(sn);
    v.push_back(&s3);

    std::basic_string<wchar_t>* result = ss.ConcatStrings(&v);

    int debug = 0;
}

void EraseSequenceTest()
{
    generic_tools::string_stat<wchar_t> ss;
    std::basic_string<wchar_t> s1 = L"HELLO!";

    ss.EraseSequence(&s1, L'L');

    int debug = 0;
}

void EraseSequenceNewStrTest()
{
    generic_tools::string_stat<wchar_t> ss;
    std::basic_string<wchar_t> s1 = L"HELLO!";

    std::basic_string<wchar_t>*new_str = ss.EraseSequenceNewStr(&s1, L'L');

    int debug = 0;
}

int main()
{
    EraseSequenceNewStrTest();
    EraseSequenceTest();
    TestConcatStrings();
    TestStringContains();
    SMTest();
    TestSS();

    USetTest();


    std::string hw("hello!");
    std::string empty("");
    generic_tools::string_stat<char> st(&hw);
    
    int result = st.ProcessString(&empty);

    if (result == generic_tools::EMPTY_STRING)
        std::cout << "string_EMPTY" << std::endl;
    

    TestReference();

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
