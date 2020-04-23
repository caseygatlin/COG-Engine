#pragma once

#include <float.h>


namespace Engine
{
    namespace Helpers
    {

        bool RelativeEpsilonCompareF(const float& i_f1, const float& i_f2, const float& i_epsilon = FLT_EPSILON);
        bool CompareZeroF(const float& i_val);
        bool isNaN(const float& i_val);

    }
}