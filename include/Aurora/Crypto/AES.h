// ┌─┐┬ ┬┬─┐┌─┐┬─┐┌─┐  ┌─┐┬─┐┌─┐┌┬┐┌─┐┬ ┬┌─┐┬─┐┬┌─ | Powerful, Scalable and Cross Platform Framework
// ├─┤│ │├┬┘│ │├┬┘├─┤  ├┤ ├┬┘├─┤│││├┤ ││││ │├┬┘├┴┐ | @author Luís Ferreira
// ┴ ┴└─┘┴└─└─┘┴└─┴ ┴  └  ┴└─┴ ┴┴ ┴└─┘└┴┘└─┘┴└─┴ ┴ | @license GNU Public License v3
//  Copyright (c) 2016 - Luís Ferreira. All right reserved
//  More information in: https://github.com/ljmf00/ (Github Page)

#include <Aurora/TLib/Target/PragmaOnce.h>
#if defined(AURORA_TARGET_PRAGMA_ONCE_SUPPORT) && AURORA_TARGET_PRAGMA_ONCE_SUPPORT
    #pragma once
#endif

#ifndef AURORA_FW
#define AURORA_FW 1
#endif // AURORA_FW

#ifndef INCLUDE_H_AURORA_CRYPTO_AES
#define INCLUDE_H_AURORA_CRYPTO_AES

#include <Aurora/TLib/Memory.h>

/*
 * The number of columns comprising a _s in AES.
 * This is a constant in AES. Value=4
 */
#define AURORA_AES_NUM 4

// AURORA_AES_TIME is a macro that finds the product of {02} and the argument to xtime modulo {1b}
#define AURORA_AES_TIME(x)   ((x<<1) ^ (((x>>7) & 1) * 0x1b))

// _AURORA_AES_MULTI is a macro used to multiply numbers in the field GF(2^8)
#define AURORA_AES_MULTI(x,y) (((y & 1) * x) ^ ((y>>1 & 1) * AURORA_AES_TIME(x)) ^ ((y>>2 & 1) * AURORA_AES_TIME(AURORA_AES_TIME(x))) ^ ((y>>3 & 1) * AURORA_AES_TIME(AURORA_AES_TIME(AURORA_AES_TIME(x)))) ^ ((y>>4 & 1) * AURORA_AES_TIME(AURORA_AES_TIME(AURORA_AES_TIME(AURORA_AES_TIME(x))))))

namespace Aurora
{
	class AES
	{
	private:
		static int nr, nk;

		/* i - it is the array that holds the CipherText to be decrypted.
		** o - it is the array that holds the output of the for decryption.
		** s - the array that holds the intermediate results during decryption.
		*/
		static unsigned char in[16], out[16], stt[4][4];

		// The array that stores the round keys.
		static unsigned char rk[240];
		// The Key input to the AES Program
		static unsigned char key[32];

		static int getSBV(const int);
		// Inverted getSBV
		static int getISBV(const int);

		// This function produces Nb(Nr+1) round keys. The round keys are used in each round to decrypt the states.
		static void ke();
		/* This function adds the round key to state.
		* The round key is added to the state by an XOR function.
		*/
		static void ark(int round);
		/* The SubBytes Function Substitutes the values in the
		* state matrix with values in an S-box.
		*/
		static void sb();
		// Inverted sb
		static void isb();

		/* The ShiftRows() function shifts the rows in the state to the left.
		* Each row is shifted with different offset.
		* Offset = Row number. So the first row is not shifted.
		*/
		static void sr();
		// Inverted method of _sr
		static void isr();

		// MixColumns function mixes the columns of the state matrix
		static void mc();
		// Inverted method of _mc
		static void imc();

		// Cipher is the main function that encrypts the input text
		static void c();
		// Inverted Cipher
		static void ic();
	public:
		// AES encrypt function
		static unsigned char* encrypt(const unsigned char*, const int, unsigned char*);
		// AES decrypt functionx
		static unsigned char* decrypt(const unsigned char*, const int, unsigned char*);
	};
}


#endif // INCLUDE_H_AURORA_CRYPTO_AES
