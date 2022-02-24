#ifndef EXCECAOCNPJINVALIDO_H
#define EXCECAOCNPJINVALIDO_H

#include <stdexcept>

using namespace std;

class ExcecaoCNPJInvalido : public runtime_error
{
public:

	ExcecaoCNPJInvalido();

};

#endif