/// "src/aurora-core-tlib/String.cpp" -*- C++ -*-
/// ┌─┐┬ ┬┬─┐┌─┐┬─┐┌─┐  ┌─┐┬─┐┌─┐┌┬┐┌─┐┬ ┬┌─┐┬─┐┬┌─ | Powerful, Scalable and Cross Platform Framework
/// ├─┤│ │├┬┘│ │├┬┘├─┤  ├┤ ├┬┘├─┤│││├┤ ││││ │├┬┘├┴┐ | @author Luís Ferreira
/// ┴ ┴└─┘┴└─└─┘┴└─┴ ┴  └  ┴└─┴ ┴┴ ┴└─┘└┴┘└─┘┴└─┴ ┴ | @license GNU Public License v3
///  Copyright (c) 2016 - Luís Ferreira. All right reserved
///  More information in: https://github.com/ljmf00/ (Github Page)

/// This file is part of the Aurora Framework. This framework is free
/// software; you can redistribute it and/or modify it under the
/// terms of the GNU Lesser General Public License, v3.

/* @module aurora-core-tlib
** @title String Class (Compatible with STL)
** @brief This is the source file of Aurora String implementation.
** 		  It's more fast than STL String Class and it's compatible
** 		  with STL.
**
** @TODO: Create Ar::String Normal and Conditional Operators:
**			Conditional Operators:
**         		- >
**         		- <
**         		- <=
**         		- >=
*/

#include <Aurora/TLib/Target/CCPlusPlus.h>
#include <Aurora/TLib/String.h>
//#include <Aurora/TLib/Memory.h>
#include <Aurora/Info/RAM.h>
#ifdef AURORA_TARGET_CXX
#include <istream>
#include <ostream>
#include <cstring>
#include <cwchar>
#include <cassert>
#elif defined(AURORA_TARGET_CC)
#include <string.h>
#include <wchar.h>
#include <assert.h>
#endif /// AURORA_TARGET_CXX

