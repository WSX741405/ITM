// Copyright 2014-2017 Oxford University Innovation Limited and the authors of ITM

#pragma once

#include "../Interface/ITMLowLevelEngine.h"

namespace ITMLib
{
	class ITMLowLevelEngine_CUDA : public ITMLowLevelEngine
	{
	private:
		int *counterTempData_device, *counterTempData_host;

	public:
		void CopyImage(ITMUChar4Image *image_out, const ITMUChar4Image *image_in) const;
		void CopyImage(ITMFloatImage *image_out, const ITMFloatImage *image_in) const;
		void CopyImage(ITMFloat4Image *image_out, const ITMFloat4Image *image_in) const;

		void ConvertColourToIntensity(ITMFloatImage *image_out, const ITMUChar4Image *image_in) const;

		void FilterIntensity(ITMFloatImage *image_out, const ITMFloatImage *image_in) const;

		void FilterSubsample(ITMUChar4Image *image_out, const ITMUChar4Image *image_in) const;
		void FilterSubsample(ITMFloatImage *image_out, const ITMFloatImage *image_in) const;
		void FilterSubsampleWithHoles(ITMFloatImage *image_out, const ITMFloatImage *image_in) const;
		void FilterSubsampleWithHoles(ITMFloat4Image *image_out, const ITMFloat4Image *image_in) const;

		void GradientX(ITMShort4Image *grad_out, const ITMUChar4Image *image_in) const;
		void GradientY(ITMShort4Image *grad_out, const ITMUChar4Image *image_in) const;
		void GradientXY(ITMFloat2Image *grad_out, const ITMFloatImage *image_in) const;

		int CountValidDepths(const ITMFloatImage *image_in) const;

		ITMLowLevelEngine_CUDA(void);
		~ITMLowLevelEngine_CUDA(void);
	};
}
