#pragma once

#include "../../GameObject/Public/GameObject.h"
#include "../../Containers/Public/Point2D.h"
#include "../../Containers/Public/Pointers.h"


namespace Engine
{
    namespace Physics
    {

        class PhysicsInfo
        {
        public:
            PhysicsInfo() :
                m_pObject(),
                m_mass(),
                m_drag()
            {}

            PhysicsInfo(WeakPtr<GameObject> i_pObject, float i_mass, float i_drag) :
                m_pObject(i_pObject),
                m_mass(i_mass),
                m_drag(i_drag)
            {}

            PhysicsInfo(const PhysicsInfo& i_src) :
                m_pObject(i_src.m_pObject),
                m_mass(i_src.m_mass),
                m_drag(i_src.m_drag)
            {}

            PhysicsInfo& operator=(const PhysicsInfo& i_src)
            {
                m_pObject = i_src.m_pObject;
                m_mass = i_src.m_mass;
                m_drag = i_src.m_drag;
            }

            PhysicsInfo& operator=(PhysicsInfo&& i_src) noexcept
            {
                m_pObject = i_src.m_pObject;
                m_mass = i_src.m_mass;
                m_drag = i_src.m_drag;
            }

            void Update(float i_dt);

        private:
            
            WeakPtr<GameObject> m_pObject;
            float m_mass;
            float m_drag;

        };

    }
}