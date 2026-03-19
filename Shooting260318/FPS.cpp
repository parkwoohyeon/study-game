#include <Windows.h>
#include "FPS.h"

static int m_Fps = 0;
static int m_FpsCount = 0;
static int m_StartTick = GetTickCount64(); //현재 시간
int GetFPS()
{
	return m_Fps;
}

static int m_DeltaTick = 0;
static int m_PreTick = GetTickCount64();

float GetDeltaTime()
{
	return m_DeltaTick * 0.001f;
}
void DeltaTime()
{
	m_DeltaTick = GetTickCount64() - m_PreTick;
	m_PreTick = GetTickCount64();
}

void FPSUpdate()
{
	++m_FpsCount;
	if (GetTickCount64() - m_StartTick >= 1000)
	{
		m_StartTick = GetTickCount64();
		m_Fps = m_FpsCount;
		m_FpsCount = 0;
	}
	DeltaTime();
}