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
#ifndef XBD3D8TYPES_H
#define XBD3D8TYPES_H

// For transforming code that's written for Direct3D 8 into Direct3D 9,
// See "Converting to Direct3D 9" https://msdn.microsoft.com/en-us/library/windows/desktop/bb204851(v=vs.85).aspx

// See https://msdn.microsoft.com/en-us/library/windows/desktop/bb204851(v=vs.85).aspx#D3DENUM_NO_WHQL_LEVEL_Changes
#define D3DENUM_NO_WHQL_LEVEL 0 // default in Direct3D 9

// Alias all host Direct3D 9 symbols to generic symbols
#define DXGetErrorString                DXGetErrorString9A
#define DXGetErrorDescription           DXGetErrorDescription9A
#define Direct3DCreate			        Direct3DCreate9
#define D3DXAssembleShader		        D3DXAssembleShader
#define FullScreen_PresentationInterval PresentationInterval // a field in D3DPRESENT_PARAMETERS
#define D3DLockData                     void
#define PixelShaderConstantType         float

#define D3DADAPTER_IDENTIFIER           D3DADAPTER_IDENTIFIER9
#define D3DCAPS                         D3DCAPS9
#define D3DVERTEXELEMENT                D3DVERTEXELEMENT9
#define D3DVIEWPORT                     D3DVIEWPORT9

#define IDirect3D                       IDirect3D8
#define IDirect3DDevice                 IDirect3DDevice8
#define IDirect3DStateBlock             IDirect3DStateBlock9 // unuse8
#define IDirect3DVertexDeclaration      IDirect3DVertexDeclaration8
#define IDirect3DVertexShader           IDirect3DVertexShader8
#define IDirect3DPixelShader            IDirect3DPixelShader8
#define IDirect3DResource               IDirect3DResource8
#define IDirect3DBaseTexture            IDirect3DBaseTexture8
#define IDirect3DTexture                IDirect3DTexture8
#define IDirect3DVolumeTexture          IDirect3DVolumeTexture8
#define IDirect3DCubeTexture            IDirect3DCubeTexture8
#define IDirect3DVertexBuffer           IDirect3DVertexBuffer8
#define IDirect3DIndexBuffer            IDirect3DIndexBuffer8
#define IDirect3DSurface                IDirect3DSurface8
#define IDirect3DVolume                 IDirect3DVolume8
#define IDirect3DSwapChain              IDirect3DSwapChain8
#define IDirect3DQuery                  IDirect3DQuery8

typedef struct IDirect3DDevice8 { void *lpVtbl; } IDirect3DDevice8;

typedef enum _D3DCULL
{
	D3DCULL_NONE = 0,
	D3DCULL_CW = 0x900,
	D3DCULL_CCW = 0x901,
	D3DCULL_FORCE_DWORD = 0x7fffffff
}
D3DCULL;

typedef enum _D3DFORMAT
{
/*
	Xbox1 D3DFORMAT notes
	---------------------

	The Xbox1 D3DFORMAT type consists of 4 different format categories :
	1. Swizzled (improves data locality, incompatible with native Direct3D)
	2. Compressed (DXT compression, giving 4:1 reduction on 4x4 pixel blocks)
	3. Linear (compatible with native Direct3D)
	4. Depth (Fixed or Floating point, stored Linear or Swizzled)

	Requirements\Format      Swizzled  Compressed  Linear  Depth   Notes

	Power-of-two required ?  YES       YES         NO      NO
	Mipmap supported ?       YES       YES         NO      YES     Linear has MipmapLevels = 1
	CubeMaps supported ?     YES       YES         NO      NO      Cubemaps have 6 faces
	Supports volumes ?       YES       YES         NO      NO      Volumes have 3 dimensions, Textures have 2
	Can be a rendertarget ?  YES       YES         YES     LINEAR  Depth buffers can only be rendered to if stored Linear

	Implications :
	- CubeMaps must be square
	- Volumes cannot be cube mapped and vice versa

	Maximum dimensions :
	2D : 4096 x 4096 (12 mipmap levels)
	3D : 512 x 512 x 512 (9 mipmap levels)

*/

	// Xbox D3DFORMAT types :
	// See https://wiki.beyondunreal.com/Legacy:Texture_Format

	// Swizzled Formats

	D3DFMT_L8 = 0x00,
	D3DFMT_AL8 = 0x01,
	D3DFMT_A1R5G5B5 = 0x02,
	D3DFMT_X1R5G5B5 = 0x03,
	D3DFMT_A4R4G4B4 = 0x04,
	D3DFMT_R5G6B5 = 0x05,
	D3DFMT_A8R8G8B8 = 0x06,
	D3DFMT_X8R8G8B8 = 0x07,
	D3DFMT_X8L8V8U8 = 0x07, // Alias

	D3DFMT_P8 = 0x0b, // 8-bit Palletized

	D3DFMT_A8 = 0x19,
	D3DFMT_A8L8 = 0x1a,
	D3DFMT_R6G5B5 = 0x27,
	D3DFMT_L6V5U5 = 0x27, // Alias

	D3DFMT_G8B8 = 0x28,
	D3DFMT_V8U8 = 0x28, // Alias

	D3DFMT_R8B8 = 0x29,
	D3DFMT_D24S8 = 0x2a,
	D3DFMT_F24S8 = 0x2b,
	D3DFMT_D16 = 0x2c,
	D3DFMT_D16_LOCKABLE = 0x2c, // Alias

	D3DFMT_F16 = 0x2d,
	D3DFMT_L16 = 0x32,
	D3DFMT_V16U16 = 0x33,
	D3DFMT_R5G5B5A1 = 0x38,
	D3DFMT_R4G4B4A4 = 0x39,
	D3DFMT_A8B8G8R8 = 0x3A,
	D3DFMT_Q8W8V8U8 = 0x3A, // Alias

	D3DFMT_B8G8R8A8 = 0x3B,
	D3DFMT_R8G8B8A8 = 0x3C,

	// YUV Formats

	D3DFMT_YUY2 = 0x24,
	D3DFMT_UYVY = 0x25,

	// Compressed Formats

	D3DFMT_DXT1 = 0x0C, // opaque/one-bit alpha
	D3DFMT_DXT2 = 0x0E, // Alias for D3DFMT_DXT3
	D3DFMT_DXT3 = 0x0E, // linear alpha
	D3DFMT_DXT4 = 0x0F, // Alias for D3DFMT_DXT5
	D3DFMT_DXT5 = 0x0F, // interpolated alpha

	// Linear Formats

	D3DFMT_LIN_A1R5G5B5 = 0x10,
	D3DFMT_LIN_R5G6B5 = 0x11,
	D3DFMT_LIN_A8R8G8B8 = 0x12,
	D3DFMT_LIN_L8 = 0x13,
	D3DFMT_LIN_R8B8 = 0x16,
	D3DFMT_LIN_G8B8 = 0x17,
	D3DFMT_LIN_V8U8 = 0x17, // Alias

	D3DFMT_LIN_AL8 = 0x1b,
	D3DFMT_LIN_X1R5G5B5 = 0x1c,
	D3DFMT_LIN_A4R4G4B4 = 0x1d,
	D3DFMT_LIN_X8R8G8B8 = 0x1e,
	D3DFMT_LIN_X8L8V8U8 = 0x1e, // Alias

	D3DFMT_LIN_A8 = 0x1f,
	D3DFMT_LIN_A8L8 = 0x20,
	D3DFMT_LIN_D24S8 = 0x2E,
	D3DFMT_LIN_F24S8 = 0x2f,
	D3DFMT_LIN_D16 = 0x30,
	D3DFMT_LIN_F16 = 0x31,
	D3DFMT_LIN_L16 = 0x35,
	D3DFMT_LIN_V16U16 = 0x36,
	D3DFMT_LIN_R6G5B5 = 0x37,
	D3DFMT_LIN_L6V5U5 = 0x37, // Alias

	D3DFMT_LIN_R5G5B5A1 = 0x3D,
	D3DFMT_LIN_R4G4B4A4 = 0x3e,
	D3DFMT_LIN_A8B8G8R8 = 0x3f,
	D3DFMT_LIN_B8G8R8A8 = 0x40,
	D3DFMT_LIN_R8G8B8A8 = 0x41,

	D3DFMT_VERTEXDATA = 0x64,

	D3DFMT_INDEX16 = 101/*=D3DFMT_INDEX16*/, // Dxbx addition : Not an Xbox format, used internally

	D3DFMT_UNKNOWN = 0xFFFFFFFF - 3,  // Unique declaration to make overloads possible
}
D3DFORMAT, *PD3DFORMAT;

// Primitives supported by draw-primitive API
typedef enum _D3DPRIMITIVETYPE
{
    D3DPT_NONE = 0, // Dxbx addition

    D3DPT_POINTLIST             = 1,
    D3DPT_LINELIST              = 2,
    D3DPT_LINELOOP              = 3,    // Xbox only
    D3DPT_LINESTRIP             = 4,
    D3DPT_TRIANGLELIST          = 5,
    D3DPT_TRIANGLESTRIP         = 6,
    D3DPT_TRIANGLEFAN           = 7,
    D3DPT_QUADLIST              = 8,    // Xbox only
    D3DPT_QUADSTRIP             = 9,    // Xbox only
    D3DPT_POLYGON               = 10,   // Xbox only

    D3DPT_MAX                   = 11,
    D3DPT_INVALID               = 0x7fffffff, /* force 32-bit size enum */
}
D3DPRIMITIVETYPE;

