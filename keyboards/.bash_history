make git-submodule
cd ..
cd qmk_firmware/
git gc --aggressive
git clone --bare https://github.com/ulralraho/qmk_firmware.git
cd qmk_firmware.git/
ls
git push --mirror https://github.com/ulralraho/qmk_firmware_old.git
cd ..
rm -rf qmk_firmware.git
ls
qmk setup --help
qmk config
qmk config compile
qmk config user.qmk_home
qmk config user.qmk_home="c:\nc\privates\qmk"
qmk setup -H "c:\nc\private\qmk"
qmk config -h
qmk config
qmk setup
qmk config user.qmk_home="C:/nc/privates/qmk_firmware"
qmk setup
python --version
python3 --version
qmk config user.qmk_home=None
qmk setup
qmk compile -kb planck/rev6 -km default
qmk config user.qmk_home="C:/nc/privates/qmk_firmware"
qmk config user.qmk_home="C:/nc/privates"
qmk setup
qmk config user.qmk_home="C:/nc/privates/qmk_firmware"
qmk setup
qmk compile -kb planck/rev6 -km default
qmk compile -kb planck/rev6 -km ulralraho
qmk compile -kb preonic/rev3 -km ulralraho
qmk flash -kb preonic/rev3 -km ulralraho
qmk flash -kb planck/rev6 -km ulralraho
git clone --bare https://github.com/ulralraho/qmk_firmware.git
git clone --bare https://github.com/ulralraho/qmk_firmware_old2.git
cd qmk_firmware_old2.git/
ls
git clone --bare https://github.com/ulralraho/qmk_firmware.git
cd ..
git clone --bare https://github.com/ulralraho/qmk_firmware.git
cd qmk_firmware.git/
git push --mirror https://github.com/ulralraho/qmk_firmware_old2.git
git push --mirror https://github.com/ulralraho/qmk_firmware_old2.git
cd ..
rm -rf qmk_firmware.git/
qmk --help
qmk flash -kb preonic/rev3 -km ulralraho
qmk compile -kb planck/rev6 -km ulralraho
qmk flash -kb preonic/rev3 -km ulralraho
qmk flash -kb preonic/rev3 -km ulralraho
qmk compile -kb planck/rev6 -km ulralraho
pwd
ls -al
