#include <iostream>

#include <sol/sol.hpp>
#define SOL_ALL_SAFTIES_ON 1

#include "src/headers/SolUtils.h";
#include "src/headers/XInputHandler.h";



int main() {

	sol::state lua{};

	SolUtils::setupSolState(lua);
	
}
