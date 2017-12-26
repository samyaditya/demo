#!/bin/bash
libtool --mode=link gcc -o gamepad -Iprotobuf -lprotobuf-c protobuf/Interface.pb-c.c gamepad.c /usr/local/lib/libSDL2.la
