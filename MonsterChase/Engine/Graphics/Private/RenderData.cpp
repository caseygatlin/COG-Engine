#include "../Public/RenderData.h"
#include "../../GameObject/Public/GameObject.h"
#include "../../Containers/Public/Pointers.h"
#include "GLib.h"

namespace Engine
{
    namespace Graphics
    {
        void RenderData::Present()
        {

            SmartPtr<GameObject> gameObject = m_gameObject.Acquire();

            Point2D position = gameObject->getPosition();
            GLib::Point2D glibPosition;
            glibPosition = { position.X(), position.Y() };

            // Tell GLib to render this sprite at our calculated location
            GLib::Sprites::RenderSprite(*m_texture, glibPosition, 0.0f);
        }

        void RenderData::ReleaseSprite()
        {
            GLib::Sprites::Release(m_texture);
        }
    }
}