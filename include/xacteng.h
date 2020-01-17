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
#ifndef EMUXACTENG_H
#define EMUXACTENG_H

#include "xapi.h" // For EMUPATCH

#undef FIELD_OFFSET     // prevent macro redefinition warnings

// ******************************************************************
// * XACT Interfaces
// ******************************************************************
struct XACTEngine;
struct XACTWaveBank;
struct XACTSoundBank;
struct XACTSoundSource;
struct XACTSoundCue;

// ******************************************************************
// * XACT_RUNTIME_PARAMETERS
// ******************************************************************
struct XACT_RUNTIME_PARAMETERS
{
    DWORD	dwMax2DHwVoices;
    DWORD   dwMax3DHwVoices;
    DWORD   dwMaxConcurrentStreams;
    DWORD   dwMaxNotifications;
    DWORD   dwInteractiveAudioLookaheadTime; // Time in ms
};

// ******************************************************************
// * XACT_WAVEBANK_STREAMING_PARAMETERS
// ******************************************************************
struct XACT_WAVEBANK_STREAMING_PARAMETERS
{
    HANDLE                      hFile;                          // file handle associated with wavebank data
    DWORD                       dwOffset;                       // offset within file of wavebank header
    DWORD                       dwPacketSizeInMilliSecs;        // stream packet size to use for each stream (in ms)
};

// ******************************************************************
// * XACT_NOTIFICATION_DESCRIPTION
// ******************************************************************
struct XACT_NOTIFICATION_DESCRIPTION
{
    WORD				wType;
    WORD				wFlags;
    XACTSoundBank*	pSoundBank;
    XACTWaveBank*		pWaveBank;
    DWORD				dwSoundCueIndex;
    XACTSoundCue*		pSoundCue;
    PVOID				pvContext;
    HANDLE				hEvent;
};

typedef const XACT_NOTIFICATION_DESCRIPTION *PCXACT_NOTIFICATION_DESCRIPTION;

//struct XACT_NOTIFICATION
//{
//    XACT_NOTIFICATION_DESCRIPTION Header;
//    XACT_NOTIFICATION_UNION Data;
//    REFERENCE_TIME rtTimeStamp;
//};
//
//typedef const XACT_NOTIFICATION *PXACT_NOTIFICATION;

// ******************************************************************
// * XACTEngine
// ******************************************************************
struct XACTEngine
{
	// TODO: Fill this in?
};

// ******************************************************************
// * XACTWaveBank
// ******************************************************************
struct XACTWaveBank
{
	// TODO: Fill this in?
};

// ******************************************************************
// * XACTSoundBank
// ******************************************************************
struct XACTSoundBank
{
	// TODO: Fill this in?
};

// ******************************************************************
// * XACTSoundSource
// ******************************************************************
struct XACTSoundSource
{
	// TODO: Fill this in?
};

// ******************************************************************
// * XACTSoundCue
// ******************************************************************
struct XACTSoundCue
{
	// TODO: Fill this in?
};


// ******************************************************************
// * EmuXACTEngineCreate
// ******************************************************************
HRESULT WINAPI EMUPATCH(XACTEngineCreate)( XACT_RUNTIME_PARAMETERS* pParams, XACTEngine** ppEngine );

// ******************************************************************
// * EmuXACTEngineDoWork
// ******************************************************************
void WINAPI EMUPATCH(XACTEngineDoWork)();

// ******************************************************************
// * EmuIXACTEngine_RegisterWaveBank
// ******************************************************************
HRESULT WINAPI EMUPATCH(IXACTEngine_RegisterWaveBank)
(
	XACTEngine*		pThis,
	LPVOID				pvData,
	DWORD				dwSize,
	XACTWaveBank**	ppWaveBank
);

// ******************************************************************
// * EmuIXACTEngine_RegisterStreamedWaveBank
// ******************************************************************
HRESULT WINAPI EMUPATCH(IXACTEngine_RegisterStreamedWaveBank)
(
	XACTEngine*							pThis,
	XACT_WAVEBANK_STREAMING_PARAMETERS*	pParams,
	XACTWaveBank**						ppWaveBank
);

// ******************************************************************
// * EmuIXACTEngine_CreateSoundBank
// ******************************************************************
HRESULT WINAPI EMUPATCH(IXACTEngine_CreateSoundBank)
(
	XACTEngine*		pThis,
	LPVOID				pvData,
	DWORD				dwSize,
	XACTSoundBank**	ppSoundBank
);

// ******************************************************************
// * EmuIXACTEngine_DownloadEffectsImage
// ******************************************************************
HRESULT WINAPI EMUPATCH(IXACTEngine_DownloadEffectsImage)
(
	XACTEngine*		pThis,
	PVOID				pvData,
	DWORD				dwSize,
	LPVOID				pEffectLoc,
	LPVOID*				ppImageDesc
);

