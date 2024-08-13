#pragma once
#include "Sound_System.h"
#include "memory"

class SDL_Sound_System final : public Sound_System
{
public:
	SDL_Sound_System();
	virtual ~SDL_Sound_System();
	void Play(const sound_id id, const int volume) override;
	void Update() override;
	void LoadSound(const std::string file) override;
	void QuitRunning() override;
	void Mute() override;
private:
	class Soundimpl;
	std::unique_ptr<Soundimpl> m_Soundimpl;
};