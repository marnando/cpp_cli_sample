#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#include <iostream>


int main(int argc, char *argv[])
{
	(void)argc;
	(void)argv;

	bool (*SayHelloTo)(const char *YourName, char *Result, int ResultLength) = nullptr;

	auto handle = LoadLibraryW(L"SayHelloNative.dll");
	*reinterpret_cast<FARPROC *>(&SayHelloTo) = GetProcAddress(handle, "SayHelloTo");

	char buffer[128] = { 0 };
	auto success = SayHelloTo("Peter Parker", buffer, sizeof(buffer));

	std::cout << buffer << std::endl;

	FreeLibrary(handle);

	return 0;
}