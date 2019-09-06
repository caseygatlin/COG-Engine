/*

#include "String.h"

namespace Engine
{
	String::String()
	{
		m_str = nullptr;
		m_size = 0;
	}

	String::~String()
	{
		delete[] m_str;
	}

	String& String::operator=(const char* src)
	{
		delete[] m_str;
		m_str = nullptr;

		int size = 0;
		int index = 0;
		while (src[index] != '\0')
		{
			size++;
			
			if (m_str != nullptr)
				delete[] m_str;

			m_str = new char[size];
			m_str[index] = src[index];
			index++;
		}
		
		m_str[index] = '\0';
	}


	char &String::operator[](int index)
	{
		if (index >= m_size)
			return m_str[m_size - 1];

		return m_str[index];
	}


}

*/