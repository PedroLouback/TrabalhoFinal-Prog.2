#ifndef EXCECAOCPFINVALIDO_H
#define EXCECAOCPFINVALIDO_H

#include <stdexcept>

using namespace std;

class ExcecaoCPFInvalido : public runtime_error
{
public:

	ExcecaoCPFInvalido();

};

#endif