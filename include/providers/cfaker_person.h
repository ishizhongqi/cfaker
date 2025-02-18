#ifndef __CFAKER_PERSON_H__
#define __CFAKER_PERSON_H__

enum cfaker_person_gender {
    CFAKER_PERSON_FEMALE,
    CFAKER_PERSON_MALE,
    CFAKER_PERSON_ANY,
};

const char* cfaker_person_first_name(enum cfaker_person_gender gender);

const char* cfaker_person_last_name();

const char* cfaker_person_prefix(enum cfaker_person_gender gender);

const char* cfaker_person_suffix(enum cfaker_person_gender gender);

const char* cfaker_person_full_name(enum cfaker_person_gender gender);

#endif
