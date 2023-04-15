#include "headers/SolUtils.h";
#include "headers/XInputHandler.h";

#include <XInput.h>

void SolUtils::setupSolState(sol::state& _lua) noexcept {

	_lua.open_libraries(sol::lib::base, sol::lib::jit, sol::lib::math, sol::lib::string, sol::lib::bit32);

	sol::usertype<XINPUT_GAMEPAD> gamepadUDT = _lua.new_usertype<XINPUT_GAMEPAD>("gamepad");

	gamepadUDT["wButtons"] = &XINPUT_GAMEPAD::wButtons;
	gamepadUDT["bLeftTrigger"] = &XINPUT_GAMEPAD::bLeftTrigger;
	gamepadUDT["bRightTrigger"] = &XINPUT_GAMEPAD::bRightTrigger;
	gamepadUDT["sThumbLX"] = &XINPUT_GAMEPAD::sThumbLX;
	gamepadUDT["sThumbLY"] = &XINPUT_GAMEPAD::sThumbLY;
	gamepadUDT["sThumbRX"] = &XINPUT_GAMEPAD::sThumbRX;
	gamepadUDT["sThumbRY"] = &XINPUT_GAMEPAD::sThumbRY;
}