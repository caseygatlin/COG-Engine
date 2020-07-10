#include "../Public/Input.h"
#include "../GLib/GLib.h"
#include "../../Graphics/Public/Graphics.h"
#include "../../Public/Engine.h"
#include "../../World/Public/World.h"
#include "../../Containers/Public/Point2D.h"
#include "../../Containers/Public/Pointers.h"
#include "../../Components/Public/ComponentType.h"
#include "../../Components/Public/PlayerControllerComponent.h"
#include "../../Components/Public/IGOComponent.h"
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

                WeakPtr<GameObject> playerWeakPtr;
                if (World::GetFirstGameObjectWithController("Player", playerWeakPtr))
                {

                    SmartPtr<GameObject> player = playerWeakPtr.Acquire();
                    
                    WeakPtr<IGOComponent> playerControllerWeakPtr;
                    if (player->GetComponent(ComponentType::PLAYER_INPUT, playerControllerWeakPtr))
                    {
                        SmartPtr<IGOComponent> playerControllerBase = playerControllerWeakPtr.Acquire();
                        SmartPtr<PlayerControllerComponent> playerController = playerControllerBase;

                        Point2D dir = player->GetDir();

                        if (i_bWentDown)
                        {

                            if (i_VKeyID == playerController->GetVKeyIDUp())
                            {

                                dir += Point2D(0.0f, 1.0f);

                            }

                            else if (i_VKeyID == playerController->GetVKeyIDDown())
                            {

                                dir += Point2D(0.0f, -1.0f);

                            }

                            else if (i_VKeyID == playerController->GetVKeyIDRight())
                            {

                                dir += Point2D(1.0f, 0.0f);

                            }

                            else if (i_VKeyID == playerController->GetVKeyIDLeft())
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

                            if (i_VKeyID == playerController->GetVKeyIDUp())
                            {

                                dir -= Point2D(0.0f, 1.0f);

                            }

                            else if (i_VKeyID == playerController->GetVKeyIDDown())
                            {

                                dir -= Point2D(0.0f, -1.0f);

                            }

                            else if (i_VKeyID == playerController->GetVKeyIDRight())
                            {

                                dir -= Point2D(1.0f, 0.0f);

                            }

                            else if (i_VKeyID == playerController->GetVKeyIDLeft())
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
            }

            

            
        }

        void Read()
        {

            // IMPORTANT (if we want keypress info from GLib): Set a callback for notification of key presses
            GLib::SetKeyStateChangeCallback(MoveObject);

        }

        
    }
}