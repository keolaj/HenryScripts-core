#define WIN32_LEAN_AND_MEAN
#include <Windows.h>

#include <Xinput.h>

#include <ViGEm/Client.h>

#pragma comment(lib, "setupapi.lib")
#pragma comment(lib,"XInput.lib")

class XInputHandler {
private:
	const PVIGEM_CLIENT _client;
	const PVIGEM_TARGET _controller;
	XINPUT_STATE _rControllerState{};
public:
	XInputHandler();
	~XInputHandler();
	XINPUT_STATE getControllerState();
	XINPUT_GAMEPAD getGamepad();
	void pollController();
	void updateVControllerState();
	void updateVControllerStateWithGamepad(const XINPUT_GAMEPAD& pad);
};