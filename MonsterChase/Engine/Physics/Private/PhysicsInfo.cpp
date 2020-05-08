
#include "../../GameObject/Public/GameObject.h"
#include "../../Containers/Public/Point2D.h"
#include "../../Containers/Public/Pointers.h"
#include "../Public/PhysicsInfo.h"

namespace Engine
{
    namespace Physics
    {
        void PhysicsInfo::Update(float i_dt)
        {
            SmartPtr<GameObject> gameObject = m_pObject.Acquire();

            Point2D objectVelocity = gameObject->GetVelocity();

            Point2D forces(0.0F, 0.0F);

            if (gameObject->GetDir().Y() > 0)
            {
                forces += Point2D(0.0F, .1F);
            }
            else if (gameObject->GetDir().Y() < 0)
            {
                forces += Point2D(0.0F, -.1F);
            }

            if (gameObject->GetDir().X() < 0)
            {
                forces += Point2D(-.1F, 0.0F);
            }
            else if (gameObject->GetDir().X() > 0)
            {
                forces += Point2D(.1F, 0.0F);
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

            gameObject->SetVelocity(gameObject->GetVelocity() + acceleration * i_dt);
            gameObject->ChangePosition(gameObject->GetVelocity() * i_dt);
        }
    }
}