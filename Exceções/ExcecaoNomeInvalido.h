#ifndef EXCECAONOMEINVALIDO_H
#define EXCECAONOMEINVALIDO_H

#include <stdexcept>

using namespace std;

class ExcecaoNomeInvalido : public runtime_error
{
public:

	ExcecaoNomeInvalido();

};

#endif