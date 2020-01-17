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
#ifndef DIRECT3D9_H
#define DIRECT3D9_H

#include "xapi.h" // For EMUPATCH
#include "d3d8types.h"

#define D3DXMATRIX D3DMATRIX

// ******************************************************************
// * patch: Direct3D_CreateDevice
// ******************************************************************
HRESULT WINAPI EMUPATCH(Direct3D_CreateDevice)
(
    UINT                        Adapter,
    D3DDEVTYPE                  DeviceType,
    HWND                        hFocusWindow,
    DWORD                       BehaviorFlags,
    D3DPRESENT_PARAMETERS      *pPresentationParameters,
    IDirect3DDevice           **ppReturnedDeviceInterface
);

HRESULT WINAPI EMUPATCH(Direct3D_CreateDevice_16)
(
    UINT                        Adapter,
    D3DDEVTYPE                  DeviceType,
    HWND                        hFocusWindow,
    D3DPRESENT_PARAMETERS      *pPresentationParameters
);

HRESULT WINAPI EMUPATCH(Direct3D_CreateDevice_4)
(
    D3DPRESENT_PARAMETERS      *pPresentationParameters
);

// ******************************************************************
// * patch: IDirect3DResource8_IsBusy
// ******************************************************************
BOOL WINAPI EMUPATCH(D3DDevice_IsBusy)();

// ******************************************************************
// * patch: D3DDevice_GetCreationParameters
// ******************************************************************
VOID WINAPI EMUPATCH(D3DDevice_GetCreationParameters)
(
	D3DDEVICE_CREATION_PARAMETERS *pParameters
);

#if 0 // patch disabled
// ******************************************************************
// * patch: D3D_CheckDeviceFormat
// ******************************************************************
HRESULT WINAPI EMUPATCH(D3D_CheckDeviceFormat)
(
    UINT                        Adapter,
    D3DDEVTYPE                  DeviceType,
    D3DFORMAT                   AdapterFormat,
    DWORD                       Usage,
    D3DRESOURCETYPE             RType,
    D3DFORMAT                   CheckFormat
);
#endif

#if 0 // patch disabled
// ******************************************************************
// * patch: D3DDevice_GetDeviceCaps
// ******************************************************************
VOID WINAPI EMUPATCH(D3DDevice_GetDeviceCaps)
(
    D3DCAPS                     *pCaps
);
#endif

// ******************************************************************
// * patch: D3DDevice_GetDisplayFieldStatus
// ******************************************************************
VOID WINAPI EMUPATCH(D3DDevice_GetDisplayFieldStatus)
(
	D3DFIELD_STATUS   *pFieldStatus
);

// ******************************************************************
// * patch: D3DDevice_BeginPush
// ******************************************************************
PDWORD WINAPI EMUPATCH(D3DDevice_BeginPush)(DWORD Count);

// ******************************************************************
// * patch: D3DDevice_BeginPush2  //two arg version for xdk before 4531
// ******************************************************************
VOID WINAPI EMUPATCH(D3DDevice_BeginPush2)(DWORD Count, DWORD **ppPush);

// ******************************************************************
// * patch: D3DDevice_EndPush
// ******************************************************************
VOID WINAPI EMUPATCH(D3DDevice_EndPush)(DWORD *pPush);

// ******************************************************************
// * patch: D3DDevice_BeginVisibilityTest
// ******************************************************************
HRESULT WINAPI EMUPATCH(D3DDevice_BeginVisibilityTest)();

// ******************************************************************
// * patch: D3DDevice_EndVisibilityTest
// ******************************************************************
HRESULT WINAPI EMUPATCH(D3DDevice_EndVisibilityTest)
(
    DWORD                       Index
);

HRESULT __stdcall EMUPATCH(D3DDevice_EndVisibilityTest_0)();

// ******************************************************************
// * patch: D3DDevice_GetVisibilityTestResult
// ******************************************************************
HRESULT WINAPI EMUPATCH(D3DDevice_GetVisibilityTestResult)
(
    DWORD                       Index,
    UINT                       *pResult,
    ULONGLONG                  *pTimeStamp
);

// ******************************************************************
// * patch: D3DDevice_SetBackBufferScale
// ******************************************************************
VOID WINAPI EMUPATCH(D3DDevice_SetBackBufferScale)(FLOAT x, FLOAT y);

// ******************************************************************
// * patch: D3DDevice_LoadVertexShader
// ******************************************************************
VOID WINAPI EMUPATCH(D3DDevice_LoadVertexShader)
(
    DWORD                       Handle,
    DWORD                       Address
);

VOID __stdcall EMUPATCH(D3DDevice_LoadVertexShader_0)();
VOID WINAPI EMUPATCH(D3DDevice_LoadVertexShader_4)
(
    DWORD                       Address
);

// ******************************************************************
// * patch: D3DDevice_SelectVertexShader
// ******************************************************************
VOID WINAPI EMUPATCH(D3DDevice_SelectVertexShader)
(
    DWORD                       Handle,
    DWORD                       Address
);

VOID __stdcall EMUPATCH(D3DDevice_SelectVertexShader_0)();
VOID __stdcall EMUPATCH(D3DDevice_SelectVertexShader_4)
(
    DWORD                       Address
);

// ******************************************************************
// * patch: D3D_KickOffAndWaitForIdle
// ******************************************************************
VOID WINAPI EMUPATCH(D3D_KickOffAndWaitForIdle)();

// ******************************************************************
// * patch: D3D_KickOffAndWaitForIdle
// ******************************************************************
VOID WINAPI EMUPATCH(D3D_KickOffAndWaitForIdle2)(DWORD dwDummy1, DWORD dwDummy2);

// ******************************************************************
// * patch: D3DDevice_SetGammaRamp
// ******************************************************************
VOID WINAPI EMUPATCH(D3DDevice_SetGammaRamp)
(
    DWORD                   dwFlags,
    CONST D3DGAMMARAMP     *pRamp
);

// ******************************************************************
// * patch: D3DDevice_AddRef
// ******************************************************************
ULONG WINAPI EMUPATCH(D3DDevice_AddRef)();

// ******************************************************************
// * patch: D3DDevice_BeginStateBlock
// ******************************************************************
VOID WINAPI EMUPATCH(D3DDevice_BeginStateBlock)();

// ******************************************************************
// * patch: D3DDevice_CaptureStateBlock
// ******************************************************************
VOID WINAPI EMUPATCH(D3DDevice_CaptureStateBlock)(DWORD Token);

// ******************************************************************
// * patch: D3DDevice_ApplyStateBlock
// ******************************************************************
VOID WINAPI EMUPATCH(D3DDevice_ApplyStateBlock)(DWORD Token);

// ******************************************************************
// * patch: D3DDevice_EndStateBlock
// ******************************************************************
HRESULT WINAPI EMUPATCH(D3DDevice_EndStateBlock)(DWORD *pToken);

// ******************************************************************
// * patch: D3DDevice_CopyRects
// ******************************************************************
VOID WINAPI EMUPATCH(D3DDevice_CopyRects)
(
    D3DSurface         *pSourceSurface,
    CONST RECT         *pSourceRectsArray,
    UINT                cRects,
    D3DSurface         *pDestinationSurface,
    CONST POINT        *pDestPointsArray
);

// ******************************************************************
// * patch: D3DDevice_CreateImageSurface
// ******************************************************************
HRESULT WINAPI EMUPATCH(D3DDevice_CreateImageSurface)
(
    UINT                Width,
    UINT                Height,
    D3DFORMAT           Format,
    D3DSurface        **ppBackBuffer
);

// ******************************************************************
// * patch: D3DDevice_GetGammaRamp
// ******************************************************************
VOID WINAPI EMUPATCH(D3DDevice_GetGammaRamp)
(
    D3DGAMMARAMP       *pRamp
);

// ******************************************************************
// * patch: D3DDevice_GetBackBuffer2
// ******************************************************************
D3DSurface  * WINAPI EMUPATCH(D3DDevice_GetBackBuffer2)
(
    INT                 BackBuffer
);

