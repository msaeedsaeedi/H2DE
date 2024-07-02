#!/bin/bash

# Exit immediately if a command exits with a non-zero status.
set -e

# Function to check if a specific version of a library is installed using CMake
check_version_installed_cmake() {
    local package_name=$1
    local version=$2

    if cmake --find-package -DNAME=$package_name -DVERSION=$version -DCOMPILER_ID=GNU -DLANGUAGE=C -DMODE=EXIST > /dev/null 2>&1; then
        return 0
    else
        return 1
    fi
}

# Function to clone, build, and install a GitHub repository
install_from_github() {
    local repo_url=$1
    local branch=$2
    local package_name=$3
    local version=$4
    local dir_name=$(basename $repo_url .git)

    echo "Cloning $dir_name repository..."
    git clone --branch $branch $repo_url $dir_name

    echo "Creating build directory for $dir_name..."
    cd $dir_name
    mkdir build
    cd build

    echo "Configuring the build for $dir_name with CMake..."
    cmake ..

    echo "Building $dir_name..."
    make -j$(nproc)

    echo "Installing $dir_name..."
    sudo make install

    echo "$dir_name installation completed."
    cd ../..
}

# Variables for SFML
SFML_VERSION="2.6.1"
SFML_REPO="https://github.com/SFML/SFML.git"

# Variables for libconfig
LIBCONFIG_VERSION="1.7.3"  # You might need to check the latest version if it's not specified in the repository
LIBCONFIG_REPO="https://github.com/hyperrealm/libconfig.git"
LIBCONFIG_PACKAGE_NAME="libconfig"

# Check if SFML is installed
if [ -d "/usr/local/include/SFML" ] && [ -n "$(ls /usr/local/include/SFML)" ]; then
    echo "SFML $SFML_VERSION is already installed."
else
    # Install SFML 2.6.1 if not already installed
    install_from_github $SFML_REPO $SFML_VERSION "SFML" $SFML_VERSION
fi

# Install the latest version of libconfig if not already installed
if check_version_installed_cmake $LIBCONFIG_PACKAGE_NAME $LIBCONFIG_VERSION; then
    echo "libconfig $LIBCONFIG_VERSION is already installed."
else
    install_from_github $LIBCONFIG_REPO "master" $LIBCONFIG_PACKAGE_NAME $LIBCONFIG_VERSION
fi

echo "All installations completed successfully."
