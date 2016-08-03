// ┌─┐┬ ┬┬─┐┌─┐┬─┐┌─┐  ┌─┐┬─┐┌─┐┌┬┐┌─┐┬ ┬┌─┐┬─┐┬┌─ | Powerful, Scalable and Cross Platform Framework
// ├─┤│ │├┬┘│ │├┬┘├─┤  ├┤ ├┬┘├─┤│││├┤ ││││ │├┬┘├┴┐ | @author Luís Ferreira
// ┴ ┴└─┘┴└─└─┘┴└─┴ ┴  └  ┴└─┴ ┴┴ ┴└─┘└┴┘└─┘┴└─┴ ┴ | @license GNU Public License v3
//  Copyright (c) 2016 - Luís Ferreira. All right reserved
//  More information in: https://github.com/ljmf00/ (Github Page)

#ifndef INCLUDE_H_AURORA_CRYPTO_AES
#define INCLUDE_H_AURORA_CRYPTO_AES

#include <Aurora/Core/Aurora.h>

namespace Aurora
{
	class AES
	{
		static int _nr, _nk;

		/* _i - it is the array that holds the CipherText to be decrypted.
		* _o - it is the array that holds the output of the for decryption.
		* _s - the array that holds the intermediate results during decryption.
		*/
		static unsigned char _i[16], _o[16], _s[4][4];

		// The array that stores the round keys.
		static unsigned char _rk[240];
		// The Key input to the AES Program
		static unsigned char _k[32];

		static int _getSBV(const int);
		// Inverted _getSBV
		static int _getISBV(const int);

		// This function produces Nb(Nr+1) round keys. The round keys are used in each round to decrypt the states. 
		static void _ke();
		/* This function adds the round key to state.
		* The round key is added to the state by an XOR function.
		*/
		static void _ark(int round);
		/* The SubBytes Function Substitutes the values in the
		* state matrix with values in an S-box.
		*/
		static void _sb();
		// Inverted _sb
		static void _isb();

		/* The ShiftRows() function shifts the rows in the state to the left.
		* Each row is shifted with different offset.
		* Offset = Row number. So the first row is not shifted.
		*/
		static void _sr();
		// Inverted method of _sr
		static void _isr();

		// MixColumns function mixes the columns of the state matrix
		static void _mc();
		// Inverted method of _mc
		static void _imc();

		// Cipher is the main function that encrypts the input text
		static void _c();
		// Inverted Cipher
		static void _ic();
	public:
		// AES encrypt function
		static unsigned char* encrypt(const unsigned char*, const int, unsigned char*);
		// AES decrypt functionx
		static unsigned char* decrypt(const unsigned char*, const int, unsigned char*);
	};
}


#endif // INCLUDE_H_AURORA_CRYPTO_AES