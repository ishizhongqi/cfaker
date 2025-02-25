#ifndef __CFAKER_JOB_DATA_H__
#define __CFAKER_JOB_DATA_H__

#include <stddef.h>

struct cfaker_job {
    const char** names; /* List of jobs */
    size_t job_count;   /* Number of jobs */
};

extern const struct cfaker_job cfaker_job_en_US;
extern const struct cfaker_job cfaker_job_zh_CN;

#endif
