#pragma once
#include <sys/time.h>
#include <sys/types.h>

// --- Windows 实现 ---
#if defined(_WIN32) || defined(_WIN64)
#include <conio.h>

inline void
setupConsole ()
{ /* Windows 不需要特殊设置 */
}
inline void
restoreConsole ()
{ /* Windows 不需要特殊还原 */
}

// 检测是否有按键被按下
inline bool
kbhit ()
{
    return _kbhit () != 0;
}

// 获取按键字符 (不回显)
inline char
getch ()
{
    return _getch ();
}

// --- Linux / macOS 实现 ---
#else
#include <fcntl.h>
#include <stdio.h>
#include <termios.h>
#include <unistd.h>

// 保持终端的原始设置，以便退出时恢复
static struct termios original_termios;

// 禁用行缓冲和回显 (进入 Raw Mode)
inline void
setupConsole ()
{
    tcgetattr (STDIN_FILENO, &original_termios);
    struct termios new_termios = original_termios;

    // ICANON: 关闭规范模式 (不需要按回车)
    // ECHO: 关闭回显 (按键不显示在屏幕上)
    new_termios.c_lflag &= ~static_cast<tcflag_t> (ICANON | ECHO);

    tcsetattr (STDIN_FILENO, TCSANOW, &new_termios);

    // 设置非阻塞读取
    int flags = fcntl (STDIN_FILENO, F_GETFL, 0);
    fcntl (STDIN_FILENO, F_SETFL, flags | O_NONBLOCK);
}

// 恢复终端设置
inline void
restoreConsole ()
{
    tcsetattr (STDIN_FILENO, TCSANOW, &original_termios);
}

// 检测是否有按键被按下
inline bool
kbhit ()
{
    struct timeval tv = { 0L, 0L };
    fd_set fds;
    FD_ZERO (&fds);
    FD_SET (STDIN_FILENO, &fds);
    return select (STDIN_FILENO + 1, &fds, NULL, NULL, &tv) > 0;
}

// 获取按键字符
inline char
getch ()
{
    char ch = 0;
    if (read (STDIN_FILENO, &ch, 1) < 0)
        {
            return 0;
        }
    return ch;
}
#endif