typedef enum _D3DRESOURCETYPE
{
    D3DRTYPE_NONE               =  0,
    D3DRTYPE_SURFACE            =  1, // = D3DRESOURCETYPE.D3DRTYPE_SURFACE
    D3DRTYPE_VOLUME             =  2, // = D3DRESOURCETYPE.D3DRTYPE_VOLUME
    D3DRTYPE_TEXTURE            =  3, // = D3DRESOURCETYPE.D3DRTYPE_TEXTURE
    D3DRTYPE_VOLUMETEXTURE      =  4, // = D3DRESOURCETYPE.D3DRTYPE_VOLUMETEXTURE
    D3DRTYPE_CUBETEXTURE        =  5, // = D3DRESOURCETYPE.D3DRTYPE_CUBETEXTURE
    D3DRTYPE_VERTEXBUFFER       =  6, // = D3DRESOURCETYPE.D3DRTYPE_VERTEXBUFFER
    D3DRTYPE_INDEXBUFFER        =  7, // = D3DRESOURCETYPE.D3DRTYPE_INDEXBUFFER
    D3DRTYPE_PUSHBUFFER         =  8,
    D3DRTYPE_PALETTE            =  9,
    D3DRTYPE_FIXUP              =  10,

    D3DRTYPE_FORCE_DWORD        = 0x7fffffff
}
D3DRESOURCETYPE;


/* XbConvert.h */

typedef enum _D3DTRANSFORMSTATETYPE {
	D3DTS_VIEW             = 0,
	D3DTS_PROJECTION       = 1,
	D3DTS_TEXTURE0         = 2,
	D3DTS_TEXTURE1         = 3,
	D3DTS_TEXTURE2         = 4,
	D3DTS_TEXTURE3         = 5,
	D3DTS_WORLD            = 6,
	D3DTS_WORLD1           = 7,
	D3DTS_WORLD2           = 8,
	D3DTS_WORLD3           = 9,
	D3DTS_FORCE_DWORD      = 0x7fffffff
} D3DTRANSFORMSTATETYPE;
// // Handle World Matrix offsets
// if (State >= 256 && State <= 511) {
// return D3DTS_WORLDMATRIX(State - 256);
// }

#include "d3d8types_wine.h"


    
typedef enum _D3DBLENDOP {
	D3DBLENDOP_ADD               = 0x8006,
	D3DBLENDOP_SUBTRACT          = 0x800a,
	D3DBLENDOP_REVSUBTRACT       = 0x800b,
	D3DBLENDOP_MIN               = 0x8007,
	D3DBLENDOP_MAX               = 0x8008,
	D3DBLENDOP_ADDSIGNED         = 0xF006,
	D3DBLENDOP_REVSUBTRACTSIGNED = 0xF005,
	D3DBLENDOP_FORCE_DWORD       = 0x7fffffff
} D3DBLENDOP;

typedef enum _D3DBLEND {
	D3DBLEND_ZERO             = 0x000,
	D3DBLEND_ONE              = 0x001,
	D3DBLEND_SRCCOLOR         = 0x300,
	D3DBLEND_INVSRCCOLOR      = 0x301,
	D3DBLEND_SRCALPHA         = 0x302,
	D3DBLEND_INVSRCALPHA      = 0x303,
	D3DBLEND_DESTALPHA        = 0x304,
	D3DBLEND_INVDESTALPHA     = 0x305,
	D3DBLEND_DESTCOLOR        = 0x306,
	D3DBLEND_INVDESTCOLOR     = 0x307,
	D3DBLEND_SRCALPHASAT      = 0x308,
	D3DBLEND_CONSTANTCOLOR    = 0x8001,
	D3DBLEND_INVCONSTANTCOLOR = 0x8002,
	D3DBLEND_CONSTANTALPHA    = 0x8003,
	D3DBLEND_INVCONSTANTALPHA = 0x8004,
	D3DBLEND_FORCE_DWORD      = 0x7fffffff
} D3DBLEND;

typedef enum _D3DCMPFUNC {
	D3DCMP_NEVER              = 0x200,
	D3DCMP_LESS               = 0x201,
	D3DCMP_EQUAL              = 0x202,
	D3DCMP_LESSEQUAL          = 0x203,
	D3DCMP_GREATER            = 0x204,
	D3DCMP_NOTEQUAL           = 0x205,
	D3DCMP_GREATEREQUAL       = 0x206,
	D3DCMP_ALWAYS             = 0x207,
	D3DCMP_FORCE_DWORD        = 0x7fffffff
} D3DCMPFUNC;

typedef enum _D3DSTENCILOP {
	D3DSTENCILOP_KEEP         = 0x1e00,
	D3DSTENCILOP_ZERO         = 0x0000,
	D3DSTENCILOP_REPLACE      = 0x1e01,
	D3DSTENCILOP_INCRSAT      = 0x1e02,
	D3DSTENCILOP_DECRSAT      = 0x1e03,
	D3DSTENCILOP_INVERT       = 0x150a,
	D3DSTENCILOP_INCR         = 0x8507,
	D3DSTENCILOP_DECR         = 0x8508,
	D3DSTENCILOP_FORCE_DWORD  = 0x7fffffff
} D3DSTENCILOP;

typedef enum _D3DFILLMODE {
	D3DFILL_POINT             = 0x1B00,
	D3DFILL_WIREFRAME         = 0x1B01,
	D3DFILL_SOLID             = 0x1B02,
	D3DFILL_FORCE_DWORD       = 0x7fffffff
} D3DFILLMODE;

typedef enum _D3DSHADEMODE {
	D3DSHADE_FLAT             = 0x1D00,
	D3DSHADE_GOURAUD          = 0x1D01,
	D3DSHADE_FORCE_DWORD      = 0x7fffffff
} D3DSHADEMODE;


// TODO: fill out these enumeration tables for convienance
// typedef D3DSWAPEFFECT D3DSWAPEFFECT;
typedef struct _D3DXVECTOR4 {
    float x,y,z,w;
} D3DXVECTOR4;
typedef DWORD D3DMULTISAMPLE_TYPE;
typedef DWORD D3DTEXTURESTAGESTATETYPE;

// D3DUSAGE values (all but the Xbox extensions match the PC versions) :
#define D3DUSAGE_RENDERTARGET           0x00000001
#define D3DUSAGE_DEPTHSTENCIL           0x00000002
// for Vertex/Index buffers
#define D3DUSAGE_WRITEONLY              0x00000008
#define D3DUSAGE_POINTS                 0x00000040
#define D3DUSAGE_RTPATCHES              0x00000080
#define D3DUSAGE_DYNAMIC                0x00000200
// for CreateVertexShader
#define D3DUSAGE_PERSISTENTDIFFUSE      0x00000400L   // Xbox-only
#define D3DUSAGE_PERSISTENTSPECULAR     0x00000800L   // Xbox-only
#define D3DUSAGE_PERSISTENTBACKDIFFUSE  0x00001000L   // Xbox-only
#define D3DUSAGE_PERSISTENTBACKSPECULAR 0x00002000L   // Xbox-only
// for CreateTexture/CreateImageSurface
#define D3DUSAGE_BORDERSOURCE_COLOR     0x00000000L   // Xbox-only
#define D3DUSAGE_BORDERSOURCE_TEXTURE   0x00010000L   // Xbox-only

#define D3D_RENDER_MEMORY_ALIGNMENT     64

#define D3DSURFACE_ALIGNMENT            D3D_RENDER_MEMORY_ALIGNMENT
#define D3DTEXTURE_ALIGNMENT            (2 * D3D_RENDER_MEMORY_ALIGNMENT)
#define D3DTEXTURE_CUBEFACE_ALIGNMENT   (2 * D3D_RENDER_MEMORY_ALIGNMENT)
#define D3DTEXTURE_PITCH_ALIGNMENT      D3D_RENDER_MEMORY_ALIGNMENT
#define D3DTEXTURE_PITCH_MIN            D3DTEXTURE_PITCH_ALIGNMENT

typedef enum _D3DSET_DEPTH_CLIP_PLANES_FLAGS
{
    D3DSDCP_SET_VERTEXPROGRAM_PLANES         = 1,
    D3DSDCP_SET_FIXEDFUNCTION_PLANES         = 2,
    D3DSDCP_USE_DEFAULT_VERTEXPROGRAM_PLANES = 3,
    D3DSDCP_USE_DEFAULT_FIXEDFUNCTION_PLANES = 4,
} 
D3DSET_DEPTH_CLIP_PLANES_FLAGS;

