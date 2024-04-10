#include "vector.h"

int main(){
    vector<double> vec1={11, 13, 15, 17, 19};
    std::cout << vec1 << std::endl;

    vector<double> vec2={19, 17, 15, 13, 11};
    std::cout << vec2 << std::endl;

    vector<double> res1=vec1+vec2;
    std::cout << "сложение " << res1 << std::endl;
    vector<double> res2=vec1-vec2;
    std::cout << "вычитание " << res2 << std::endl;
    vector<double> res3=vec1*2;
    std::cout << "умножение на скаляр первого вектора " << res3 << std::endl;
    vector<double> res4=vec2*2.5;
    std::cout << "умножение на скаляр второго вектора " << res4 << std::endl;
    double res5=vec1*vec2;
    std::cout << "скалярное произведение " << res5 << std::endl;
    double res6=vec1.length();
    std::cout << "длина вектора первого вектора " << res6 << std::endl;
    double res7=vec2.length();
    std::cout << "длина вектора второго вектора " << res7 << std::endl;
    vector<double> res8=vec1.norma();
    std::cout << "нормализация первого вектора " << res8 << std::endl;
    vector<double> res9=vec2.norma();
    std::cout << "нормализация второго вектора " << res9 << std::endl;


    return 0;
}