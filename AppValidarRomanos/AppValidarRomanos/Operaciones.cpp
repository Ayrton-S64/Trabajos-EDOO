#include"Operaciones.h"
#include"String.h"

COperaciones::COperaciones(){}
COperaciones::~COperaciones(){}

long COperaciones::ADecimal(System::String^ Roma, int k, int t){
	if(k<= t){
		int xDecimal = 0;
		if(Roma[k] == 'I'){
			if((Roma[k+ 1] == 'V'|| Roma[k+ 1] == 'X') && (k+ 1) <= t)
				xDecimal -= 1;
			else 
				xDecimal += 1;
		}
		if(Roma[k] == 'V') 
			xDecimal += 5;
		if(Roma[k] == 'X'){
			if((Roma[k+ 1] == 'L'|| Roma[k+ 1] == 'C') && (k+ 1) <= t)
				xDecimal -= 10;
			else 
				xDecimal += 10;
		}
		if(Roma[k] == 'L') 
			xDecimal += 50;
		if(Roma[k] == 'C'){
			if((Roma[k+ 1] == 'D'|| Roma[k+ 1] == 'M') && (k+ 1) <= t)
				xDecimal -= 100;
			else
				xDecimal += 100;
		}
		if(Roma[k] == 'D') 
			xDecimal += 500;
		if(Roma[k] == 'M') 
			xDecimal += 1000;
		return(xDecimal+ADecimal(Roma, k+ 1, t));
	}
	else
		return(0);
}

bool COperaciones::validarRomano(System::String^ cadena, char prev, int cont, int estado, int maximo,bool valido) {
	// Cadena -> Para tener informacion del estado de la cadena en la que estamos,
	// prev que es el char previo que ayuda a ver problemas que habia con D, L, V
	// cont que empezó para 'M', pero ahora lo uso como  'niveles'
	// estado es el estado en el que nos enconreamos, estado inicio, fin, I, X, C, M
	// maximo es para asegurarse que se siga el orden M->>C->>X->>I
	// valido será nuestra respuesta, creo que no es necesario tenerlo... 
	if (valido){
		if (cadena->Length > 0) {
			if (estado <= maximo) { // capaz esto no funciona... idk humm al menos en M no hace nada
				System::Char checking = cadena[0];
				switch (estado)
				{
				case 0:
					if (checking == 'M') {
						return validarRomano(cadena, prev, cont, 4, maximo, valido);
					}
					else if (checking == 'C' || checking == 'D') {
						return validarRomano(cadena, prev, 0, 3, maximo, valido);
					}
					else if (checking == 'X' || checking == 'L') {
						return validarRomano(cadena, prev, 0, 2, maximo, valido);
					}
					else if (checking == 'I' || checking == 'V') {
						return validarRomano(cadena, prev, 0, 1, maximo, valido);
					}
					else {
						return false;
					}
					break;
				case 4:
					if (cont < 3) { // M... || MM... || M >
						return validarRomano(cadena->Substring(1), checking, cont + 1, 0, 4, valido);
					}
					else // MMMM ... aunque no es posible uu
						return false;
				case 3:
					switch (checking) {
					case 'C':
						switch (cont) {
						case 0: // C...
							return validarRomano(cadena->Substring(1), checking, cont + 1, 3, 3, valido);
						case 1:
							if (prev == 'D') {  // DC...
								return (cadena->Substring(1), checking, cont, 3, 3, valido);
							}
							else // CC... || DCC...
								return validarRomano(cadena->Substring(1), checking, cont + 1, 3, 3, valido);
						case 2: // CCC > || DCCC >
							return validarRomano(cadena->Substring(1), checking, cont + 1, 0, 2, valido);
						default:
							return false;
						}
					case 'D':
						if (cont == 0) { // D...
							return validarRomano(cadena->Substring(1), checking, cont + 1, 3, 3, valido);
						}
						if (prev == 'C') { // CD > 
							return validarRomano(cadena->Substring(1), checking, cont + 1, 0, 2, valido);
						}
						else {
							return false;
						}
					case 'M': // CM >
						if (prev == 'C') {
							return validarRomano(cadena->Substring(1), checking, 0, 0, 2, valido);
						}
						else {
							return false;
						}
					default:
						return validarRomano(cadena, checking, 0, 0, 2, valido);
						break;
					}
				case 2:
					switch (checking) {
					case 'X':
						switch (cont) {
						case 0: // X...
							return validarRomano(cadena->Substring(1), checking, cont + 1, 2, 2, valido);
						case 1:
							if (prev == 'L') {  // LX...
								return (cadena->Substring(1), checking, cont, 2, 2, valido);
							}
							else // XX... || LXX...
								return validarRomano(cadena->Substring(1), checking, cont + 1, 2, 2, valido);
						case 2: // XXX > || LXXX >
							return validarRomano(cadena->Substring(1), checking, cont + 1, 0, 1, valido);
						default:
							return false;
						}
					case 'L':
						if (cont == 0) { // L...
							return validarRomano(cadena->Substring(1), checking, cont + 1, 2, 2, valido);
						}
						if (prev == 'X') { // XL > 
							return validarRomano(cadena->Substring(1), checking, cont + 1, 0, 1, valido);
						}
						else {
							return false;
						}
					case 'C': // XC >
						if (prev == 'X') {
							return validarRomano(cadena->Substring(1), checking, 0, 0, 1, valido);
						}
						else {
							return false;
						}
					default:
						return validarRomano(cadena, checking, 0, 0, 1, valido);
						break;
					}
					break;
				case 1:
					switch (checking) {
					case 'I':
						switch (cont) {
						case 0: // I...
							return validarRomano(cadena->Substring(1), checking, cont + 1, 1, 1, valido);
						case 1:
							if (prev == 'V') {  // VI...
								return (cadena->Substring(1), checking, cont, 1, 1, valido);
							}
							else // II... || VII...
								return validarRomano(cadena->Substring(1), checking, cont + 1, 1, 1, valido);
						case 2: // III > || VIII >
							return validarRomano(cadena->Substring(1), checking, cont + 1, 0, 0, valido);
						default:
							return false;
						}
					case 'V':
						if (cont == 0) { // V...
							return validarRomano(cadena->Substring(1), checking, cont + 1, 1, 1, valido);
						}
						if (prev == 'I') { // IV > 
							return validarRomano(cadena->Substring(1), checking, cont + 1, 0, 0, valido);
						}
						else {
							return false;
						}
					case 'X': // IX >
						if (prev == 'I') {
							return validarRomano(cadena->Substring(1), checking, 0, 0, 0, valido);
						}
						else {
							return false;
						}
					default:
						return validarRomano(cadena, checking, 0, 0, 0, valido);
						break;
					}
					break;
				default:
					return false;
					break;
				}
			} else 
				return false; // Estado mas grande que el maximo
		} else 
			return true; //La cadena ya no tiene longitud
	} else  // Posiblemente obsoleto
		return valido; // El estado se convierte en false
}
