
#include "../../GameObject/Public/GameObject.h"
#include "../../Containers/Public/Point2D.h"
#include "../Public/PhysicsInfo.h"

namespace Engine
{
    namespace Physics
    {
        void PhysicsInfo::Init(GameObject* i_pObject, float i_mass, float i_drag)
        {
            m_pObject = i_pObject;
            m_mass = i_mass;
            m_drag = i_drag;
        }

        void PhysicsInfo::Update(float i_dt)
        {
            Point2D objectVelocity = m_pObject->getVelocity();

            Point2D forces(0.0F, 0.0F);

            if (m_pObject->getDir() == 'u')
            {
                forces = Point2D(0.0F, .1F);
            }
            else if (m_pObject->getDir() == 'd')
            {
                forces = Point2D(0.0F, -.1F);
            }
            else if (m_pObject->getDir() == 'l')
            {
                forces = Point2D(-.1F, 0.0F);
            }
            else if (m_pObject->getDir() == 'r')
            {
                forces = Point2D(.1F, 0.0F);
            }

            Point2D dragForce(0.0F, 0.0F);

            if (objectVelocity.X() > 0 && objectVelocity.Y() < 0)
            {
                dragForce += Point2D(m_drag * -1, m_drag);
            }
            else if (objectVelocity.X() < 0 && objectVelocity.Y() > 0)
            {
                dragForce += Point2D(m_drag, m_drag * -1);
            }
            else if (objectVelocity.X() < 0 || objectVelocity.Y() < 0)
            {
                dragForce += Point2D(m_drag, m_drag);
            }
            else if (objectVelocity.X() > 0 || objectVelocity.Y() > 0)
            {
                dragForce += Point2D(m_drag * -1, m_drag * -1);
            }

            forces += objectVelocity * objectVelocity * dragForce;

            Point2D acceleration = forces / m_mass;

            m_pObject->SetVelocity(m_pObject->getVelocity() + acceleration * i_dt);
            m_pObject->changePosition(m_pObject->getVelocity() * i_dt);
        }
    }
}