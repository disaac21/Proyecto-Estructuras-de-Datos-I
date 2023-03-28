#pragma once

#include "Object.h"

class TDACola {

	public:
        virtual void encolar(Object*) = 0;
        virtual Object* desencolar() = 0;
        virtual Object* verfrente() = 0;
		virtual bool IsVacio()=0;
		virtual void imprime()=0;
		virtual void anula()=0;
		
};