#include <iostream>
#include "src/headers/XInputHandler.h"
#include <sol/sol.hpp>
#define SOL_ALL_SAFTIES_ON 1

int main() {
	sol::state lua{};
	lua.open_libraries(sol::lib::base, sol::lib::jit);
	lua.script("print(jit.status())");
	return 0;
}