// ******************************************************************
// * patch: D3DDevice_GetBackBuffer
// ******************************************************************
VOID WINAPI EMUPATCH(D3DDevice_GetBackBuffer)
(
    INT                 BackBuffer,
    D3DBACKBUFFER_TYPE  Type,
    D3DSurface        **ppBackBuffer
);

// ******************************************************************
// * patch: D3DDevice_SetViewport
// ******************************************************************
VOID WINAPI EMUPATCH(D3DDevice_SetViewport)
(
    CONST D3DVIEWPORT8   *pViewport
);

// ******************************************************************
// * patch: D3DDevice_GetViewport
// ******************************************************************
VOID WINAPI EMUPATCH(D3DDevice_GetViewport)
(
    D3DVIEWPORT8   *pViewport
);

// ******************************************************************
// * patch: D3DDevice_GetViewportOffsetAndScale
// ******************************************************************
VOID WINAPI EMUPATCH(D3DDevice_GetViewportOffsetAndScale)
(
	D3DXVECTOR4   *pOffset,
	D3DXVECTOR4   *pScale
);

VOID __stdcall EMUPATCH(D3DDevice_GetViewportOffsetAndScale_0)();

// ******************************************************************
// * patch: D3DDevice_SetShaderConstantMode
// ******************************************************************
VOID WINAPI EMUPATCH(D3DDevice_SetShaderConstantMode)
(
    VERTEXSHADERCONSTANTMODE   Mode
);

VOID __stdcall EMUPATCH(D3DDevice_SetShaderConstantMode_0)();

// ******************************************************************
// * patch: D3DDevice_Reset
// ******************************************************************
HRESULT WINAPI EMUPATCH(D3DDevice_Reset)
(
    D3DPRESENT_PARAMETERS   *pPresentationParameters
);

// ******************************************************************
// * patch: D3DDevice_GetRenderTarget
// ******************************************************************
HRESULT WINAPI EMUPATCH(D3DDevice_GetRenderTarget)
(
    D3DSurface    **ppRenderTarget
);

// ******************************************************************
// * patch: D3DDevice_GetRenderTarget
// ******************************************************************
D3DSurface   * WINAPI EMUPATCH(D3DDevice_GetRenderTarget2)();

// ******************************************************************
// * patch: D3DDevice_GetDepthStencilSurface
// ******************************************************************
HRESULT WINAPI EMUPATCH(D3DDevice_GetDepthStencilSurface)
(
    D3DSurface    **ppZStencilSurface
);

// ******************************************************************
// * patch: D3DDevice_GetDepthStencilSurface
// ******************************************************************
D3DSurface   * WINAPI EMUPATCH(D3DDevice_GetDepthStencilSurface2)();

// ******************************************************************
// * patch: D3DDevice_GetTile
// ******************************************************************
VOID WINAPI EMUPATCH(D3DDevice_GetTile)
(
    DWORD           Index,
    D3DTILE        *pTile
);

// ******************************************************************
// * patch: D3DDevice_SetTile
// ******************************************************************
VOID WINAPI EMUPATCH(D3DDevice_SetTile)
(
    DWORD               Index,
    CONST D3DTILE      *pTile
);

// ******************************************************************
// * patch: D3DDevice_CreateVertexShader
// ******************************************************************
HRESULT WINAPI EMUPATCH(D3DDevice_CreateVertexShader)
(
    CONST DWORD    *pDeclaration,
    CONST DWORD    *pFunction,
    DWORD          *pHandle,
    DWORD           Usage
);

// ******************************************************************
// * patch: D3DDevice_SetPixelShaderConstant
// ******************************************************************
VOID WINAPI EMUPATCH(D3DDevice_SetPixelShaderConstant)
(
    DWORD       Register,
    CONST PVOID pConstantData,
    DWORD       ConstantCount
);

VOID WINAPI EMUPATCH(D3DDevice_SetPixelShaderConstant_4)
(
    CONST PVOID pConstantData
);

// ******************************************************************
// * patch: D3DDevice_SetVertexShaderConstant
// ******************************************************************
VOID WINAPI EMUPATCH(D3DDevice_SetVertexShaderConstant)
(
    INT         Register,
    CONST PVOID pConstantData,
    DWORD       ConstantCount
);

VOID __stdcall EMUPATCH(D3DDevice_SetVertexShaderConstant_8)();

// ******************************************************************
// * patch: D3DDevice_SetVertexShaderConstant1
// ******************************************************************
VOID __fastcall EMUPATCH(D3DDevice_SetVertexShaderConstant1)
(
    INT         Register,
    CONST PVOID pConstantData
);

// ******************************************************************
// * patch: D3DDevice_SetVertexShaderConstant1Fast
// ******************************************************************
VOID __fastcall EMUPATCH(D3DDevice_SetVertexShaderConstant1Fast)
(
    INT         Register,
    CONST PVOID pConstantData
);

// ******************************************************************
// * patch: D3DDevice_SetVertexShaderConstant4
// ******************************************************************
VOID __fastcall EMUPATCH(D3DDevice_SetVertexShaderConstant4)
(
    INT         Register,
    CONST PVOID pConstantData
);

// ******************************************************************
// * patch: D3DDevice_SetVertexShaderConstantNotInline
// ******************************************************************
VOID __fastcall EMUPATCH(D3DDevice_SetVertexShaderConstantNotInline)
(
    INT         Register,
    CONST PVOID pConstantData,
    DWORD       ConstantCount
);

// ******************************************************************
// * patch: D3DDevice_SetVertexShaderConstantNotInlineFast
// ******************************************************************
VOID __fastcall EMUPATCH(D3DDevice_SetVertexShaderConstantNotInlineFast)
(
    INT         Register,
    CONST PVOID pConstantData,
    DWORD       ConstantCount
);

// ******************************************************************
// * patch: D3DDevice_DeletePixelShader
// ******************************************************************
VOID WINAPI EMUPATCH(D3DDevice_DeletePixelShader)
(
    DWORD          Handle
);

// ******************************************************************
// * patch: D3DDevice_CreatePixelShader
// ******************************************************************
HRESULT WINAPI EMUPATCH(D3DDevice_CreatePixelShader)
(
    D3DPIXELSHADERDEF      *pPSDef,
    DWORD				   *pHandle
);

// ******************************************************************
// * patch: D3DDevice_SetPixelShader
// ******************************************************************
VOID WINAPI EMUPATCH(D3DDevice_SetPixelShader)
(
    DWORD           Handle
);

VOID WINAPI EMUPATCH(D3DDevice_SetPixelShader_0)();

// ******************************************************************
// * patch: D3DDevice_CreateTexture2
// ******************************************************************
D3DResource   * WINAPI EMUPATCH(D3DDevice_CreateTexture2)
(
    UINT                Width,
    UINT                Height,
    UINT                Depth,
    UINT                Levels,
    DWORD               Usage,
    D3DFORMAT           Format,
    D3DRESOURCETYPE     D3DResource
);

// ******************************************************************
// * patch: D3DDevice_CreateTexture
// ******************************************************************
HRESULT WINAPI EMUPATCH(D3DDevice_CreateTexture)
(
    UINT                Width,
    UINT                Height,
    UINT                Levels,
    DWORD               Usage,
    D3DFORMAT           Format,
    D3DPOOL             Pool,
    D3DTexture        **ppTexture
);

// ******************************************************************
// * patch: D3DDevice_CreateVolumeTexture
// ******************************************************************
HRESULT WINAPI EMUPATCH(D3DDevice_CreateVolumeTexture)
(
    UINT                 Width,
    UINT                 Height,
    UINT                 Depth,
    UINT                 Levels,
    DWORD                Usage,
    D3DFORMAT            Format,
    D3DPOOL              Pool,
    D3DVolumeTexture   **ppVolumeTexture
);

