// Copyright 2014-2017 Oxford University Innovation Limited and the authors of ITM

#pragma once

#include "SlamGraphErrorFunction.h"

namespace MiniSlamGraph 
{
	class LevenbergMarquardtMethod {
	public:
		static int minimize(const SlamGraphErrorFunction & function, SlamGraphErrorFunction::Parameters & initialization);
	};
}

