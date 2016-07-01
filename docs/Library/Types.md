# Aurora Library - Fundamental Types

```c
#include <Aurora/Lib/Type.h>
```
  This header contains the fundamental types used across the aurora framework (Except String Class Type).

### Types
- ArFloat
- ArBool
- ArSlot_t
- ArDouble
- ArLDouble

##### Signed
- ArChar
- ArInt
- ArShort_t
- ArLong_t
- ArInt8_t
- ArInt16_t
- ArInt32_t
- ArInt64_t

##### Unsigned
- ArUChar
- ArByte
- ArUInt_t
- ArUShort_t
- ArULong_t
- ArUInt8_t
- ArUInt16_t
- ArUInt32_t
- ArUInt64_t

### Directives
```c
#define AURORA_INT_MIN
#define AURORA_INT8_MIN
#define AURORA_INT16_MIN
#define AURORA_INT32_MIN
#define AURORA_INT64_MIN

#define AURORA_INT_MAX
#define AURORA_INT8_MAX
#define AURORA_INT16_MAX
#define AURORA_INT32_MAX
#define AURORA_INT64_MAX

#define AURORA_UINT8_MAX
#define AURORA_UINT16_MAX
#define AURORA_UINT32_MAX
#define AURORA_UINT64_MAX
```

### Size Table
|Type|Min|Max|
|:--:|:--:|:--:|
|ArInt|-|-|
|ArShort_t|-|-|
|ArLong_t|-|-|
|ArInt8_t|-|-|
|ArInt16_t|-|-|
|ArInt32_t|-|-|
|ArInt64_t|-|-|
|ArUInt_t|0|4294967295|
|ArUShort_t|-|-|
|ArULong_t|-|-|
|ArUInt8_t|0|255|
|ArUInt16_t|0|65535|
|ArUInt32_t|0|4294967295|
|ArUInt64_t|0|18446744073709551615|
|-|-|-|
