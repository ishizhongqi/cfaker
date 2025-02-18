#include "cfaker_format.h"
#include "cfaker_locale.h"
#include "cfaker_random.h"

#include "providers/cfaker_job.h"
#include "providers/data/cfaker_job_data.h"

const char* cfaker_job_name() {
    enum cfaker_locale locale = cfaker_locale_get();
    switch (locale) {
    case en_US:
        return cfaker_job_en_US.jobs[cfaker_random_int(0, cfaker_job_en_US.job_count - 1)];
        break;
    case zh_CN:
        return cfaker_job_zh_CN.jobs[cfaker_random_int(0, cfaker_job_zh_CN.job_count - 1)];
        break;
    default:
        break;
    }
    return cfaker_job_en_US.jobs[cfaker_random_int(0, cfaker_job_en_US.job_count - 1)];
}
