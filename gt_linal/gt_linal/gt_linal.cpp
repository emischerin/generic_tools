// gt_linal.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <vector>


void Print3x3Matrix(int m[3][3])
{

    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            std::cout << m[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

//void* MultiplyMatrix2x2(int m1[2][2], int m2 [2][2])
//{
//    int result[2][2];
//
//    result[0][0] = m1[0][0] * m2[0][0] + m1[0][1] * m2[1][0];
//    result[0][1] = m1[0][0] * m2[0][1] + m1[0][1] * m2[1][1];
//
//    result[1][0] = m1[1][0] * m2[0][0] + m1[1][1] * m2[1][0];
//    result[1][1] = m1[1][0] * m2[0][1] + m1[1][1] * m2[1][1];
//
//    return &result;
//}

struct Vec3 {
    Vec3() {};
    Vec3(int x, int y, int z) {
        _x = x;
        _y = y;
        _z = z;
    }
    int _x, _y, _z;
};

struct Vec2 {
    Vec2() {};
    Vec2(int x, int y) {
        _x = x;
        _y = y;
    }

    int _x, _y;
};

Vec2* MultVec2Matrix(Vec2& v, int m[2][2])
{
    Vec2* result = new Vec2();

    result->_x = v._x * m[0][0] + v._y * m[1][0];
    result->_y = v._x * m[0][1] + v._y * m[1][1];

    return result;

}

int Matrix2x2Det(int matrix[2][2])
{
    return (matrix[0][0]) * (matrix[1][1]) - (matrix[0][1]) * (matrix[1][0]);
}

int Matrix3x3Det(int matrix[3][3])
{
    int diagonal1 = matrix[0][0] * matrix[1][1] * matrix[2][2];
    int diagonal2 = matrix[0][1] * matrix[1][2] * matrix[2][0];
    int diagonal3 = matrix[0][2] * matrix[1][0] * matrix[2][1];
    int diagonal4 = -(matrix[0][2] * matrix[1][1] * matrix[2][0]);
    int diagonal5 = -(matrix[0][0] * matrix[1][2] * matrix[2][1]);
    int diagonal6 = -(matrix[0][1] * matrix[1][0] * matrix[2][2]);

    return (diagonal1 + diagonal2 + diagonal3) - (diagonal4 - diagonal5 - diagonal6);
}
void TestDet2x2()
{
    int matrix[2][2] = { 1,1,
                         1,1 };
    int matrix2[2][2] = { 2,2,
                         2,2 };

    int matrix3[2][2] = { 1,1,
                         1,0 };

    int matrix4[2][2] = { 15,5,
                         7,17 };

    std::cout << Matrix2x2Det(matrix) << std::endl;
    std::cout << Matrix2x2Det(matrix2) << std::endl;
    std::cout << Matrix2x2Det(matrix3) << std::endl;
    std::cout << Matrix2x2Det(matrix4) << std::endl;
}

void Print2x2Matrix(int m[2][2])
{
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 2; ++j) {
            std::cout << m[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

void TestMultiply2x2M()
{
    int m1[2][2] = { 1,0,
                    0, 1 };
    int m2[2][2] = { 2,1,
                    1,2 };

    int result[2][2];

    result[0][0] = m1[0][0] * m2[0][0] + m1[0][1] * m2[1][0];
    result[0][1] = m1[0][0] * m2[0][1] + m1[0][1] * m2[1][1];

    result[1][0] = m1[1][0] * m2[0][0] + m1[1][1] * m2[1][0];
    result[1][1] = m1[1][0] * m2[0][1] + m1[1][1] * m2[1][1];

    Print2x2Matrix(result);

}

void Vec2Research()
{
    Vec2 v(2, 1);
    int m[2][2] = { 1,2,
                   0,0 };

    Vec2* result = MultVec2Matrix(v, m);

    std::cout << result->_x << " " << result->_y << std::endl;
}

void TestDet3x3()
{
    int matrix3x3[3][3] = { 1,-2,3,
                           4,0,6,
                           -7,8,9 };

    std::cout << Matrix3x3Det(matrix3x3) << std::endl;
}

void TestTriangle()
{
    int matrix1[3][3] = { 1,1,0,
                          1,3,0,
                          3,1,0 };

    /*int matrix2[3][3] = { 1,1,0,
                          1,2,0,
                          2,1,0 };*/

    int matrix2[3][3] = { 0,0,0,
                          2,0,0,
                          0,0,0 };

    
    int result[3][3];

    result[0][0] = matrix1[0][0] * matrix2[0][0] + matrix1[0][1] * matrix2[1][0] + matrix1[0][2] * matrix2[2][0];
    result[0][1] = matrix1[0][0] * matrix2[0][1] + matrix1[0][1] * matrix2[1][1] + matrix1[0][2] * matrix2[2][1];
    result[0][2] = matrix1[0][0] * matrix2[0][2] + matrix1[0][1] * matrix2[1][2] + matrix1[0][2] * matrix2[2][2];

    result[1][0] = matrix1[1][0] * matrix2[0][0] + matrix1[1][1] * matrix2[1][0] + matrix1[1][2] * matrix2[2][0];
    result[1][1] = matrix1[1][0] * matrix2[0][1] + matrix1[1][1] * matrix2[1][1] + matrix1[1][2] * matrix2[2][1];
    result[1][2] = matrix1[1][0] * matrix2[0][2] + matrix1[1][1] * matrix2[1][2] + matrix1[1][2] * matrix2[2][2];

    result[2][0] = matrix1[2][0] * matrix2[0][0] + matrix1[2][1] * matrix2[1][0] + matrix1[2][2] * matrix2[2][0];
    result[2][1] = matrix1[2][0] * matrix2[0][1] + matrix1[2][1] * matrix2[1][1] + matrix1[2][2] * matrix2[2][1];
    result[2][2] = matrix1[2][0] * matrix2[0][2] + matrix1[2][1] * matrix2[1][2] + matrix1[2][2] * matrix2[2][2];

    Print3x3Matrix(result);



}

//int* MatrixXMatrix3(int matrix1[3][3], int matrix2[3][3])
//{
//    int* result[3] = {};
//
//    *result[0][0] = matrix1[0][0] * matrix2[0][0] + matrix1[0][1] * matrix2[1][0] + matrix1[0][2] * matrix2[2][0];
//    *result[0][1] = matrix1[0][0] * matrix2[0][1] + matrix1[0][1] * matrix2[1][1] + matrix1[0][2] * matrix2[2][1];
//    *result[0][2] = matrix1[0][0] * matrix2[0][2] + matrix1[0][1] * matrix2[1][2] + matrix1[0][2] * matrix2[2][2];
//    
//    *result[1][0] = matrix1[1][0] * matrix2[0][0] + matrix1[1][1] * matrix2[1][0] + matrix1[1][2] * matrix2[2][0];
//    *result[1][1] = matrix1[1][0] * matrix2[0][1] + matrix1[1][1] * matrix2[1][1] + matrix1[1][2] * matrix2[2][1];
//    *result[1][2] = matrix1[1][0] * matrix2[0][2] + matrix1[1][1] * matrix2[1][2] + matrix1[1][2] * matrix2[2][2];
//
//    *result[2][0] = matrix1[2][0] * matrix2[0][0] + matrix1[2][1] * matrix2[1][0] + matrix1[2][2] * matrix2[2][0];
//    *result[2][1] = matrix1[2][0] * matrix2[0][1] + matrix1[2][1] * matrix2[1][2] + matrix1[2][2] * matrix2[2][1];
//    *result[2][2] = matrix1[2][0] * matrix2[0][2] + matrix1[2][1] * matrix2[1][2] + matrix1[2][2] * matrix2[2][2];
//
//    return result;
//}


//Matrix* MatrixXMatrix3(int matrix1[3][3],int matrix2[3][3])
//{
//    Matrix* result = new Matrix(3);
//
//    result->m[0][0] = matrix1[0][0] * matrix2[0][0] + matrix1[0][1] * matrix2[1][0] + matrix1[0][2] * matrix2[2][0];
//    result->m[0][1] = matrix1[0][0] * matrix2[0][1] + matrix1[0][1] * matrix2[1][1] + matrix1[0][2] * matrix2[2][1];
//    result->m[0][2] = matrix1[0][0] * matrix2[0][2] + matrix1[0][1] * matrix2[1][2] + matrix1[0][2] * matrix2[2][2];
//
//    result->m[1][0] = matrix1[1][0] * matrix2[0][0] + matrix1[1][1] * matrix2[1][0] + matrix1[1][2] * matrix2[2][0];
//    result->m[1][1] = matrix1[1][0] * matrix2[0][1] + matrix1[1][1] * matrix2[1][1] + matrix1[1][2] * matrix2[2][1];
//    result->m[1][2] = matrix1[1][0] * matrix2[0][2] + matrix1[1][1] * matrix2[1][2] + matrix1[1][2] * matrix2[2][2];
//
//    result->m[2][0] = matrix1[2][0] * matrix2[0][0] + matrix1[2][1] * matrix2[1][0] + matrix1[2][2] * matrix2[2][0];
//    result->m[2][1] = matrix1[2][0] * matrix2[0][1] + matrix1[2][1] * matrix2[1][2] + matrix1[2][2] * matrix2[2][1];
//    result->m[2][2] = matrix1[2][0] * matrix2[0][2] + matrix1[2][1] * matrix2[1][2] + matrix1[2][2] * matrix2[2][2];
//
//    return result;
//}



void Test3x3Mult()
{
    int matrix1[3][3] = { 2,2,0,
                          2,0,0,
                          0,0,0 };
    int matrix2[3][3] = { 0,1,1,
                          1,0,1,
                          0,0,0 };

    int result[3][3];

    result[0][0] = matrix1[0][0] * matrix2[0][0] + matrix1[0][1] * matrix2[1][0] + matrix1[0][2] * matrix2[2][0];
    result[0][1] = matrix1[0][0] * matrix2[0][1] + matrix1[0][1] * matrix2[1][1] + matrix1[0][2] * matrix2[2][1];
    result[0][2] = matrix1[0][0] * matrix2[0][2] + matrix1[0][1] * matrix2[1][2] + matrix1[0][2] * matrix2[2][2];

    result[1][0] = matrix1[1][0] * matrix2[0][0] + matrix1[1][1] * matrix2[1][0] + matrix1[1][2] * matrix2[2][0];
    result[1][1] = matrix1[1][0] * matrix2[0][1] + matrix1[1][1] * matrix2[1][1] + matrix1[1][2] * matrix2[2][1];
    result[1][2] = matrix1[1][0] * matrix2[0][2] + matrix1[1][1] * matrix2[1][2] + matrix1[1][2] * matrix2[2][2];

    result[2][0] = matrix1[2][0] * matrix2[0][0] + matrix1[2][1] * matrix2[1][0] + matrix1[2][2] * matrix2[2][0];
    result[2][1] = matrix1[2][0] * matrix2[0][1] + matrix1[2][1] * matrix2[1][1] + matrix1[2][2] * matrix2[2][1];
    result[2][2] = matrix1[2][0] * matrix2[0][2] + matrix1[2][1] * matrix2[1][2] + matrix1[2][2] * matrix2[2][2];

    Print3x3Matrix(result);
}

void TestVec2Incr()
{
    Vec2 v(1, 1);
    Vec2 v1(3, 1);
    Vec2 v2(1, 3);

    std::vector<std::vector<Vec2>> vec;

    for (int i = 0; i < 3; ++i) {
        std::vector<Vec2> result;
        vec.push_back(result);
        


    }
    int brk = 10;
}

int main()
{
   /* TestMultiply2x2M();
    Test3x3Mult();
    TestDet3x3();
    TestTriangle();*/
   // Test3x3Mult();
   // Vec2Research();

   // TestMultiply2x2M();

    Vec2Research();
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
