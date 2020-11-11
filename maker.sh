#!/usr/bin/env bash

keymap=${1:-monkeeb}
cd ~/CODE/qmk_firmware/
sudo make planck/rev4:${keymap}-clean
sudo make planck/rev4:${keymap}-dfu