// ******************************************************************
// * patch: D3DDevice_CreateCubeTexture
// ******************************************************************
HRESULT WINAPI EMUPATCH(D3DDevice_CreateCubeTexture)
(
    UINT                 EdgeLength,
    UINT                 Levels,
    DWORD                Usage,
    D3DFORMAT            Format,
    D3DPOOL              Pool,
    D3DCubeTexture    **ppCubeTexture
);

// ******************************************************************
// * patch: D3DDevice_CreateIndexBuffer
// ******************************************************************
HRESULT WINAPI EMUPATCH(D3DDevice_CreateIndexBuffer)
(
    UINT                 Length,
    DWORD                Usage,
    D3DFORMAT            Format,
    D3DPOOL              Pool,
    D3DIndexBuffer     **ppIndexBuffer
);

// ******************************************************************
// * patch: D3DDevice_CreateIndexBuffer2
// ******************************************************************
D3DIndexBuffer   * WINAPI EMUPATCH(D3DDevice_CreateIndexBuffer2)(UINT Length);

// ******************************************************************
// * patch: D3DDevice_SetIndices
// ******************************************************************
VOID WINAPI EMUPATCH(D3DDevice_SetIndices)
(
    D3DIndexBuffer     *pIndexData,
    UINT                BaseVertexIndex
);

// ******************************************************************
// * patch: D3DDevice_SetIndices_4
// ******************************************************************
VOID WINAPI EMUPATCH(D3DDevice_SetIndices_4)
(
    UINT                BaseVertexIndex
);

// ******************************************************************
// * patch: D3DDevice_SetTexture
// ******************************************************************
VOID WINAPI EMUPATCH(D3DDevice_SetTexture)
(
    DWORD           Stage,
	D3DBaseTexture    *pTexture
);

VOID WINAPI EMUPATCH(D3DDevice_SetTexture_4)
(
	D3DBaseTexture    *pTexture
);

// ******************************************************************
// * patch: D3DDevice_SwitchTexture
// ******************************************************************
VOID __fastcall EMUPATCH(D3DDevice_SwitchTexture)
(
    DWORD           Method,
    DWORD           Data,
    DWORD           Format
);

// ******************************************************************
// * patch: D3DDevice_GetDisplayMode
// ******************************************************************
VOID WINAPI EMUPATCH(D3DDevice_GetDisplayMode)
(
    D3DDISPLAYMODE           *pModes
);

// ******************************************************************
// * patch: D3DDevice_Begin
// ******************************************************************
VOID WINAPI EMUPATCH(D3DDevice_Begin)
(
    D3DPRIMITIVETYPE       PrimitiveType
);

// ******************************************************************
// * patch: D3DDevice_SetVertexData2f
// ******************************************************************
VOID WINAPI EMUPATCH(D3DDevice_SetVertexData2f)
(
    int     Register,
    FLOAT   a,
    FLOAT   b
);

// ******************************************************************
// * patch: D3DDevice_SetVertexData2s
// ******************************************************************
VOID WINAPI EMUPATCH(D3DDevice_SetVertexData2s)
(
    int     Register,
    SHORT   a,
    SHORT   b
);

// ******************************************************************
// * patch: D3DDevice_SetVertexData4f
// ******************************************************************
VOID WINAPI EMUPATCH(D3DDevice_SetVertexData4f)
(
    int     Register,
    FLOAT   a,
    FLOAT   b,
    FLOAT   c,
    FLOAT   d
);

// ******************************************************************
// * patch: D3DDevice_SetVertexData4f_16
// ******************************************************************
VOID WINAPI EMUPATCH(D3DDevice_SetVertexData4f_16)
(
	FLOAT   a,
	FLOAT   b,
	FLOAT   c,
	FLOAT   d
);

// ******************************************************************
// * patch: D3DDevice_SetVertexData4ub
// ******************************************************************
VOID WINAPI EMUPATCH(D3DDevice_SetVertexData4ub)
(
	INT		Register,
	BYTE	a,
	BYTE	b,
	BYTE	c,
	BYTE	d
);

// ******************************************************************
// * patch: D3DDevice_SetVertexData4s
// ******************************************************************
VOID WINAPI EMUPATCH(D3DDevice_SetVertexData4s)
(
	INT		Register,
	SHORT	a,
	SHORT	b,
	SHORT	c,
	SHORT	d
);

// ******************************************************************
// * patch: D3DDevice_SetVertexDataColor
// ******************************************************************
VOID WINAPI EMUPATCH(D3DDevice_SetVertexDataColor)
(
    int         Register,
    D3DCOLOR    Color
);

// ******************************************************************
// * patch: D3DDevice_End
// ******************************************************************
VOID WINAPI EMUPATCH(D3DDevice_End)();

// ******************************************************************
// * patch: D3DDevice_RunPushBuffer
// ******************************************************************
VOID WINAPI EMUPATCH(D3DDevice_RunPushBuffer)
(
    D3DPushBuffer         *pPushBuffer,
    D3DFixup              *pFixup
);

// ******************************************************************
// * patch: D3DDevice_Clear
// ******************************************************************
VOID WINAPI EMUPATCH(D3DDevice_Clear)
(
    DWORD                  Count,
    CONST D3DRECT         *pRects,
    DWORD                  Flags,
    D3DCOLOR               Color,
    float                  Z,
    DWORD                  Stencil
);

// ******************************************************************
// * patch: D3DDevice_Present
// ******************************************************************
VOID WINAPI EMUPATCH(D3DDevice_Present)
(
    CONST RECT* pSourceRect,
    CONST RECT* pDestRect,
    PVOID       pDummy1,
    PVOID       pDummy2
);

// ******************************************************************
// * patch: D3DDevice_Swap
// ******************************************************************
DWORD WINAPI EMUPATCH(D3DDevice_Swap)
(
    DWORD Flags
);

DWORD EMUPATCH(D3DDevice_Swap_0)();

// ******************************************************************
// * patch: IDirect3DResource8_Register
// ******************************************************************
VOID WINAPI EMUPATCH(D3DResource_Register)
(
    D3DResource        *pThis,
    PVOID               pBase
);

// ******************************************************************
// * patch: IDirect3DResource8_Release
// ******************************************************************
ULONG WINAPI EMUPATCH(D3DResource_Release)
(
    D3DResource        *pThis
);

#if 0 // patch disabled
// ******************************************************************
// * patch: IDirect3DResource8_GetType
// ******************************************************************
D3DRESOURCETYPE   WINAPI EMUPATCH(D3DResource_GetType)
(
    D3DResource        *pThis
);
#endif

// ******************************************************************
// * patch: IDirect3DResource8_AddRef
// ******************************************************************
ULONG WINAPI EMUPATCH(D3DResource_AddRef)
(
    D3DResource        *pThis
);

// ******************************************************************
// * patch: IDirect3DResource8_IsBusy
// ******************************************************************
BOOL WINAPI EMUPATCH(D3DResource_IsBusy)
(
    D3DResource        *pThis
);

// ******************************************************************
// * patch: Lock2DSurface
// ******************************************************************
VOID WINAPI EMUPATCH(Lock2DSurface)
(
    D3DPixelContainer   *pPixelContainer,
    D3DCUBEMAP_FACES     FaceType,
    UINT                 Level,
    D3DLOCKED_RECT      *pLockedRect,
    RECT                *pRect,
    DWORD                Flags
);

// ******************************************************************
// * patch: Lock3DSurface
// ******************************************************************
VOID WINAPI EMUPATCH(Lock3DSurface)
(
    D3DPixelContainer   *pPixelContainer,
    UINT				Level,
	D3DLOCKED_BOX		*pLockedVolume,
	D3DBOX				*pBox,
	DWORD				Flags
);

#if 0 // patch disabled
// ******************************************************************
// * patch: Get2DSurfaceDesc
// ******************************************************************
VOID WINAPI EMUPATCH(Get2DSurfaceDesc)
(
    D3DPixelContainer   *pPixelContainer,
    DWORD                dwLevel,
    D3DSURFACE_DESC     *pDesc
);

