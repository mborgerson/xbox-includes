// ******************************************************************
// *
// *  This file is part of the Cxbx project.
// *
// *  Cxbx and Cxbe are free software; you can redistribute them
// *  and/or modify them under the terms of the GNU General Public
// *  License as published by the Free Software Foundation; either
// *  version 2 of the license, or (at your option) any later version.
// *
// *  This program is distributed in the hope that it will be useful,
// *  but WITHOUT ANY WARRANTY; without even the implied warranty of
// *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
// *  GNU General Public License for more details.
// *
// *  You should have recieved a copy of the GNU General Public License
// *  along with this program; see the file COPYING.
// *  If not, write to the Free Software Foundation, Inc.,
// *  59 Temple Place - Suite 330, Bostom, MA 02111-1307, USA.
// *
// *  (c) 2002-2003 Aaron Robinson <caustik@caustik.com>
// *
// *  All rights reserved
// *
// ******************************************************************
#ifndef XONLINE_H
#define XONLINE_H

#include "xboxdef.h"
#include "xapi.h" // For EMUPATCH

typedef struct _WSADATA {
  // FIXME
} WSADATA;


typedef struct _SOCKET {
  // FIXME
} SOCKET;

// ******************************************************************
// * patch: WSAStartup
// ******************************************************************
int WINAPI EMUPATCH(WSAStartup)
(
    WORD        wVersionRequested,
    WSADATA    *lpWSAData
);

// ******************************************************************
// * patch: XNetStartup
// ******************************************************************
INT WINAPI EMUPATCH(XNetStartup)
(
    const PVOID pDummy
);

// ******************************************************************
// * patch: XNetGetEthernetLinkStatus
// ******************************************************************
DWORD WINAPI EMUPATCH(XNetGetEthernetLinkStatus)();

// ******************************************************************
// * patch: XOnlineLaunchNewImage
// ******************************************************************
HRESULT WINAPI XOnlineLaunchNewImage
(
    LPCSTR	lpImagePath,
    LPVOID	pLaunchData
);

// ******************************************************************
// * patch: XOnlineLogon
// ******************************************************************
HRESULT WINAPI EMUPATCH(XOnlineLogon)
(
    VOID*	pUsers,
    DWORD*	pdwServiceIDs,
    DWORD	dwServices,
    HANDLE	hEvent,
    HANDLE	pHandle
);

SOCKET WINAPI EMUPATCH(socket)
(
    int   af,
    int   type,
    int   protocol
);

int WINAPI EMUPATCH(connect)
(
    SOCKET s,
    const struct sockaddr *name,
    int namelen
);

int WINAPI EMUPATCH(send)
(
    SOCKET s,
    const char *buf,
    int len,
    int flags
);

int WINAPI EMUPATCH(recv)
(
    SOCKET s,
    char *buf,
    int len,
    int flags
);


int WINAPI EMUPATCH(bind)
(
    SOCKET s,
    const struct sockaddr *name,
    int namelen
);

int WINAPI EMUPATCH(listen)
(
    SOCKET s,
    int backlog
);

int WINAPI EMUPATCH(ioctlsocket)
(
    SOCKET s,
    long cmd,
    u_long *argp
);

typedef struct _XNKID
{
    BYTE ab[8];
} XNKID;

typedef struct _XNKEY
{
    BYTE ab[16];
} XNKEY;

typedef struct _IN_ADDR
{
    union
    {
        struct
        {
            UCHAR s_b1;
            UCHAR s_b2;
            UCHAR s_b3;
            UCHAR s_b4;
        } S_un_b;
        struct
        {
            USHORT s_w1;
            USHORT s_w2;
        } S_un_w;
        ULONG S_addr;
    } S_un;
} IN_ADDR;

typedef struct _XNADDR
{
    IN_ADDR ina;
    IN_ADDR inaOnline;
    WORD wPortOnline;
    BYTE abEnet[6];
    BYTE abOnline[20];
} XNADDR;

typedef struct _XONLINE_MATCH_SEARCHRESULT
{
    DWORD dwReserved;
    XNKID SessionID;
    XNADDR HostAddress;
    XNKEY KeyExchangeKey;
    DWORD dwPublicOpen;
    DWORD dwPrivateOpen;
    DWORD dwPublicFilled;
    DWORD dwPrivateFilled;
    DWORD dwNumAttributes;
} XONLINE_MATCH_SEARCHRESULT, *PXONLINE_MATCH_SEARCHRESULT;

typedef struct _XONLINE_ATTRIBUTE {
    DWORD dwAttributeID;
    BOOL fChanged;
    union {
        struct {
            ULONGLONG qwValue;
        } integer;
        struct {
            LPWSTR lpValue;
        } string;
        struct {
            PVOID pvValue;
            DWORD dwLength;
        } blob;
    } info;
} XONLINE_ATTRIBUTE, *PXONLINE_ATTRIBUTE;

typedef HANDLE XONLINETASK_HANDLE, *PXONLINETASK_HANDLE;

typedef struct _XONLINE_ATTRIBUTE_SPEC
{
    DWORD dwType;
    DWORD dwLength;
 } XONLINE_ATTRIBUTE_SPEC, *PXONLINE_ATTRIBUTE_SPEC;

HRESULT WINAPI XOnlineMatchSessionCreate
(
    IN DWORD dwPublicCurrent,
    IN DWORD dwPublicAvailable,
    IN DWORD dwPrivateCurrent,
    IN DWORD dwPrivateAvailable,
    IN DWORD dwNumAttributes,
    IN PXONLINE_ATTRIBUTE pAttributes,
    IN HANDLE hWorkEvent,
    OUT PXONLINETASK_HANDLE phTask
);

HRESULT WINAPI XOnlineMatchSessionUpdate
(
    IN XNKID SessionID,
    IN DWORD dwPublicCurrent,
    IN DWORD dwPublicAvailable,
    IN DWORD dwPrivateCurrent,
    IN DWORD dwPrivateAvailable,
    IN DWORD dwNumAttributes,
    IN PXONLINE_ATTRIBUTE pAttributes,
    IN HANDLE hWorkEvent,
    OUT PXONLINETASK_HANDLE phTask
);

HRESULT WINAPI XOnlineMatchSearch
(
    IN DWORD dwProcedureIndex,
    IN DWORD dwNumResults,
    IN DWORD dwNumAttributes,
    IN const XONLINE_ATTRIBUTE *pAttributes,
    IN DWORD dwResultsLen,
    IN OPTIONAL HANDLE hWorkEvent,
    OUT PXONLINETASK_HANDLE phTask
);

DWORD WINAPI XOnlineMatchSearchResultsLen
(
    IN DWORD dwNumResults,
    IN DWORD dwNumSessionAttributes,
    IN const XONLINE_ATTRIBUTE_SPEC *pSessionAttributeSpec
);

HRESULT WINAPI XOnlineMatchSearchGetResults
(
    IN XONLINETASK_HANDLE hTask,
    OUT PXONLINE_MATCH_SEARCHRESULT **prgpSearchResults,
    OUT DWORD *pdwReturnedResults
);

#endif
