#pragma once

#include "../../GameObject/Public/GameObject.h"
#include "../../Containers/Public/Point2D.h"


namespace Engine
{
    namespace Physics
    {

        class PhysicsInfo
        {
        public:
            PhysicsInfo() :
                m_pObject(nullptr),
                m_mass(0.0F),
                m_drag(0.0F)
            {}


            void Init(GameObject* i_pObject, float i_mass, float i_drag);
            void Update(float i_dt);


        private:
            
            GameObject* m_pObject;
            float m_mass;
            float m_drag;

        };

    }
}