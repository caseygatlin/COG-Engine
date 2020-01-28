#pragma once
#include "../GLib/GLib.h"
#include "../../GameObject/Public/GameObject.h"
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
                m_gameObject(nullptr), 
                m_texture(nullptr) 
            {}

            void Init(GameObject* i_gameObject, GLib::Sprites::Sprite* i_texture);

            void Present();
            void ReleaseSprite();

        private:
            GameObject* m_gameObject;
            GLib::Sprites::Sprite* m_texture;
        };
    }
}