// ******************************************************************
// * patch: IDirect3DSurface8_GetDesc
// ******************************************************************
VOID WINAPI EMUPATCH(D3DSurface_GetDesc)
(
    D3DResource        *pThis,
    D3DSURFACE_DESC    *pDesc
);

// ******************************************************************
// * patch: IDirect3DSurface8_LockRect
// ******************************************************************
VOID WINAPI EMUPATCH(D3DSurface_LockRect)
(
    D3DResource    *pThis,
    D3DLOCKED_RECT *pLockedRect,
    CONST RECT     *pRect,
    DWORD           Flags
);

// ******************************************************************
// * patch: IDirect3DBaseTexture8_GetLevelCount
// ******************************************************************
DWORD WINAPI EMUPATCH(D3DBaseTexture_GetLevelCount)
(
    D3DBaseTexture     *pThis
);

// ******************************************************************
// * patch: IDirect3DTexture8_GetSurfaceLevel2
// ******************************************************************
D3DSurface   * WINAPI EMUPATCH(D3DTexture_GetSurfaceLevel2)
(
    D3DTexture     *pThis,
    UINT            Level
);

// ******************************************************************
// * patch: IDirect3DTexture8_LockRect
// ******************************************************************
VOID WINAPI EMUPATCH(D3DTexture_LockRect)
(
    D3DTexture     *pThis,
    UINT            Level,
    D3DLOCKED_RECT *pLockedRect,
    CONST RECT     *pRect,
    DWORD           Flags
);

// ******************************************************************
// * patch: IDirect3DTexture8_GetSurfaceLevel
// ******************************************************************
HRESULT WINAPI EMUPATCH(D3DTexture_GetSurfaceLevel)
(
    D3DTexture     *pThis,
    UINT            Level,
    D3DSurface    **ppSurfaceLevel
);

// ******************************************************************
// * patch: IDirect3DVolumeTexture8_LockBox
// ******************************************************************
VOID WINAPI EMUPATCH(D3DVolumeTexture_LockBox)
(
    D3DVolumeTexture   *pThis,
    UINT                Level,
    D3DLOCKED_BOX      *pLockedVolume,
    CONST D3DBOX       *pBox,
    DWORD               Flags
);

// ******************************************************************
// * patch: IDirect3DCubeTexture8_LockRect
// ******************************************************************
VOID WINAPI EMUPATCH(D3DCubeTexture_LockRect)
(
    D3DCubeTexture     *pThis,
    D3DCUBEMAP_FACES    FaceType,
    UINT                Level,
    D3DLOCKED_RECT     *pLockedBox,
    CONST RECT         *pRect,
    DWORD               Flags
);

// ******************************************************************
// * patch: D3DDevice_CreateVertexBuffer
// ******************************************************************
HRESULT WINAPI EMUPATCH(D3DDevice_CreateVertexBuffer)
(
    UINT                Length,
    DWORD               Usage,
    DWORD               FVF,
    D3DPOOL             Pool,
    D3DVertexBuffer   **ppVertexBuffer
);
#endif

#if 0 // patch disabled
// ******************************************************************
// * patch: D3DDevice_CreateVertexBuffer2
// ******************************************************************
D3DVertexBuffer  * WINAPI EMUPATCH(D3DDevice_CreateVertexBuffer2)
(
    UINT Length
);
#endif

// ******************************************************************
// * patch: D3DDevice_EnableOverlay
// ******************************************************************
VOID WINAPI EMUPATCH(D3DDevice_EnableOverlay)
(
    BOOL Enable
);

// ******************************************************************
// * patch: D3DDevice_UpdateOverlay
// ******************************************************************
VOID WINAPI EMUPATCH(D3DDevice_UpdateOverlay)
(
    D3DSurface   *pSurface,
    CONST RECT   *SrcRect,
    CONST RECT   *DstRect,
    BOOL          EnableColorKey,
    D3DCOLOR      ColorKey
);

// ******************************************************************
// * patch: D3DDevice_GetOverlayUpdateStatus
// ******************************************************************
BOOL WINAPI EMUPATCH(D3DDevice_GetOverlayUpdateStatus)();

// ******************************************************************
// * patch: D3DDevice_BlockUntilVerticalBlank
// ******************************************************************
VOID WINAPI EMUPATCH(D3DDevice_BlockUntilVerticalBlank)();

// ******************************************************************
// * patch: D3DDevice_SetVerticalBlankCallback
// ******************************************************************
VOID WINAPI EMUPATCH(D3DDevice_SetVerticalBlankCallback)
(
    D3DVBLANKCALLBACK   pCallback
);

// ******************************************************************
// * patch: D3DDevice_SetTextureState_TexCoordIndex
// ******************************************************************
VOID WINAPI EMUPATCH(D3DDevice_SetTextureState_TexCoordIndex)
(
    DWORD Stage,
    DWORD Value
);

VOID __stdcall EMUPATCH(D3DDevice_SetTextureState_TexCoordInde0  )();
VOID WINAPI EMUPATCH(D3DDevice_SetTextureState_TexCoordInde4  )
(
    DWORD Value
);

// ******************************************************************
// * patch: D3DDevice_SetRenderState_TwoSidedLighting
// ******************************************************************
VOID WINAPI EMUPATCH(D3DDevice_SetRenderState_TwoSidedLighting)
(
    DWORD Value
);

// ******************************************************************
// * patch: D3DDevice_SetRenderState_BackFillMode
// ******************************************************************
VOID WINAPI EMUPATCH(D3DDevice_SetRenderState_BackFillMode)
(
    DWORD Value
);

// ******************************************************************
// * patch: D3DDevice_SetTextureState_BorderColor
// ******************************************************************
VOID WINAPI EMUPATCH(D3DDevice_SetTextureState_BorderColor)
(
    DWORD Stage,
    DWORD Value
);

VOID EMUPATCH(D3DDevice_SetTextureState_BorderColor_0)();
VOID WINAPI EMUPATCH(D3DDevice_SetTextureState_BorderColor_4)
(
    DWORD Value
);

// ******************************************************************
// * patch: D3DDevice_SetTextureState_ColorKeyColor
// ******************************************************************
VOID WINAPI EMUPATCH(D3DDevice_SetTextureState_ColorKeyColor)
(
    DWORD Stage,
    DWORD Value
);

VOID EMUPATCH(D3DDevice_SetTextureState_ColorKeyColor_0)();
VOID __stdcall EMUPATCH(D3DDevice_SetTextureState_ColorKeyColor_4)
(
    DWORD Value
);

// ******************************************************************
// * patch: D3DDevice_SetTextureState_BumpEnv
// ******************************************************************
VOID WINAPI EMUPATCH(D3DDevice_SetTextureState_BumpEnv)
(
    DWORD                      Stage,
    D3DTEXTURESTAGESTATETYPE   Type,
    DWORD                      Value
);

VOID WINAPI EMUPATCH(D3DDevice_SetTextureState_BumpEnv_8)
(
    D3DTEXTURESTAGESTATETYPE   Type,
    DWORD                      Value
);

// ******************************************************************
// * patch: D3DDevice_SetRenderState_FrontFace
// ******************************************************************
VOID WINAPI EMUPATCH(D3DDevice_SetRenderState_FrontFace)
(
    DWORD Value
);

// ******************************************************************
// * patch: D3DDevice_SetRenderState_LogicOp
// ******************************************************************
VOID WINAPI EMUPATCH(D3DDevice_SetRenderState_LogicOp)
(
    DWORD Value
);

// ******************************************************************
// * patch: D3DDevice_SetRenderState_NormalizeNormals
// ******************************************************************
VOID WINAPI EMUPATCH(D3DDevice_SetRenderState_NormalizeNormals)
(
    DWORD Value
);

// ******************************************************************
// * patch: D3DDevice_SetRenderState_TextureFactor
// ******************************************************************
VOID WINAPI EMUPATCH(D3DDevice_SetRenderState_TextureFactor)
(
    DWORD Value
);

