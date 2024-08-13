#pragma once
#include "Singleton.h"
#include <chrono>
namespace dae
{
	class DeltaTime final: public Singleton<DeltaTime>
	{
	public:
		void Update();
		float GetDeltaTime() const;
	private:
		std::chrono::high_resolution_clock::time_point m_lastTime = std::chrono::high_resolution_clock::now();
		float m_DeltaTime = 0.0f;
	};
}