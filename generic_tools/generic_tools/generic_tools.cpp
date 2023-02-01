// generic_tools.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "async_reader.h"
#include <string>
#include <vector>



void ConvertToVec(std::unordered_map<std::string*, std::string*>* files)
{
    std::vector<std::string*> v;

    for (auto i = files->cbegin(); i != files->cend(); ++i) {
        v.push_back(i->second);
    }
}

void InitPaths(std::vector<std::string>* p)
{
    p->push_back(std::string("C:/asyncReadTest/1.txt"));
    p->push_back(std::string("C:/asyncReadTest/2.txt"));
    p->push_back(std::string("C:/asyncReadTest/3.txt"));
    p->push_back(std::string("C:/asyncReadTest/4.txt"));
    p->push_back(std::string("C:/asyncReadTest/5.txt"));
    p->push_back(std::string("C:/asyncReadTest/6.txt"));
    p->push_back(std::string("C:/asyncReadTest/7.txt"));
    p->push_back(std::string("C:/asyncReadTest/8.txt"));
    p->push_back(std::string("C:/asyncReadTest/999.txt")); //doesn't exist
    
    

}

int main()
{
    std::vector<std::string> paths;
    InitPaths(&paths);

    generic_tools::async_reader ar(&paths);

   int result = ar.ReadFilesAsync();

   std::cout << result << std::endl;
   std::cout << ar.GetStatus() << std::endl;
    
   std::unordered_map<std::string*, std::string*>* files = ar.GetResult();

   ConvertToVec(files);

}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
