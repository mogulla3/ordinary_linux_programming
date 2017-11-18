
## 第5章

- ストリームに関わるシステムコール
  - `read` : ストリームからバイト列を読み込む
    - `ssize_t read(int fd, void *buf, size_t bufsize)`
  - `write` : ストリームにバイト列を書き込む
    - `ssize_t write(int fd, const void *buf, size_t bufsize)`
  - `open` : ストリームを作る
    - `int open(const char *path, int flags)`
    - `int open(const char *path, int flags, mode_t mode)`
  - `close` : 用済みのストリームを始末する
    - `int close(int fd)`
  
- ファイルディスクリプタ
  - プログラムからストリームを扱うにはファイルディスクリプタを使う
  - カーネルから見るとただの整数値
  - ストリームをプロセスに直接見せることはできない。そこで、カーネルが持っているストリームを番号と対応付け、プロセスには番号でストリームを指定させる
  - 標準入力（`STDIN_FILENO`）は0番、標準出力（`STDOUT_FILENO`）は1番、標準エラー出力（`STDERR_FILENO`）は2番に対応する
  
- ストリームの定義：ファイルディスクリプタで表現され、`read()`または`write()`で操作できるもののこと

## 第6章

- システムコールは不便なところが多い。バイト単位でしか読み書きできないなど
- システムコール呼び出しは関数呼び出しよりもずっと遅い
- stdio : 標準入出力ライブラリ。libcの中でも大部分を占める重要なライブラリ。
- FILE型
  - システムコールレベルでは、ストリームを指すためにファイルディスクリプタ（整数値）を使っていた
  - 一方、stdioでは同じような役割のためにFILEという型へのポインタを使う
  - FILEは、ファイルという名前ではあるが、本書で言うストリームを表現するために使われる型である
- stdioでの標準入出力
  - 標準入力 : `stdin`
  - 標準出力 : `stdout`
  - 標準エラー出力 : `stderr`
- stdioを利用したcatコマンドの実装
  - `fopen`
  - `fclose`
  - `fgetc`
  - `putchar`
