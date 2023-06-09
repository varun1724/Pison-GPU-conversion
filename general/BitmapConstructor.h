#ifndef BITMAPCONSTRUCTOR_H
#define BITMAPCONSTRUCTOR_H

#include <string>
#include "Bitmap.h"
#include "BitmapIterator.h"
#include "../serialSpec/SerialBitmapConstructor.h"
#include "../parallelSpec/ParallelBitmapConstructor.h"
#include "../serialSpec/SerialBitmapIterator.h"
#include "../parallelSpec/ParallelBitmapIterator.h"
#include "Records.h"

class BitmapConstructor {
  public:
    // construct leveled bitmaps for a JSON record
    static Bitmap* construct(Record* record, int thread_num = 1, int level_num = MAX_LEVEL);
    // get bitmap iterator for given bitmap index
    static BitmapIterator* getIterator(Bitmap* bi);
};

#endif