// ******************************************************************
// * patch: D3DDevice_SetRenderState_ZBias
// ******************************************************************
VOID WINAPI EMUPATCH(D3DDevice_SetRenderState_ZBias)
(
    DWORD Value
);

// ******************************************************************
// * patch: D3DDevice_SetRenderState_EdgeAntiAlias
// ******************************************************************
VOID WINAPI EMUPATCH(D3DDevice_SetRenderState_EdgeAntiAlias)
(
    DWORD Value
);

// ******************************************************************
// * patch: D3DDevice_SetRenderState_FillMode
// ******************************************************************
VOID WINAPI EMUPATCH(D3DDevice_SetRenderState_FillMode)
(
    DWORD Value
);

// ******************************************************************
// * patch: D3DDevice_SetRenderState_FogColor
// ******************************************************************
VOID WINAPI EMUPATCH(D3DDevice_SetRenderState_FogColor)
(
    DWORD Value
);

// ******************************************************************
// * patch: D3DDevice_SetRenderState_Dxt1NoiseEnable
// ******************************************************************
VOID WINAPI EMUPATCH(D3DDevice_SetRenderState_Dxt1NoiseEnable)
(
    DWORD Value
);

// ******************************************************************
// * patch: D3DDevice_SetRenderState_Simple
// ******************************************************************
VOID __fastcall EMUPATCH(D3DDevice_SetRenderState_Simple)
(
    DWORD Method,
    DWORD Value
);

// ******************************************************************
// * patch: D3DDevice_SetRenderState_VertexBlend
// ******************************************************************
VOID WINAPI EMUPATCH(D3DDevice_SetRenderState_VertexBlend)
(
    DWORD Value
);

// ******************************************************************
// * patch: D3DDevice_SetRenderState_PSTextureModes
// ******************************************************************
VOID WINAPI EMUPATCH(D3DDevice_SetRenderState_PSTextureModes)
(
    DWORD Value
);

// ******************************************************************
// * patch: D3DDevice_SetRenderState_CullMode
// ******************************************************************
VOID WINAPI EMUPATCH(D3DDevice_SetRenderState_CullMode)
(
    DWORD Value
);

// ******************************************************************
// * patch: D3DDevice_SetRenderState_LineWidth
// ******************************************************************
VOID WINAPI EMUPATCH(D3DDevice_SetRenderState_LineWidth)
(
    DWORD Value
);

// ******************************************************************
// * patch: D3DDevice_SetRenderState_StencilFail
// ******************************************************************
VOID WINAPI EMUPATCH(D3DDevice_SetRenderState_StencilFail)
(
    DWORD Value
);

// ******************************************************************
// * patch: D3DDevice_SetRenderState_OcclusionCullEnable
// ******************************************************************
VOID WINAPI EMUPATCH(D3DDevice_SetRenderState_OcclusionCullEnable)
(
    DWORD Value
);

// ******************************************************************
// * patch: D3DDevice_SetRenderState_StencilCullEnable
// ******************************************************************
VOID WINAPI EMUPATCH(D3DDevice_SetRenderState_StencilCullEnable)
(
    DWORD Value
);

// ******************************************************************
// * patch: D3DDevice_SetRenderState_RopZCmpAlwaysRead
// ******************************************************************
VOID WINAPI EMUPATCH(D3DDevice_SetRenderState_RopZCmpAlwaysRead)
(
    DWORD Value
);

// ******************************************************************
// * patch: D3DDevice_SetRenderState_RopZRead
// ******************************************************************
VOID WINAPI EMUPATCH(D3DDevice_SetRenderState_RopZRead)
(
    DWORD Value
);

// ******************************************************************
// * patch: D3DDevice_SetRenderState_DoNotCullUncompressed
// ******************************************************************
VOID WINAPI EMUPATCH(D3DDevice_SetRenderState_DoNotCullUncompressed)
(
    DWORD Value
);

// ******************************************************************
// * patch: D3DDevice_SetRenderState_ZEnable
// ******************************************************************
VOID WINAPI EMUPATCH(D3DDevice_SetRenderState_ZEnable)
(
    DWORD Value
);

// ******************************************************************
// * patch: D3DDevice_SetRenderState_StencilEnable
// ******************************************************************
VOID WINAPI EMUPATCH(D3DDevice_SetRenderState_StencilEnable)
(
    DWORD Value
);

// ******************************************************************
// * patch: D3DDevice_SetRenderState_MultiSampleMask
// ******************************************************************
VOID WINAPI EMUPATCH(D3DDevice_SetRenderState_MultiSampleMask)
(
    DWORD Value
);

// ******************************************************************
// * patch: D3DDevice_SetRenderState_MultiSampleMode
// ******************************************************************
VOID WINAPI EMUPATCH(D3DDevice_SetRenderState_MultiSampleMode)
(
    DWORD Value
);

// ******************************************************************
// * patch: D3DDevice_SetRenderState_MultiSampleRenderTargetMode
// ******************************************************************
VOID WINAPI EMUPATCH(D3DDevice_SetRenderState_MultiSampleRenderTargetMode)
(
    DWORD Value
);

// ******************************************************************
// * patch: D3DDevice_SetRenderState_MultiSampleAntiAlias
// ******************************************************************
VOID WINAPI EMUPATCH(D3DDevice_SetRenderState_MultiSampleAntiAlias)
(
    DWORD Value
);

// ******************************************************************
// * patch: D3DDevice_SetRenderState_ShadowFunc
// ******************************************************************
VOID WINAPI EMUPATCH(D3DDevice_SetRenderState_ShadowFunc)
(
    DWORD Value
);

// ******************************************************************
// * patch: D3DDevice_SetTransform
// ******************************************************************
VOID WINAPI EMUPATCH(D3DDevice_SetTransform)
(
    D3DTRANSFORMSTATETYPE State,
    CONST D3DMATRIX      *pMatrix
);

VOID __stdcall EMUPATCH(D3DDevice_SetTransform_0)();

// ******************************************************************
// * patch: D3DDevice_MultiplyTransform
// ******************************************************************
VOID WINAPI EMUPATCH(D3DDevice_MultiplyTransform)
(
	D3DTRANSFORMSTATETYPE State,
	CONST D3DMATRIX      *pMatrix
);

// ******************************************************************
// * patch: D3DDevice_GetTransform
// ******************************************************************
VOID WINAPI EMUPATCH(D3DDevice_GetTransform)
(
    D3DTRANSFORMSTATETYPE State,
    D3DMATRIX            *pMatrix
);

// ******************************************************************
// * patch: IDirect3DVertexBuffer8_Lock
// ******************************************************************
VOID WINAPI EMUPATCH(D3DVertexBuffer_Lock)
(
    D3DVertexBuffer     *pVertexBuffer,
    UINT                OffsetToLock,
    UINT                SizeToLock,
    BYTE              **ppbData,
    DWORD               Flags
);

// ******************************************************************
// * patch: IDirect3DVertexBuffer8_Lock2
// ******************************************************************
BYTE* WINAPI EMUPATCH(D3DVertexBuffer_Lock2)
(
    D3DVertexBuffer    *pVertexBuffer,
    DWORD               Flags
);

// ******************************************************************
// * patch: D3DDevice_GetStreamSource2
// ******************************************************************
D3DVertexBuffer  * WINAPI EMUPATCH(D3DDevice_GetStreamSource2)
(
    UINT  StreamNumber,
    UINT *pStride
);

// ******************************************************************
// * patch: D3DDevice_SetStreamSource
// ******************************************************************
VOID WINAPI EMUPATCH(D3DDevice_SetStreamSource)
(
    UINT                StreamNumber,
    D3DVertexBuffer    *pStreamData,
    UINT                Stride
);

VOID WINAPI EMUPATCH(D3DDevice_SetStreamSource_4)
(
    UINT                Stride
);

