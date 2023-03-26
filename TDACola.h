#pragma once

#include "Object.h"

class TDACola {

	public:
        virtual bool encolar(Object*) = 0;
        virtual bool desencolar() = 0;
        virtual void verfrente() = 0;
		virtual bool IsVacio()=0;
		virtual void imprime()=0;
		virtual void anula()=0;

};