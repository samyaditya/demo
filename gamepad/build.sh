#!/bin/bash
libtool --mode=link gcc -o gamepad gamepad.c /usr/local/lib/libSDL2.la
