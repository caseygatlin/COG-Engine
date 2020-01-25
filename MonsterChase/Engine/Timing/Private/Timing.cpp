#include "../Public/Timing.h"
#include <Windows.h>
#include <limits.h>

namespace Engine
{
    namespace Timing
    {
        long GetCurrentCPUCounter() 
        {
            LARGE_INTEGER currentCounter;
            QueryPerformanceCounter(&currentCounter);
            
            return currentCounter.QuadPart;

        }

        double GetCPUCounterFrequency_ms()
        {

            LARGE_INTEGER cpuFrequency;
            QueryPerformanceFrequency(&cpuFrequency);
            
            double divisor = 1000.0;
            long frequency = cpuFrequency.QuadPart;

            return frequency / divisor;

        }


        float CalcTimeSinceLastCall_ms()
        {
            static long g_LastFrameStartTick = 0;
            float g_LastFrameTime_ms;

            long currentTick = GetCurrentCPUCounter();


            if (g_LastFrameStartTick)
            {
                long elapsedTIcks = (currentTick - g_LastFrameStartTick);

                g_LastFrameTime_ms = elapsedTIcks / GetCPUCounterFrequency_ms();

            }
            else
            {
                g_LastFrameTime_ms = 13.3;
            }

            g_LastFrameStartTick = currentTick;

            return g_LastFrameTime_ms;

        }
    }
}