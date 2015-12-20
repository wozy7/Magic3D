#pragma once
#include "IPointCloud.h"

namespace GPP
{
    enum NormalQuality
    {
        NORMAL_QUALITY_LOW = 0,
        NORMAL_QUALITY_HIGH
    };

    class GPP_EXPORT ConsolidatePointCloud
    {
    public:
        ConsolidatePointCloud();
        ~ConsolidatePointCloud();

        static ErrorCode LaplaceSmooth(IPointCloud* pointCloud, Real positionWeight = 1.0);

        static ErrorCode CalculatePointCloudNormal(IPointCloud* pointCloud, NormalQuality quality = NORMAL_QUALITY_LOW);

        static ErrorCode SmoothNormal(IPointCloud* pointCloud, Real normalWeight = 1.0);

        // isolation should allocate memory first
        // isolation value is between [0, 1], smaller value means more isolated
        // pointCloud shoud have normal
        static ErrorCode CalculateIsolation(const IPointCloud* pointCloud, Real* isolation);
    };
}
