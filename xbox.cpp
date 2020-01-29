#ifdef TEST_COMPILE
#define _cdecl
#define __cdecl
#define __stdcall
#define __fastcall
#endif
#define __declspec(x)

typedef unsigned short uint16_t;
typedef unsigned int uint32_t;

#include <xboxkrnl.h>
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