VOID WINAPI EMUPATCH(D3DDevice_SetStreamSource_8)
(
    D3DVertexBuffer    *pStreamData,
    UINT                Stride
);

// ******************************************************************
// * patch: D3DDevice_SetVertexShader
// ******************************************************************
VOID WINAPI EMUPATCH(D3DDevice_SetVertexShader)
(
    DWORD            Handle
);

// ******************************************************************
// * patch: D3DDevice_DrawVertices
// ******************************************************************
VOID WINAPI EMUPATCH(D3DDevice_DrawVertices)
(
    D3DPRIMITIVETYPE    PrimitiveType,
    UINT                StartVertex,
    UINT                VertexCount
);

// ******************************************************************
// * patch: D3DDevice_DrawVertices_4
// ******************************************************************
VOID WINAPI EMUPATCH(D3DDevice_DrawVertices_4)
(
    D3DPRIMITIVETYPE    PrimitiveType
);

// ******************************************************************
// * patch: D3DDevice_DrawVerticesUP
// ******************************************************************
VOID WINAPI EMUPATCH(D3DDevice_DrawVerticesUP)
(
    D3DPRIMITIVETYPE    PrimitiveType,
    UINT                VertexCount,
    CONST PVOID         pVertexStreamZeroData,
    UINT                VertexStreamZeroStride
);

// ******************************************************************
// * patch: D3DDevice_DrawIndexedVertices
// ******************************************************************
VOID WINAPI EMUPATCH(D3DDevice_DrawIndexedVertices)
(
    D3DPRIMITIVETYPE    PrimitiveType,
    UINT                VertexCount,
    CONST PWORD         pIndexData
);

// ******************************************************************
// * patch: D3DDevice_DrawIndexedVerticesUP
// ******************************************************************
VOID WINAPI EMUPATCH(D3DDevice_DrawIndexedVerticesUP)
(
    D3DPRIMITIVETYPE    PrimitiveType,
    UINT                VertexCount,
    CONST PVOID         pIndexData,
    CONST PVOID         pVertexStreamZeroData,
    UINT                VertexStreamZeroStride
);

// ******************************************************************
// * patch: D3DDevice_GetLight
// ******************************************************************
VOID WINAPI EMUPATCH(D3DDevice_GetLight)
(
    DWORD            Index,
    D3DLIGHT8         *pLight
);

// ******************************************************************
// * patch: D3DDevice_SetLight
// ******************************************************************
HRESULT WINAPI EMUPATCH(D3DDevice_SetLight)
(
    DWORD            Index,
    CONST D3DLIGHT8   *pLight
);

// ******************************************************************
// * patch: D3DDevice_SetMaterial
// ******************************************************************
VOID WINAPI EMUPATCH(D3DDevice_SetMaterial)
(
    CONST D3DMATERIAL8   *pMaterial
);

// ******************************************************************
// * patch: D3DDevice_LightEnable
// ******************************************************************
HRESULT WINAPI EMUPATCH(D3DDevice_LightEnable)
(
    DWORD            Index,
    BOOL             bEnable
);

// ******************************************************************
// * patch: D3DDevice_Release
// ******************************************************************
ULONG WINAPI EMUPATCH(D3DDevice_Release)();

// ******************************************************************
// * patch: D3DDevice_CreatePalette
// ******************************************************************
HRESULT WINAPI EMUPATCH(D3DDevice_CreatePalette)
(
    D3DPALETTESIZE      Size,
    D3DPalette        **ppPalette
);

// ******************************************************************
// * patch: D3DDevice_CreatePalette2
// ******************************************************************
D3DPalette   * WINAPI EMUPATCH(D3DDevice_CreatePalette2)
(
    D3DPALETTESIZE      Size
);

// ******************************************************************
// * patch: D3DDevice_SetRenderTarget
// ******************************************************************
VOID WINAPI EMUPATCH(D3DDevice_SetRenderTarget)
(
    D3DSurface      *pRenderTarget,
    D3DSurface      *pNewZStencil
);

// ******************************************************************
// * patch: D3DDevice_SetPalette
// ******************************************************************
VOID WINAPI EMUPATCH(D3DDevice_SetPalette)
(
    DWORD         Stage,
    D3DPalette   *pPalette
);

VOID __stdcall EMUPATCH(D3DDevice_SetPalette_4)();

// ******************************************************************
// * patch: D3DDevice_SetFlickerFilter
// ******************************************************************
void WINAPI EMUPATCH(D3DDevice_SetFlickerFilter)
(
    DWORD         Filter
);

VOID __stdcall EMUPATCH(D3DDevice_SetFlickerFilter_0)();

// ******************************************************************
// * patch: D3DDevice_SetSoftDisplayFilter
// ******************************************************************
void WINAPI EMUPATCH(D3DDevice_SetSoftDisplayFilter)
(
    BOOL Enable
);

// ******************************************************************
// * patch: IDirect3DPalette8_Lock
// ******************************************************************
VOID WINAPI EMUPATCH(D3DPalette_Lock)
(
    D3DPalette     *pThis,
    D3DCOLOR      **ppColors,
    DWORD           Flags
);

// ******************************************************************
// * patch: IDirect3DPalette8_Lock2
// ******************************************************************
D3DCOLOR * WINAPI EMUPATCH(D3DPalette_Lock2)
(
    D3DPalette     *pThis,
    DWORD           Flags
);

// ******************************************************************
// * patch: D3DDevice_GetVertexShaderSize
// ******************************************************************
VOID WINAPI EMUPATCH(D3DDevice_GetVertexShaderSize)
(
    DWORD Handle,
    UINT* pSize
);

// ******************************************************************
// * patch: D3DDevice_DeleteVertexShader
// ******************************************************************
VOID WINAPI EMUPATCH(D3DDevice_DeleteVertexShader)
(
    DWORD Handle
);

VOID __stdcall EMUPATCH(D3DDevice_DeleteVertexShader_0)();

// ******************************************************************
// * patch: D3DDevice_SelectVertexShaderDirect
// ******************************************************************
VOID WINAPI EMUPATCH(D3DDevice_SelectVertexShaderDirect)
(
    VERTEXATTRIBUTEFORMAT   *pVAF,
    DWORD                    Address
);

// ******************************************************************
// * patch: D3DDevice_GetShaderConstantMode
// ******************************************************************
VOID WINAPI EMUPATCH(D3DDevice_GetShaderConstantMode)
(
    DWORD *pMode
);

// ******************************************************************
// * patch: D3DDevice_GetVertexShader
// ******************************************************************
VOID WINAPI EMUPATCH(D3DDevice_GetVertexShader)
(
    DWORD *pHandle
);

// ******************************************************************
// * patch: D3DDevice_GetVertexShaderConstant
// ******************************************************************
VOID WINAPI EMUPATCH(D3DDevice_GetVertexShaderConstant)
(
    INT   Register,
    void  *pConstantData,
    DWORD ConstantCount
);

// ******************************************************************
// * patch: D3DDevice_SetVertexShaderInputDirect
// ******************************************************************
VOID WINAPI EMUPATCH(D3DDevice_SetVertexShaderInputDirect)
(
    VERTEXATTRIBUTEFORMAT   *pVAF,
    UINT                     StreamCount,
    STREAMINPUT             *pStreamInputs
);

// ******************************************************************
// * patch: D3DDevice_GetVertexShaderInput
// ******************************************************************
HRESULT WINAPI EMUPATCH(D3DDevice_GetVertexShaderInput)
(
    DWORD              *pHandle,
    UINT               *pStreamCount,
    STREAMINPUT        *pStreamInputs
);

// ******************************************************************
// * patch: D3DDevice_GetVertexShaderInput
// ******************************************************************
VOID WINAPI EMUPATCH(D3DDevice_SetVertexShaderInput)
(
    DWORD              Handle,
    UINT               StreamCount,
    STREAMINPUT       *pStreamInputs
);

// ******************************************************************
// * patch: D3DDevice_RunVertexStateShader
// ******************************************************************
VOID WINAPI EMUPATCH(D3DDevice_RunVertexStateShader)
(
    DWORD        Address,
    CONST FLOAT *pData
);