#define D3DPRESENTFLAG_LOCKABLE_BACKBUFFER      0x00000001
#define D3DPRESENTFLAG_WIDESCREEN               0x00000010
#define D3DPRESENTFLAG_INTERLACED               0x00000020
#define D3DPRESENTFLAG_PROGRESSIVE              0x00000040
#define D3DPRESENTFLAG_FIELD                    0x00000080
#define D3DPRESENTFLAG_10X11PIXELASPECTRATIO    0x00000100

typedef struct _D3DDISPLAYMODE
{
    UINT        Width;
    UINT        Height;
    UINT        RefreshRate;
    DWORD       Flags;
    D3DFORMAT Format;
}
D3DDISPLAYMODE;

typedef struct _D3DVERTEXBUFFER_DESC
{
	D3DFORMAT           Format;
	D3DRESOURCETYPE     Type;
}
D3DVERTEXBUFFER_DESC;

typedef struct _D3DINDEXBUFFER_DESC
{
	D3DFORMAT           Format;
	D3DRESOURCETYPE     Type;
}
D3DINDEXBUFFER_DESC;

typedef struct _D3DSURFACE_DESC
{
    D3DFORMAT         Format;
    D3DRESOURCETYPE   Type;
    DWORD               Usage;
    UINT                Size;
    D3DMULTISAMPLE_TYPE MultiSampleType;
    UINT                Width;
    UINT                Height;
}
D3DSURFACE_DESC;

struct D3DSurface; // forward
typedef struct _D3DPRESENT_PARAMETERS
{
    UINT                BackBufferWidth;
    UINT                BackBufferHeight;
    D3DFORMAT         BackBufferFormat;
    UINT                BackBufferCount;

    D3DMULTISAMPLE_TYPE MultiSampleType;

    D3DSWAPEFFECT     SwapEffect;
    HWND                hDeviceWindow;
    BOOL                Windowed;
    BOOL                EnableAutoDepthStencil;
    D3DFORMAT         AutoDepthStencilFormat;
    DWORD               Flags;

    UINT                FullScreen_RefreshRateInHz;
    UINT                FullScreen_PresentationInterval;
    // The Windows DirectX8 variant ends here
    // This check guarantees identical layout, compared to Direct3D8._D3DPRESENT_PARAMETERS_:
    // assert(offsetof(D3DPRESENT_PARAMETERS, BufferSurfaces) == sizeof(_D3DPRESENT_PARAMETERS_));
    D3DSurface       *BufferSurfaces[3];
    D3DSurface       *DepthStencilSurface;
}
D3DPRESENT_PARAMETERS;

typedef struct _D3DGAMMARAMP
{
    BYTE    red[256];
    BYTE    green[256];
    BYTE    blue[256];
}
D3DGAMMARAMP;

typedef struct _D3DPIXELSHADERDEF	// <- blueshogun 10/1/07
{
   DWORD    PSAlphaInputs[8];          // D3DRS_PSALPHAINPUTS0..D3DRS_PSALPHAINPUTS7 : Alpha inputs for each stage
   DWORD    PSFinalCombinerInputsABCD; // D3DRS_PSFINALCOMBINERINPUTSABCD : Final combiner inputs
   DWORD    PSFinalCombinerInputsEFG;  // D3DRS_PSFINALCOMBINERINPUTSEFG : Final combiner inputs (continued)
   DWORD    PSConstant0[8];            // D3DRS_PSCONSTANT0_0..D3DRS_PSCONSTANT0_7 : C0 for each stage
   DWORD    PSConstant1[8];            // D3DRS_PSCONSTANT1_0..D3DRS_PSCONSTANT1_7 : C1 for each stage
   DWORD    PSAlphaOutputs[8];         // D3DRS_PSALPHAOUTPUTS0..D3DRS_PSALPHAOUTPUTS7 : Alpha output for each stage
   DWORD    PSRGBInputs[8];            // D3DRS_PSRGBINPUTS0..D3DRS_PSRGBINPUTS7 : RGB inputs for each stage
   DWORD    PSCompareMode;             // D3DRS_PSCOMPAREMODE : Compare modes for clipplane texture mode
   DWORD    PSFinalCombinerConstant0;  // D3DRS_PSFINALCOMBINERCONSTANT0 : C0 in final combiner
   DWORD    PSFinalCombinerConstant1;  // D3DRS_PSFINALCOMBINERCONSTANT1 : C1 in final combiner
   DWORD    PSRGBOutputs[8];           // D3DRS_PSRGBOUTPUTS0..D3DRS_PSRGBOUTPUTS7 : Stage 0 RGB outputs
   DWORD    PSCombinerCount;           // D3DRS_PSCOMBINERCOUNT : Active combiner count (Stages 0-7)
   DWORD    PSTextureModes;            // D3DRS_PSTEXTUREMODES: Texture addressing modes
   DWORD    PSDotMapping;              // D3DRS_PSDOTMAPPING : Input mapping for dot product modes
   DWORD    PSInputTexture;            // D3DRS_PSINPUTTEXTURE : Texture source for some texture modes

    // These last three DWORDs are used to define how Direct3D8 pixel shader constants map to the constant
    // registers in each combiner stage. They are used by the Direct3D run-time software but not by the hardware.
   DWORD    PSC0Mapping;               // Mapping of c0 regs to D3D constants
   DWORD    PSC1Mapping;               // Mapping of c1 regs to D3D constants
   DWORD    PSFinalCombinerConstants;  // Final combiner constant mapping
}
D3DPIXELSHADERDEF;


typedef struct _PixelShader
{
	DWORD RefCount;
	DWORD D3DOwned;
	D3DPIXELSHADERDEF *pPSDef;
} PixelShader;

struct D3DResource
{
    DWORD Common;
	DWORD Data;
	DWORD Lock;
};

// D3D resource "common" masks
#define D3DCOMMON_REFCOUNT_MASK      0x0000FFFF
#define D3DCOMMON_TYPE_MASK          0x00070000
#define D3DCOMMON_TYPE_SHIFT         16
#define D3DCOMMON_TYPE_VERTEXBUFFER  0x00000000
#define D3DCOMMON_TYPE_INDEXBUFFER   0x00010000
#define D3DCOMMON_TYPE_PUSHBUFFER    0x00020000
#define D3DCOMMON_TYPE_PALETTE       0x00030000
#define D3DCOMMON_TYPE_TEXTURE       0x00040000
#define D3DCOMMON_TYPE_SURFACE       0x00050000 // Also covers Volume resources
#define D3DCOMMON_TYPE_FIXUP         0x00060000
#define D3DCOMMON_INTREFCOUNT_MASK   0x00780000
#define D3DCOMMON_INTREFCOUNT_SHIFT  19
#define D3DCOMMON_INTREFCOUNT_1      (1 << D3DCOMMON_INTREFCOUNT_SHIFT) // Dxbx addition
#define D3DCOMMON_VIDEOMEMORY        0x00000000 // Was 0x00800000, but Xbox doesn't have this flag!
#define D3DCOMMON_D3DCREATED         0x01000000
#define D3DCOMMON_ISLOCKED           0x02000010 // Surface is currently locked (potential unswizzle candidate)
#define D3DCOMMON_UNUSED_MASK        0xFE000000
#define D3DCOMMON_UNUSED_SHIFT       25

// d3d palette common
#define D3DPALETTE_COMMON_PALETTESIZE_MASK       0xC0000000
#define D3DPALETTE_COMMON_PALETTESIZE_SHIFT      30

// special resource lock flags
#define D3DRESOURCE_LOCK_FLAG_NOSIZE  0xEFFFFFFF

// Lock flags
#define D3DLOCK_NOFLUSH               0x00000010 // Xbox extension
#define D3DLOCK_NOOVERWRITE           0x00000020
#define D3DLOCK_TILED                 0x00000040 // Xbox extension
#define D3DLOCK_READONLY              0x00000080


const int D3DMULTISAMPLE_NONE = 0x0011;
const int D3DMULTISAMPLE_2_SAMPLES_MULTISAMPLE_LINEAR = 0x1021;
const int D3DMULTISAMPLE_2_SAMPLES_MULTISAMPLE_QUINCUNX = 0x1121;
const int D3DMULTISAMPLE_2_SAMPLES_SUPERSAMPLE_HORIZONTAL_LINEAR = 0x2021;
const int D3DMULTISAMPLE_2_SAMPLES_SUPERSAMPLE_VERTICAL_LINEAR = 0x2012;
const int D3DMULTISAMPLE_4_SAMPLES_MULTISAMPLE_LINEAR = 0x1022;
const int D3DMULTISAMPLE_4_SAMPLES_MULTISAMPLE_GAUSSIAN = 0x1222;
const int D3DMULTISAMPLE_4_SAMPLES_SUPERSAMPLE_LINEAR = 0x2022;
const int D3DMULTISAMPLE_4_SAMPLES_SUPERSAMPLE_GAUSSIAN = 0x2222;
const int D3DMULTISAMPLE_9_SAMPLES_MULTISAMPLE_GAUSSIAN = 0x1233;
const int D3DMULTISAMPLE_9_SAMPLES_SUPERSAMPLE_GAUSSIAN = 0x2233;

