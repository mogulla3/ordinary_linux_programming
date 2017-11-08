#include <stdio.h>
#include <stdlib.h>

int
main(int argc, char *argv[])
{
    int i;

    for (i = 1; i < argc; i++) {
        FILE *f;
        int c;

        f = fopen(argv[i], "r");
        if (!f) {
            perror(argv[i]);
            exit(1);
        }

        // EOFに当たるまで fgetc() し続ける
        // fgetc(): 引数のstreamから1byte読み込んで返す
        while ((c = fgetc(f)) != EOF) {
            // putchar(c): put(c, stdout)と同義
            if (putchar(c) < 0) exit(1);
        }

        fclose(f);
    }

    exit(0);
}
