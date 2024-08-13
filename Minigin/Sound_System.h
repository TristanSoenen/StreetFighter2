#pragma once
#include "string"
using sound_id = unsigned short;
struct PlayMessage
{
	sound_id id;
	int volume;
};

class Sound_System
{
public:
	virtual ~Sound_System() = default;
	virtual void Play(const sound_id id, const int volume) = 0;
	virtual void Update() = 0;
	virtual void LoadSound(const std::string file) = 0;
	virtual void QuitRunning() = 0;
	virtual void Mute() = 0;
};