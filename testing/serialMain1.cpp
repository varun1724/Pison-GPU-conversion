#include <chrono>
#include "../general/RecordLoader.h"
#include "../general/BitmapIterator.h"
#include "../general/BitmapConstructor.h"
using namespace std::chrono;

// {$.user.id, $.retweet_count}
std::string query(BitmapIterator* iter) {
    std::string output = "";
    if (iter->isObject()) {
        std::unordered_set<char*> set;

        set.insert((char*)"user");
        set.insert((char*)"text");
        char* key = NULL;
        while ((key = iter->moveToKey(set)) != NULL) {
            if (strcmp(key, "text") == 0) {
                // value of "retweet_count"
                char* value = iter->getValue();
                output.append(value).append(";");
                if (value) free(value);
            } else {
                if (iter->down() == false) continue;  /* value of "user" */
                if (iter->isObject() && iter->moveToKey((char*)"id")) {
                    // value of "id"
                    char* value = iter->getValue();
                    output.append(value).append(";");
                    if (value) free(value);
                }
                iter->up();
            }
        }
    }
    return output;
}

int main() {
    // PATH TO LOCAL SAMPLE SMALL RECORD = "dataset/twitter_sample_smalle_record.json"
    const char* file_path = "/content/drive/MyDrive/pthreads/data/twitter_small_records.json";
    RecordSet* record_set = RecordLoader::loadRecords(file_path);
    if (record_set->size() == 0) {
        std::cout << "record loading fails." << std::endl;
        return -1;
    }
    std::string output = "";

    // set the number of threads for parallel bitmap construction
    int thread_num = 1;

    /* set the number of levels of bitmaps to create, either based on the
     * query or the JSON records. E.g., query $[*].user.id needs three levels
     * (level 0, 1, 2), but the record may be of more than three levels
     */
    int level_num = 2;

    /* process the records one by one: for each one, first build bitmap, then perform
     * the query with a bitmap iterator
     */
    int num_recs = record_set->size();
    Bitmap* bm = NULL;
    //cout << "Num_recs: " << num_recs << endl;
    //int counter = 0;

     // Start clock to measure speeds
    auto start = high_resolution_clock::now();

    for (int i = 0; i < num_recs; i++) {
        //cout << "Counter:" << counter << endl;
        //++counter;
        bm = BitmapConstructor::construct((*record_set)[i], thread_num, level_num);
        BitmapIterator* iter = BitmapConstructor::getIterator(bm);
        std::string out = query(iter);
        // std::cout << "String output: " << out << std::endl;
        output.append(out);
        delete iter;
    }

    // End clock
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cout << "Duration: " << duration.count() << endl;

    // std::cout << "matches are: " << output << std::endl;

    delete bm;

    return 0;
}
