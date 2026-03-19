#include "DoubleBuffering.h"
static HANDLE g_hScreen[2];
static int g_ScreenIndex = 0;


void ScreenPrintUI(SHORT x, SHORT y,const char* _String)
{
	DWORD dw = 0;
	COORD Pos = { x,y };
	SetConsoleCursorPosition(g_hScreen[g_ScreenIndex], Pos);
	WriteFile(g_hScreen[g_ScreenIndex],_String,strlen(_String),&dw,NULL);
}
void ScreenFlipping()
{
	SetConsoleActiveScreenBuffer(g_hScreen[g_ScreenIndex]);
	g_ScreenIndex = !g_ScreenIndex;
}
void ScereenInit()
{
    g_hScreen[0] = CreateConsoleScreenBuffer(
        GENERIC_READ | GENERIC_WRITE,
        0, NULL,
        CONSOLE_TEXTMODE_BUFFER, NULL);

    g_hScreen[1] = CreateConsoleScreenBuffer(
        GENERIC_READ | GENERIC_WRITE,
        0, NULL,
        CONSOLE_TEXTMODE_BUFFER, NULL);

    COORD size = { DF_BG_SIZE_X, DF_BG_SIZE_Y };
    SetConsoleScreenBufferSize(g_hScreen[0], size);
    SetConsoleScreenBufferSize(g_hScreen[1], size);

    CONSOLE_CURSOR_INFO cci;
    cci.dwSize = 1;
    cci.bVisible = FALSE;

    SetConsoleCursorInfo(g_hScreen[0], &cci);
    SetConsoleCursorInfo(g_hScreen[1], &cci);
}
void ScreenClear()
{
	DWORD dw = 0;
	FillConsoleOutputCharacter(
		g_hScreen[g_ScreenIndex],' ',
		DF_BG_SIZE_X * DF_BG_SIZE_Y,
		COORD{ 0, 0 }, &dw);

}