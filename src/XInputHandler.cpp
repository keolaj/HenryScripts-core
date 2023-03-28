#include <stdexcept>;
#include "headers/XInputHandler.h";

int XInputHandler::_rControllerPort;

XInputHandler::XInputHandler() : _client{ vigem_alloc() }, _controller{ vigem_target_x360_alloc() } {
	if (!VIGEM_SUCCESS(vigem_connect(_client)) || _client == nullptr) {
		throw std::runtime_error("Could not connect to ViGEm driver");
	}
	if (!VIGEM_SUCCESS(vigem_target_add(_client, _controller))) {
		throw std::runtime_error("could not plug in vController");
	}
	_rControllerPort = 1; // for this program to work in certain games our virtual controller must be plugged into port 0. Hence why the real controller port is default set to 1.
}

[[nodiscard]] XINPUT_STATE XInputHandler::getControllerState() noexcept {
	return _rControllerState;
}

void XInputHandler::pollController() noexcept {
	XInputGetState(_rControllerPort , &_rControllerState);
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

void XInputHandler::setRControllerPort(int port) {
	if (port > 3 || port < 0) {
		throw std::runtime_error("port must be between 0 and 3");
	}
	_rControllerPort = port;
}

XInputHandler::~XInputHandler() {
	vigem_target_free(_controller);
	vigem_disconnect(_client);
	vigem_free(_client);
}