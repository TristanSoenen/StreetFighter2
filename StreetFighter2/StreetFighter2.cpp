#include <SDL.h>

#if _DEBUG
// ReSharper disable once CppUnusedIncludeDirective
#if __has_include(<vld.h>)
#include <vld.h>
#endif
#endif

#include "Minigin.h"
#include "SceneManager.h"
#include "GameObject.h"
//#include "ResourceManager.h"
//#include "InputManager.h"
#include "Scene.h"
//#include "Component.h"
//#include "RenderComponent.h"
//#include "TextComponent.h"
//#include "GalagaPlayer.h"
//#include "BackGround.h"
//#include "Controller.h"
//#include "Command.h"
//#include "GameCommands.h"
#include "ServiceLocator.h"
#include "Sound_System.h"
#include "SDL_Sound_System.h"
#include "Logging_Sound_System.h"
//#include "Structs.h"
//#include "ScoreComponent.h"
//#include "LivesComponent.h"
//#include "GameComponent.h"
//#include "EnemyComponent.h"
//#include "EnemyManagerComponent.h"
//#include "HelperFunctions.h"

std::unique_ptr<Sound_System> ServiceLocator::_ss_instance{ std::make_unique<Null_Sound_System>() };

void load()
{
#if _DEBUG
	ServiceLocator::register_Sound_System(std::make_unique<Logging_Sound_System>(std::make_unique<SDL_Sound_System>()));
#else

	ServiceLocator::register_Sound_System(std::make_unique<SDL_Sound_System>());
#endif

	auto& scene = dae::SceneManager::GetInstance().CreateScene("Level1");
	//dae::SceneManager::GetInstance().CreateScene("Level2");
	//dae::SceneManager::GetInstance().CreateScene("Level3");
	//dae::SceneManager::GetInstance().CreateScene("GameOver");
	//dae::SceneManager::GetInstance().CreateScene("HighScores");
	auto background0 = std::make_shared<dae::GameObject>();
	//background0->SetPosition(0, 0);
	//background0->AddComponent(std::make_shared<dae::BackGround>(background0.get(), 100.0f));
	scene.Add(background0);

	//auto background1 = std::make_shared<dae::GameObject>();
	//background1->SetPosition(0, -480);
	//background1->AddComponent(std::make_shared<dae::BackGround>(background1.get(), 100.0f));
	//scene.Add(background1);

	//auto player = std::make_shared<dae::GameObject>();
	//player->AddComponent(std::make_shared<dae::GalagaPlayer>(player.get()));
	//player->SetPosition(200, 400);
	//auto& input = dae::InputManager::GetInstance();
	//input.AddController(std::make_unique<dae::Controller>());
	//input.CreateCommandKeyBoard(std::make_unique<dae::MoveCommand>(player.get(), glm::vec3{ 1.0f, 0.0f, 0.0f }, 100.0f), SDL_SCANCODE_D, false);
	//input.CreateCommandKeyBoard(std::make_unique<dae::MoveCommand>(player.get(), glm::vec3{ -1.0f, 0.0f, 0.0f }, 100.0f), SDL_SCANCODE_A, false);
	//input.CreateCommandForController(std::make_unique<dae::MoveCommand>(player.get(), glm::vec3{ -1.0f, 0.0f, 0.0f }, 100.0f), 0, dae::DPAD_LEFT, false);
	//input.CreateCommandForController(std::make_unique<dae::MoveCommand>(player.get(), glm::vec3{ 1.0f, 0.0f, 0.0f }, 100.0f), 0, dae::DPAD_RIGHT, false);
	//input.CreateCommandForController(std::make_unique<dae::FireCommand>(player.get()), 0, dae::GAMEPAD_A, true);
	//input.CreateCommandKeyBoard(std::make_unique<dae::FireCommand>(player.get()), SDL_SCANCODE_SPACE, true);
	//auto ss = ServiceLocator::get_Sound_System();
	//ss->LoadSound("../Data/PlayerShoot.wav");
	//scene.Add(player);

	//auto font = dae::ResourceManager::GetInstance().LoadFont("Lingua.otf", 36);
	//auto score = std::make_shared<dae::GameObject>();
	//score->AddComponent(std::make_shared<dae::ScoreComponent>(score.get(), font));
	//score->SetPosition(400, 50);
	//auto scoreComp = score->GetComponent<dae::ScoreComponent>();
	//scene.Add(score);

	//auto galagaPlayerComp = player->GetComponent<dae::GalagaPlayer>();
	//auto lives = std::make_shared<dae::GameObject>();
	//lives->AddComponent(std::make_shared<dae::LivesComponent>(lives.get(), galagaPlayerComp->GetLives(), font));
	//auto livesComp = lives->GetComponent<dae::LivesComponent>();
	//lives->SetPosition(400, 350);
	//galagaPlayerComp->AddObserverToPlayer(livesComp->GetObserver());
	//scene.Add(lives);

	//auto game = std::make_shared<dae::GameObject>();
	//game->AddComponent(std::make_shared<dae::GameComponent>(game.get()));
	//auto gameComp = game->GetComponent<dae::GameComponent>();
	//scene.Add(game);
	//input.CreateCommandKeyBoard(std::make_unique<dae::MuteCommand>(game.get()), SDL_SCANCODE_M, true);
	//input.CreateCommandKeyBoard(std::make_unique<dae::SwitchHighScoresCommand>(game.get()), SDL_SCANCODE_P, true);
	//input.CreateCommandKeyBoard(std::make_unique<dae::SkipLevelCommand>(game.get()), SDL_SCANCODE_F1, true);
	//input.CreateCommandForController(std::make_unique<dae::SwitchHighScoresCommand>(game.get()), 0, dae::GAMEPAD_B, true);

	//auto enemyManager = std::make_shared<dae::GameObject>();
	//enemyManager->AddComponent(std::make_shared<dae::EnemyManagerComponent>(enemyManager.get()));
	//scene.Add(enemyManager);
	//auto enemyManagerComp = enemyManager->GetComponent<dae::EnemyManagerComponent>();
	//int halfindex = 0;
	//int enemyCountRight = 0;
	//int enemyCountLeft = 0;
	////adding enemies to the game with filepositions
	//std::vector<glm::vec2> positions;
	//ReadPositions(positions, "../Data/Formation1Bees.txt");
	//halfindex = int(positions.size() / 2) - 1;
	//for (int i = 0; i < int(positions.size()); i++)
	//{
	//	auto bee = std::make_shared<dae::GameObject>();
	//	if (i > halfindex)
	//	{
	//		bee->AddComponent(std::make_shared<dae::EnemyComponent>(bee.get(), positions[i], dae::EnemyTypes::BEE, false));
	//		bee->SetPosition(400.0f + (50.0f * enemyCountRight), 400 + (50.0f * enemyCountRight));
	//		++enemyCountRight;
	//	}
	//	else
	//	{
	//		bee->AddComponent(std::make_shared<dae::EnemyComponent>(bee.get(), positions[i], dae::EnemyTypes::BEE, true));
	//		bee->SetPosition(-50.0f * enemyCountLeft, 400 + (50.0f * enemyCountLeft));
	//		++enemyCountLeft;
	//	}
	//	auto beeComp2 = bee->GetComponent<dae::EnemyComponent>();
	//	beeComp2->AddObserverToEnemy(scoreComp->GetObserver());
	//	enemyManagerComp->AddEnemy(beeComp2.get());
	//	scene.Add(bee);
	//}
	//halfindex = 0;
	//positions.clear();
	//ReadPositions(positions, "../Data/Formation1Butterflies.txt");
	//halfindex = int(positions.size() / 2) - 1;
	//for (int i = 0; i < int(positions.size()); i++)
	//{
	//	auto btfly = std::make_shared<dae::GameObject>();
	//	if (i > halfindex)
	//	{
	//		btfly->AddComponent(std::make_shared<dae::EnemyComponent>(btfly.get(), positions[i], dae::EnemyTypes::BUTTERFLY, false));
	//		btfly->SetPosition(800.0f + (50.0f * enemyCountRight), 800 + (50.0f * enemyCountRight));
	//		++enemyCountRight;
	//	}
	//	else
	//	{
	//		btfly->AddComponent(std::make_shared<dae::EnemyComponent>(btfly.get(), positions[i], dae::EnemyTypes::BUTTERFLY, true));
	//		btfly->SetPosition(-400 - 50.0f * enemyCountLeft, 800 + (50.0f * enemyCountLeft));
	//		++enemyCountLeft;
	//	}
	//	auto btlfyComp = btfly->GetComponent<dae::EnemyComponent>();
	//	btlfyComp->AddObserverToEnemy(scoreComp->GetObserver());
	//	enemyManagerComp->AddEnemy(btlfyComp.get());
	//	scene.Add(btfly);
	//}
	//positions.clear();
	//halfindex = 0;
	//ReadPositions(positions, "../Data/Formation1Boss.txt");
	//halfindex = int(positions.size() / 2) - 1;
	//for (int i = 0; i < int(positions.size()); i++)
	//{
	//	auto bs = std::make_shared<dae::GameObject>();
	//	if (i > halfindex)
	//	{
	//		bs->AddComponent(std::make_shared<dae::EnemyComponent>(bs.get(), positions[i], dae::EnemyTypes::BOSS, false));
	//		bs->SetPosition(1200.0f + (50.0f * enemyCountRight), 1200 + (50.0f * enemyCountRight));
	//		++enemyCountRight;
	//	}
	//	else
	//	{
	//		bs->AddComponent(std::make_shared<dae::EnemyComponent>(bs.get(), positions[i], dae::EnemyTypes::BOSS, true));
	//		bs->SetPosition(-800 - 50.0f * enemyCountLeft, 1200 + (50.0f * enemyCountLeft));
	//		++enemyCountLeft;
	//	}
	//	auto bsComp = bs->GetComponent<dae::EnemyComponent>();
	//	bsComp->AddObserverToEnemy(scoreComp->GetObserver());
	//	enemyManagerComp->AddEnemy(bsComp.get());
	//	scene.Add(bs);
	//}
	//galagaPlayerComp->AddObserverToPlayer(gameComp->GetObserver());
	//player->GetComponent<dae::RocketLauncher>()->AddObserverToLauncher(gameComp->GetObserver());
	//enemyManagerComp->AddObserverToEnemyManager(gameComp->GetObserver());
}

int main(int, char* []) {
	dae::Minigin engine("../Data/");
	engine.Run(load);
	return 0;
}
