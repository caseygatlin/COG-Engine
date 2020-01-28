#include "../Public/RenderData.h"
#include "../../GameObject/Public/GameObject.h"
#include "GLib.h"

namespace Engine
{
    namespace Graphics
    {
        void RenderData::Init(GameObject* i_gameObject, GLib::Sprites::Sprite* i_texture)
        {
            m_gameObject = i_gameObject;
            m_texture = i_texture;
        }


        void RenderData::Present()
        {
            
            Point2D position = m_gameObject->getPosition();
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