#! /bin/bash
docker run -e keymap=llaaiiqq -e keyboard=redox -e VERBOSE=1 --rm -v $('pwd'):/qmk:rw edasque/qmk_firmware
