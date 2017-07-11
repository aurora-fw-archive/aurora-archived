// "src/Lib/Memory.c" -*- C -*-
// ┌─┐┬ ┬┬─┐┌─┐┬─┐┌─┐  ┌─┐┬─┐┌─┐┌┬┐┌─┐┬ ┬┌─┐┬─┐┬┌─ | Powerful, Scalable and Cross Platform Framework
// ├─┤│ │├┬┘│ │├┬┘├─┤  ├┤ ├┬┘├─┤│││├┤ ││││ │├┬┘├┴┐ | @author Luís Ferreira
// ┴ ┴└─┘┴└─└─┘┴└─┴ ┴  └  ┴└─┴ ┴┴ ┴└─┘└┴┘└─┘┴└─┴ ┴ | @license GNU Public License v3
//  Copyright (c) 2016 - Luís Ferreira. All right reserved
//  More information in: https://github.com/ljmf00/ (Github Page)

// This file is part of the Aurora Framework. This framework is free
// software; you can redistribute it and/or modify it under the
// terms of the GNU General Public License, v3.

/* Contains: Memory Managment function */

#include <Aurora/TLib/Memory.h>

void *memcpy(void *dst, const void *src, size_t n)
{
	char *t = dst;
	const char *s = src;

	while (n--)
		*t++ = *s++;
	return dst;
}

void *memmove(void *dst, const void *src, size_t n)
{
	char *t;
	const char *s;

	if (dst <= src) {
		t = dst;
		s = src;
		while (n--)
			*t++ = *s++;
	} else {
		t = dst;
		t += n;
		s = src;
		s += n;
		while (n--)
			*--t = *--s;
	}
	return dst;
}

int memcmp(const void *cs, const void *ct, size_t n)
{
	const unsigned char *su1, *su2;
	int r = 0;

	for (su1 = cs, su2 = ct; 0 < n; ++su1, ++su2, n--)
		if ((r = *su1 - *su2) != 0)
			break;
	return r;
}

void *memset(void *s, int c, size_t n)
{
	char *xs = s;

	while (n--)
		*xs++ = c;
	return s;
}
