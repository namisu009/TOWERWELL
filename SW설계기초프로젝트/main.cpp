#include "GameManager.h"
#include <io.h>
#include <fcntl.h>

void setConsoleEncoding() {
    // 표준 출력과 입력을 UTF-8로 설정
    _setmode(_fileno(stdout), _O_U8TEXT);
    _setmode(_fileno(stdin), _O_U8TEXT);
}

int main() {
    setConsoleEncoding();
    GameManager gameManager;
    gameManager.initialize();
    gameManager.start();
    return 0;
}