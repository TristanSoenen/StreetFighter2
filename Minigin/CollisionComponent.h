#pragma once
#include "Component.h"
#include "Subject.h"
#include "Structs.h"
namespace dae
{
	class TransformComponent;
	class CollisionComponent final : public Component, Subject
	{
	public:
		CollisionComponent(GameObject* pOwner, CollisionTypes type);
		~CollisionComponent() = default;
		void Update() override;
		void Hit();
		void HitEnemy();
		void RemoveFromCollisionVector();
		void AddCollisionObserver(Observer* obsevrer);
		Rect GetSize() const { return m_CollisionRect; }
		bool CanBeRemovedFromMangager() const { return m_RemoveFromVector; }
	private:
		std::shared_ptr<TransformComponent> m_TransformComp;
		CollisionTypes m_Type;
		Rect m_CollisionRect;
		bool m_RemoveFromVector = false;
	};
}