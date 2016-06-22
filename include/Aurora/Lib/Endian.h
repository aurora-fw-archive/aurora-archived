// ┌─┐┬ ┬┬─┐┌─┐┬─┐┌─┐  ┌─┐┬─┐┌─┐┌┬┐┌─┐┬ ┬┌─┐┬─┐┬┌─ | Powerful, Scalable and Cross Platform Framework
// ├─┤│ │├┬┘│ │├┬┘├─┤  ├┤ ├┬┘├─┤│││├┤ ││││ │├┬┘├┴┐ | @author Luís Ferreira
// ┴ ┴└─┘┴└─└─┘┴└─┴ ┴  └  ┴└─┴ ┴┴ ┴└─┘└┴┘└─┘┴└─┴ ┴ | @license GNU Public License v3
//  Copyright (c) 2016 - Luís Ferreira. All right reserved
//  More information in: https://github.com/ljmf00/ (Github Page)

#ifndef INCLUDE_H_AURORA_LIB_ENDIAN
#define INCLUDE_H_AURORA_LIB_ENDIAN 1

#pragma once

#include <Aurora/Core/Aurora.h>
#include <Aurora/Core/Target.h>

#if defined(AURORA_TARGET_LINUX) || defined(AURORA_TARGET_CYGWIN)
    #include <endian.h>
#elif defined(AURORA_TARGET_APPLE)
    #include <libkern/OSByteOrder.h>

    #define htobe16(x) OSSwapHostToBigInt16(x)
    #define htole16(x) OSSwapHostToLittleInt16(x)
    #define be16toh(x) OSSwapBigToHostInt16(x)
    #define le16toh(x) OSSwapLittleToHostInt16(x)

    #define htobe32(x) OSSwapHostToBigInt32(x)
    #define htole32(x) OSSwapHostToLittleInt32(x)
    #define be32toh(x) OSSwapBigToHostInt32(x)
    #define le32toh(x) OSSwapLittleToHostInt32(x)

    #define htobe64(x) OSSwapHostToBigInt64(x)
    #define htole64(x) OSSwapHostToLittleInt64(x)
    #define be64toh(x) OSSwapBigToHostInt64(x)
    #define le64toh(x) OSSwapLittleToHostInt64(x)

    #define __BYTE_ORDER    BYTE_ORDER
    #define __BIG_ENDIAN    BIG_ENDIAN
    #define __LITTLE_ENDIAN LITTLE_ENDIAN
    #define __PDP_ENDIAN    PDP_ENDIAN
#elif defined(AURORA_TARGET_OPENBSD)
    #include <sys/endian.h>
#elif defined(AURORA_TARGET_NETBSD) || defined(AURORA_TARGET_FREEBSD) || defined(AURORA_TARGET_DRAGONFLY)
    #include <sys/endian.h>
    #define be16toh(x) betoh16(x)
    #define le16toh(x) letoh16(x)

    #define be32toh(x) betoh32(x)
    #define le32toh(x) letoh32(x)

    #define be64toh(x) betoh64(x)
    #define le64toh(x) letoh64(x)
#elif defined(AURORA_TARGET_WINDOWS)
    #include <winsock2.h>
    #include <sys/param.h>

    #if BYTE_ORDER == LITTLE_ENDIAN
        #define htobe16(x) htons(x)
        #define htole16(x) (x)
        #define be16toh(x) ntohs(x)
        #define le16toh(x) (x)

        #define htobe32(x) htonl(x)
        #define htole32(x) (x)
        #define be32toh(x) ntohl(x)
        #define le32toh(x) (x)

        #define htobe64(x) htonll(x)
        #define htole64(x) (x)
        #define be64toh(x) ntohll(x)
        #define le64toh(x) (x)
    #elif BYTE_ORDER == BIG_ENDIAN

        #define htobe16(x) (x)
        #define htole16(x) __builtin_bswap16(x)
        #define be16toh(x) (x)
        #define le16toh(x) __builtin_bswap16(x)

        #define htobe32(x) (x)
        #define htole32(x) __builtin_bswap32(x)
        #define be32toh(x) (x)
        #define le32toh(x) __builtin_bswap32(x)

        #define htobe64(x) (x)
        #define htole64(x) __builtin_bswap64(x)
        #define be64toh(x) (x)
        #define le64toh(x) __builtin_bswap64(x)
    #endif

    #define __BYTE_ORDER    BYTE_ORDER
    #define __BIG_ENDIAN    BIG_ENDIAN
    #define __LITTLE_ENDIAN LITTLE_ENDIAN
    #define __PDP_ENDIAN    PDP_ENDIAN
#endif

#ifndef __AURORA_ENDIAN
    #define __AURORA_ENDIAN

    #define AURORA_HTOBE16(x) htobe16(x)
    #define AURORA_HTOLE16(x) htole16(x)
    #define AURORA_BE16TOH(x) be16toh(x)
    #define AURORA_LE16TOH(x) le16toh(x)

    #define AURORA_HTOBE32(x) htobe32(x)
    #define AURORA_HTOLE32(x) htole32(x)
    #define AURORA_BE32TOH(x) be32toh(x)
    #define AURORA_LE32TOH(x) le32toh(x)

    #define AURORA_HTOBE64(x) htobe64(x)
    #define AURORA_HTOLE64(x) htole64(x)
    #define AURORA_BE64TOH(x) be64toh(x)
    #define AURORA_LE64TOH(x) le64toh(x)

    #define AURORA_ENDIAN_BYTE_ORDER    __BYTE_ORDER
    #define AURORA_BIG_ENDIAN           __BIG_ENDIAN
    #define AURORA_LITTLE_ENDIAN 	    __LITTLE_ENDIAN
    #define AURORA_PDP_ENDIAN           __PDP_ENDIAN
#endif

#endif // INCLUDE_H_AURORA_LIB_ENDIAN