struct D3DVertexBuffer //: public D3DResource
{
	D3DResource resource;

};
struct D3DIndexBuffer //: public D3DResource
{
	D3DResource resource;

};

struct D3DPushBuffer //: public D3DResource
{
	D3DResource resource;
    ULONG Size;
    ULONG AllocationSize;
};

struct D3DFixup //: public D3DResource
{
	D3DResource resource;
    ULONG Run;
    ULONG Next;
    ULONG Size;
};

struct D3DPalette //: public D3DResource
{
	D3DResource resource;
};

typedef enum _D3DPALETTESIZE
{
    D3DPALETTE_256              = 0,
    D3DPALETTE_128              = 1,
    D3DPALETTE_64               = 2,
    D3DPALETTE_32               = 3,
    D3DPALETTE_MAX              = 4,
    D3DPALETTE_FORCE_DWORD      = 0x7fffffff, /* force 32-bit size enum */
}
D3DPALETTESIZE;

struct D3DPixelContainer //: public D3DResource
{
	D3DResource resource;
    DWORD		Format; // Format information about the texture.
    DWORD       Size; // Size of a non power-of-2 texture, must be zero otherwise
};

// pixel container "format" masks
#define D3DFORMAT_RESERVED1_MASK        0x00000003      // Must be zero
#define D3DFORMAT_DMACHANNEL_MASK       0x00000003
#define D3DFORMAT_DMACHANNEL_A          0x00000001      // DMA channel A - the default for all system memory
#define D3DFORMAT_DMACHANNEL_B          0x00000002      // DMA channel B - unused
#define D3DFORMAT_CUBEMAP               0x00000004      // Set if the texture if a cube map
#define D3DFORMAT_BORDERSOURCE_COLOR    0x00000008      // If set, uses D3DTSS_BORDERCOLOR as a border
#define D3DFORMAT_DIMENSION_MASK        0x000000F0      // # of dimensions, must be 2 or 3
#define D3DFORMAT_DIMENSION_SHIFT       4
#define D3DFORMAT_FORMAT_MASK           0x0000FF00      // D3DFORMAT - See D3DFMT_* above
#define D3DFORMAT_FORMAT_SHIFT          8
#define D3DFORMAT_MIPMAP_MASK           0x000F0000      // # mipmap levels (always 1 for surfaces)
#define D3DFORMAT_MIPMAP_SHIFT          16
#define D3DFORMAT_USIZE_MASK            0x00F00000      // Log 2 of the U size of the base texture (only set for swizzled or compressed)
#define D3DFORMAT_USIZE_SHIFT           20
#define D3DFORMAT_VSIZE_MASK            0x0F000000      // Log 2 of the V size of the base texture (only set for swizzled or compressed)
#define D3DFORMAT_VSIZE_SHIFT           24
#define D3DFORMAT_PSIZE_MASK            0xF0000000      // Log 2 of the P size of the base texture (only set for swizzled or compressed)
#define D3DFORMAT_PSIZE_SHIFT           28

// pixel container "size" masks
// The layout of the size field, used for non swizzled or compressed textures.
//
// The Size field of a container will be zero if the texture is swizzled or compressed.
// It is guarenteed to be non-zero otherwise because either the height/width will be
// greater than one or the pitch adjust will be nonzero because the minimum texture
// pitch is 8 bytes.
#define D3DSIZE_WIDTH_MASK              0x00000FFF   // Width of the texture - 1, in texels
//#define D3DSIZE_WIDTH_SHIFT           0
#define D3DSIZE_HEIGHT_MASK             0x00FFF000   // Height of the texture - 1, in texels
#define D3DSIZE_HEIGHT_SHIFT            12
#define D3DSIZE_PITCH_MASK              0xFF000000   // Pitch / 64 - 1
#define D3DSIZE_PITCH_SHIFT             24


struct D3DBaseTexture // : public D3DPixelContainer
{
	D3DPixelContainer super;

};

struct D3DTexture // : public D3DBaseTexture
{
	D3DBaseTexture super;

};

struct D3DVolumeTexture // : public D3DBaseTexture
{
	D3DBaseTexture super;

};

struct D3DCubeTexture // : public D3DBaseTexture
{
	D3DBaseTexture super;

};

struct D3DVolume // : public D3DPixelContainer
{
	D3DPixelContainer super;
	D3DBaseTexture *Parent;
};

struct D3DSurface // : public D3DPixelContainer
{
	D3DPixelContainer super;
	D3DBaseTexture *Parent;
};

struct D3DTILE
{
    DWORD   Flags;
    PVOID   pMemory;
    DWORD   Size;
    DWORD   Pitch;
    DWORD   ZStartTag;
    DWORD   ZOffset;
};

typedef enum _D3DCALLBACKTYPE	// blueshogun96 10/1/07
{
	D3DCALLBACK_READ		= 0, // Fixed PatrickvL 10/7/22
	D3DCALLBACK_WRITE		= 1
}
D3DCALLBACKTYPE;

typedef enum _D3DFIELDTYPE
{
    D3DFIELD_ODD            = 1,
    D3DFIELD_EVEN           = 2,
    D3DFIELD_PROGRESSIVE    = 3,
    D3DFIELD_FORCE_DWORD    = 0x7fffffff
}
D3DFIELDTYPE;

typedef struct _D3DFIELD_STATUS
{
    D3DFIELDTYPE Field;
    UINT           VBlankCount;
}
D3DFIELD_STATUS;

typedef struct _D3DVBLANKDATA
{
    DWORD           VBlank;
    DWORD           Swap;
    DWORD           Flags;
}
D3DVBLANKDATA;

typedef struct _D3DSWAPDATA 
{
    DWORD           Swap;
    DWORD           SwapVBlank;
    DWORD           MissedVBlanks;
    DWORD           TimeUntilSwapVBlank;
    DWORD           TimeBetweenSwapVBlanks;
} 
D3DSWAPDATA;

// D3DVBLANKCALLBACK
typedef void (__cdecl * D3DVBLANKCALLBACK)(D3DVBLANKDATA *pData);

// D3DSWAPCALLBACK
typedef void (__cdecl * D3DSWAPCALLBACK)(D3DSWAPDATA *pData);

// D3DCALLBACK
typedef void (__cdecl * D3DCALLBACK)(DWORD Context);

