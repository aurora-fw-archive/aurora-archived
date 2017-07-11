// <Aurora/Hash/MD5.h> -*- C++ -*-
// ┌─┐┬ ┬┬─┐┌─┐┬─┐┌─┐  ┌─┐┬─┐┌─┐┌┬┐┌─┐┬ ┬┌─┐┬─┐┬┌─ | Powerful, Scalable and Cross Platform Framework
// ├─┤│ │├┬┘│ │├┬┘├─┤  ├┤ ├┬┘├─┤│││├┤ ││││ │├┬┘├┴┐ | @author Luís Ferreira
// ┴ ┴└─┘┴└─└─┘┴└─┴ ┴  └  ┴└─┴ ┴┴ ┴└─┘└┴┘└─┘┴└─┴ ┴ | @license GNU Public License v3
//  Copyright (c) 2016 - Luís Ferreira. All right reserved
//  More information in: https://github.com/ljmf00/ (Github Page)

// This file is part of the Aurora Framework. This framework is free
// software; you can redistribute it and/or modify it under the
// terms of the GNU General Public License, v3.

/*
** @contains: MD5 Hash Algorithm Header file
*/

#ifndef INCLUDE_H_AURORA_HASH_MD5
#define INCLUDE_H_AURORA_HASH_MD5

#include <Aurora/TLib/Type.h>
#include <Aurora/TLib/CircularShift.h>
#include <Aurora/TLib/Endian.h>

namespace Aurora
{
	namespace Hash
	{
		class MD5 //: public Hash
		{
		public:
			MD5();
			void reset();

			// split into 64 byte blocks (=> 512 bits), hash is 16 bytes long
			enum
			{
				BlockSize = 512 / 8,
				HashBytes = 16
			};

			// compute MD5 of a memory block
			const char* operator()(const void* , size_t );
			// compute MD5 of a string, excluding final zero
			const char* operator()(const char& );

			// add arbitrary number of bytes
			void add(const void* , size_t );

			// return latest hash as 32 hex characters
			const char* getHash();
			// return latest hash as bytes
			unsigned char* getHash();

		private:
			// process 64 bytes
			void processBlock(const void* data);
			// process everything left in the internal buffer
			void processBuffer();

			// size of processed data in bytes
			uint64_t m_numBytes;
			/// valid bytes in m_buffer
			size_t   m_bufferSize;
			// bytes not processed yet
			uint8_t  m_buffer[BlockSize];
			// hash, stored as integers
			uint32_t m_hash[HashValues];

			enum
			{
				HashValues = HashBytes / 4
			};
		};
	}
}

#endif // INCLUDE_H_AURORA_HASH_MD5
