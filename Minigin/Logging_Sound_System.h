#pragma once
#include "Sound_System.h"
#include "memory"
#include "iostream"

class Logging_Sound_System final : public Sound_System
{
	std::unique_ptr<Sound_System> _real_ss;
public:
	Logging_Sound_System(std::unique_ptr<Sound_System>&& ss) : _real_ss(std::move(ss)) {}
	virtual ~Logging_Sound_System() = default;

	void Play(const sound_id id, const int volume) override
	{
		_real_ss->Play(id, volume);
		std::cout << "Playing " << id << " at volume " << volume << "\n";
	}

	void LoadSound(const std::string file) override
	{
		_real_ss->LoadSound(file);
	}

	void Update() override 
	{
		_real_ss->Update();
	};

	void QuitRunning() override
	{
		_real_ss->QuitRunning();
	}

	void Mute() override 
	{
		_real_ss->Mute();
	}
};

