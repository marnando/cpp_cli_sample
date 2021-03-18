
#pragma unmanaged
#include <cstring>
#pragma managed

#include <msclr/marshal_cppstd.h>

#pragma unmanaged

extern "C" bool SayHelloTo(const char *YourName, char *Result, int ResultLength);

#pragma managed

bool SayHelloTo(const char *YourName, char *Result, int ResultLength)
{
	using namespace msclr::interop;

	marshal_context ctx;

	SayHello::SayHello clrObj;	
	auto result = ctx.marshal_as<const char *>(clrObj.SayHelloTo(marshal_as<System::String ^>(YourName)));
	strcpy_s(Result, ResultLength, result);

	return true;
}