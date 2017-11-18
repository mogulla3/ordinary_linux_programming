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


