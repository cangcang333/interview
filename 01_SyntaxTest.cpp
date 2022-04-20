/**
 * Basic syntax test
 */

#include <iostream>

class TrueEmptyClass
{

};

class EmptyClass
{
    EmptyClass();
    virtual ~EmptyClass();
};

EmptyClass::EmptyClass() {
    std::cout << "EmptyClass constructor\n";
}
EmptyClass::~EmptyClass() {
    std::cout << "EmptyClass destructor\n";
}

class A
{
private:
    int value;
public:
    A(int n) { value = n; }
    A(A const &other) { value = other.value; }
    void Print() { std::cout << value << std::endl; }
};

int GetSize(int data[])
{
    return sizeof(data);
}

int main(int argc, char *argv[])
{
    // 空类型占用多少内存由编译器决定，在此，每个空类型的实例占用 1 字节的空间
    std::cout << "TrueEmptyClass size is " << sizeof(TrueEmptyClass) << std::endl;
    std::cout << "EmptyClass size is " << sizeof(EmptyClass) << std::endl;


    A a = 10;
    A b = a;
    b.Print();

    A c(20);
    c.Print();


    int data1[] = {1, 2, 3, 4, 5};
    int size1 = sizeof(data1);

    int *data2 = data1;
    int size2 = sizeof(data2);

    int size3 = GetSize(data1);
    printf("size1: %d, size2: %d, size3: %d\n", size1, size2, size3);



    std::cout << "... end ..." << std::endl;


	return 0;
}
