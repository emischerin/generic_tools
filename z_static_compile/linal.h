#pragma once
namespace generic_tools {
	namespace math {
		namespace linal {


            template<class T>
            class matrix {
            public:
                matrix(size_t& x, size_t& y) {
                    
                    _size = x * y;
                    _x_size = x;
                    _y_size = y;
                    _max_x = _x_size - 1;
                    _max_y = _y_size - 1;
                    _data = new T[_size];

                   

                    
                }
                matrix(size_t&& x, size_t&& y) {

                    _size = x * y;
                    _x_size = x;
                    _y_size = y;
                    _max_x = _x_size - 1;
                    _max_y = _y_size - 1;
                    _data = new T[_size];


                }

                T* get_element(size_t x, size_t y) {
                    if (x > _max_x) return nullptr;
                    if (y > _max_y) return nullptr;
                    return &(_data[x * _x_size + y]);
                }

                T get_value(size_t x, size_t y) {
                    if (x > _max_x) return nullptr;
                    if (y > _max_y) return nullptr;
                    return *(_data[x * _x_size + y]);
                }

                ~matrix() {
                    delete[] _data;
                }

            private:
                T* _data;
                size_t _size;
                size_t _x_size;
                size_t _y_size;
                size_t _max_x;
                size_t _max_y;
                
            };

            template<class T>
            struct Vec3 {
                Vec3() {};
                Vec3(T x, T y, T z) {
                    _x = x;
                    _y = y;
                    _z = z;
                }
                T _x, _y, _z;
            };

            template<class T>
            struct Vec2 {
                Vec2() {};
                Vec2(T x, T y) {
                    _x = x;
                    _y = y;
                }

                T _x, _y;
            };

            template<class T>
            Vec2<T>* MultVec2Matrix(Vec2<T>& v, T m[2][2]) {
                Vec2<T>* result = new Vec2<T>();

                result->_x = v._x * m[0][0] + v._y * m[1][0];
                result->_y = v._x * m[0][1] + v._y * m[1][1];

                return result;
            }

            template<class T>
            T Matrix2x2Det(T matrix[2][2]) {
                return (matrix[0][0]) * (matrix[1][1]) - (matrix[0][1]) * (matrix[1][0]);
            }

            template<class T>
            T Matrix3x3Det(T matrix[3][3])
            {
                T diagonal1 = matrix[0][0] * matrix[1][1] * matrix[2][2];
                T diagonal2 = matrix[0][1] * matrix[1][2] * matrix[2][0];
                T diagonal3 = matrix[0][2] * matrix[1][0] * matrix[2][1];
                T diagonal4 = -(matrix[0][2] * matrix[1][1] * matrix[2][0]);
                T diagonal5 = -(matrix[0][0] * matrix[1][2] * matrix[2][1]);
                T diagonal6 = -(matrix[0][1] * matrix[1][0] * matrix[2][2]);

                return (diagonal1 + diagonal2 + diagonal3) - (diagonal4 - diagonal5 - diagonal6);
            }

            template<class T>
            matrix<T>* TestMultiply2x2M(matrix<T> a,matrix<T> b)
            {
                int m1[2][2] = { 1,0,
                                0, 1 };
                int m2[2][2] = { 2,1,
                                1,2 };

                matrix<int> result(2,2);

                

                result.get_element(0,0) = m1[0][0] * m2[0][0] + m1[0][1] * m2[1][0];
                result.get_element(0, 1) = m1[0][0] * m2[0][1] + m1[0][1] * m2[1][1];

                result.get_element(1, 0) = m1[1][0] * m2[0][0] + m1[1][1] * m2[1][0];
                result.get_element(1, 1) = m1[1][0] * m2[0][1] + m1[1][1] * m2[1][1];

                //Print2x2Matrix(result);

                return &result;

            }

            template<class T>
            matrix<T>* TestTriangle()
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


                matrix<int> result(3,3);

                result.get_element(0,0) = matrix1[0][0] * matrix2[0][0] + matrix1[0][1] * matrix2[1][0] + matrix1[0][2] * matrix2[2][0];
                result.get_element(0,1) = matrix1[0][0] * matrix2[0][1] + matrix1[0][1] * matrix2[1][1] + matrix1[0][2] * matrix2[2][1];
                result.get_element(0,2)= matrix1[0][0] * matrix2[0][2] + matrix1[0][1] * matrix2[1][2] + matrix1[0][2] * matrix2[2][2];

                result.get_element(1,0) = matrix1[1][0] * matrix2[0][0] + matrix1[1][1] * matrix2[1][0] + matrix1[1][2] * matrix2[2][0];
                result.get_element(1,1) = matrix1[1][0] * matrix2[0][1] + matrix1[1][1] * matrix2[1][1] + matrix1[1][2] * matrix2[2][1];
                result.get_element(1,2) = matrix1[1][0] * matrix2[0][2] + matrix1[1][1] * matrix2[1][2] + matrix1[1][2] * matrix2[2][2];

                result.get_element(2,0) = matrix1[2][0] * matrix2[0][0] + matrix1[2][1] * matrix2[1][0] + matrix1[2][2] * matrix2[2][0];
                result.get_element(2,1) = matrix1[2][0] * matrix2[0][1] + matrix1[2][1] * matrix2[1][1] + matrix1[2][2] * matrix2[2][1];
                result.get_element(2,2) = matrix1[2][0] * matrix2[0][2] + matrix1[2][1] * matrix2[1][2] + matrix1[2][2] * matrix2[2][2];

                //Print3x3Matrix(result);

                return &result;



            }

		}
	}
}


