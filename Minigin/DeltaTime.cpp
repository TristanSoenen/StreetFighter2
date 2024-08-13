#include "DeltaTime.h"
#include <chrono>

void dae::DeltaTime::Update()
{
	const auto current_time = std::chrono::high_resolution_clock::now();
	m_DeltaTime = std::chrono::duration<float>(current_time - m_lastTime).count();
	m_lastTime = current_time;
}

float dae::DeltaTime::GetDeltaTime() const
{
	return m_DeltaTime;
}
