#ifndef __CMYSTRING_H__
#define __CMYSTRING_H__
#include <cstring>
#include <iostream>
//剑指offer
//赋值运算符函数
//题目：如下为CMystring的声明，为该类型添加赋值运算符函数
class CMyString
{
public:
	CMyString(char* pData = nullptr);
	CMyString(const CMyString& str);
	~CMyString();
	CMyString& operator=(const CMyString& str);
	void print();
private:
	char *m_pData;
};

CMyString::CMyString(char* pData)
{
	if (pData == nullptr)
	{
		m_pData = new char[1];
		m_pData = '\0';
	}
	else
	{
		int length = strlen(pData) + 1;
		m_pData = new char[length];
		strcpy(m_pData, pData);
	}
}

CMyString::CMyString(const CMyString& str)
{
	m_pData = new char[strlen(str.m_pData) + 1];
	//m_pData = nullptr;
	strcpy(m_pData, str.m_pData);
}

CMyString::~CMyString()
{
	delete[]m_pData;
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

void CMyString::print()
{
	std::cout << m_pData <<std::endl;
}
#endif