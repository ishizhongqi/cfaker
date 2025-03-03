# cfaker

`cfaker` is a lightweight fake data generation library written in **C**, designed for cross-platform use, providing efficient and thread-safe fake data generation.

## Features

- Pure C implementation with no external dependencies
- Thread-safe pseudo-random number generation
- Cross-platform support (Linux/Windows/macOS)
- Predefined localized data
- Uses static data storage to avoid dynamic memory allocation

## Installation & Compilation

### Dependencies

- Requires a **C11** or later compiler
- Uses CMake as the build tool

### Build Steps

#### Linux
```sh
mkdir build && cd build
cmake ..
make
```
#### Windows
```sh
mkdir build && cd build
cmake -G "MinGW Makefiles" ..
cmake --build .
```

## Usage

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
    cfaker_free();
    return 0;
}
```

## Localization

Currently supports `en_US` and `zh_CN`

## Fake Data Interface Progress

The current interface is not yet complete include the checked part, I will continue to improve them.

- [ ] Address (`cfaker_address`)
- [x] Bank (`cfaker_bank`)
- [ ] Barcode (`cfaker_barcode`)
- [x] Book (`cfaker_book`)
- [x] Color (`cfaker_color`)
- [x] Company (`cfaker_company`)
- [x] Date & Time (`cfaker_datetime`)
- [ ] Internet (`cfaker_internet`)
- [x] Job (`cfaker_job`)
- [x] Number (`cfaker_number`)
- [x] Person (`cfaker_person`)
- [x] Phone (`cfaker_phone`)
- [ ] Payment (`cfaker_payment`)
- [ ] Uuid (`cfaker_uuid`)
- [ ] ...

## License

MIT License

