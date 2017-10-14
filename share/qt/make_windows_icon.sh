#!/bin/bash
# create multiresolution windows icon
ICON_SRC=../../src/qt/res/icons/mudcoin.png
ICON_DST=../../src/qt/res/icons/mudcoin.ico
convert ${ICON_SRC} -resize 16x16 mudcoin-16.png
convert ${ICON_SRC} -resize 32x32 mudcoin-32.png
convert ${ICON_SRC} -resize 48x48 mudcoin-48.png
convert mudcoin-48.png mudcoin-32.png mudcoin-16.png ${ICON_DST}

