#!/bin/bash

# Exit immediately if a command exits with a non-zero status.
set -e

# Function to clone, build, and install a GitHub repository
install_from_github() {
    local repo_url=$1
    local branch=$2
    local package_name=$3
    local version=$4
    local dir_name=$(basename $repo_url .git)

    cd external/

    echo "Cloning $dir_name repository..."
    git clone --branch $branch $repo_url $dir_name

    echo "$dir_name installation completed."
    cd ../../..
}

# Variables for SFML
SFML_VERSION="2.6.1"
SFML_REPO="https://github.com/SFML/SFML.git"

# Variables for libconfig
LIBCONFIG_VERSION="1.7.3"
LIBCONFIG_REPO="https://github.com/hyperrealm/libconfig.git"
LIBCONFIG_PACKAGE_NAME="libconfig"

# Check if SFML is installed
if [ -d "external/SFML" ] && [ -n "$(ls external/SFML)" ]; then
    echo "SFML $SFML_VERSION is already installed."
else
    # Install SFML 2.6.1 if not already installed
    install_from_github $SFML_REPO $SFML_VERSION "SFML" $SFML_VERSION
fi

# Install the latest version of libconfig if not already installed
if [ -d "external/libconfig" ] && [ -n "$(ls external/libconfig)" ]; then
    echo "libconfig $LIBCONFIG_VERSION is already installed."
else
    install_from_github $LIBCONFIG_REPO "master" $LIBCONFIG_PACKAGE_NAME $LIBCONFIG_VERSION
fi

echo "All installations completed successfully."
