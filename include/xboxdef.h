#ifndef __XBOXDEF_H__
#define __XBOXDEF_H__

typedef const void *LPCVOID;
typedef void *PVOID, *LPVOID;
typedef PVOID HANDLE, *PHANDLE;

typedef unsigned char BOOLEAN, *PBOOLEAN;

typedef signed char SCHAR, *PSCHAR;

typedef char CHAR, *PCHAR, CCHAR, *LPCH, *PCH, OCHAR, *POCHAR;
typedef short SHORT, *PSHORT, CSHORT;
typedef int INT, *PINT, *LPINT;
typedef long LONG, *PLONG, *LPLONG;
typedef long long LONGLONG, *PLONGLONG;

typedef unsigned char UCHAR, *PUCHAR;
typedef unsigned short USHORT, *PUSHORT;
typedef unsigned short WORD, WCHAR, *PWSTR;
typedef unsigned int UINT, *PUINT, *LPUINT;
typedef unsigned long DWORD, *PDWORD, *LPDWORD;
typedef unsigned long ULONG, *PULONG;
typedef unsigned long long ULONGLONG;

#define MAXDWORD 0xFFFFFFFFUL

typedef LONG LONG_PTR;
typedef ULONG ULONG_PTR;
typedef ULONG_PTR DWORD_PTR;
typedef ULONG_PTR SIZE_T, *PSIZE_T;

typedef int BOOL, *PBOOL;
typedef const char *PCSZ, *PCSTR, *LPCSTR;
typedef WCHAR *LPWSTR;



typedef struct _STRING {
    USHORT Length;
    USHORT MaximumLength;
    PCHAR  Buffer;
} STRING, *PSTRING;

typedef STRING ANSI_STRING, *PANSI_STRING;

/**
 * MS's way to represent a 64-bit signed int on platforms that may not support
 * them directly.
 */
typedef union _LARGE_INTEGER
{
    struct
    {
        ULONG LowPart; /**< The low-order 32 bits. */
        LONG HighPart; /**< The high-order 32 bits. */
    };
    struct
    {
        ULONG LowPart; /**< The low-order 32 bits. */
        LONG HighPart; /**< The high-order 32 bits. */
    } u;
    LONGLONG QuadPart; /**< A signed 64-bit integer. */
} LARGE_INTEGER, *PLARGE_INTEGER;

/**
 * MS's way to represent a 64-bit unsigned int on platforms that may not support
 * them directly.
 */
typedef union _ULARGE_INTEGER
{
    struct
    {
        ULONG LowPart; /**< The low-order 32 bits. */
        ULONG HighPart; /**< The high-order 32 bits. */ /**< The high-order 32 bits. */
    };
    struct
    {
        ULONG LowPart; /**< The low-order 32 bits. */
        ULONG HighPart; /**< The high-order 32 bits. */
    } u;
    ULONGLONG QuadPart; /**< An unsigned 64-bit integer. */
} ULARGE_INTEGER, *PULARGE_INTEGER;

/**
 * Header or descriptor for an entry in a doubly linked list.
 * Initialized by InitializeListHead, members shouldn't be updated manually.
 */
typedef struct _LIST_ENTRY
{
    struct _LIST_ENTRY *Flink; /**< Points to the next entry of the list or the header if there is no next entry */
    struct _LIST_ENTRY *Blink; /**< Points to the previous entry of the list or the header if there is no previous entry */
} LIST_ENTRY, *PLIST_ENTRY;

/**
 * Struct for modelling critical sections in the XBOX-kernel
 */
typedef struct _RTL_CRITICAL_SECTION
{
    union {
        struct {
            UCHAR Type;
            UCHAR Absolute;
            UCHAR Size;
            UCHAR Inserted;
            LONG SignalState;
            LIST_ENTRY WaitListHead;
        } Event;
        ULONG RawEvent[4];
    } Synchronization;

    LONG LockCount;
    LONG RecursionCount;
    PVOID OwningThread;
} RTL_CRITICAL_SECTION, *PRTL_CRITICAL_SECTION;

#endif
