#include <Windows.h>


LRESULT CALLBACK MainWinProc(HWND, UINT, WPARAM, LPARAM);
HINSTANCE h;

int WINAPI WinMain(HINSTANCE hInst, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nShowCmd) {

WNDCLASS wc;
HWND hwnd;
MSG msg;

wc.style = 0;
wc.lpfnWndProc = MainWinProc;
wc.cbClsExtra = wc.cbWndExtra=0;
wc.hInstance = hInst;
wc.hIcon = NULL;
wc.hCursor = NULL;
wc.hbrBackground = (HBRUSH)(COLOR_WINDOW+1);
wc.lpszMenuName = "-=Egor_Sigma_SL4YER=-";
wc.lpszClassName = "__MegaEgorSigmaTop1ImbaMetaTop1__";

if(!RegisterClass(&wc)) { return FALSE; }

hwnd = CreateWindowA("__MegaEgorSigmaTop1ImbaMetaTop1__", "-=Egor_Sigma_SL4YER=-", WS_OVERLAPPEDWINDOW,
                     CW_USEDEFAULT,CW_USEDEFAULT,CW_USEDEFAULT,CW_USEDEFAULT,NULL,NULL,hInst,NULL);

if(!hwnd) { return FALSE; }

ShowWindow(hwnd, nShowCmd);
UpdateWindow(hwnd);

while (GetMessage(&msg, NULL, 0, 0)) {
TranslateMessage(&msg);
DispatchMessage(&msg);
}

return msg.wParam;
}

LRESULT CALLBACK MainWinProc(HWND hwnd, UINT msg, WPARAM wp, LPARAM lp) {

switch (msg) {

case WM_CREATE:
CreateWindow("Button", TEXT("button1"), WS_CHILD | WS_VISIBLE | BS_TEXT, 50, 50
, 80, 30, hwnd, (HMENU)1, NULL, NULL);

CreateWindow("Button", TEXT("button2"), WS_CHILD | WS_VISIBLE | BS_TEXT, 150, 50
, 80, 30, hwnd, (HMENU)2, NULL, NULL);

CreateWindow("Button", TEXT("button3"), WS_CHILD | WS_VISIBLE | BS_TEXT, 250, 50
, 80, 30, hwnd, (HMENU)3, NULL, NULL);
        CreateWindow("Button", TEXT("button4"), WS_CHILD | WS_VISIBLE | BS_TEXT, 350, 50
        , 80, 30, hwnd, (HMENU)4, NULL, NULL);



return 0;
case WM_COMMAND:
if (LOWORD(wp) == 1) {
MessageBox(hwnd, "button is pressed (modal)", "Info", MB_OK | MB_ICONINFORMATION);
} else if (LOWORD(wp) == 2) {
MessageBox(NULL, " button is pressed (non-modal)", "Info", MB_OK | MB_ICONINFORMATION);
} else if (LOWORD(wp) == 3) {
MessageBox(hwnd, "sigma", "S1gma_Egor", MB_OK | MB_ICONINFORMATION);
MessageBox(hwnd, "non-sigma", "S1gma_Egor", MB_OK | MB_ICONINFORMATION);
}
else if (LOWORD(wp) == 4) {
    MessageBox(hwnd, "sigma_penis", "S1gma_Egor", MB_OK | MB_ICONINFORMATION);
}

return 0;
case WM_DESTROY:
PostQuitMessage(0);
return 0;
}

return DefWindowProc(hwnd, msg, wp, lp);
}