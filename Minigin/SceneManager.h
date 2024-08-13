#pragma once
#include <vector>
#include <string>
#include <memory>
#include "Singleton.h"

namespace dae
{
	class Scene;
	class SceneManager final : public Singleton<SceneManager>
	{
	public:
		Scene& CreateScene(const std::string& name);
		void Fixed_Update();
		void Update();
		void Render();
		Scene* GetCurrentScene() { return m_scenes[m_CurrentScene].get(); }
		Scene* GetSceneAtIndex(int index) 
		{
				return m_scenes[index].get();
		}
		void SetCurrentScene(int sceneIndex);
	private:
		friend class Singleton<SceneManager>;
		SceneManager() = default;
		std::vector<std::shared_ptr<Scene>> m_scenes;
		int m_CurrentScene = 0;
	};
}
