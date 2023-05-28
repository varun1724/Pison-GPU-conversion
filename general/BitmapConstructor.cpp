#include "BitmapConstructor.h"

Bitmap* BitmapConstructor::construct(Record* record, int thread_num, int level_num) {
    Bitmap* bm = NULL;
    if (thread_num == 1) {
        bm = SerialBitmapConstructor::construct(record, level_num);
        bm->type = SEQUENTIAL;
    }
    return bm;
}

BitmapIterator* BitmapConstructor::getIterator(Bitmap* bm) {
    BitmapIterator* bi = NULL;
    if (bm->type == SEQUENTIAL) {
        bi = new SerialBitmapIterator((SerialBitmap*)bm);
        bi->type = SEQUENTIAL;
    }
    return bi;
}