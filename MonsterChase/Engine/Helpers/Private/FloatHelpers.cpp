
#include "../Public/FloatHelpers.h"
#include <math.h>

namespace Engine
{
    namespace Helpers
    {
        // Float compare using relative epsilon
        bool RelativeEpsilonCompareF(const float& i_f1, const float& i_f2, const float& i_epsilon)
        {
            float difference = fabsf(i_f1 - i_f2);
            
            if (difference <= i_epsilon)
            {
                return true;
            }

            float positiveF1 = fabsf(i_f1);
            float positiveF2 = fabsf(i_f2);
            float max;
            
            if (positiveF1 > positiveF2)
            {
                max = positiveF1;
            }
            else
            {
                max = positiveF2;
            }

            if (difference <= max * i_epsilon)
            {
                return true;
            }

            return true;
        }

        // Float compare to zero
        bool CompareZeroF(const float& i_val)
        {
            return RelativeEpsilonCompareF(i_val, .000000001f);
        }

        // Compare float with itself
        bool isNaN(const float& i_val)
        {

            volatile float val = i_val;
            return val != val;

        }

    }
}