// D3DRENDERSTATETYPE values
typedef enum _D3DRENDERSTATETYPE {

	// Dxbx note : These declarations are from XDK version 5933, the most recent and complete version.
	// Older versions are slightly different (some members are missing), so we use a mapping table to
	// cater for the differences (see XboxRenderStateConverter::BuildRenderStateMappingTable). This enables to ignore these
	// version-differences in the rest of our code (unless it matters somehow); We write like this :
	//   XboxRenderStates.SetXboxRenderState(D3DRENDERSTATETYPE, Value);
	//
	// And we read like this (do note, that missing elements all point to the same dummy) :
	//   Result = XboxRenderStates.GetXboxRenderState(D3DRENDERSTATETYPE);

	// Dxbx note : The PS* render states map 1-on-1 to the D3DPIXELSHADERDEF record,
	// SetPixelShader actually pushes the definition into these render state slots.
	// See DxbxUpdateActivePixelShader for how this is employed.

	// The set starts out with "pixel-shader" render states (all Xbox extensions) :
	D3DRS_PSALPHAINPUTS0 = 0,
	D3DRS_PSALPHAINPUTS1 = 1,
	D3DRS_PSALPHAINPUTS2 = 2,
	D3DRS_PSALPHAINPUTS3 = 3,
	D3DRS_PSALPHAINPUTS4 = 4,
	D3DRS_PSALPHAINPUTS5 = 5,
	D3DRS_PSALPHAINPUTS6 = 6,
	D3DRS_PSALPHAINPUTS7 = 7,
	D3DRS_PSFINALCOMBINERINPUTSABCD = 8,
	D3DRS_PSFINALCOMBINERINPUTSEFG = 9,
	D3DRS_PSCONSTANT0_0 = 10,
	D3DRS_PSCONSTANT0_1 = 11,
	D3DRS_PSCONSTANT0_2 = 12,
	D3DRS_PSCONSTANT0_3 = 13,
	D3DRS_PSCONSTANT0_4 = 14,
	D3DRS_PSCONSTANT0_5 = 15,
	D3DRS_PSCONSTANT0_6 = 16,
	D3DRS_PSCONSTANT0_7 = 17,
	D3DRS_PSCONSTANT1_0 = 18,
	D3DRS_PSCONSTANT1_1 = 19,
	D3DRS_PSCONSTANT1_2 = 20,
	D3DRS_PSCONSTANT1_3 = 21,
	D3DRS_PSCONSTANT1_4 = 22,
	D3DRS_PSCONSTANT1_5 = 23,
	D3DRS_PSCONSTANT1_6 = 24,
	D3DRS_PSCONSTANT1_7 = 25,
	D3DRS_PSALPHAOUTPUTS0 = 26,
	D3DRS_PSALPHAOUTPUTS1 = 27,
	D3DRS_PSALPHAOUTPUTS2 = 28,
	D3DRS_PSALPHAOUTPUTS3 = 29,
	D3DRS_PSALPHAOUTPUTS4 = 30,
	D3DRS_PSALPHAOUTPUTS5 = 31,
	D3DRS_PSALPHAOUTPUTS6 = 32,
	D3DRS_PSALPHAOUTPUTS7 = 33,
	D3DRS_PSRGBINPUTS0 = 34,
	D3DRS_PSRGBINPUTS1 = 35,
	D3DRS_PSRGBINPUTS2 = 36,
	D3DRS_PSRGBINPUTS3 = 37,
	D3DRS_PSRGBINPUTS4 = 38,
	D3DRS_PSRGBINPUTS5 = 39,
	D3DRS_PSRGBINPUTS6 = 40,
	D3DRS_PSRGBINPUTS7 = 41,
	D3DRS_PSCOMPAREMODE = 42,
	D3DRS_PSFINALCOMBINERCONSTANT0 = 43,
	D3DRS_PSFINALCOMBINERCONSTANT1 = 44,
	D3DRS_PSRGBOUTPUTS0 = 45,
	D3DRS_PSRGBOUTPUTS1 = 46,
	D3DRS_PSRGBOUTPUTS2 = 47,
	D3DRS_PSRGBOUTPUTS3 = 48,
	D3DRS_PSRGBOUTPUTS4 = 49,
	D3DRS_PSRGBOUTPUTS5 = 50,
	D3DRS_PSRGBOUTPUTS6 = 51,
	D3DRS_PSRGBOUTPUTS7 = 52,
	D3DRS_PSCOMBINERCOUNT = 53,
	D3DRS_PS_RESERVED = 54, // Dxbx note : This takes the slot of D3DPIXELSHADERDEF.PSTextureModes, set by D3DDevice_SetRenderState_LogicOp?
	D3DRS_PSDOTMAPPING = 55,
	D3DRS_PSINPUTTEXTURE = 56,
	// End of "pixel-shader" render states, continuing with "simple" render states :
	D3DRS_ZFUNC = 57, // D3DCMPFUNC
	D3DRS_ALPHAFUNC = 58, // D3DCMPFUNC
	D3DRS_ALPHABLENDENABLE = 59, // TRUE to enable alpha blending
	D3DRS_ALPHATESTENABLE = 60, // TRUE to enable alpha tests
	D3DRS_ALPHAREF = 61, // BYTE
	D3DRS_SRCBLEND = 62, // D3DBLEND
	D3DRS_DESTBLEND = 63, // D3DBLEND
	D3DRS_ZWRITEENABLE = 64, // TRUE to enable Z writes
	D3DRS_DITHERENABLE = 65, // TRUE to enable dithering
	D3DRS_SHADEMODE = 66, // D3DSHADEMODE
	D3DRS_COLORWRITEENABLE = 67, // D3DCOLORWRITEENABLE_ALPHA, etc. per-channel write enable
	D3DRS_STENCILZFAIL = 68, // D3DSTENCILOP to do if stencil test passes and Z test fails
	D3DRS_STENCILPASS = 69, // D3DSTENCILOP to do if both stencil and Z tests pass
	D3DRS_STENCILFUNC = 70, // D3DCMPFUNC
	D3DRS_STENCILREF = 71, // BYTE reference value used in stencil test
	D3DRS_STENCILMASK = 72, // BYTE mask value used in stencil test
	D3DRS_STENCILWRITEMASK = 73, // BYTE write mask applied to values written to stencil buffer
	D3DRS_BLENDOP = 74, // D3DBLENDOP setting
	D3DRS_BLENDCOLOR = 75, // D3DCOLOR for D3DBLEND_CONSTANTCOLOR
	D3DRS_SWATHWIDTH = 76, // D3DSWATHWIDTH (Xbox ext.)
	D3DRS_POLYGONOFFSETZSLOPESCALE = 77, // float Z factor for shadow maps (Xbox ext.)
	D3DRS_POLYGONOFFSETZOFFSET = 78, // Xbox ext.
	D3DRS_POINTOFFSETENABLE = 79, // Xbox ext.
	D3DRS_WIREFRAMEOFFSETENABLE = 80, // Xbox ext.
	D3DRS_SOLIDOFFSETENABLE = 81, // Xbox ext.
	D3DRS_DEPTHCLIPCONTROL = 82, // [4432+] Xbox ext.
	D3DRS_STIPPLEENABLE = 83, // [4627+] Xbox ext.
	D3DRS_SIMPLE_UNUSED8 = 84, // [4627+]
	D3DRS_SIMPLE_UNUSED7 = 85, // [4627+]
	D3DRS_SIMPLE_UNUSED6 = 86, // [4627+]
	D3DRS_SIMPLE_UNUSED5 = 87, // [4627+]
	D3DRS_SIMPLE_UNUSED4 = 88, // [4627+]
	D3DRS_SIMPLE_UNUSED3 = 89, // [4627+]
	D3DRS_SIMPLE_UNUSED2 = 90, // [4627+]
	D3DRS_SIMPLE_UNUSED1 = 91, // [4627+]
	// End of "simple" render states, continuing with "deferred" render states :
	D3DRS_FOGENABLE = 92,
	D3DRS_FOGTABLEMODE = 93,
	D3DRS_FOGSTART = 94,
	D3DRS_FOGEND = 95,
	D3DRS_FOGDENSITY = 96,
	D3DRS_RANGEFOGENABLE = 97,
	D3DRS_WRAP0 = 98,
	D3DRS_WRAP1 = 99,
	D3DRS_WRAP2 = 100, // Dxbx addition
	D3DRS_WRAP3 = 101, // Dxbx addition
	D3DRS_LIGHTING = 102,
	D3DRS_SPECULARENABLE = 103,
	D3DRS_LOCALVIEWER = 104, // Dxbx addition
	D3DRS_COLORVERTEX = 105,
	D3DRS_BACKSPECULARMATERIALSOURCE = 106, // Xbox ext. nsp.
	D3DRS_BACKDIFFUSEMATERIALSOURCE = 107, // Xbox ext. nsp.
	D3DRS_BACKAMBIENTMATERIALSOURCE = 108, // Xbox ext. nsp.
	D3DRS_BACKEMISSIVEMATERIALSOURCE = 109, // Xbox ext. nsp.
	D3DRS_SPECULARMATERIALSOURCE = 110,
	D3DRS_DIFFUSEMATERIALSOURCE = 111,
	D3DRS_AMBIENTMATERIALSOURCE = 112,
	D3DRS_EMISSIVEMATERIALSOURCE = 113,
	D3DRS_BACKAMBIENT = 114, // Xbox ext. nsp.
	D3DRS_AMBIENT = 115,
	D3DRS_POINTSIZE = 116,
	D3DRS_POINTSIZE_MIN = 117,
	D3DRS_POINTSPRITEENABLE = 118,
	D3DRS_POINTSCALEENABLE = 119,
	D3DRS_POINTSCALE_A = 120,
	D3DRS_POINTSCALE_B = 121,
	D3DRS_POINTSCALE_C = 122,
	D3DRS_POINTSIZE_MAX = 123,
	D3DRS_PATCHEDGESTYLE = 124, // Dxbx addition
	D3DRS_PATCHSEGMENTS = 125,
	D3DRS_SWAPFILTER = 126, // [4039+] Xbox ext. nsp. D3DTEXF_LINEAR etc. filter to use for Swap
	D3DRS_PRESENTATIONINTERVAL = 127, // [4627+] Xbox ext. nsp. TODO : Use 4361?
	D3DRS_DEFERRED_UNUSED8 = 128, // [4627+]
	D3DRS_DEFERRED_UNUSED7 = 129, // [4627+]
	D3DRS_DEFERRED_UNUSED6 = 130, // [4627+]
	D3DRS_DEFERRED_UNUSED5 = 131, // [4627+]
	D3DRS_DEFERRED_UNUSED4 = 132, // [4627+]
	D3DRS_DEFERRED_UNUSED3 = 133, // [4627+]
	D3DRS_DEFERRED_UNUSED2 = 134, // [4627+]
	D3DRS_DEFERRED_UNUSED1 = 135, // [4627+]
	// End of "deferred" render states, continuing with "complex" render states :
	D3DRS_PSTEXTUREMODES = 136, // Xbox ext.
	D3DRS_VERTEXBLEND = 137,
	D3DRS_FOGCOLOR = 138,
	D3DRS_FILLMODE = 139,
	D3DRS_BACKFILLMODE = 140, // Dxbx addition : Xbox ext. nsp.
	D3DRS_TWOSIDEDLIGHTING = 141, // Dxbx addition : Xbox ext. nsp.
	D3DRS_NORMALIZENORMALS = 142,
	D3DRS_ZENABLE = 143,
	D3DRS_STENCILENABLE = 144,
	D3DRS_STENCILFAIL = 145,
	D3DRS_FRONTFACE = 146, // Dxbx addition : Xbox ext. nsp.
	D3DRS_CULLMODE = 147,
	D3DRS_TEXTUREFACTOR = 148,
	D3DRS_ZBIAS = 149,
	D3DRS_LOGICOP = 150, // Xbox ext. nsp.
	D3DRS_EDGEANTIALIAS = 151, // Dxbx note : No Xbox ext. (according to Direct3D8) !
	D3DRS_MULTISAMPLEANTIALIAS = 152,
	D3DRS_MULTISAMPLEMASK = 153,
	D3DRS_MULTISAMPLETYPE = 154, // [-4039] Xbox ext.
	// Note : D3DRS_MULTISAMPLETYPE seems the only one that got removed, but it does need a slot, so the rest is increased by 1 compared to 5933.
	D3DRS_MULTISAMPLEMODE = 155, // [4361+] Xbox ext. // D3DMULTISAMPLEMODE for the backbuffer
	D3DRS_MULTISAMPLERENDERTARGETMODE = 156, // [4039+] Xbox ext.
	D3DRS_SHADOWFUNC = 157, // D3DCMPFUNC (Xbox extension)
	D3DRS_LINEWIDTH = 158, // Xbox ext.
	D3DRS_SAMPLEALPHA = 159, // Xbox ext.
	D3DRS_DXT1NOISEENABLE = 160, // Xbox ext.
	D3DRS_YUVENABLE = 161, // [3911+] Xbox ext.
	D3DRS_OCCLUSIONCULLENABLE = 162, // [3911+] Xbox ext.
	D3DRS_STENCILCULLENABLE = 163, // [3911+] Xbox ext.
	D3DRS_ROPZCMPALWAYSREAD = 164, // [3911+] Xbox ext.
	D3DRS_ROPZREAD = 165, // [3911+] Xbox ext.
	D3DRS_DONOTCULLUNCOMPRESSED = 166, // [3911+] Xbox ext.
	// End of "complex" render states.
	D3DRS_UNK = 0x7fffffff // deferred render state "unknown" flag
} D3DRENDERSTATETYPE;

