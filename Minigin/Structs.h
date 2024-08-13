#pragma once
#include <glm/glm.hpp>
#include <memory>


namespace dae
{
	enum eventType
	{
		PLAYER_DIED,
		HIT,
		FIRED,
		BEE_DIED,
		BUTTERFLY_DIED,
		BOSSGALAGA_DIED,
		BEE_INPOS_DIED,
		BUTTERFLY_INPOS_DIED,
		BOSSGALAGA_INPOS_DIED,
		ENEMY_HIT,
		LEVEL_COMPLETE,
		GAME_OVER
	};

	enum ControllerButtons
	{
		DPAD_LEFT = 0x0004,
		DPAD_RIGHT = 0x0008,
		GAMEPAD_A = 0x1000,
		GAMEPAD_B = 0x2000
	};

	struct Event
	{
		eventType type;
	};

	enum CollisionTypes
	{
		Player,
		Enemy,
		Projectile
	};

	enum EnemyTypes
	{
		BEE,
		BUTTERFLY,
		BOSS
	};

	struct Rect
	{
		float x;
		float y;
		float width;
		float height;
	};

	struct GameSizes
	{
		glm::vec2 characterSizes = { 25, 25 };
		glm::vec2 playfieldSize = { 400, 480 };
		glm::vec2 rocketSize = { 5, 8 };
		glm::vec2 GetRocketSize() const { return rocketSize; }
	};
}
