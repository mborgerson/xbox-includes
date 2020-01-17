#ifdef TEST_COMPILE
#define _cdecl
#define __cdecl
#define __stdcall
#define __fastcall
#endif
#define __declspec(x)

#if 0
#include <stdint.h>
#else
typedef unsigned short uint16_t;
typedef unsigned int uint32_t;
#endif

#if 1
#include <xboxkrnl/xboxkrnl.h>
#else
#define CONST const
typedef const char *PCSTR, *LPCSTR;
typedef const void *LPCVOID;
typedef unsigned short      WORD;
typedef unsigned long       DWORD;
typedef wchar_t *LPCWSTR;
typedef WORD *PWORD;
typedef DWORD *PDWORD;
typedef unsigned long *ULONG_PTR;
typedef long LONG;
typedef long long LONGLONG;
typedef unsigned long long ULONGLONG;
typedef struct _LIST_ENTRY
{
    struct _LIST_ENTRY *Flink;
    struct _LIST_ENTRY *Blink;
}
LIST_ENTRY, *PLIST_ENTRY;
typedef union _LARGE_INTEGER
{
    struct
    {
        DWORD   LowPart;
        LONG    HighPart;
    }
    u;

    LONGLONG QuadPart;
}
LARGE_INTEGER, *PLARGE_INTEGER;
#include <xapi.h>
#endif

#include <d3d8.h>
#include <dsound.h>
#include <xacteng.h>
#include <xgraphic.h>
#include <xonline.h>

#ifdef TEST_COMPILE
int main(int argc, char *argv[]) {
	return 0;
}
#endif
