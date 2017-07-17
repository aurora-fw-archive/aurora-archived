# Aurora Library - Endian

```c
#include <Aurora/Lib/Endian.h>
```
  Header to convert values between host and big-/little-endian byte order. These directives functions convert the byte encoding of integer values from the byte order that the current CPU (the "host") uses, to and from little-endian and big-endian byte order.

### Directives
```c
#define AURORA_HTOBE16(x)
#define AURORA_HTOLE16(x)
#define AURORA_BE16TOH(x)
#define AURORA_LE16TOH(x)

#define AURORA_HTOBE32(x)
#define AURORA_HTOLE32(x)
#define AURORA_BE32TOH(x)
#define AURORA_LE32TOH(x)

#define AURORA_HTOBE64(x)
#define AURORA_HTOLE64(x)
#define AURORA_BE64TOH(x)
#define AURORA_LE64TOH(x)

#define AURORA_ENDIAN_BYTE_ORDER
#define AURORA_BIG_ENDIAN
#define AURORA_LITTLE_ENDIAN
#define AURORA_PDP_ENDIAN
```
