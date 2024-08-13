#pragma once
#include "memory"
#include "Sound_System.h"

class Null_Sound_System final : public Sound_System
{
	void Play(const sound_id, const int) override {};
	void LoadSound(const std::string file) override {};
	void Update() override {};
	void QuitRunning() override {};
	void Mute() override {};
};

class ServiceLocator final
{
	static std::unique_ptr<Sound_System> _ss_instance;
public:
	static Sound_System* get_Sound_System() { return _ss_instance.get(); }
	static void register_Sound_System(std::unique_ptr<Sound_System>&& ss) { _ss_instance = ss == nullptr ? std::make_unique<Null_Sound_System>() : std::move(ss); }
};

