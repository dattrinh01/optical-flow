#!/bin/sh
# @file      install_vs_code_extensions.sh
# @author    Ignacio Vizzo     [ivizzo@uni-bonn.de]
#
# Copyright (c) 2019 Ignacio Vizzo, all rights reserved
echo "Installing Visual Studio Code Extension Pack"
code --install-extension ms-vscode.cpptools
code --install-extension jbenden.c-cpp-flylint
code --install-extension twxs.cmake
code --install-extension ms-vscode.cmake-tools
code --install-extension cheshirekow.cmake-format
