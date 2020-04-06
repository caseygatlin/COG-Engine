#include "../Public/Input.h"
#include "../GLib/GLib.h"
#include "../../Graphics/Public/Graphics.h"
#include "../../Public/Engine.h"
#include <Windows.h>

namespace Engine
{
    namespace Input
    {
        void MoveUp(unsigned int i_VKeyID, bool i_bWentDown)
        {
            const size_t	lenBuffer = 65;
            char			Buffer[lenBuffer];
            
            char dir = 'n';
            if (i_bWentDown)
            {
                if (i_VKeyID == 0x0057)
                {
                    dir = 'u';
                }
                else if (i_VKeyID == 0x0053)
                {
                    dir = 'd';
                }
                else if (i_VKeyID == 0x0044)
                {
                    dir = 'r';
                }
                else if (i_VKeyID == 0x0041)
                {
                    dir = 'l';
                }
                else
                {
                    dir = 'n';
                }
            }
            else
            {
                dir = 'n';
            }

            GetGameObject(0)->changeDir(dir);

            sprintf_s(Buffer, lenBuffer, "VKey %c %s\n", GetGameObject(0)->getDir(), i_bWentDown ? "wayDown" : "wayUp");
            OutputDebugStringA(Buffer);
        }

        void Read()
        {
            // IMPORTANT (if we want keypress info from GLib): Set a callback for notification of key presses
            GLib::SetKeyStateChangeCallback(MoveUp);
        }

        
    }
}