#ifdef AURORA_TARGET_CXX
	namespace Ar
	{

		// @brief blank constructor for new string.
		template<class charT> string<charT>::string() {}

		/**
		** @brief        private constructor for temporary buffer.
		** @param cstr array of characters (string)
		*/
		template<class charT> string<charT>::string(size_t n)
		{
			buf = new charT[n + 1];
			len = n;
		}

		/**
		** @brief        constructor for new string.
		** @param cstr array of characters (string)
		*/
		template<>
		string<char>::string(const char* cstr)
		{
			len = strlen(cstr);
			buf = new char[size() + 1];
			memcpy(buf, cstr, (size() + 1) * sizeof(char));
		}
		template<>
		string<wchar_t>::string(const wchar_t* cstr)
		{
			len = wcslen(cstr);
			buf = new wchar_t[size() + 1];
			memcpy(buf, cstr, (size() + 1) * sizeof(wchar_t));
		}
		/**
		** @brief        constructor for new string by copy.
		** @param &str string object (for copy purpose).
		*/
		template<class charT>
		string<charT>::string(const string<charT> &str)
		{
			len  = str.size();
			buf = new charT[size() + 1];
			memcpy(buf, str.buf, (size() + 1) * sizeof(charT));
		}

		/**
		** @brief destructor of string object: delete buffer ptr
		**        (pointer).
		*/
		template<class charT>
		string<charT>::~string()
		{
			delete [] buf;
		}

		/**
		** @brief  function to get size of the string
		** @return size (size of buffer)
		*/
		template<class charT>
		inline size_t string<charT>::size() const
		{
			return len * sizeof(charT);
		}

		/**
		** @brief  function to get length of the string
		** @return length
		*/
		template<class charT>
		inline size_t string<charT>::length() const
		{
			return len;
		}

		/**
		** @brief function to find a strings inside the string buffer
		** @return pos of first char of search query
		*/
		template<class charT>
		int string<charT>::find(const string<charT>& needle, const size_t pos) const
		{
			assert(pos+needle.length()+1<=len);
			for(size_t i = pos; i+1<=len-needle.length(); i++)
			{
				size_t j = 0;
				while(j+1 < needle.length() && buf[i+j] == needle[j]) j++;
				if(j+1 == needle.length()) return i;
			}
			return -1;
		}

		/**
		** @brief function to find a array of chars inside the string buffer
		** @return pos of first char of search query
		*/
		template<>
		int string<char>::find(const char* needle, const size_t pos) const
		{
			size_t tmp_len = strlen(needle);
			assert(pos+tmp_len+1<=len);
			for(size_t i = pos; i+1<=len-tmp_len; i++)
			{
				size_t j = 0;
				while(j+1 < tmp_len && buf[i+j] == needle[j]) j++;
				if(j+1 == tmp_len) return i;
			}
			return -1;
		}
		template<>
		int string<wchar_t>::find(const wchar_t* needle, const size_t pos) const
		{
		 	size_t tmp_len = wcslen(needle);
			assert(pos+tmp_len+1<=len);
			for(size_t i = pos; i+1<=len-tmp_len; i++)
			{
				size_t j = 0;
				while(j+1 < tmp_len && buf[i+j] == needle[j]) j++;
				if(j+1 == tmp_len) return i;
			}
			return -1;
		}

		/**
		** @brief function to find a array of chars inside the string buffer with a specific counter
		** @return pos of first char of search query
		*/
		template<>
		int string<char>::find(const char* needle, size_t pos, const size_t count) const
		{
			for(size_t tmp_count = 1; tmp_count <= count; tmp_count++)
			{
				pos += find(needle, pos)+strlen(needle);
			}
			return pos;
		}
		template<>
		int string<wchar_t>::find(const wchar_t* needle, size_t pos, const size_t count) const
		{
			for(size_t tmp_count = 1; tmp_count <= count; tmp_count++)
			{
				pos += find(needle, pos)+wcslen(needle);
			}
			return pos;
		}

		/**
		** @brief function to find a char inside the string buffer
		** @return pos of char of search query
		*/
		template<class charT>
		int string<charT>::find(const charT needle, size_t pos) const
		{
			assert(pos+2<=len);
			for(size_t i = pos; i+1<=len-1; i++)
			{
				if(buf[i] == needle) return i;
			}
			return -1;
		}

		/**
		** @brief        string operator = from another string
		** @param &str string object
		** @return       string (string with the same character type)
		*/
		template<class charT>
		string<charT>& string<charT>::operator = (const string<charT> str)
		{
			len = str.size();
			buf = new charT[size() + 1];
			memcpy(buf, str.buf, (size() + 1) * sizeof(charT) );
			return *this;
		}

		/**
		** @brief      string operator [] from index of buffer
		** @param  i index of the buffer
		** @return     character from the specific index of the
		**  string / buffer.
		*/
		template<class charT>
		inline charT& string<charT>::operator [] (const size_t i) const
		{
			return buf[i];
		}

		/**
		** @breif		 string operator + from a char ptr
		** @param &str char ptr
		** @return		 string (default string + char ptr)
		*/
		template<>
		string<char> string<char>::operator + (const char* str)
		{
			string<char> temp(size() + strlen(str));
			memcpy(temp.buf, buf, size() * sizeof(char));
			strcat(temp.buf, str);
			return temp;
		}
		template<>
		string<wchar_t> string<wchar_t>::operator + (const wchar_t* str)
		{
			string<wchar_t> temp(size() + wcslen(str));
			memcpy(temp.buf, buf, size() * sizeof(wchar_t));
			wcscat(temp.buf, str);
			return temp;
		}
		/**
		** @brief        string operator + from another string
		** @param &str string object
		** @return       string (string with the same character type)
		*/
		template<>
		string<char> string<char>::operator + (const string<char> str)
		{
			string<char> temp(size() + str.size());
			memcpy(temp.buf, buf, size() * sizeof(char));
			strcat(temp.buf, str.buf);
			return temp;
		}
		template<>
		string<wchar_t> string<wchar_t>::operator + (const string<wchar_t> str)
		{
			string<wchar_t> temp(size() + str.size());
			memcpy(temp.buf, buf, size() * sizeof(wchar_t));
			wcscat(temp.buf, str.buf);
			return temp;
		}

		/**
		** @brief        string operator += from another string
		** @param &str string object
		** @return       string (string with the same character type)
		*/
		template<>
		string<char>& string<char>::operator += (const string<char> str)
		{
			len += str.size();
			strcat(buf, str.buf);
			return *this;
		}
		template<>
		string<wchar_t>& string<wchar_t>::operator += (const string<wchar_t> str)
		{
			len += str.size();
			wcscat(buf, str.buf);
			return *this;
		}

		/**
		** @brief        string operator += from a char ptr
		** @param &str char pointer
		** @return       string (string with the same character type)
		*/
		template<>
		string<char>& string<char>::operator += (const char* str)
		{
			len += strlen(str);
			strcat(buf, str);
			return *this;
		}
		template<>
		string<wchar_t>& string<wchar_t>::operator += (const wchar_t* str)
		{
			len += wcslen(str);
			wcscat(buf, str);
			return *this;
		}

		/**
		** @brief			string conditional operator ==
		** @param &str	string object
		** @return			bool
		*/
		template<class charT>
		inline bool string<charT>::operator == (const string<charT> str)
		{
			return (size() == str.size()) && (memcmp(buf, str.buf, sizeof(charT)) == 0);
		}

		/**
		** @brief			string conditional operator ==
		** @param &str	char pointer
		** @return			bool
		*/
		template<>
		inline bool string<char>::operator == (const char str)
		{
			return (size() == strlen(&str)) && (memcmp(buf, &str, sizeof(char)) == 0);
		}
		template<>
		inline bool string<wchar_t>::operator == (const wchar_t str)
		{
			return (size() == wcslen(&str)) && (memcmp(buf, &str, sizeof(wchar_t)) == 0);
		}

		/**
		** @brief			string conditional operator !=
		** @param &str	string object
		** @return			bool
		*/
		template<class charT>
		inline bool string<charT>::operator != (const string<charT> str)
		{
			return (size() != str.size()) || (memcmp(buf, str.buf, sizeof(charT)) != 0);
		}

		/**
		** @brief			string conditional operator !=
		** @param &str	char pointer
		** @return			bool
		*/
		template<class charT>
		inline bool string<charT>::operator != (const charT* str)
		{
			return memcmp(buf, str, sizeof(charT));
		}

		template<class charT>
		inline void string<charT>::erase(size_t pos, size_t n)
		{
			//for(int i = )
		}

		template<class charT>
		inline charT* string<charT>::toCString() const
		{
			return buf;
		}
		/**
		** @brief        function to write on the output stream (std::ostream)
		** @param &out ostream object (output stream)
		*/
		template<>
		inline void string<char>::output (std::ostream &out)
		{
			out << buf;
		}
		template<>
		inline void string<wchar_t>::output (std::wostream &wout)
		{
			wout << buf;
		}

		/**
		** @brief       function to write on the input stream (std::istream)
		** @param &in istream object (input stream)
		**
		** bytes 	    2097152 <----- *
		** kilobits 	16384
		** kilobytes 	2048
		** megabits 	16
		** megabytes    2 <-----
		*/
		template<>
		void string<char>::input (std::istream &in)
		{
			char *tempbuf = new char[(Aurora::InfoRAM::getFreeVirtualMemory() / sizeof(char))];
			in >> tempbuf;
			len = strlen(tempbuf);
			buf = new char[size() + 1];
			memcpy(buf, tempbuf, size() + 1);
			delete [] tempbuf;
		}
		template<>
		void string<wchar_t>::input (std::wistream &win)
		{
			wchar_t *tempbuf = new wchar_t[(Aurora::InfoRAM::getFreeVirtualMemory() / sizeof(wchar_t))];
			win >> tempbuf;
			len = wcslen(tempbuf);
			buf = new wchar_t[size() + 1];
			memcpy(buf, tempbuf, size() + 1);
			delete [] tempbuf;
		}

		// string
		template class string<char>;
		template class string<wchar_t>;

		// stream operators
		/**
		** @brief        output stream (std::ostream) operator << from String
		**        (string).
		** @param &_out stream object (output stream)
		** @param &str String object (string object)
		*/
		std::ostream & operator << (std::ostream& out, String &str)
		{
			str.output(out);
			return out;
		}

		/**
		** @brief        input stream (std::istream) operator >> from String
		**        (string).
		** @param &_in   stream object (input stream)
		** @param &str String object (string object)
		*/
		std::istream & operator >> (std::istream& in, String &str)
		{
			str.input(in);
			return in;
		}
		// for wide characters
		/**
		** @brief        output stream (std::wostream) operator << from wString
		**        (wide string).
		** @param &_wout  stream object (output stream for wide characters)
		** @param &wstr wString object (string object for wide characters)
		*/
		std::wostream & operator << (std::wostream& wout, wString &wstr)
		{
			wstr.output(wout);
			return wout;
		}

		/**
		** @brief         input stream (std::wistream) operator >> from wString
		**        (wide string).
		** @param &_win   wstream object (input stream for wide characters)
		** @param &wstr wString object (string object for wide characters)
		*/
		std::wistream & operator >> (std::wistream& win, wString &wstr)
		{
			wstr.input(win);
			return win;
		}
	}
#endif /// AURORA_TARGET_CXX
