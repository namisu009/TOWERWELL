#include "GameManager.h"
#include <io.h>
#include <fcntl.h>

void setConsoleEncoding() {
    // 표준 출력과 입력을 UTF-8로 설정
    _setmode(_fileno(stdout), _O_U8TEXT); // 유니코드 출력
    _setmode(_fileno(stdin), _O_U8TEXT); // 유니코드 입력
}

int main() {
    setConsoleEncoding();
    GameManager gameManager;
    gameManager.initialize();
    gameManager.start();
    return 0;
}