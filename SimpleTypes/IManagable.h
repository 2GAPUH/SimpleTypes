#pragma once
#include "ICopyable.h"
#include "IValue.h"
#include "IPrintable.h"


class IManagable : public ICopyable, public IValue, public IPrintable {};

