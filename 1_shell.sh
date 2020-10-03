touch 1_sh.txt

ln -s 1_sh.txt 1_a_sh_softlink

ln 1_sh.txt 1_b_sh_hardlink

mknod 1_myfifo p
