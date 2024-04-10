#include <iostream>
#include <math.h>

template<typename T>

class vector{
private:
    T* _array;
    size_t _size;

public:
    vector() = delete; // если дефолтный конструктор не нужен, то пишем так, просто не написать его не получится
    vector(size_t size, T* array):_size(size), _array(new T[size]){// если используются шаблоны, то лучше писать это в хидере, в срр это будет долго и нудно
        for(int i = 0; i < _size; i++){
            _array[i] = array[i];
        }
    }

    vector(size_t size): _size(size) {// параметры можно выносить через двоеточие, но хз зачем оно надо
        _array = new T[size];
        for(int i = 0; i < _size; i++)
            _array[i] = 0;
    }

    vector& operator=(const vector& tmp){
        if (tmp._size>_size){
            delete[]_array;
            _array=new T[tmp._size];
        }
        _size=tmp._size;
        for (size_t i=0; i<_size; i++){
            _array[i]=tmp._array[i];
        }
        return *this;
    }

    vector(const vector& tmp){
        _size=tmp._size;
        _array=new T[_size];
        for(size_t i=0; i<_size; i++){
            _array[i]=tmp._array[i];
        }

    }

    vector operator+(const vector& v) const{
        if(_size!=v._size)
            throw "error";
        vector vec=vector(_size);
        for (int i=0; i<_size; i++)
            vec._array[i]=v._array[i]+_array[i];
        return vec;
    }

    vector operator-(const vector& v) const{
        if (_size!=v._size)
            throw "error";
        vector vec=vector(_size);
        for (int i=0; i<_size; i++)
            vec._array[i]=_array[i]-v._array[i];
        return vec;
    }

    vector operator*(double a) const{
        vector vec=vector(_size);
        for (int i=0; i<_size; i++)
            vec._array[i]=a*_array[i];
        return vec;
    }

    double operator*(const vector& v) const{
        double c=0;
        if (_size!=v._size)
            throw "error";
        for (int i=0; i<_size; i++)
            c+=_array[i]*_array[i];
        return c;
    }

    double length(){
        double len=sqrt((*this)*(*this));
        return len;
    }

    vector<double> norma(){
        double len=length();
        for (int i=0; i<_size; i++)
            _array[i]=_array[i]/len;
        return *this;
    }

    ~vector(){ // деструктор, самоудаляется, когда перестает испоользоваться
        delete [] _array;
    }

    T& operator[](int i){
        return _array[i];
    }

    friend std::ostream& operator<< (std::ostream& os, const vector& vec){
        os << "(";
        for(int i = 0; i < vec._size; i++){
            os << vec._array[i];
            if(i+1 != vec._size)
                os << ", ";
        }
        os << ")";
        return os;
    }
    vector(std::initializer_list<T> list){ // конструктор для того, чтобы нароямую задавать векторы
        _size = list.size();
        _array = new T[_size];
        int i = 0;
        for(auto elem = list.begin(); elem != list.end(); elem++, i++){
            _array[i] = *elem;
        }
    }
};
