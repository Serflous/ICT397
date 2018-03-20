#ifndef INPUTMANAGER_H
#define INPUTMANAGER_H

#include <iostream>

enum KeyState
{
	KS_KEY_PRESSED,
	KS_KEY_REPEAT,
	KS_KEY_RELEASED
};

class InputManager
{
public:
	static InputManager * GetInstance();

	KeyState GetKeyState(int key);
	void KeyCallback(int key, bool pressed);

private:
	InputManager();
	~InputManager();
	InputManager(const InputManager & other);

private:
	static InputManager * m_instance;

	KeyState m_keys[550];
};

#endif