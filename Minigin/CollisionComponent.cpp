#include "CollisionComponent.h"
#include "TransformComponent.h"
#include "CollisionManager.h"

dae::CollisionComponent::CollisionComponent(dae::GameObject* pOwner, dae::CollisionTypes type)
	:dae::Component(pOwner)
	,m_Type(type)
{
	m_CollisionRect = dae::Rect{};
	m_TransformComp = pOwner->GetComponent<dae::TransformComponent>();
	glm::vec3 pos = m_TransformComp->GetWorldPosition();
	
	dae::GameSizes sizes;
	switch (m_Type)
	{
	case dae::CollisionTypes::Projectile:
		m_CollisionRect.x = pos.x;
		m_CollisionRect.y = pos.y;
		m_CollisionRect.width = sizes.rocketSize.x;
		m_CollisionRect.height = sizes.rocketSize.y;

		break;
	case dae::CollisionTypes::Enemy:
		m_CollisionRect.x = pos.x;
		m_CollisionRect.y = pos.y;
		m_CollisionRect.width = sizes.characterSizes.x;
		m_CollisionRect.height = sizes.characterSizes.y;
		break;
	case dae::CollisionTypes::Player:
		m_CollisionRect.x = pos.x;
		m_CollisionRect.y = pos.y;
		m_CollisionRect.width = sizes.characterSizes.x;
		m_CollisionRect.height = sizes.characterSizes.y;
		break;
	}

	auto& collManager = CollisionManager::GetInstance();
	collManager.AddToCollisionVector(this, type);
}

void dae::CollisionComponent::AddCollisionObserver(dae::Observer* obsevrer)
{
	AddObserver(obsevrer);
}

void dae::CollisionComponent::Hit()
{
	dae::Event event{};
	event.type = HIT;
	NotifyObservers(event);
}

void dae::CollisionComponent::HitEnemy()
{
	dae::Event event{};
	event.type = ENEMY_HIT;
	NotifyObservers(event);
}

void dae::CollisionComponent::RemoveFromCollisionVector()
{
	m_RemoveFromVector = true;
}

void dae::CollisionComponent::Update()
{
	glm::vec3 pos = m_TransformComp->GetWorldPosition();
	m_CollisionRect.x = pos.x;
	m_CollisionRect.y = pos.y;
}