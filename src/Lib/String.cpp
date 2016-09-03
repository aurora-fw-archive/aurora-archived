// "src/Lib/String.cpp" -*- C++ -*-
// ┌─┐┬ ┬┬─┐┌─┐┬─┐┌─┐  ┌─┐┬─┐┌─┐┌┬┐┌─┐┬ ┬┌─┐┬─┐┬┌─ | Powerful, Scalable and Cross Platform Framework
// ├─┤│ │├┬┘│ │├┬┘├─┤  ├┤ ├┬┘├─┤│││├┤ ││││ │├┬┘├┴┐ | @author Luís Ferreira
// ┴ ┴└─┘┴└─└─┘┴└─┴ ┴  └  ┴└─┴ ┴┴ ┴└─┘└┴┘└─┘┴└─┴ ┴ | @license GNU Public License v3
//  Copyright (c) 2016 - Luís Ferreira. All right reserved
//  More information in: https://github.com/ljmf00/ (Github Page)

// This file is part of the Aurora Framework. This framework is free
// software; you can redistribute it and/or modify it under the
// terms of the GNU General Public License, v3.

/* @brief: String Class (Compatible with STL) */

/* @TODO: Create Ar::String Normal and Conditional Operators:
**        Conditional Operators:
**         - ==
**         - !=
**         - >
**         - <
**         - <=
**         - >=
*/

#include <Aurora/Lib/Target.h>
#include <Aurora/Lib/String.h>
#include <Aurora/Info/RAM.h>
#ifdef AURORA_TARGET_CXX
#include <istream>
#include <ostream>
#include <cstring>
#include <cwchar>
//#include <cassert>
#elif defined(AURORA_TARGET_CC)
#include <string.h>
#include <wchar.h>
//#include <assert.h>
#endif

#ifdef AURORA_TARGET_CXX
namespace Ar
{
	
	// @brief blank constructor for new string.
	template<class charT> __string<charT>::__string() {}

	/*
	** @brief        constructor for new string.
	** @param __cstr array of characters (string)
	*/
	template<>
	__string<char>::__string(const char* __cstr)
	{
		/* create new buffer with str length +1 (null 
		** character: '\0').
		*/
		_buf = new char[strlen(__cstr) + 1];
		//copy array of characters to the buffer
		memcpy(_buf, __cstr, (strlen(__cstr) + 1) * sizeof(char));
	}
	template<>
	__string<wchar_t>::__string(const wchar_t* __cstr)
	{
		/* create new buffer with str length +1 (null 
		** character: '\0').
		*/
		_buf = new wchar_t[wcslen(__cstr) + 1];
		//copy array of characters to the buffer
		memcpy(_buf, __cstr, (wcslen(__cstr) + 1) * sizeof(wchar_t));
	}
	/*
	** @brief        constructor for new string by copy.
	** @param &__str string object (for copy purpose).
	*/
	template<class charT>
	__string<charT>::__string(const __string<charT> &__str)
	{
		//create new buffer
		_buf = new charT[__str.size() + 1];
		//clone the string object
		memcpy(_buf, __str._buf, (__str.size() + 1) * sizeof(charT));
	}

	/*
	** @brief destructor of string object: delete buffer ptr 
	**        (pointer).
	*/
	template<class charT>
	__string<charT>::~__string()
	{
		//delete buffer
		delete [] _buf;
	}

	/*
	** @brief  function to get length of the string
	** @return length (size of buffer)
	*/
	template<>
	inline int __string<char>::size() const
	{
		return strlen(_buf);
	}
	template<>
	inline int __string<wchar_t>::size() const
	{
		return wcslen(_buf);
	}

	/*
	** @brief        string operator = from another string
	** @param &__str string object
	** @return       string (string with the same character type)
	*/
	template<class charT>
	__string<charT>& __string<charT>::operator = (const __string<charT> &__str)
	{
		_buf = new charT[__str.size() + 1];
		//clone the string object
		memcpy(_buf, __str._buf, (__str.size() + 1) * sizeof(charT) );
		//return this object (string)
		return *this;
	}

	/*
	** @brief      string operator [] from index of buffer
	** @param  __i index of the buffer
	** @return     character from the specific index of the
	**  string / buffer.
	*/
	template<class charT>
	inline charT& __string<charT>::operator [] (const int __i) const
	{
		return _buf[__i];
	}

	/*
	** @breif		 string operator + from a char ptr
	** @param &__str char ptr
	** @return		 string (default string + char ptr)
	*/
	template<>
	__string<char> __string<char>::operator + (const char &__str)
	{
		//temp buffer
		char* __buf = new char[this->size() + strlen(&__str) + 1];
		memcpy(__buf, _buf, this->size() * sizeof(char));
		strcat(__buf, &__str);
		__string<char> __ret(__buf);
		delete [] __buf;
		return __ret;
	}
	template<>
	__string<wchar_t> __string<wchar_t>::operator + (const wchar_t &__str)
	{
		//temp buffer
		wchar_t* __buf = new wchar_t[this->size() + wcslen(&__str) + 1];
		memcpy(__buf, _buf, this->size() * sizeof(wchar_t));
		wcscat(__buf, &__str);
		__string<wchar_t> __ret(__buf);
		delete [] __buf;
		return __ret;
	}
	/*
	** @brief        string operator + from another string
	** @param &__str string object
	** @return       string (string with the same character type)
	*/
	template<>
	__string<char> __string<char>::operator + (const __string<char> &__str)
	{
		//temp buffer length
		char* __buf = new char[this->size() + __str.size() + 1];
		memcpy(__buf, _buf, (this->size() + __str.size() + 1) * sizeof(char));
		strcat(__buf, __str._buf);
		__string<char> __ret(__buf);
		delete [] __buf;
		return __ret;
	}
	template<>
	__string<wchar_t> __string<wchar_t>::operator + (const __string<wchar_t> &__str)
	{
		//temp buffer length
		wchar_t* __buf = new wchar_t[this->size() + __str.size() + 1];
		memcpy(__buf, _buf, (this->size() + __str.size() + 1) * sizeof(wchar_t));
		wcscat(__buf, __str._buf);
		__string<wchar_t> __ret(__buf);
		delete [] __buf;
		return __ret;
	}

