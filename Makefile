ifdef OS
   RM = rmdir /q /s
	 MK = @rmdir bin & mkdir
else
   ifeq ($(shell uname), Linux)
      RM = rm -f
			MK = @mkdir -p
   endif
endif

bin/app: src/main.cpp
	$(MK) bin
	@g++ $^ -o bin/out

run: bin/app
	@bin/out

make clean:
	$(RM) bin