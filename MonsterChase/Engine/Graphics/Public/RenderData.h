#pragma once
#include "../GLib/GLib.h"
#include "../../GameObject/Public/GameObject.h"
#include "../../Containers/Public/Pointers.h"
#include <vector>

namespace GLib
{
    namespace Sprites
    {
        struct Sprite;
    }
}

namespace Engine
{
    namespace Graphics
    {
        class RenderData
        {
        public:
            RenderData() :
                m_gameObject(),
                m_texture()
            {}

            RenderData(WeakPtr<GameObject> i_gameObject, GLib::Sprites::Sprite* i_texture) :
                m_gameObject(i_gameObject), 
                m_texture(i_texture)
            {}

            RenderData(const RenderData& i_src) :
                m_gameObject(i_src.m_gameObject),
                m_texture(i_src.m_texture)
            {}

            RenderData& operator=(const RenderData& i_src);

            RenderData& operator=(RenderData&& i_src) noexcept
            {
                m_gameObject = i_src.m_gameObject;
                m_texture = i_src.m_texture;

                return (*this);
            }

            bool Present();
            void ReleaseSprite();

        private:
            WeakPtr<GameObject> m_gameObject;
            GLib::Sprites::Sprite* m_texture;
        };
    }
}