// Render state boundaries :

#define D3DRS_PS_FIRST D3DRS_PSALPHAINPUTS0
#define D3DRS_PS_LAST D3DRS_PSINPUTTEXTURE

#define D3DRS_SIMPLE_FIRST D3DRS_ZFUNC
#define D3DRS_SIMPLE_LAST D3DRS_SIMPLE_UNUSED1

#define D3DRS_DEFERRED_FIRST D3DRS_FOGENABLE
#define D3DRS_DEFERRED_LAST D3DRS_DEFERRED_UNUSED1

#define D3DRS_COMPLEFIRST D3DRS_PSTEXTUREMODES
#define D3DRS_COMPLELAST D3DRS_DONOTCULLUNCOMPRESSED

#define D3DRS_FIRST D3DRS_PS_FIRST
#define D3DRS_LAST D3DRS_COMPLELAST

// D3DWRAP values :
// constexpr DWORD D3DWRAP_U = 0x00000010;
// constexpr DWORD D3DWRAP_V = 0x00001000;
// constexpr DWORD D3DWRAP_W = 0x00100000;

// D3DTEXTURESTAGESTATETYPE values :
// Dxbx note : See DxbxFromOldVersion_D3DTSS(), as these might need correction for older SDK versions!
// The set starts out with "deferred" texture states :
// constexpr DWORD D3DTSS_ADDRESSU = 0;
// constexpr DWORD D3DTSS_ADDRESSV = 1;
// constexpr DWORD D3DTSS_ADDRESSW = 2;
// constexpr DWORD D3DTSS_MAGFILTER = 3;
// constexpr DWORD D3DTSS_MINFILTER = 4;
// constexpr DWORD D3DTSS_MIPFILTER = 5;
// constexpr DWORD D3DTSS_MIPMAPLODBIAS = 6;
// constexpr DWORD D3DTSS_MAXMIPLEVEL = 7;
// constexpr DWORD D3DTSS_MAXANISOTROPY = 8;
// constexpr DWORD D3DTSS_COLORKEYOP = 9; // Xbox ext.
// constexpr DWORD D3DTSS_COLORSIGN = 10; // Xbox ext.
// constexpr DWORD D3DTSS_ALPHAKILL = 11; // Xbox ext.
// constexpr DWORD D3DTSS_COLOROP = 12;
// constexpr DWORD D3DTSS_COLORARG0 = 13;
// constexpr DWORD D3DTSS_COLORARG1 = 14;
// constexpr DWORD D3DTSS_COLORARG2 = 15;
// constexpr DWORD D3DTSS_ALPHAOP = 16;
// constexpr DWORD D3DTSS_ALPHAARG0 = 17;
// constexpr DWORD D3DTSS_ALPHAARG1 = 18;
// constexpr DWORD D3DTSS_ALPHAARG2 = 19;
// constexpr DWORD D3DTSS_RESULTARG = 20;
// constexpr DWORD D3DTSS_TEXTURETRANSFORMFLAGS = 21;
// End of "deferred" texture states, continuing with the rest :
// constexpr DWORD D3DTSS_BUMPENVMAT00 = 22;
// constexpr DWORD D3DTSS_BUMPENVMAT01 = 23;
// constexpr DWORD D3DTSS_BUMPENVMAT11 = 24;
// constexpr DWORD D3DTSS_BUMPENVMAT10 = 25;
// constexpr DWORD D3DTSS_BUMPENVLSCALE = 26;
// constexpr DWORD D3DTSS_BUMPENVLOFFSET = 27;
// constexpr DWORD D3DTSS_TEXCOORDINDEX = 28;
// constexpr DWORD D3DTSS_BORDERCOLOR = 29;
// constexpr DWORD D3DTSS_COLORKEYCOLOR = 30; // Xbox ext.
// constexpr DWORD D3DTSS_UNSUPPORTED = 31; // Note : Somehow, this one comes through D3DDevice_SetTextureStageStateNotInline sometimes
// End of texture states.

// Texture state boundaries :

// constexpr DWORD D3DTSS_DEFERRED_FIRST = D3DTSS_ADDRESSU;
// constexpr DWORD D3DTSS_DEFERRED_LAST = D3DTSS_TEXTURETRANSFORMFLAGS;

// constexpr DWORD D3DTSS_FIRST = D3DTSS_ADDRESSU;
// constexpr DWORD D3DTSS_LAST = D3DTSS_COLORKEYCOLOR;

// constexpr DWORD D3DTS_STAGECOUNT = 4; // Dxbx addition
// constexpr DWORD D3DTS_STAGESIZE = 32; // Dxbx addition

// constexpr DWORD PSH_COMBINECOUNT = 8; // Dxbx addition
// constexpr DWORD PSH_CONSTANTCOUNT = 8; // Dxbx addition

// D3DTEXTUREOP values :
// constexpr DWORD D3DTOP_DISABLE = 1;
// constexpr DWORD D3DTOP_SELECTARG1 = 2;
// constexpr DWORD D3DTOP_SELECTARG2 = 3;
// constexpr DWORD D3DTOP_MODULATE = 4;
// constexpr DWORD D3DTOP_MODULATE2X = 5;
// constexpr DWORD D3DTOP_MODULATE4X = 6;
// constexpr DWORD D3DTOP_ADD = 7;
// constexpr DWORD D3DTOP_ADDSIGNED = 8;
// constexpr DWORD D3DTOP_ADDSIGNED2X = 9;
// constexpr DWORD D3DTOP_SUBTRACT = 10;
// constexpr DWORD D3DTOP_ADDSMOOTH = 11;
// constexpr DWORD D3DTOP_BLENDDIFFUSEALPHA = 12;
// constexpr DWORD D3DTOP_BLENDCURRENTALPHA = 13;
// constexpr DWORD D3DTOP_BLENDTEXTUREALPHA = 14;
// constexpr DWORD D3DTOP_BLENDFACTORALPHA = 15;
// constexpr DWORD D3DTOP_BLENDTEXTUREALPHAPM = 16;
// constexpr DWORD D3DTOP_PREMODULATE = 17;
// constexpr DWORD D3DTOP_MODULATEALPHA_ADDCOLOR = 18;
// constexpr DWORD D3DTOP_MODULATECOLOR_ADDALPHA = 19;
// constexpr DWORD D3DTOP_MODULATEINVALPHA_ADDCOLOR = 20;
// constexpr DWORD D3DTOP_MODULATEINVCOLOR_ADDALPHA = 21;
// constexpr DWORD D3DTOP_DOTPRODUCT3 = 22;
// constexpr DWORD D3DTOP_MULTIPLYADD = 23;
// constexpr DWORD D3DTOP_LERP = 24;
// constexpr DWORD D3DTOP_BUMPENVMAP = 25;
// constexpr DWORD D3DTOP_BUMPENVMAPLUMINANCE = 26;

// constexpr DWORD D3DTOP_FIRST = D3DTOP_DISABLE;
// constexpr DWORD D3DTOP_LAST = D3DTOP_BUMPENVMAPLUMINANCE;

// D3DTEXTUREADDRESS values :
// constexpr DWORD D3DTADDRESS_WRAP = 1;
// constexpr DWORD D3DTADDRESS_MIRROR = 2;
// constexpr DWORD D3DTADDRESS_CLAMP = 3;
// constexpr DWORD D3DTADDRESS_BORDER = 4;
// constexpr DWORD D3DTADDRESS_CLAMPTOEDGE = 5;

