#include <stdexcept>
#define WIN32_LEAN_AND_MEAN 
#include <windows.h>
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <SDL_mixer.h>
#include "SDL_Sound_System.h"
#include "Minigin.h"
#include "InputManager.h"
#include "SceneManager.h"
#include "Renderer.h"
#include "ResourceManager.h"
#include "CollisionManager.h"
#include "DeltaTime.h"
#include <chrono>
#include <thread>
#include <iostream>
#include "ServiceLocator.h"


SDL_Window* g_window{};

void PrintSDLVersion()
{
	SDL_version version{};
	SDL_VERSION(&version);
	printf("We compiled against SDL version %u.%u.%u ...\n",
		version.major, version.minor, version.patch);

	SDL_GetVersion(&version);
	printf("We are linking against SDL version %u.%u.%u.\n",
		version.major, version.minor, version.patch);

	SDL_IMAGE_VERSION(&version);
	printf("We compiled against SDL_image version %u.%u.%u ...\n",
		version.major, version.minor, version.patch);

	version = *IMG_Linked_Version();
	printf("We are linking against SDL_image version %u.%u.%u.\n",
		version.major, version.minor, version.patch);

	SDL_TTF_VERSION(&version)
	printf("We compiled against SDL_ttf version %u.%u.%u ...\n",
		version.major, version.minor, version.patch);

	version = *TTF_Linked_Version();
	printf("We are linking against SDL_ttf version %u.%u.%u.\n",
		version.major, version.minor, version.patch);

	SDL_MIXER_VERSION(&version);
	printf("We compiled against SDL_mixer version %u.%u.%u ...\n",
		version.major, version.minor, version.patch);

	version = *Mix_Linked_Version();
	printf("We are linking against SDL_mixer version %u.%u.%u.\n",
		version.major, version.minor, version.patch);

}

dae::Minigin::Minigin(const std::string &dataPath)
{
	PrintSDLVersion();
	
	if (SDL_Init(SDL_INIT_VIDEO) != 0) 
	{
		throw std::runtime_error(std::string("SDL_Init Error: ") + SDL_GetError());
	}

	if (Mix_OpenAudio(22050, MIX_DEFAULT_FORMAT, 2, 4096) == -1)
	{
		throw std::runtime_error(std::string("SDL_Audio Error: ") + SDL_GetError());
	}

	g_window = SDL_CreateWindow(
		"Programming 4: Tristan Soenen 2DAE19 Galaga",
		SDL_WINDOWPOS_CENTERED,
		SDL_WINDOWPOS_CENTERED,
		640,
		480,
		SDL_WINDOW_OPENGL
	);

	if (g_window == nullptr) 
	{
		throw std::runtime_error(std::string("SDL_CreateWindow Error: ") + SDL_GetError());
	}

	Renderer::GetInstance().Init(g_window);

	ResourceManager::GetInstance().Init(dataPath);
}

dae::Minigin::~Minigin()
{
	Renderer::GetInstance().Destroy();
	SDL_DestroyWindow(g_window);
	g_window = nullptr;
	SDL_Quit();
}

void dae::Minigin::Run(const std::function<void()>& load)
{
	load();
	
	auto& renderer = Renderer::GetInstance();
	auto& sceneManager = SceneManager::GetInstance();
	auto& input = InputManager::GetInstance();
	auto& time = DeltaTime::GetInstance();
	//auto& collisionManager = CollisionManager::GetInstance();
	auto sound = ServiceLocator::get_Sound_System();

	bool doContinue = true;
	float lag = 0.0f;
	const float fixed_time_Step = 1.0f / 60.0f;
	//!!!ROBBE HIJZEN HELPED MAKING IT THREADED!!!
	std::jthread soundThread{ &Sound_System::Update, sound };

	while (doContinue)
	{
		time.Update();
		lag += time.GetDeltaTime();

		doContinue = input.ProcessInput();
		while (lag >= fixed_time_Step)
		{
			//fixed update voor physics
			sceneManager.Fixed_Update();
			lag -= fixed_time_Step;
		}
		sceneManager.Update();
		//collisionManager.Update();
		renderer.Render();

		const auto sleep_time = std::chrono::high_resolution_clock::now() + std::chrono::milliseconds(int(fixed_time_Step * 1000)) - std::chrono::high_resolution_clock::now();
		std::this_thread::sleep_for(sleep_time);
	}
	sound->QuitRunning();
}
