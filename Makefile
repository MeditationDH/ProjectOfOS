# SRC:=pmtest9.asm
SRC:=task1.asm
BIN:=$(subst .asm,.com,$(SRC))

.PHONY : everything

everything : $(BIN)
	sudo mount -o loop pmtest.img /mnt/floppy/
	sudo cp $(BIN) /mnt/floppy/ -v
	sudo umount /mnt/floppy/

$(BIN) : $(SRC)
	nasm $< -o $@