	/*
	** @brief        string operator += from another string
	** @param &__str string object
	** @return       string (string with the same character type)
	*/
	template<>
	__string<char>& __string<char>::operator += (const __string<char> &__str)
	{
		strcat(_buf, __str._buf);
		return *this;
	}
	template<>
	__string<wchar_t>& __string<wchar_t>::operator += (const __string<wchar_t> &__str)
	{
		wcscat(_buf, __str._buf);
		return *this;
	}

	/*
	** @brief			string conditional operator ==
	** @param &__str	string object
	** @return			bool
	*/
	template<class charT>
	inline bool __string<charT>::operator == (const __string<charT> &__str)
	{
		return !(bool)memcmp(this->_buf, __str._buf, sizeof(charT));
	}

	/*
	** @brief			string conditional operator ==
	** @param &__str	char pointer
	** @return			bool
	*/
	template<class charT>
	inline bool __string<charT>::operator == (const charT &__str)
	{
		return !(bool)memcmp(this->_buf, &__str, sizeof(charT));
	}

	/*
	** @brief			string conditional operator !=
	** @param &__str	string object
	** @return			bool
	*/
	template<class charT>
	inline bool __string<charT>::operator != (const __string<charT> &__str)
	{
		return memcmp(this->_buf, __str._buf, sizeof(charT));
	}

	/*
	** @brief			string conditional operator !=
	** @param &__str	char pointer
	** @return			bool
	*/
	template<class charT>
	inline bool __string<charT>::operator != (const charT &__str)
	{
		return memcmp(this->_buf, &__str, sizeof(charT));
	}

	/*
	** @brief        function to write on the output stream (std::ostream)
	** @param &__out ostream object (output stream)
	*/
	template<>
	inline void __string<char>::output (std::ostream &__out)
	{
		__out << _buf;
	}
	template<>
	inline void __string<wchar_t>::output (std::wostream &__wout)
	{
		__wout << _buf;
	}

	/*
	** @brief       function to write on the input stream (std::istream)
	** @param &__in istream object (input stream)
	**
	** bytes 	    2097152 <----- *
	** kilobits 	16384
	** kilobytes 	2048
	** megabits 	16
	** megabytes    2 <-----
	*/
	template<>
	void __string<char>::input (std::istream &__in)
	{
		//char __buf[(2097152 / sizeof(char))]; // Limit: 2Mb per Input Stream [OLD]
		char *__buf = new char[(Aurora::InfoRAM::getFreeVirtualMemory() / sizeof(char))];
		__in >> __buf;
		_buf = new char[strlen(__buf)+1];
		memcpy(_buf, __buf, strlen(__buf)+1);
		delete [] __buf;
	}
	template<>
	void __string<wchar_t>::input (std::wistream &__win)
	{
		//wchar_t *__buf[(2097152 / sizeof(wchar_t))]; // Limit: 2Mb per Input Stream [OLD]
		wchar_t *__buf = new wchar_t[(Aurora::InfoRAM::getFreeVirtualMemory() / sizeof(wchar_t))];
		__win >> __buf;
		_buf = new wchar_t[wcslen(__buf)+1];
		memcpy(_buf, __buf, sizeof(&__buf));
		delete [] __buf;
	}

	// __string
	template class __string<char>;
	template class __string<wchar_t>;

	/// stream operators
	/*
	** @brief        output stream (std::ostream) operator << from String
	**        (string).
	** @param &_out stream object (output stream)
	** @param &__str String object (string object)
	*/
	std::ostream & operator << (std::ostream &_out, String &__str)
	{
		__str.output(_out);
		return _out;
	}

	/*
	** @brief        input stream (std::istream) operator >> from String
	**        (string).
	** @param &_in   stream object (input stream)
	** @param &__str String object (string object)
	*/
	std::istream & operator >> (std::istream &_in, String &__str)
	{
		__str.input(_in);
		return _in;
	}
	// for wide characters
	/*
	** @brief        output stream (std::wostream) operator << from wString
	**        (wide string).
	** @param &_wout  stream object (output stream for wide characters)
	** @param &__wstr wString object (string object for wide characters)
	*/
	std::wostream & operator << (std::wostream &_wout, wString &__wstr)
	{
		__wstr.output(_wout);
		return _wout;
	}

	/*
	** @brief         input stream (std::wistream) operator >> from wString
	**        (wide string).
	** @param &_win   wstream object (input stream for wide characters)
	** @param &__wstr wString object (string object for wide characters)
	*/
	std::wistream & operator >> (std::wistream &_win, wString &__wstr)
	{
		__wstr.input(_win);
		return _win;
	}
}
#endif