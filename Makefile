mycalc: mycalc.c
	gcc -o mycalc mycalc.c -lraylib -Wall -Wextra -Werror

release: mycalc.c
	mkdir release
	gcc -o release/mycalc-linux-x86_64 mycalc.c -lraylib -Wall -Wextra -Werror
	tar -czf release/mycalc-linux-x86_64.tar.gz release/mycalc-linux-x86_64
