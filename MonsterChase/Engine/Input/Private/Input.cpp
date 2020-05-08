#include "../Public/Input.h"
#include "../GLib/GLib.h"
#include "../../Graphics/Public/Graphics.h"
#include "../../Public/Engine.h"
#include "../../World/Public/World.h"
#include "../../Containers/Public/Point2D.h"
#include "../../Containers/Public/Pointers.h"
#include "../../Console/Public/ConsolePrint.h"
#include <Windows.h>

namespace Engine
{
    namespace Input
    {
        void MoveObject(unsigned int i_VKeyID, bool i_bWentDown)
        {

            if (World::GetNumGameObjects() > 0)
            {
                SmartPtr<GameObject> player = World::GetGameObject(0).Acquire();

                Point2D dir = player->GetDir();

                if (i_bWentDown)
                {
                    if (i_VKeyID == 0x0057)
                    {
                        dir += Point2D(0.0f, 1.0f);
                    }
                    else if (i_VKeyID == 0x0053)
                    {
                        dir += Point2D(0.0f, -1.0f);
                    }
                    else if (i_VKeyID == 0x0044)
                    {
                        dir += Point2D(1.0f, 0.0f);
                    }
                    else if (i_VKeyID == 0x0041)
                    {
                        dir += Point2D(-1.0f, 0.0f);
                    }
                    else
                    {
                        dir = Point2D(0.0f, 0.0f);
                    }
                }
                else
                {
                    if (i_VKeyID == 0x0057)
                    {
                        dir -= Point2D(0.0f, 1.0f);
                    }
                    else if (i_VKeyID == 0x0053)
                    {
                        dir -= Point2D(0.0f, -1.0f);
                    }
                    else if (i_VKeyID == 0x0044)
                    {
                        dir -= Point2D(1.0f, 0.0f);
                    }
                    else if (i_VKeyID == 0x0041)
                    {
                        dir -= Point2D(-1.0f, 0.0f);
                    }
                    else
                    {
                        dir = Point2D(0.0f, 0.0f);
                    }
                }

                dir.MakeUnit();
                player->ChangeDir(dir);

            }

            

            
        }

        void Read()
        {
            // IMPORTANT (if we want keypress info from GLib): Set a callback for notification of key presses
            GLib::SetKeyStateChangeCallback(MoveObject);
        }

        
    }
}