#ifndef __CFAKER_H__
#define __CFAKER_H__

#include "cfaker_format.h"
#include "cfaker_locale.h"
#include "cfaker_random.h"

#include "providers/cfaker_bank.h"
#include "providers/cfaker_book.h"
#include "providers/cfaker_job.h"
#include "providers/cfaker_person.h"

int cfaker_init();
void cfaker_free();

#endif  // __CFAKER_H__