// ******************************************************************
// * patch: D3DDevice_LoadVertexShaderProgram
// ******************************************************************
VOID WINAPI EMUPATCH(D3DDevice_LoadVertexShaderProgram)
(
    CONST DWORD *pFunction,
    DWORD        Address
);

// ******************************************************************
// * patch: D3DDevice_GetVertexShaderType
// ******************************************************************
VOID WINAPI EMUPATCH(D3DDevice_GetVertexShaderType)
(
    DWORD  Handle,
    DWORD *pType
);

// ******************************************************************
// * patch: D3DDevice_GetVertexShaderDeclaration
// ******************************************************************
HRESULT WINAPI EMUPATCH(D3DDevice_GetVertexShaderDeclaration)
(
    DWORD  Handle,
    PVOID  pData,
    DWORD *pSizeOfData
);

// ******************************************************************
// * patch: D3DDevice_GetVertexShaderFunction
// ******************************************************************
HRESULT WINAPI EMUPATCH(D3DDevice_GetVertexShaderFunction)
(
    DWORD  Handle,
    PVOID *pData,
    DWORD *pSizeOfData
);

// ******************************************************************
// * patch: D3DDevice_SetDepthClipPlanes
// ******************************************************************
HRESULT WINAPI EMUPATCH(D3DDevice_SetDepthClipPlanes)
(
    FLOAT Near,
    FLOAT Far,
    DWORD Flags
);

#if 0 // DISABLED (Just calls MmAllocateContiguousMemory)
// ******************************************************************
// * patch: D3D_AllocContiguousMemory
// ******************************************************************
PVOID WINAPI EMUPATCH(D3D_AllocContiguousMemory)
(
    SIZE_T dwSize,
    DWORD dwAllocAttributes
);
#endif

#if 0 // DISABLED (Just calls Get2DSurfaceDesc)
// ******************************************************************
// * patch: D3DTexture_GetLevelDesc
// ******************************************************************
HRESULT WINAPI EMUPATCH(D3DTexture_GetLevelDesc)
(
    UINT Level,
    D3DSURFACE_DESC  * pDesc
);
#endif

#if 0 // patch disabled
// ******************************************************************
// * patch: Direct3D_CheckDeviceMultiSampleType
// ******************************************************************
HRESULT WINAPI EMUPATCH(Direct3D_CheckDeviceMultiSampleType)
(
    UINT                 Adapter,
    D3DDEVTYPE           DeviceType,
    D3DFORMAT            SurfaceFormat,
    BOOL                 Windowed,
    D3DMULTISAMPLE_TYPE  MultiSampleType
);
#endif

#if 0 // patch disabled
// ******************************************************************
// * patch: D3D_GetDeviceCaps
// ******************************************************************
HRESULT WINAPI EMUPATCH(D3D_GetDeviceCaps)
(
    UINT        Adapter,
    D3DDEVTYPE  DeviceType,
    D3DCAPS    *pCaps
);
#endif

#if 0 // patch disabled
// ******************************************************************
// * patch: D3D_SetPushBufferSize
// ******************************************************************
HRESULT WINAPI EMUPATCH(D3D_SetPushBufferSize)
(
    DWORD PushBufferSize,
    DWORD KickOffSize
);
#endif

// ******************************************************************
// * patch: D3DDevice_InsertFence
// ******************************************************************
DWORD WINAPI EMUPATCH(D3DDevice_InsertFence)();

// ******************************************************************
// * patch: D3DDevice_IsFencePending
// ******************************************************************
BOOL WINAPI EMUPATCH(D3DDevice_IsFencePending)
(
    DWORD Fence
);

// ******************************************************************
// * patch: D3DDevice_BlockOnFence
// ******************************************************************
VOID WINAPI EMUPATCH(D3DDevice_BlockOnFence)
(
    DWORD Fence
);

// ******************************************************************
// * patch: D3DResource_BlockUntilNotBusy
// ******************************************************************
VOID WINAPI EMUPATCH(D3DResource_BlockUntilNotBusy)
(
    D3DResource   *pThis
);

#if 0 // patch DISABLED
// ******************************************************************
// * patch: D3DVertexBuffer_GetDesc
// ******************************************************************
VOID WINAPI EMUPATCH(D3DVertexBuffer_GetDesc)
(
    D3DVertexBuffer      *pThis,
    D3DVERTEXBUFFER_DESC   *pDesc
);
#endif

// ******************************************************************
// * patch: D3DDevice_SetScissors
// ******************************************************************
VOID WINAPI EMUPATCH(D3DDevice_SetScissors)
(
    DWORD          Count,
    BOOL           Exclusive,
    CONST D3DRECT  *pRects
);

// ******************************************************************
// * patch: D3DDevice_SetScreenSpaceOffset
// ******************************************************************
VOID WINAPI EMUPATCH(D3DDevice_SetScreenSpaceOffset)
(
    FLOAT x,
    FLOAT y
);

// ******************************************************************
// * patch: D3DDevice_SetPixelShaderProgram
// ******************************************************************
VOID WINAPI EMUPATCH(D3DDevice_SetPixelShaderProgram)
(
	D3DPIXELSHADERDEF   *pPSDef
);

// ******************************************************************
// * patch: D3DDevice_CreateStateBlock
// ******************************************************************
HRESULT WINAPI EMUPATCH(D3DDevice_CreateStateBlock)
(
	D3DSTATEBLOCKTYPE Type,
	DWORD			  *pToken
);

// ******************************************************************
// * patch: D3DDevice_InsertCallback
// ******************************************************************
VOID WINAPI EMUPATCH(D3DDevice_InsertCallback)
(
	D3DCALLBACKTYPE  	Type,
	D3DCALLBACK  		pCallback,
	DWORD				Context
);

// ******************************************************************
// * patch: D3DDevice_DrawRectPatch
// ******************************************************************
HRESULT WINAPI EMUPATCH(D3DDevice_DrawRectPatch)
(
	UINT					Handle,
	CONST FLOAT				*pNumSegs,
	CONST D3DRECTPATCH_INFO *pRectPatchInfo
);

// ******************************************************************
// * patch: D3DDevice_DrawTriPatch
// ******************************************************************
HRESULT WINAPI EMUPATCH(D3DDevice_DrawTriPatch)
(
	UINT					Handle,
	CONST FLOAT				*pNumSegs,
	CONST D3DTRIPATCH_INFO* pTriPatchInfo
);

// ******************************************************************
// * patch: D3DDevice_GetProjectionViewportMatrix
// ******************************************************************
VOID WINAPI EMUPATCH(D3DDevice_GetProjectionViewportMatrix)
(
	D3DXMATRIX *pProjectionViewport
);

// ******************************************************************
// * patch: D3DDevice_KickOff (D3D::CDevice::KickOff)
// ******************************************************************
VOID WINAPI EMUPATCH(D3DDevice_KickOff)();

// ******************************************************************
// * patch: D3DDevice_KickPushBuffer
// ******************************************************************
VOID WINAPI EMUPATCH(D3DDevice_KickPushBuffer)();

// ******************************************************************
// * patch: D3DDevice_GetTexture2
// ******************************************************************
D3DBaseTexture  * WINAPI EMUPATCH(D3DDevice_GetTexture2)(DWORD Stage);

// ******************************************************************
// * patch: D3DDevice_GetTexture
// ******************************************************************
VOID WINAPI EMUPATCH(D3DDevice_GetTexture)
(
	DWORD           Stage,
	D3DBaseTexture    **pTexture
);

// ******************************************************************
// * patch: D3DDevice_SetStateVB (D3D::CDevice::SetStateVB)
// ******************************************************************
VOID WINAPI EMUPATCH(D3DDevice_SetStateVB)( ULONG Unknown1 );

