#include "SceneManager.h"
#include "Scene.h"

void dae::SceneManager::Fixed_Update()
{
	m_scenes[m_CurrentScene]->Fixed_Update();
}

void dae::SceneManager::Update()
{
	m_scenes[m_CurrentScene]->Update();
}

void dae::SceneManager::Render()
{
	m_scenes[m_CurrentScene]->Render();
}

void dae::SceneManager::SetCurrentScene(int sceneIndex)
{
	m_CurrentScene = sceneIndex;
}

dae::Scene& dae::SceneManager::CreateScene(const std::string& name)
{
	const auto& scene = std::shared_ptr<Scene>(new Scene(name));
	m_scenes.push_back(scene);
	return *scene;
}
