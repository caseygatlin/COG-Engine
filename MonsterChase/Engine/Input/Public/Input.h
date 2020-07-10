#pragma once

namespace Engine
{
    namespace Input
    {
        void Read();

        // Moves the player controlled object based on input.
        void MoveObject(unsigned int i_VKeyID, bool i_bWentDown);
    }
}