#pragma once
#include "GameObject.h"
#include "glm/glm.hpp"
#include "DeltaTime.h"
#include "Structs.h"


namespace dae
{
	class Command
	{
	public:
		Command() {};

		virtual ~Command() = default;
		virtual void Execute() = 0;
	};

	class GameActorCommand : public Command
	{
	private: 
		GameObject* m_actor;
	protected:
		GameObject* GetGameActor() const { return m_actor; }
	public:
		GameActorCommand(GameObject* actor) 
			:Command()
			,m_actor(actor)
		{
		
		}
		virtual ~GameActorCommand() = default;
	};

	class MoveCommand final : public GameActorCommand
	{
		glm::vec3 m_Direction;
		float m_MoveSpeed;
	public:
		MoveCommand(GameObject* actor, const glm::vec3 direction, const float moveSpeed)
			: GameActorCommand(actor)
			, m_Direction(direction)
			, m_MoveSpeed(moveSpeed)
		{

		}

		~MoveCommand() = default;
		void Execute() override
		{
			auto actor = GetGameActor();
			if (actor->GetMarkedForDead() == false)
			{
				GameSizes sizes{};
				glm::vec3 nextPos = actor->GetWorldPosition();
				nextPos += glm::normalize(m_Direction) * m_MoveSpeed * DeltaTime::GetInstance().GetDeltaTime();
				if (nextPos.x < 0)
				{
					nextPos.x = 0;
				}
				else if (nextPos.x > (sizes.playfieldSize.x - sizes.characterSizes.x))
				{
					nextPos.x = sizes.playfieldSize.x - sizes.characterSizes.x;
				}
				GetGameActor()->SetPosition(nextPos.x, nextPos.y);
			}
		}
	};
}