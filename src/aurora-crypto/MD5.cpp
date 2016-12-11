// "src/Hash/MD5.cpp" -*- C++ -*-
// ┌─┐┬ ┬┬─┐┌─┐┬─┐┌─┐  ┌─┐┬─┐┌─┐┌┬┐┌─┐┬ ┬┌─┐┬─┐┬┌─ | Powerful, Scalable and Cross Platform Framework
// ├─┤│ │├┬┘│ │├┬┘├─┤  ├┤ ├┬┘├─┤│││├┤ ││││ │├┬┘├┴┐ | @author Luís Ferreira
// ┴ ┴└─┘┴└─└─┘┴└─┴ ┴  └  ┴└─┴ ┴┴ ┴└─┘└┴┘└─┘┴└─┴ ┴ | @license GNU Public License v3
//  Copyright (c) 2016 - Luís Ferreira. All right reserved
//  More information in: https://github.com/ljmf00/ (Github Page)

// This file is part of the Aurora Framework. This framework is free
// software; you can redistribute it and/or modify it under the
// terms of the GNU General Public License, v3.

/*
** @contains: MD5 Hash Algorithm Source file
*/

#include <Aurora/Hash/MD5.h>

namespace Aurora
{
	namespace Hash
	{
		MD5::MD5()
		{
			reset();
		}

		void MD5::reset()
		{
			m_numBytes   = 0;
			m_bufferSize = 0;

			// according to RFC 1321
			m_hash[0] = 0x67452301;
			m_hash[1] = 0xefcdab89;
			m_hash[2] = 0x98badcfe;
			m_hash[3] = 0x10325476;
		}
	}
}