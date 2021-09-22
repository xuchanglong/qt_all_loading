#/** @file         build.sh
# *  @brief        
# *  @details      
# *  @author       xcl
# *  @date         2021-09-23 06:37
# *  @version      v1.0
# *  @copyright    Copyright By xuchanglong, All Rights Reserved
# *
# **********************************************************
# *  @LOG 修改日志:
# **********************************************************
#*/

#!/bin/bash

echo begin

TARGET_NAME=all_loading
ARCHITECTURE=amd64
VERSION=1.0.0

cp ./code/build/${TARGET_NAME} ./package/etc/qt_all_loading
sudo dpkg-deb -b ./package ./${TARGET_NAME}-${ARCHITECTURE}-${VERSION}.deb

echo end