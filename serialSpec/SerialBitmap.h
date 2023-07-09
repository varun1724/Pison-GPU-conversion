#ifndef SERIALBITMAP_H
#define SERIALBITMAP_H
#include <string>
#include <iostream>
#include <vector>
#include <bitset>
#include <cassert>
#include <stack>
#include <algorithm>
#include <unordered_map>
#include <functional>
#include <math.h>
#include <immintrin.h>
#include "../general/Bitmap.h"

class SerialBitmap : public Bitmap {
    friend class SerialBitmapIterator;
  private:
    char* mRecord;
    // for a single large record, stream length equals to record length
    long long mRecordLength;
    // each temp word has 32 bytes
    long long mNumTmpWords;
    // each word has 64 bytes
    long long mNumWords;
    // structural quote bitmap, used for key field parsing
    unsigned long long *mQuoteBitmap;
    // leveled colon bitmap
    unsigned long long *mLevColonBitmap[MAX_LEVEL];
    // leveled comma bitmap
    unsigned long long *mLevCommaBitmap[MAX_LEVEL];
    // the deepest level of leveled bitmap indexes (starting from 0)
    int mDepth;
    
  public:
    SerialBitmap();
    SerialBitmap(char* record, int level_num);
    ~SerialBitmap();
    void indexConstruction();
    void setRecordLength(long long length);
 
  private:
    void freeMemory();
};
#endif
