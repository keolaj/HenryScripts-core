#include <stdexcept>;

#include "headers/XInputHandler.h";

XInputHandler::XInputHandler() : _client{ vigem_alloc() }, _controller{ vigem_target_x360_alloc() } {
	if (!VIGEM_SUCCESS(vigem_connect(_client)) || _client == nullptr) {
		throw std::runtime_error("Could not connect to ViGEm driver");
	}
	if (!VIGEM_SUCCESS(vigem_target_add(_client, _controller))) {
		throw std::runtime_error("could not plug in vController");
	}
}

[[nodiscard]] XINPUT_STATE XInputHandler::getControllerState() noexcept {
	return _rControllerState;
}

void XInputHandler::pollController() noexcept {
	XInputGetState(1, &_rControllerState);
}

void XInputHandler::updateVControllerState() noexcept {
	vigem_target_x360_update(_client, _controller, *reinterpret_cast<XUSB_REPORT*>(&_rControllerState.Gamepad));
}

[[nodiscard]] XINPUT_GAMEPAD XInputHandler::getGamepad() noexcept {
	pollController();
	return _rControllerState.Gamepad;
}

void XInputHandler::updateVControllerStateWithGamepad(const XINPUT_GAMEPAD& pad) noexcept {
	vigem_target_x360_update(_client, _controller, *reinterpret_cast<const XUSB_REPORT*>(&pad));
}

XInputHandler::~XInputHandler() {
	vigem_target_free(_controller);
	vigem_disconnect(_client);
	vigem_free(_client);
}