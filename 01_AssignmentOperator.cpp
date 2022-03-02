//
// Created by spzhu on 2022/3/2.
//


// 题1：赋值运算符函数
// 题目：如下为类型 CMyString 的声明，请为该类型添加赋值运算符函数

#include <cstdio>
#include <cstring>

class CMyString
{
private:
    char *m_pData;
public:
    CMyString(char *pData = nullptr);
    CMyString(const CMyString &str);
    ~CMyString();

    CMyString& operator=(const CMyString& str);

    void Print();
};

CMyString::CMyString(char *pData) {
    if (pData == nullptr)
    {
        m_pData = new char[1];
        m_pData[0] = '\0';
    }
    else
    {
        int length = strlen(pData);
        m_pData = new char[length + 1];
        strcpy(m_pData, pData);
    }
}

CMyString::CMyString(const CMyString &str) {
    int length = strlen(str.m_pData);
    m_pData = new char[length + 1];
    strcpy(m_pData, str.m_pData);
}

CMyString::~CMyString() {
    delete []m_pData;
}

CMyString& CMyString::operator=(const CMyString& str)
{
    if (this == &str)
        return *this;

    delete []m_pData;
    m_pData = nullptr;

    m_pData = new char[strlen(str.m_pData) + 1];
    strcpy(m_pData, str.m_pData);

    return *this;
}

void CMyString::Print() {
    printf("%s\n", m_pData);
}

void Test1()
{
    printf("Test1 begins:\n");
    char *text = "hi";
    CMyString str1(text);
    str1.Print();
}

int main(int argc, char *argv[])
{
    Test1();

    return 0;
}