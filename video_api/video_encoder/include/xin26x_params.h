/***************************************************************************//**
*
* @file          xin26x_params.h
* @brief         This files contains h26x encoder configuration api.
* @authors       Pig Peppa
* @copyright     (c) 2020, Pig Peppa <pig.peppa@qq.com>  All rights reserved
*
*******************************************************************************/
#ifndef _xin26x_params_h_
#define _xin26x_params_h_

#include "xin26x_logger.h"

#ifdef __cplusplus
extern "C" {
#endif

#define XIN26X_OPTION_SET_IDR               0
#define XIN26X_OPTION_SET_FPS               1
#define XIN26X_OPTION_SET_BITRATE           2
#define XIN26X_OPTION_SET_TEMPLAYER         3
#define XIN26X_OPTION_SET_RCMODE            4
#define XIN26X_OPTION_GET_PSNR              5
#define XIN26X_DYN_COMMAND_INVALID          (255)

#define XIN26X_STAT_NONE                    0
#define XIN26X_STAT_SEQ                     1
#define XIN26X_STAT_PIC                     2

typedef struct xin_frame_desc
{
    UINT8      *yuvBuf[3];

    UINT32     lumaWidth;
    UINT32     lumaHeight;

    intptr_t   lumaStride;
    intptr_t   chromaStride;

} xin_frame_desc;

typedef struct xin_out_buf_desc
{
    UINT8   *bitsBuf;
    SINT32  bytesGenerate;
    UINT32  temporalLayer;

} xin_out_buf_desc;

typedef struct xin26x_params
{
    UINT32      inputWidth;
    UINT32      inputHeight;

    float       frameRate;
    UINT32      bitRate;
    UINT32      minQp;
    UINT32      maxQp;
    UINT32      rcMode;
    BOOL        frameSkip;
    UINT32      encoderMode;
    UINT32      algorithmMode;

    UINT32      frameToBeEncoded;

    UINT32      bFrameNum;
    UINT32      refFrameNum;
    UINT32      refreshType;
    UINT32      temporalLayerNum;

    UINT32      intraPeriod;

    UINT32      screenContentMode;

    UINT32      bitDepth;

    UINT32      minCbSize;
    UINT32      maxCbSize;

    UINT32      minTbSize;
    UINT32      maxTbSize;

    UINT32      interTbDepth;
    UINT32      intraTbDepth;

    UINT32      qp;

    BOOL        calcPsnr;

    BOOL        enableSao;

    BOOL        enableStrongIntraSmoothing;
    BOOL        enableTMvp;

    BOOL        enableSignDataHiding;
    
    BOOL        enableRdoq;

    BOOL        enableIntraNxN;
    BOOL        enableInterNxN;

    BOOL        constrainedIntraPredFlag;

    BOOL        transformSkipFlag;

    BOOL        enableCuQpDelta;
    UINT32      diffCuQpDeltaDepth;

    UINT32      motionSearchMode;
    UINT32      searchRange;

    BOOL        enableSmp;
    BOOL        enableAmp;

    // h266 settings
    UINT32      ctuSize;
    UINT32      minQtSize;
    UINT32      maxBtSize;
    UINT32      maxTtSize;
    UINT32      maxMttDepth;
    UINT32      minCuSize;
    BOOL        lumaTrSize64;

    // av1 settings
    UINT32      sbSize;
    BOOL        enableRectPartType;

    BOOL        enableMultiThread;
    UINT32      threadNum;
    BOOL        enableWpp;
    BOOL        enableFpp;
    UINT32      numTileCols;
    UINT32      numTileRows;
    BOOL        unitTree;
    UINT32      lookAhead;
    UINT32      laThreadNum;
    double      unitTreeStrength;

    BOOL        disableDeblockFilter;
    XinLogEntry pfXinLogEntry;
    UINT32      statLevel;

} xin26x_params;

typedef struct xin26x_dynamic_params
{
    UINT32      optionId;
    float       frameRate;
    UINT32      bitRate;
    UINT32      temporalLayerNum;
    UINT32      rcMode;
    double      psnrYuv[3];

} xin26x_dynamic_params;

#ifdef __cplusplus
}
#endif
#endif
