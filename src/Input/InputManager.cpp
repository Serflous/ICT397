#include "InputManager.h"

InputManager * InputManager::m_instance;

InputManager * InputManager::GetInstance()
{
	if (!m_instance)
	{
		m_instance = new InputManager();
	}
	return m_instance;
}

InputManager::InputManager()
{
	for (int i = 0; i < 550; i++)
	{
		m_keys[i] = KS_KEY_RELEASED;
	}
}

InputManager::~InputManager()
{

}

InputManager::InputManager(const InputManager & other)
{

}

KeyState InputManager::GetKeyState(int key)
{
	
	return m_keys[key];

}

void InputManager::KeyCallback(int key, bool press)
{
	m_keys[key] = press ? KS_KEY_PRESSED : KS_KEY_RELEASED;
	std::cout << "KeyCallback: " << key << " - " << m_keys[key] << std::endl;
}