// ******************************************************************
// * EmuIXACTEngine_CreateSoundSource
// ******************************************************************
HRESULT WINAPI EMUPATCH(IXACTEngine_CreateSoundSource)
(
	XACTEngine*		pThis,
	DWORD				dwFlags,
	XACTSoundSource** ppSoundSource
);

// ******************************************************************
// * EmuIXACTEngine_EnableHeadphones
// ******************************************************************
HRESULT WINAPI EMUPATCH(IXACTEngine_EnableHeadphones)
(
	XACTEngine*		pThis,
	BOOL				fEnabled
);

// ******************************************************************
// * EmuIXACTEngine_SetListenerOrientation
// ******************************************************************
HRESULT WINAPI EMUPATCH(IXACTEngine_SetListenerOrientation)
(
	XACTEngine*	pThis,
	float			xFront,
	float			yFront,
	float			zFront,
	float			xTop,
	float			yTop,
	float			zTop,
	DWORD			dwApply
);

// ******************************************************************
// * EmuIXACTEngine_SetListenerPosition
// ******************************************************************
HRESULT WINAPI EMUPATCH(IXACTEngine_SetListenerPosition)
(
	XACTEngine*	pThis,
	float			x,
	float			y,
	float			z,
	DWORD			dwApply
);

// ******************************************************************
// * EmuIXACTEngine_SetListenerVelocity
// ******************************************************************
HRESULT WINAPI EMUPATCH(IXACTEngine_SetListenerVelocity)
(
	XACTEngine*	pThis,
	float			x,
	float			y,
	float			z,
	DWORD			dwApply
);

// ******************************************************************
// * EmuIXACTEngine_SetMasterVolume
// ******************************************************************
HRESULT WINAPI EMUPATCH(IXACTEngine_SetMasterVolume)
(
	XACTEngine*	pThis,
    WORD			wCategory,
    LONG			lVolume
);

// ******************************************************************
// * EmuIXACTEngine_CommitDeferredSettings
// ******************************************************************
HRESULT WINAPI EMUPATCH(IXACTEngine_CommitDeferredSettings)(XACTEngine* pThis);

// ******************************************************************
// * EmuIXACTSoundBank_GetSoundCueIndexFromFriendlyName
// ******************************************************************
HRESULT WINAPI EMUPATCH(IXACTSoundBank_GetSoundCueIndexFromFriendlyName)
(
	XACTEngine*		pThis,
	PCSTR				pFriendlyName,
	DWORD*				pdwSoundCueIndex
);

// ******************************************************************
// * EmuIXACTSoundBank_Play
// ******************************************************************
HRESULT WINAPI EMUPATCH(IXACTSoundBank_Play)
(
	XACTSoundBank*	pThis,
	DWORD				dwSoundCueIndex,
	XACTSoundSource*	pSoundSource,
	DWORD				dwFlags,
	XACTSoundCue**	ppSoundCue
);

// ******************************************************************
// * EmuIXACTSoundBank_Stop
// ******************************************************************
HRESULT WINAPI EMUPATCH(IXACTSoundBank_Stop)
(
	XACTSoundBank*	pThis,
	DWORD				dwSoundCueIndex,
	DWORD				dwFlags,
	XACTSoundCue*		pSoundCue
);

// ******************************************************************
// * EmuIXACTSoundSource_SetPosition
// ******************************************************************
HRESULT WINAPI EMUPATCH(IXACTSoundSource_SetPosition)
(
	XACTSoundSource*	pThis,
    FLOAT				x,
    FLOAT				y,
    FLOAT				z,
    DWORD				dwApply
);

// ******************************************************************
// * EmuIXACTSoundSource_SetVelocity
// ******************************************************************
HRESULT WINAPI EMUPATCH(IXACTSoundSource_SetVelocity)
(
	XACTSoundSource*	pThis,
    FLOAT				x,
    FLOAT				y,
    FLOAT				z,
    DWORD				dwApply
);

// ******************************************************************
// * EmuIXACTEngine_RegisterNotification
// ******************************************************************
HRESULT WINAPI EMUPATCH(IXACTEngine_RegisterNotification)
(
	XACTEngine*					pThis,
    PCXACT_NOTIFICATION_DESCRIPTION pNotificationDesc
);

// ******************************************************************
// * EmuIXACTEngine_GetNotification
// ******************************************************************
HRESULT WINAPI EMUPATCH(IXACTEngine_GetNotification)
(
	XACTEngine*					pThis,
    PCXACT_NOTIFICATION_DESCRIPTION pNotificationDesc,
    LPVOID						    pNotification
);

// ******************************************************************
// * EmuIXACTEngine_UnRegisterWaveBank
// ******************************************************************
HRESULT WINAPI EMUPATCH(IXACTEngine_UnRegisterWaveBank)
(
	XACTEngine*	pThis,
    XACTWaveBank*	pWaveBank
);

#endif
