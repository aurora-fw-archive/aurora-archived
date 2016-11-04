// <Aurora/Lib/String.h> -*- C++ -*-
// ┌─┐┬ ┬┬─┐┌─┐┬─┐┌─┐  ┌─┐┬─┐┌─┐┌┬┐┌─┐┬ ┬┌─┐┬─┐┬┌─ | Powerful, Scalable and Cross Platform Framework
// ├─┤│ │├┬┘│ │├┬┘├─┤  ├┤ ├┬┘├─┤│││├┤ ││││ │├┬┘├┴┐ | @author Luís Ferreira
// ┴ ┴└─┘┴└─└─┘┴└─┴ ┴  └  ┴└─┴ ┴┴ ┴└─┘└┴┘└─┘┴└─┴ ┴ | @license GNU Public License v3
//  Copyright (c) 2016 - Luís Ferreira. All right reserved
//  More information in: https://github.com/ljmf00/ (Github Page)

// This file is part of the Aurora Framework. This framework is free
// software; you can redistribute it and/or modify it under the
// terms of the GNU General Public License, v3.

/* Contains: String Class (Compatible with STL) */

#ifndef INCLUDE_H_AURORA_LIB_STRING
#define INCLUDE_H_AURORA_LIB_STRING    1

#pragma once

#include <Aurora/Lib/Target.h>

#ifdef AURORA_TARGET_CXX
	extern "C"
	{
#endif
		// extern
#ifdef AURORA_TARGET_CXX
	}
	#include <istream>
	#include <ostream>

namespace Ar
{
	template<class charT>
	class string
	{
	public:
		string();                                     //Blank string
		string (const charT* );                        // Normal string
		string (const string<charT>& );              // String by copy
		~string();

		//Operators
		string& operator = (const string<charT> );		// Operator: =
		string operator + (const string<charT> );         // Operator: + (string)
		string operator + (const charT* );                   // Operator: + (char ptr)
		string& operator += (const string<charT> );       // Operator: += (string)
		string& operator += (const charT* );					// Operator: += (char ptr)
		inline charT& operator [] (const size_t ) const;			// Operator: []
		inline bool operator == (const string<charT> );		// Operator: == (string)
		inline bool operator == (const charT );			// Operator: == (char ptr)
		inline bool operator != (const string<charT> );		// Operator: != (string)
		inline bool operator != (const charT* );			// Operator: != (char ptr)

		void add (size_t, const string<charT>& );
		void add (size_t, const charT* );
		void erase (const size_t ,const size_t );
		inline void output (std::ostream& );
		inline void output (std::wostream& );
		void input (std::istream& );
		void input (std::wistream& );
		int find (const string<charT>& , size_t = 0) const; // Search from another string
		int find (const charT* , size_t  = 0) const; // Search from an array of char
		size_t find (const charT* , size_t , size_t ) const; // Search from a buffer
		size_t find (const charT , size_t = 0) const; // Search from a char
		inline size_t length() const;					// Return String length
		inline size_t size() const;                    // Return String size

	private:
		string (size_t );
		charT* buf = NULL;
		size_t len;
	};
	typedef string<char>      String;
	typedef string<wchar_t>   wString;

	extern std::ostream& operator << (std::ostream& out, String &str);
	extern std::istream& operator >> (std::istream& in, String &str);

	//for wide characters
	extern std::wostream& operator << (std::wostream& wout, wString &wstr);
	extern std::wistream& operator >> (std::wistream& win, wString &wstr);
}
#endif

#ifndef AURORA_STRING_MAXSIZE
	#ifdef AURORA_WORDSIZE
		#if AURORA_WORDSIZE == 64
			#define AURORA_STRING_MAXSIZE   9223372036854775807
		#else
			#define AURORA_STRING_MAXSIZE   2147483647
		#endif
	#endif
#endif

#endif // INCLUDE_H_AURORA_LIB_STRING
