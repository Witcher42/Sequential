#import "PPMdContext.h"
#import "PPMdSubAllocatorVariantI.h"

// PPMd Variant I. Used by WinZip.

#define MRM_RESTART 0
#define MRM_CUT_OFF 1
#define MRM_FREEZE 2

typedef struct PPMdModelVariantI
{
	PPMdCoreModel core;

	PPMdSubAllocatorVariantI *alloc;

	uint8_t NS2BSIndx[256],QTable[260]; // constants

	PPMdContext *MaxContext;
	int MaxOrder,MRMethod;
	SEE2Context SEE2Cont[24][32],DummySEE2Cont;
	uint16_t BinSumm[25][64]; // binary SEE-contexts
} PPMdModelVariantI;

void StartPPMdModelVariantI(PPMdModelVariantI *self,CSInputBuffer *input,
PPMdSubAllocatorVariantI *alloc,int maxorder,int restoration);
int NextPPMdVariantIByte(PPMdModelVariantI *self);
