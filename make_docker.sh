#! /bin/bash
docker run -e keymap=llaaiiqq -e keyboard=v60_type_r -e VERBOSE=1 --rm -v $('pwd'):/qmk:rw edasque/qmk_firmware