// D3DTEXTUREFILTERTYPE Values
// constexpr DWORD D3DTEXF_NONE = 0;
// constexpr DWORD D3DTEXF_POINT = 1;
// constexpr DWORD D3DTEXF_LINEAR = 2;
// constexpr DWORD D3DTEXF_ANISOTROPIC = 3;
// constexpr DWORD D3DTEXF_QUINCUNX = 4; // Xbox extension
// constexpr DWORD D3DTEXF_GAUSSIANCUBIC = 5;

// D3DCLEAR values :
// constexpr DWORD D3DCLEAR_ZBUFFER = 0x00000001;
// constexpr DWORD D3DCLEAR_STENCIL = 0x00000002;
// constexpr DWORD D3DCLEAR_TARGET_R = 0x00000010;  // Clear target surface R component (Xbox ext.)
// constexpr DWORD D3DCLEAR_TARGET_G = 0x00000020;  // Clear target surface G component (Xbox ext.)
// constexpr DWORD D3DCLEAR_TARGET_B = 0x00000040;  // Clear target surface B component (Xbox ext.)
// constexpr DWORD D3DCLEAR_TARGET_A = 0x00000080;  // Clear target surface A component (Xbox ext.)
// constexpr DWORD D3DCLEAR_TARGET = D3DCLEAR_TARGET_R | D3DCLEAR_TARGET_G | D3DCLEAR_TARGET_B | D3DCLEAR_TARGET_A;

// D3DCOLORWRITEENABLE values :
// constexpr DWORD D3DCOLORWRITEENABLE_RED = (1 << 16);
// constexpr DWORD D3DCOLORWRITEENABLE_GREEN = (1 << 8);
// constexpr DWORD D3DCOLORWRITEENABLE_BLUE = (1 << 0);
// constexpr DWORD D3DCOLORWRITEENABLE_ALPHA = (1 << 24);
// constexpr DWORD D3DCOLORWRITEENABLE_ALL = 0x01010101; // Xbox ext.

// deferred texture stage state "unknown" flag
#define D3DTSS_UNK 0x7fffffff

typedef DWORD VERTEXSHADERCONSTANTMODE;

// Xbox vertex shader constant modes
#define D3DSCM_96CONSTANTS                  0x00 // Enables constants 0..95
#define D3DSCM_192CONSTANTS                 0x01 // Enables constants -96..-1 on top of 0..95
#define D3DSCM_192CONSTANTSANDFIXEDPIPELINE 0x02 // Unsupported?
#define D3DSCM_NORESERVEDCONSTANTS          0x10  // Do not reserve constant -38 and -37

#define D3DSCM_RESERVED_CONSTANT_SCALE -38 // Becomes 58 after correction, contains Scale v
#define D3DSCM_RESERVED_CONSTANT_OFFSET -37 // Becomes 59 after correction, contains Offset

#define D3DSCM_CORRECTION                 96 // Add 96 to arrive at the range 0..191 (instead of -96..95)
#define D3DVS_CONSTREG_COUNT              192

// Special Registers, used to pass additional information to the shaders
// TODO co-locate shader workaround constants with shader code
#define CXBD3DVS_CONSTREG_VERTEXDATA4F_BASE      (D3DVS_CONSTREG_COUNT)
#define CXBD3DVS_CONSTREG_VERTEXDATA4F_FLAG_BASE (CXBD3DVS_CONSTREG_VERTEXDATA4F_BASE + 16)
#define CXBD3DVS_VIEWPORT_SCALE_MIRROR           (CXBD3DVS_CONSTREG_VERTEXDATA4F_FLAG_BASE + 4)
#define CXBD3DVS_VIEWPORT_OFFSET_MIRROR          (CXBD3DVS_VIEWPORT_SCALE_MIRROR + 1)

#define D3DSCM_RESERVED_CONSTANT_SCALE_CORRECTED (D3DSCM_RESERVED_CONSTANT_SCALE + D3DSCM_CORRECTION)
#define D3DSCM_RESERVED_CONSTANT_OFFSET_CORRECTED (D3DSCM_RESERVED_CONSTANT_OFFSET + D3DSCM_CORRECTION)

// Xbox vertex declaration token bit masks
#define D3DVSD_MASK_TESSUV 0x10000000
#define D3DVSD_MASK_SKIP 0x10000000 // Skips (normally) dwords
#define D3DVSD_MASK_SKIPBYTES 0x08000000 // Skips bytes (no, really?!)
#define D3DVSD_STREAMTESSMASK (1 << 28)

// Xbox vertex shader types
#define VST_NORMAL                  1
#define VST_READWRITE               2
#define VST_STATE                   3

// Xbox vertex shader counts
#define VSH_MAATTRIBUTES           16
#define VSH_MASTREAMS              16
#define VSH_MAINSTRUCTION_COUNT    136  // The maximum Xbox shader instruction count

// Xbox Vertex Shader versions
#define VERSION_XVS                    0x2078 // 'x ' Xbox vertex shader
#define VERSION_XVSS                   0x7378 // 'xs' Xbox vertex state shader
#define VERSION_XVSW                   0x7778 // 'xw' Xbox vertex read/write shader

/// nv2a microcode header
typedef struct
{
	uint16_t Version; // See VERSION_XVS*
	uint16_t NumInst;
}
VSH_SHADER_HEADER;

#define VSH_INSTRUCTION_SIZE       4
#define VSH_INSTRUCTION_SIZE_BYTES (VSH_INSTRUCTION_SIZE * sizeof(DWORD))

// ******************************************************************
// * VERTEXSHADERINPUT
// ******************************************************************
typedef struct _VERTEXSHADERINPUT
{
    DWORD IndexOfStream;
    DWORD Offset;
    DWORD Format;
    BYTE  TesselationType;
    BYTE  TesselationSource;
}
VERTEXSHADERINPUT;

// ******************************************************************
// * VERTEXATTRIBUTEFORMAT
// ******************************************************************
typedef struct _VERTEXATTRIBUTEFORMAT
{
	// Note : Alignment looks okay even without #pragma pack(1) / #include "AlignPrefix1.h" (and it's closure)
    VERTEXSHADERINPUT Slots[VSH_MAATTRIBUTES];
}
VERTEXATTRIBUTEFORMAT;

// ******************************************************************
// * STREAMINPUT
// ******************************************************************
typedef struct _STREAMINPUT
{
    D3DVertexBuffer  *VertexBuffer;
    UINT                Stride;
    UINT                Offset;
} STREAMINPUT;

struct D3DVertexShader
{
	// Note : Debug XBE's have a 'Vshd' DWORD signature prefixing this!
	DWORD RefCount; // Based on the observation this member is set to 1 in D3DDevice_CreateVertexShader and decreased in D3DDevice_DeleteVertexShader
	DWORD Flags;
	DWORD FunctionSize; // ?Also known as ProgramSize?
	DWORD TotalSize; // seems to include both the function and ?constants?
	DWORD NumberOfDimensionsPerTexture; // Guesswork, since all 4 bytes (for all 4 textures) are most often set to 0 (or 2 when a texture isn't used) and 1, 3 and 4 also occur (and nothing else)
	VERTEXATTRIBUTEFORMAT VertexAttribute;
	DWORD FunctionData[VSH_MAINSTRUCTION_COUNT]; // probably the binary function data and ?constants? (data continues futher outside this struct, up to TotalSize DWORD's)
};

// vertex shader input registers for fixed function vertex shader

//          Name                   Register number      D3DFVF
const int D3DVSDE_POSITION     = 0; // Corresponds to D3DFVF_XYZ
const int D3DVSDE_BLENDWEIGHT  = 1; // Corresponds to D3DFVF_XYZRHW
const int D3DVSDE_NORMAL       = 2; // Corresponds to D3DFVF_NORMAL
const int D3DVSDE_DIFFUSE      = 3; // Corresponds to D3DFVF_DIFFUSE
const int D3DVSDE_SPECULAR     = 4; // Corresponds to D3DFVF_SPECULAR
const int D3DVSDE_FOG          = 5; // Xbox extension
const int D3DVSDE_POINTSIZE    = 6; // Dxbx addition
const int D3DVSDE_BACKDIFFUSE  = 7; // Xbox extension
const int D3DVSDE_BACKSPECULAR = 8; // Xbox extension
const int D3DVSDE_TEXCOORD0    = 9; // Corresponds to D3DFVF_TEX1 (not D3DFVF_TEX0, which means no textures are present)
const int D3DVSDE_TEXCOORD1    = 10; // Corresponds to D3DFVF_TEX2
const int D3DVSDE_TEXCOORD2    = 11; // Corresponds to D3DFVF_TEX3
const int D3DVSDE_TEXCOORD3    = 12; // Corresponds to D3DFVF_TEX4
const int D3DVSDE_VERTEX       = 0xFFFFFFFF; // Xbox extension for Begin/End drawing (data is a D3DVSDT_FLOAT4)

