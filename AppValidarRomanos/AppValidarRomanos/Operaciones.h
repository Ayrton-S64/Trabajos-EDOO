#pragma once
class COperaciones
{
public:
	COperaciones();
	~COperaciones();

	long ADecimal(System::String^, int, int);
	bool validarRomano(System::String^, char, int, int, int, bool);
};

