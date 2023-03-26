#include <stdexcept>;

#include "headers/XInputHandler.h";

XInputHandler::XInputHandler() : _client{ vigem_alloc() }, _controller{ vigem_target_x360_alloc() } {
	if (!VIGEM_SUCCESS(vigem_connect(_client))) {
		throw std::runtime_error("Could not connect to ViGEm driver");
	}
	if (!VIGEM_SUCCESS(vigem_target_add(_client, _controller))) {
		throw std::runtime_error("could not plug in vController");
	}
}

XINPUT_STATE& XInputHandler::getControllerState() {
	return _rControllerState;
}

void XInputHandler::pollController() {
	XInputGetState(1, &_rControllerState);
}

void XInputHandler::updateVControllerState() {
	vigem_target_x360_update(_client, _controller, *reinterpret_cast<XUSB_REPORT*>(&_rControllerState.Gamepad));
}

XINPUT_GAMEPAD XInputHandler::getGamepad() {
	pollController();
	return _rControllerState.Gamepad;
}

void XInputHandler::updateVControllerStateWithGamepad(const XINPUT_GAMEPAD& pad) {
	vigem_target_x360_update(_client, _controller, *reinterpret_cast<const XUSB_REPORT*>(&pad));
}