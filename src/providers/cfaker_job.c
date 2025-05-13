#include "cfaker_format.h"
#include "cfaker_locale.h"
#include "cfaker_random.h"

#include "providers/cfaker_job.h"
#include "providers/data/cfaker_job_data.h"

static struct cfaker_job get_cfaker_job() {
    const enum cfaker_locale locale = cfaker_locale_get();
    switch (locale) {
    case en_US:
        return cfaker_job_en_US;
    case zh_CN:
        return cfaker_job_zh_CN;
    default:
        break;
    }
    return cfaker_job_en_US;
}

const char* cfaker_job_name() {
    const struct cfaker_job job = get_cfaker_job();
    return job.names[cfaker_random_uint(0, job.job_count - 1)];
}
