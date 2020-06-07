#ifndef VECTOR_H
#define VECTOR_H
#define DEFAULT_CAPACITY 3

#include"iostream"
template<typename T>
class Vector_Iterator;
typedef int Rank;
template<typename T>
class Vector{
    T * _elem;
    int _capacity;
    int _size;
    void copyFrom(T const * A,Rank lo,Rank hi);
    void expand();      //扩容
    void shrink();      //收缩
public:
    // 构造函数
    Vector(Rank c,int s,T v){
        _elem = new T[_capacity = c];
        for(_size = 0; _size < s; _elem[_size ++] = v);
    }
    Vector(int x ,T v ){
        _elem = new T[_capacity = x];
        for(_size = 0; _size < x; _elem[_size++] = v);
    }
    Vector(int x = 0){
        _elem = new T(_capacity= x);
        for(_size = 0; _size < x; _elem[_size++] = 0);
    }
//  复制构造函数
    Vector(T const *A,Rank n){
        copyFrom(A,0,n);
    }
    Vector(T const * A, Rank lo,Rank hi){
        copyFrom(A,lo,hi);
    }
    Vector(Vector<T> const &V){
        copyFrom(V._elem,0,V._size);
    }
    //拷贝构造函数
    Vector(Vector<T> const & V,Rank lo,Rank hi){
        copyFrom(V._elem,lo,hi);
    }
    //重载拷贝赋值运算符
    Vector<T> & operator=(Vector<T> const & V){
        if(_elem)
            delete []_elem;
        copyFrom(V._elem,0,V._size);
        return *this;
    }
    //析构函数
    ~Vector(){
        delete []_elem;
    }

    Rank size() const{
        return _size;
    }
    bool empty() const{
        return !_size;
    }
    T remove(Rank r);
    int remove(Rank lo,Rank hi);
    Rank  insert(Rank r,T const & e);
    Rank insert(T const & e){
        return insert(_size,e);
    }
    T & operator[](Rank r) const {
        return _elem[r];
    }

    //遍历
    void traverse(void(*)(T &));
    template<typename VST> void traverse(VST &);

    //打印所有元素
    void printAll(){
        for(int i = 0 ;i < _size; i ++)
            std::cout <<  _elem[i] << "  ";
        std::cout << std::endl;
    }

    Vector_Iterator<T> begin(){
        return Vector_Iterator<T>(*this);
    }
    // Vector_Iterator<T> end(){
    //     return Vector_Iterator<T>()
    // }

};

template<typename T>
class Vector_Iterator:public std::iterator<std::forward_iterator_tag,T>
{
    friend class Vector<T>;

protected:
    Vector<T> & range;
    T value;
public:
    explicit Vector_Iterator(Vector_Iterator<T> & a_range):range(a_range),value(a_range._elem){};
    Vector_Iterator & operator=(const Vector_Iterator & src){
        range = src.range;
        value = src.value;
    }

};


template<typename T>
void Vector<T>::copyFrom (T const * A, Rank lo,Rank hi){
    _elem = new T[_capacity = 2*(hi - lo)];
    _size = 0;
    while(lo < hi){
        _elem [_size ++] = A[lo++];
    }
}

//扩容
template<typename T>
void Vector<T>::expand (){
    if(_size < _capacity)
        return ;
    if(_capacity < DEFAULT_CAPACITY)
        _capacity = DEFAULT_CAPACITY;
    T * oldElem = _elem ;
    _elem = new T[_capacity <<= 1];
    for(int i = 0 ; i < _size; i ++){
        _elem[i] = oldElem[i];
    }
    delete []oldElem;
}

//收缩
template<typename T>
void Vector<T>::shrink (){
    if(_capacity < DEFAULT_CAPACITY << 1)
        return ;
    if(_size << 2 > _capacity)
        return ;
    T * oldElem = _elem ;
    _elem  = new T[_capacity >>=1];
    for(int i = 0; i < _size; i ++){
        _elem[i] = oldElem[i];
    }
    delete []oldElem;
}

template<typename T>
T Vector<T>::remove(Rank r){
    T e = _elem[r];
    remove(r,r+1);
    return e;
}
template<typename T>
int Vector<T>::remove(Rank lo,Rank hi){
    if(lo == hi)
        return 0;
    while(hi < _size){
        _elem[lo++] = _elem[hi++];
    }
    _size = lo;
    shrink();
    return hi - lo;
}

template<typename T>
void Vector<T>::traverse(void(*visit) (T &)){
    for(int i = 0; i < _size ; i++){
        visit(_elem[i]);    
    }
}

template<typename T> template<typename VST>
void Vector<T>::traverse(VST & visit){
    for(int i = 0; i < _size; i++)
        visit(_elem[i]);
}


#endif