// Copyright 2014-2017 Oxford University Innovation Limited and the authors of ITM

#pragma once

#include "../Interface/ITMMultiVisualisationEngine.h"

struct RenderingBlock;

namespace ITMLib {

	template<class TVoxel, class TIndex>
	class ITMMultiVisualisationEngine_CUDA : public ITMMultiVisualisationEngine<TVoxel, TIndex>
	{
	private:
		RenderingBlock *renderingBlockList_device;
		uint *noTotalBlocks_device;

	public:
		ITMMultiVisualisationEngine_CUDA(void);
		~ITMMultiVisualisationEngine_CUDA(void);

		ITMRenderState* CreateRenderState(const ITMScene<TVoxel, TIndex> *scene, const Vector2i & imgSize) const;

		void PrepareRenderState(const ITMVoxelMapGraphManager<TVoxel, TIndex> & sceneManager, ITMRenderState *state);

		void CreateExpectedDepths(const ORUtils::SE3Pose *pose, const ITMIntrinsics *intrinsics, ITMRenderState *renderState) const;

		void RenderImage(const ORUtils::SE3Pose *pose, const ITMIntrinsics *intrinsics, ITMRenderState *renderState, ITMUChar4Image *outputImage, IITMVisualisationEngine::RenderImageType type) const;
	};
}