//typedef D3DVSDE = D3DVSDE_POSITION..High(DWORD)-2; // Unique declaration to make overloads possible;

// bit declarations for _Type fields
const int D3DVSDT_FLOAT1      = 0x12; // 1D float expanded to (value, 0.0, 0.0, 1.0)
const int D3DVSDT_FLOAT2      = 0x22; // 2D float expanded to (value, value, 0.0, 1.0)
const int D3DVSDT_FLOAT3      = 0x32; // 3D float expanded to (value, value, value, 1.0) In double word format this is ARGB, or in byte ordering it would be B, G, R, A.
const int D3DVSDT_FLOAT4      = 0x42; // 4D float
const int D3DVSDT_D3DCOLOR    = 0x40; // 4D packed unsigned bytes mapped to 0.0 to 1.0 range
//const int D3DVSDT_UBYTE4      = 0x05; // 4D unsigned byte   Dxbx note : Not supported on Xbox ?
const int D3DVSDT_SHORT2      = 0x25; // 2D signed short expanded to (value, value, 0.0, 1.0)
const int D3DVSDT_SHORT4      = 0x45; // 4D signed short

//  Xbox only declarations :
const int D3DVSDT_NORMSHORT1  = 0x11; // xbox ext. 1D signed, normalized short expanded to (value, 0.0, 0.0, 1.0). Signed, normalized shorts map from -1.0 to 1.0.
const int D3DVSDT_NORMSHORT2  = 0x21; // xbox ext. 2D signed, normalized short expanded to (value, value, 0.0, 1.0). Signed, normalized shorts map from -1.0 to 1.0.
const int D3DVSDT_NORMSHORT3  = 0x31; // xbox ext. 3D signed, normalized short expanded to (value, value, value, 1.0). Signed, normalized shorts map from -1.0 to 1.0.
const int D3DVSDT_NORMSHORT4  = 0x41; // xbox ext. 4D signed, normalized short expanded to (value, value, value, value). Signed, normalized shorts map from -1.0 to 1.0.
const int D3DVSDT_NORMPACKED3 = 0x16; // xbox ext. Three signed, normalized components packed in 32-bits. (11,11,10). Each component ranges from -1.0 to 1.0. Expanded to (value, value, value, 1.0).
const int D3DVSDT_SHORT1      = 0x15; // xbox ext. 1D signed short expanded to (value, 0., 0., 1). Signed shorts map to the range [-32768, 32767].
const int D3DVSDT_SHORT3      = 0x35; // xbox ext. 3D signed short expanded to (value, value, value, 1). Signed shorts map to the range [-32768, 32767].
const int D3DVSDT_PBYTE1      = 0x14; // xbox ext. 1D packed byte expanded to (value, 0., 0., 1). Packed bytes map to the range [0, 1].
const int D3DVSDT_PBYTE2      = 0x24; // xbox ext. 2D packed byte expanded to (value, value, 0., 1). Packed bytes map to the range [0, 1].
const int D3DVSDT_PBYTE3      = 0x34; // xbox ext. 3D packed byte expanded to (value, value, value, 1). Packed bytes map to the range [0, 1].
const int D3DVSDT_PBYTE4      = 0x44; // xbox ext. 4D packed byte expanded to (value, value, value, value). Packed bytes map to the range [0, 1].
const int D3DVSDT_FLOAT2H     = 0x72; // xbox ext. 3D float that expands to (value, value, 0.0, value). Useful for projective texture coordinates.
const int D3DVSDT_NONE        = 0x02; // xbox ext. nsp

typedef enum _D3DVSD_TOKENTYPE
{
	D3DVSD_TOKEN_NOP = 0,           // NOP or extension
	D3DVSD_TOKEN_STREAM,            // stream selector
	D3DVSD_TOKEN_STREAMDATA,        // stream data definition (map to vertex input memory)
	D3DVSD_TOKEN_TESSELLATOR,       // vertex input memory from tessellator
	D3DVSD_TOKEN_CONSTMEM,          // constant memory from shader
	D3DVSD_TOKEN_EXT,               // extension
	D3DVSD_TOKEN_END = 7,           // end-of-array (requires all DWORD bits to be 1)
	D3DVSD_FORCE_DWORD = 0x7fffffff,// force 32-bit size enum
} D3DVSD_TOKENTYPE;

#define D3DVSD_TOKENTYPESHIFT   29
#define D3DVSD_TOKENTYPEMASK    (7 << D3DVSD_TOKENTYPESHIFT)

#define D3DVSD_STREAMNUMBERSHIFT 0
#define D3DVSD_STREAMNUMBERMASK (0xF << D3DVSD_STREAMNUMBERSHIFT)

#define D3DVSD_DATALOADTYPESHIFT 28
#define D3DVSD_DATALOADTYPEMASK (0x1 << D3DVSD_DATALOADTYPESHIFT)

#define D3DVSD_DATATYPESHIFT 16
#define D3DVSD_DATATYPEMASK (0xFF << D3DVSD_DATATYPESHIFT)

#define D3DVSD_SKIPCOUNTSHIFT 16
#define D3DVSD_SKIPCOUNTMASK (0xF << D3DVSD_SKIPCOUNTSHIFT)

#define D3DVSD_VERTEXREGSHIFT 0
#define D3DVSD_VERTEXREGMASK (0x1F << D3DVSD_VERTEXREGSHIFT)

#define D3DVSD_VERTEXREGINSHIFT 20
#define D3DVSD_VERTEXREGINMASK (0xF << D3DVSD_VERTEXREGINSHIFT)

#define D3DVSD_CONSTCOUNTSHIFT 25
#define D3DVSD_CONSTCOUNTMASK (0xF << D3DVSD_CONSTCOUNTSHIFT)

#define D3DVSD_CONSTADDRESSSHIFT 0
#define D3DVSD_CONSTADDRESSMASK (0xFF << D3DVSD_CONSTADDRESSSHIFT)

#define D3DVSD_CONSTRSSHIFT 16
#define D3DVSD_CONSTRSMASK (0x1FFF << D3DVSD_CONSTRSSHIFT)

#define D3DVSD_EXTCOUNTSHIFT 24
#define D3DVSD_EXTCOUNTMASK (0x1F << D3DVSD_EXTCOUNTSHIFT)

#define D3DVSD_EXTINFOSHIFT 0
#define D3DVSD_EXTINFOMASK (0xFFFFFF << D3DVSD_EXTINFOSHIFT)

#define D3DVSD_MAKETOKENTYPE(Type) ((Type << D3DVSD_TOKENTYPESHIFT) & D3DVSD_TOKENTYPEMASK)

#define D3DVSD_STREAM(Stream) (D3DVSD_MAKETOKENTYPE(D3DVSD_TOKEN_STREAM) | (Stream))
#define D3DVSD_REG(Reg, Type) (D3DVSD_MAKETOKENTYPE(D3DVSD_TOKEN_STREAMDATA) | ((Type) << D3DVSD_DATATYPESHIFT) | (Reg))

#define D3DVSD_NOP() 0x00000000
#define D3DVSD_END() 0xFFFFFFFF

// FVF Definitions
#define D3DFVF_RESERVED0        0x001
#define D3DFVF_XYZ              0x002
#define D3DFVF_XYZRHW           0x004
#define D3DFVF_XYZB1            0x006
#define D3DFVF_XYZB2            0x008
#define D3DFVF_XYZB3            0x00a
#define D3DFVF_XYZB4            0x00c
#define D3DFVF_POSITION_MASK    0x00E
#define D3DFVF_NORMAL           0x010
#define D3DFVF_RESERVED1        0x020
#define D3DFVF_DIFFUSE          0x040
#define D3DFVF_SPECULAR         0x080
#define D3DFVF_TEXCOUNT_MASK    0xf00
#define D3DFVF_TEXCOUNT_SHIFT   8
#define D3DFVF_TEX0             0x000
#define D3DFVF_TEX1             0x100
#define D3DFVF_TEX2             0x200
#define D3DFVF_TEX3             0x300
#define D3DFVF_TEX4             0x400
#define D3DFVF_TEX5             0x500
#define D3DFVF_TEX6             0x600
#define D3DFVF_TEX7             0x700
#define D3DFVF_TEX8             0x800
#define D3DFVF_TEXTUREFORMAT1   0x003
#define D3DFVF_TEXTUREFORMAT2   0x000
#define D3DFVF_TEXTUREFORMAT3   0x001
#define D3DFVF_TEXTUREFORMAT4   0x002

#define D3DFVF_TEXCOORDSIZE1(Index) (D3DFVF_TEXTUREFORMAT1 << (Index * 2 + 16))
#define D3DFVF_TEXCOORDSIZE2(Index) (D3DFVF_TEXTUREFORMAT2)
#define D3DFVF_TEXCOORDSIZE3(Index) (D3DFVF_TEXTUREFORMAT3 << (Index * 2 + 16))
#define D3DFVF_TEXCOORDSIZE4(Index) (D3DFVF_TEXTUREFORMAT4 << (Index * 2 + 16))

typedef DWORD NV2AMETHOD;

#endif
