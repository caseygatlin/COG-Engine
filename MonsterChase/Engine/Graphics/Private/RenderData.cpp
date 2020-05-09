#include "../Public/RenderData.h"
#include "../../GameObject/Public/GameObject.h"
#include "../../Containers/Public/Pointers.h"
#include "GLib.h"

namespace Engine
{
    namespace Graphics
    {

        RenderData& RenderData::operator=(const RenderData& i_src)
        {
            if (this != &i_src)
            {
                m_gameObject = i_src.m_gameObject;
                m_texture = i_src.m_texture;
            }

            return (*this);
        }

        bool RenderData::Present()
        {
            if (m_gameObject)
            {

                SmartPtr<GameObject> gameObject = m_gameObject.Acquire();

                Point2D position = gameObject->GetPosition();
                GLib::Point2D glibPosition;
                glibPosition = { position.X(), position.Y() };

                // Tell GLib to render this sprite at our calculated location
                GLib::Sprites::RenderSprite(*m_texture, glibPosition, 0.0f);

                return true;

            }

            return false;

        }

        void RenderData::ReleaseSprite()
        {

            GLib::Sprites::Release(m_texture);

        }
    }
}