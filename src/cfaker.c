#include "cfaker.h"

int cfaker_init() {
    cfaker_random_init(1024);
    cfaker_format_init(1024);
    return 0;
}

void cfaker_free() {
    cfaker_random_free();
    cfaker_format_free();
}
