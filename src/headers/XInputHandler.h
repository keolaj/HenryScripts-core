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
	static int _rControllerPort;
public:
	XInputHandler();
	~XInputHandler();
	[[nodiscard]] XINPUT_STATE getControllerState() noexcept;
	[[nodiscard]] XINPUT_GAMEPAD getGamepad() noexcept;
	void pollController() noexcept;
	void updateVControllerState() noexcept;
	void updateVControllerStateWithGamepad(const XINPUT_GAMEPAD& pad) noexcept;
	void setRControllerPort(int port);
};