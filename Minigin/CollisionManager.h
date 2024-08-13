#pragma once
#include "Singleton.h"
#include "CollisionComponent.h"
#include <vector>
namespace dae
{
	class CollisionManager final : public Singleton<CollisionManager>
	{
	public:
		void Update();
		void AddToCollisionVector(CollisionComponent* comp, CollisionTypes type);
		void CheckToRemove(std::vector<CollisionComponent*>& vec);
		void Remove(CollisionComponent* object, std::vector<CollisionComponent*>& vec);
		void Remove(CollisionComponent* object, CollisionTypes type);
	private:
		void CheckForCollisionBetweenPlayers(std::vector<CollisionComponent*>& vec1, std::vector<CollisionComponent*>& vec2);
		void CheckForCollisionBetweenProjectilesAndEnemies(std::vector<CollisionComponent*>& enemyVec, std::vector<CollisionComponent*>& projectileVec);
		bool CheckRectOverlap(Rect r1, Rect r2) const;
		
		std::vector<CollisionComponent*> m_Enemies;
		std::vector<CollisionComponent*> m_Players;
		std::vector<CollisionComponent*> m_Projectiles;
	};
}