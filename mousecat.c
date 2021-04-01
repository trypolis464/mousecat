#include <windows.h>

HHOOK hook;

LRESULT CALLBACK kbhcallback(int code, WPARAM w, LPARAM l) {
    return 1;
}

void wait_to_unhook() {
    DWORD start_time = GetTickCount();
    while (GetTickCount() < (start_time + 30000)) {
    }
    UnhookWindowsHookEx(hook);
    hook = SetWindowsHookEx(WH_MOUSE_LL, kbhcallback, GetModuleHandle(0), 0);
}

int main() {
    hook = SetWindowsHookEx(WH_MOUSE_LL, kbhcallback, GetModuleHandle(0), 0);
    while (1) {
        Sleep(5);
        wait_to_unhook();
    }
}
