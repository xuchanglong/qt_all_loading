#/** @file         build.sh
# *  @brief        
# *  @details      
# *  @author       xcl
# *  @date         2021-09-22 07:22
# *  @version      v1.0
# *  @copyright    Copyright By xuchanglong, All Rights Reserved
# *
# **********************************************************
# *  @LOG 修改日志:
# **********************************************************
#*/

#!/bin/bash

echo begin

TARGET_NAME=cmake_base_qt
ARCHITECTURE=amd64
VERSION=1.0.0

cp ./code/build/${TARGET_NAME} ./package/etc
sudo dpkg-deb -b ./package ./${TARGET_NAME}-${ARCHITECTURE}-${VERSION}.deb

echo end