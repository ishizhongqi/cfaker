# cfaker

`cfaker`  is a C library that generates fake data for you. Whether you need to bootstrap your database, create good-looking XML documents, fill-in your persistence to stress test it, or anonymize data taken from a production service, cfaker is for you.

## Installation

### Dependencies

* C11 or Later Compiler: Required for thread-local storage (_Thread_local) and modern C features. Supported compilers include:
  * GCC: Version 4.8 or later (common on Linux).
  * Clang: Version 3.3 or later (default on macOS via Xcode).
  * MSVC: Visual Studio 2015 or later (Windows).
* CMake: Build tool (version 3.10 or higher recommended).

### Build steps

#### Linux & macOS
```sh
mkdir build && cd build
cmake ..
make
```
#### Windows
* MinGW (GCC):
```sh
mkdir build && cd build
cmake -G "MinGW Makefiles" ..
cmake --build .
```

* MSVC (Visual Studio):
```sh
mkdir build && cd build
cmake -G "Visual Studio 17 2022" .. -A x64
cmake --build .
```

## Usage

Place `libcfaker.a` or `cfaker.lib` in your project and include it in your CMake or Makefile to start using it.

* Example:
```c
#include "cfaker.h"
int main() {
    int ret = cfaker_init(); // Initialize cfaker
    if (ret != 0) {
        return 1;
    }
    cfaker_locale_set(zh_CN);  // If not set, the default is en_US.
    printf("First name: %s\n", cfaker_person_first_name(CFAKER_PERSON_MALE));
    printf("Last name: %s\n", cfaker_person_last_name());
    printf("Full name: %s\n", cfaker_person_full_name(CFAKER_PERSON_FEMALE));
    cfaker_free(); // Free cfaker
    return 0;
}
```

## Localization

Currently supports the following locales:

* `en_US`: English (United States)
* `zh_CN`: Simplified Chinese (China)

You can set the locale using `cfaker_locale_set(enum cfaker_locale locale)` or `cfaker_locale_set_bystring(const char* locale)`. If no locale is set, `en_US` is used by default.

### Supported Locales
See `cfaker_locales.h` for the full list of available locales (currently limited to `en_US` and `zh_CN`, with plans for expansion).

## Fake Data Interface Progress

The library provides a variety of fake data generation interfaces. Below is the current progress (checked items are implemented):

- [ ] **Address** (`cfaker_address`): Generate fake addresses.
- [x] **Bank** (`cfaker_bank`): Generate bank names.
- [x] **Book** (`cfaker_book`): Generate book titles, authors, genres, etc.
- [x] **Color** (`cfaker_color`): Generate color names and various color formats (RGB, HEX, etc.).
- [x] **Company** (`cfaker_company`): Generate company names, prefixes, and suffixes.
- [x] **Date & Time** (`cfaker_datetime`): Generate dates, times, and timestamps.
- [x] **Internet** (`cfaker_internet`): Generate emails, URLs, etc.
- [x] **Job** (`cfaker_job`): Generate job titles.
- [x] **Number** (`cfaker_number`): Generate random integers, doubles, and formatted numbers (hex, octal, binary).
- [x] **Person** (`cfaker_person`): Generate names, prefixes, and suffixes.
- [x] **Phone** (`cfaker_phone`): Generate phone numbers with country codes.
- [ ] **Payment** (`cfaker_payment`): Generate credit card numbers, etc.
- [x] **UUID** (`cfaker_uuid`): Generate UUIDs.
- [ ] **More to come...**: Open to suggestions for additional providers!

See individual provider headers (e.g., providers/cfaker_person.h) for detailed function documentation.  
I will continue to improve and expand the library with new interfaces and locale support.

## License

Licensed under the [MIT License](LICENSE).
