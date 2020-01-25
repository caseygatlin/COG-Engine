#pragma once

namespace Engine
{
    namespace Timing
    {
        long GetCurrentCPUCounter();
        double GetCPUCounterFrequency_ms();
        float CalcTimeSinceLastCall_ms();


    }
}