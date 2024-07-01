
# C++ CMake Project Template

This repository provides a template for C++ projects using CMake with custom styling and equipped with GTest for unit testing.

## Features

- **CMake Support**: Easy project setup and building.
- **Custom Styling**: Integrated `.clang-format` for consistent code styling.
- **Editor Configuration**: `.editorconfig` for consistent editor settings.
- **Unit Testing**: GTest integration for writing and running tests.
- **.gitignore**: Pre-configured `.gitignore` for common C++ projects.

## Getting Started

### Prerequisites

- CMake 3.22 or higher
- A C++ compiler
- Git
- GTest (if not already installed)

### Installation

1. **Clone the Repository**

   ```sh
   git clone https://github.com/yourusername/cmake-project-template.git
   cd cmake-project-template
   ```

2. **Configure the Project**

   Create a build directory and configure the project using CMake:

   ```sh
   mkdir build
   cd build
   cmake ..
   ```

3. **Build the Project**

   ```sh
   cmake --build .
   ```

4. **Run Tests**

   ```sh
   ctest
   ```

## Project Structure

```
cmake-project-template/
├── .clang-format        # Custom styling configuration
├── .editorconfig        # Editor configuration
├── .gitignore           # Git ignore file
├── CMakeLists.txt       # Main CMake configuration file
├── src/
│   └── main.cpp         # Main source file
└── test/
    ├── CMakeLists.txt   # CMake configuration file for tests
    ├── test_main.cpp    # Main test file
    └── src/
        └── temp_test.cpp # Example test file
```

## Custom Styling

The project includes a `.clang-format` file to ensure consistent code styling. Customize it as needed to fit your coding standards.

## Contributions

Contributions are welcome! Please open an issue or submit a pull request if you have suggestions for improvements or new features.

## License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.

## Acknowledgments

- [CMake](https://cmake.org/)
- [GTest](https://github.com/google/googletest)
