// PruebaCE.h

#pragma once

#include "SelFecha.h"
#include "VerTabla.h"

using namespace System;
using namespace System::Text;

namespace PruebaCE {

	public ref class FuncVarias
	{
	public:

		// Convertir de Ansi a UTF8
		String^ Ansi2UTF8(String^ varCadena)
		{
			Encoding^ encoder1 = Encoding::ASCII;
			UTF8Encoding^ encoder2 = gcnew UTF8Encoding();
			ASCIIEncoding^ encoder3 = gcnew ASCIIEncoding();
			array<Byte>^ bascii = encoder1->GetBytes(varCadena);
			array<Byte>^ butf8 = encoder3->Convert(Encoding::ASCII,Encoding::UTF8,bascii);
			String^ retorno = encoder2->GetString(butf8);
			return retorno;
		}

		// Conversion UTF8 a Ansi
		String^ UTF82Ansi(String^ varCadena)
		{
			Encoding^ encoder1 = Encoding::UTF8;
			UTF8Encoding^ encoder2 = gcnew UTF8Encoding();
			ASCIIEncoding^ encoder3 = gcnew ASCIIEncoding();
			array<Byte>^ butf8 = encoder1->GetBytes(varCadena);
			array<Byte>^ bascii = encoder2->Convert(Encoding::UTF8,Encoding::ASCII,butf8);
			String^ retorno = encoder3->GetString(bascii);
			return retorno;
		}
	};
}
