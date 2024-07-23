# Harmony 2D Engine (H2DE)

[![Build Status](https://github.com/msaeedsaeedi/H2DE/actions/workflows/build.yml/badge.svg)](https://github.com/msaeedsaeedi/H2DE/actions)
[![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg)](https://opensource.org/licenses/MIT)
[![Documentation](https://img.shields.io/badge/docs-h2de.vercel.com-blue.svg)](https://h2de.vercel.com)

## Overview

Harmony 2D Engine (H2DE) is a modern, open-source game engine written in C++ using SFML for rendering. It is designed to simplify the game development process in C++. Currently, it supports Linux, with future plans to support Windows. This project is in its initial stages, and contributions are welcome.

## Features

- **Easy to Use:** Designed to simplify game development using C++.
- **SFML Rendering:** Utilizes SFML for efficient 2D rendering.
- **Cross-Platform:** Linux support, with Windows support planned.
- **Open Source:** Free to use and contribute to.
- **Modern Documentation:** Using Fumadocs for clean, accessible documentation.
- **Quality Assurance:** Tests written with gtest for high quality.

## Getting Started

### Prerequisites

- **Linux:** A Linux distribution.
- **C++ Compiler:** A modern C++ compiler (e.g., GCC, Clang).
- **CMake:** Version 3.30 or higher.
- **SFML:** Version 2.6.1 or higher.
- **GTest** Version 1.15.0 or higher.

### Installation

1. **Clone the Repository:**
    ```sh
    git clone https://github.com/msaeedsaeedi/H2DE.git
    cd H2DE
    ```
2. **Bootstrap**
    ```sh
    chmod +x bootstrap.sh
    ./bootstrap.sh
    ```

3. **Build the Engine:**
    ```sh
    mkdir build
    cd build
    cmake ..
    make
    ```

3. **Run Tests:**
    ```sh
    ctest
    ```

### Documentation

The full documentation is available [here](https://h2de.vercel.com). Documentation includes setup guides, API references, and examples.

## Contributing

Contributions are welcome! Please read our [Contributing Guidelines](CONTRIBUTING.md) for more information.

### Contributor List

Special thanks to all the contributors:

- **Muhammad Saeed Saeedi** - [msaeedsaeedi](https://github.com/msaeedsaeedi)

## License

H2DE is licensed under the MIT License. See the [LICENSE](LICENSE) file for more details.

## Code of Conduct

Please note that this project adheres to a [Code of Conduct](CODE_OF_CONDUCT.md). By participating, you are expected to uphold this code.

## Contact

If you have any questions or suggestions, feel free to open an issue or contact the maintainer:

- **Muhammad Saeed Saeedi** - [msaeedsaeedi](https://github.com/msaeedsaeedi)

## Acknowledgements

- **SFML:** Simple and Fast Multimedia Library
- **Fumadocs:** Documentation framework for modern documentation
- **gtest:** Google Test framework for testing

## Future Plans

- **Windows Support:** Plan to add Windows support using CMake for easy integration.
- **Custom Domain:** Planning to migrate documentation to a custom domain.

---

*Note: H2DE is a fun project aimed at improving skills and providing an open-source solution for game development. It is completely free, and everyone is welcome to use it, but no one can claim its copyright or ownership.*