// ******************************************************************
// * patch: D3DDevice_SetStateUP (D3D::CDevice::SetStateUP)
// ******************************************************************
VOID WINAPI EMUPATCH(D3DDevice_SetStateUP)();

// ******************************************************************
// * patch: D3DDevice_SetStipple
// ******************************************************************
void WINAPI EMUPATCH(D3DDevice_SetStipple)( DWORD* pPattern );

// ******************************************************************
// * patch: D3DDevice_SetSwapCallback
// ******************************************************************
void WINAPI EMUPATCH(D3DDevice_SetSwapCallback)
(
	D3DSWAPCALLBACK  		pCallback
);

// ******************************************************************
// * patch: D3DDevice_PersistDisplay
// ******************************************************************
HRESULT WINAPI EMUPATCH(D3DDevice_PersistDisplay)();

// ******************************************************************
// * patch: D3DDevice_GetPersistedSurface
// ******************************************************************
VOID WINAPI EMUPATCH(D3DDevice_GetPersistedSurface)(D3DSurface   **ppSurface);
D3DSurface  * WINAPI EMUPATCH(D3DDevice_GetPersistedSurface2)();

// ******************************************************************
// * patch: D3D_CMiniport_GetDisplayCapabilities
// ******************************************************************
DWORD WINAPI EMUPATCH(D3D_CMiniport_GetDisplayCapabilities)();

// ******************************************************************
// * patch: D3DDevice_PrimeVertexCache
// ******************************************************************
VOID WINAPI EMUPATCH(D3DDevice_PrimeVertexCache)
(
	UINT VertexCount,
	WORD *pIndexData
);

// ******************************************************************
// * patch: D3DDevice_SetRenderState_SampleAlpha
// ******************************************************************
HRESULT WINAPI EMUPATCH(D3DDevice_SetRenderState_SampleAlpha)
(
	DWORD dwSampleAlpha
);

// ******************************************************************
// * patch: D3DDevice_SetRenderState_Deferred
// ******************************************************************
VOID __fastcall EMUPATCH(D3DDevice_SetRenderState_Deferred)
(
	DWORD State,
	DWORD Value
);

// ******************************************************************
// * patch: D3DDevice_DeleteStateBlock
// ******************************************************************
VOID WINAPI EMUPATCH(D3DDevice_DeleteStateBlock)
(
	DWORD Token
);

// ******************************************************************
// * patch: D3DDevice_SetModelView
// ******************************************************************
VOID WINAPI EMUPATCH(D3DDevice_SetModelView)
(
	CONST D3DMATRIX *pModelView, 
	CONST D3DMATRIX *pInverseModelView, 
	CONST D3DMATRIX *pComposite
);

// ******************************************************************
// * patch: D3DDevice_FlushVertexCache
// ******************************************************************
void WINAPI EMUPATCH(D3DDevice_FlushVertexCache)();

// ******************************************************************
// * patch: D3DDevice_BeginPushBuffer
// ******************************************************************
VOID WINAPI EMUPATCH(D3DDevice_BeginPushBuffer)
(
	D3DPushBuffer   *pPushBuffer
);

// ******************************************************************
// * patch: D3DDevice_EndPushBuffer
// ******************************************************************
HRESULT WINAPI EMUPATCH(D3DDevice_EndPushBuffer)();

// ******************************************************************
// * patch: XMETAL_StartPush
// ******************************************************************
PDWORD WINAPI EMUPATCH(XMETAL_StartPush)(void* Unknown);

// ******************************************************************
// * patch: D3DDevice_GetModelView
// ******************************************************************
HRESULT WINAPI EMUPATCH(D3DDevice_GetModelView)(D3DXMATRIX* pModelView);

// ******************************************************************
// * patch: D3DDevice_SetBackMaterial
// ******************************************************************
VOID WINAPI EMUPATCH(D3DDevice_SetBackMaterial)
(
	D3DMATERIAL8  * pMaterial
);

#if 0 // patch disabled
// ******************************************************************
// * patch: D3D_GetAdapterIdentifier
// ******************************************************************
HRESULT WINAPI EMUPATCH(D3D_GetAdapterIdentifier)
(
	UINT					Adapter,
	DWORD					Flags,
	D3DADAPTER_IDENTIFIER   *pIdentifier
);
#endif

// ******************************************************************
// * patch: D3D::MakeRequestedSpace
// ******************************************************************
PDWORD WINAPI EMUPATCH(D3D_MakeRequestedSpace)
(
	DWORD MinimumSpace,
	DWORD RequestedSpace
);

// ******************************************************************
// * patch: D3DDevice_MakeSpace
// ******************************************************************
void WINAPI EMUPATCH(D3DDevice_MakeSpace)();

// ******************************************************************
// * patch: D3D_SetCommonDebugRegisters
// ******************************************************************
void WINAPI EMUPATCH(D3D_SetCommonDebugRegisters)();

// ******************************************************************
// * patch: D3D_BlockOnTime
// ******************************************************************
void WINAPI EMUPATCH(D3D_BlockOnTime)( DWORD Unknown1, int Unknown2 );

// ******************************************************************
// * patch: D3D_BlockOnResource
// ******************************************************************
void WINAPI EMUPATCH(D3D_BlockOnResource)( D3DResource  * pResource );

// ******************************************************************
// * patch: D3D_DestroyResource
// ******************************************************************
void WINAPI EMUPATCH(D3D_DestroyResource)( D3DResource  * pResource );

// ******************************************************************
// * patch: D3D_DestroyResource__LTCG
// ******************************************************************
void WINAPI EMUPATCH(D3D_DestroyResource__LTCG)();


// ******************************************************************
// * patch: D3DDevice_GetPushBufferOffset
// ******************************************************************
VOID WINAPI EMUPATCH(D3DDevice_GetPushBufferOffset)
(
	DWORD *pOffset
);

// ******************************************************************
// * patch: IDirect3DCubeTexture8_GetCubeMapSurface
// ******************************************************************
HRESULT WINAPI EMUPATCH(D3DCubeTexture_GetCubeMapSurface)
(
	D3DCubeTexture  *	pThis,
	D3DCUBEMAP_FACES	FaceType,
	UINT				Level,
	D3DSurface  **		ppCubeMapSurface
);

// ******************************************************************
// * patch: IDirect3DCubeTexture8_GetCubeMapSurface2
// ******************************************************************
D3DSurface  * WINAPI EMUPATCH(D3DCubeTexture_GetCubeMapSurface2)
(
	D3DCubeTexture  *	pThis,
	D3DCUBEMAP_FACES	FaceType,
	UINT				Level
);

// ******************************************************************
// * patch: D3DDevice_GetPixelShader
// ******************************************************************
VOID WINAPI EMUPATCH(D3DDevice_GetPixelShader)
(
	DWORD  Name,
	DWORD* pHandle
);

// ******************************************************************
// * patch: D3DDevice_SetRenderTargetFast
// ******************************************************************
VOID WINAPI EMUPATCH(D3DDevice_SetRenderTargetFast)
(
    D3DSurface  	*pRenderTarget,
    D3DSurface  	*pNewZStencil,
    DWORD			Flags
);

// ******************************************************************
// * patch: D3DDevice_GetScissors
// ******************************************************************
VOID WINAPI EMUPATCH(D3DDevice_GetScissors)
(
	DWORD	*pCount, 
	BOOL	*pExclusive, 
	D3DRECT *pRects
);
// ******************************************************************
// * patch: D3DDevice_GetBackMaterial
// ******************************************************************
VOID WINAPI EMUPATCH(D3DDevice_GetBackMaterial)
(
	D3DMATERIAL8  * pMaterial
);

// ******************************************************************
// * patch: D3D::LazySetPointParams
// ******************************************************************
void WINAPI EMUPATCH(D3D_LazySetPointParams)( void* Device );

// ******************************************************************
// * patch: D3DDevice_GetMaterial
// ******************************************************************
VOID WINAPI EMUPATCH(D3DDevice_GetMaterial)
(
	D3DMATERIAL8  * pMaterial
);

#endif
