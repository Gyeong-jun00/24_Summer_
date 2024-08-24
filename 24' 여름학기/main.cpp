#include "pch.h"
#include <vector>
#include "framework.h"
#include "24' 여름학기.h"

#include "CCore.h"
using std::vector;

// 깜빡이는 문제 -> 더블버퍼링
// 키에 대한 것 -> 문제
// 메세지 있으면 처리함 -> 없으면? 세계가 멈춰있다. (게임 x) -> 강제로 돌리자 TIMER MESSAGE 
// -> 너무 느려. 시스템 함수 호출 

// 메세지 처리 방식 구조를 바꿔야겠다. 
// 게임 프레임 워크

struct objInfo {
    POINT objpos;
    POINT objScale;
};

vector<objInfo> vecInfo;

POINT ptLT;
POINT ptRB;
bool act = false;


// #include <iostream> // c언어의 입출력파일

#define MAX_LOADSTRING 100

// 전역 변수:
HINSTANCE hInst;                                // 현재 인스턴스입니다.
HWND hWnd;
WCHAR szTitle[MAX_LOADSTRING];                  // 제목 표시줄 텍스트입니다.
WCHAR szWindowClass[MAX_LOADSTRING];            // 기본 창 클래스 이름입니다.

// 이 코드 모듈에 포함된 함수의 선언을 전달합니다:
ATOM                MyRegisterClass(HINSTANCE hInstance);
BOOL                InitInstance(HINSTANCE, int);
LRESULT CALLBACK    WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK    About(HWND, UINT, WPARAM, LPARAM);

// 프로그램 시작 지점, 윈도우 운영체제 내부에서 실행되기 시작

// SAL 주석 
int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
                     _In_opt_ HINSTANCE hPrevInstance,
                     _In_ LPWSTR    lpCmdLine,
                     _In_ int       nCmdShow)
{  
    // hinstance : 실행된 프로그램의 시작 주소
    // hPrevInstance : 의미 없음
    // IpCmdLine : 게임 프로그래밍에선 의미가 없음


    // 의미 없음
    UNREFERENCED_PARAMETER(hPrevInstance);
    UNREFERENCED_PARAMETER(lpCmdLine);


    // TODO: 여기에 코드를 입력합니다.

    // 전역 문자열을 초기화합니다.
    LoadStringW(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
    LoadStringW(hInstance, IDC_MY24, szWindowClass, MAX_LOADSTRING);

    // 윈도우 정보 등록
    MyRegisterClass(hInstance);

    // 창을 만드는 작업을 수행 (창 생성)
    if (!InitInstance (hInstance, nCmdShow))
    {
        return FALSE;
    }

    if (FAILED(CCore::Instance()->init(hWnd, POINT{1200, 768}))) {
        MessageBox(nullptr, L"Core 객체 초기화 실패", L"error", MB_OK);
        return FALSE;
    }

    // 단축키 - 단축키가 눌렸는가를 검사하는 부분
    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_MY24));

    MSG msg;

    // 기본 메시지 루프입니다:
    // 프로그램 내부에 메세지 큐가 존재한다.
    // 큐 - 먼저 넣는 애들이 먼저 나옴
    // OS 입장에서는 모든 프로세스를 관리하고 있고 그 메세지를 받게 되어 쌓인다.
    // 여러 메세지 중에서 현재 포커싱하고 있는 프로세스의 메세지를 먼저 처리하라고 한다.

    // msg.message == WM_QUIT 면은 false를 반환하고 프로그램을 종료된다.
    while (true)
    {
        if (PeekMessage(&msg, nullptr, 0, 0, PM_REMOVE)) {
            // 큐를 계속 보고 있어 -> true, false
            if (WM_QUIT == msg.message)
                break;
            if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg))
            {
            TranslateMessage(&msg);
            DispatchMessage(&msg);
            }
        }
        else {
            CCore::Instance()->Progress();
            // 게임 진행이 여기서 된다.
            // Game Code, 디자인 패턴, 싱글톤 패턴 (객체를 하나로 제한)
            // 게임루프(계산, 업데이트)
            // 랜더(그리고)
        }
    }
    return (int)msg.wParam;
}



//
//  함수: MyRegisterClass()
//
//  용도: 창 클래스를 등록합니다.
//
ATOM MyRegisterClass(HINSTANCE hInstance)
{
    WNDCLASSEXW wcex;

    wcex.cbSize = sizeof(WNDCLASSEX);

    wcex.style          = CS_HREDRAW | CS_VREDRAW;
    wcex.lpfnWndProc    = WndProc;
    wcex.cbClsExtra     = 0;
    wcex.cbWndExtra     = 0;
    wcex.hInstance      = hInstance;
    wcex.hIcon          = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_MY24));
    wcex.hCursor        = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground  = (HBRUSH)(COLOR_WINDOW+1);
    wcex.lpszMenuName   = MAKEINTRESOURCEW(IDC_MY24);
    wcex.lpszClassName  = szWindowClass;
    wcex.hIconSm        = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

    return RegisterClassExW(&wcex);
}

//
//   함수: InitInstance(HINSTANCE, int)
//
//   용도: 인스턴스 핸들을 저장하고 주 창을 만듭니다.
//
//   주석:
//
//        이 함수를 통해 인스턴스 핸들을 전역 변수에 저장하고
//        주 프로그램 창을 만든 다음 표시합니다.
//
BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
   hInst = hInstance; // 인스턴스 핸들을 전역 변수에 저장합니다.

   hWnd = CreateWindowW(szWindowClass, szTitle, WS_OVERLAPPEDWINDOW,
      CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, nullptr, nullptr, hInstance, nullptr);

   if (!hWnd)
   {
      return FALSE;
   }

   ShowWindow(hWnd, nCmdShow);
   UpdateWindow(hWnd);

   return TRUE;
}

//
//  함수: WndProc(HWND, UINT, WPARAM, LPARAM)
//
//  용도: 주 창의 메시지를 처리합니다.
//
//  WM_COMMAND  - 애플리케이션 메뉴를 처리합니다.
//  WM_PAINT    - 주 창을 그립니다.
//  WM_DESTROY  - 종료 메시지를 게시하고 반환합니다.
//
//

POINT objpos{ 500, 300 };
POINT objScale{ 100, 100 };

LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    switch (message)
    {
    case WM_COMMAND:
        {
            int wmId = LOWORD(wParam);
            // 메뉴 선택을 구문 분석합니다:
            switch (wmId)
            {
            case IDM_ABOUT:
                DialogBox(hInst, MAKEINTRESOURCE(IDD_ABOUTBOX), hWnd, About);
                break;
            case IDM_EXIT:
                DestroyWindow(hWnd);
                break;
            default:
                return DefWindowProc(hWnd, message, wParam, lParam);
            }
        }
        break;
    case WM_PAINT:  // 무효화 : 영역이 발생한 경우
        // 무효화 : 화면을 갱신하거나 다시 그릴 때를 의미함.
        // 무효화 영역 : 다른 윈도우 창에 가려졌거나 다시 누를 때 겹쳤던 부분
        {
            PAINTSTRUCT ps;
            HDC hdc = BeginPaint(hWnd, &ps);

            HPEN redPen = CreatePen(BS_SOLID, 1, RGB(255, 0, 0));
            HBRUSH blackBrush = (HBRUSH)GetStockObject(BLACK_BRUSH);

            HPEN defaultPen = (HPEN)SelectObject(hdc, redPen);
            HBRUSH defaultBrush = (HBRUSH)SelectObject(hdc, blackBrush);

           /* if (act) {
                Rectangle(hdc, ptLT.x, ptLT.y, ptRB.x, ptRB.y);
            }
            for (size_t i = 0; i < vecInfo.size(); ++i) {
                Rectangle(hdc, vecInfo[i].objpos.x - vecInfo[i].objScale.x / 2
                    , vecInfo[i].objpos.y - vecInfo[i].objScale.y / 2
                    , vecInfo[i].objpos.x + vecInfo[i].objScale.x / 2
                    , vecInfo[i].objpos.y + vecInfo[i].objScale.y / 2);
            }*/

            /*Rectangle(hdc, objpos.x - objScale.x / 2
                , objpos.y - objScale.y / 2
                , objpos.x + objScale.x / 2
                , objpos.y + objScale.y / 2); */
            // hdc : 핸들 - 창
            // Device Context : 그리기 작업할 때 필요한 데이터 모음
            // 

            SelectObject(hdc, defaultPen);
            SelectObject(hdc, defaultBrush);
            DeleteObject(redPen);
            DeleteObject(defaultBrush);

            EndPaint(hWnd, &ps);
        }
        break;

   /* case WM_KEYDOWN:
    {
         switch (wParam) {
         case VK_UP:
             objpos.y -= 10;
             InvalidateRect(hWnd, nullptr, true);
             break;
         case VK_DOWN:
             objpos.y += 10;
             InvalidateRect(hWnd, nullptr, true);
             break;
         case VK_LEFT:
             objpos.x -= 10;
             InvalidateRect(hWnd, nullptr, true);
             break;
         case VK_RIGHT:
             objpos.x += 10;
             InvalidateRect(hWnd, nullptr, true);
             break;
         }
         break;
         

    }*/

    case WM_LBUTTONDOWN:
    {
        ptLT.x = LOWORD(lParam);
        ptLT.y = HIWORD(lParam);
        act = true;
    }
    break;
    case WM_MOUSEMOVE:
    {
        ptRB.x = LOWORD(lParam);
        ptRB.y = HIWORD(lParam);
        InvalidateRect(hWnd, nullptr, true);
    }
    break;
    case WM_LBUTTONUP:
    {
        objInfo info = {};
        info.objpos.x = (ptLT.x + ptRB.x) / 2;
        info.objpos.y = (ptLT.y + ptRB.y) / 2;

        info.objScale.x = abs(ptLT.x - ptRB.x) / 2;
        info.objScale.y = abs(ptLT.y - ptRB.y) / 2;

        vecInfo.push_back(info);
        act = false;
        InvalidateRect(hWnd, nullptr, true);
    }
    break;


    case WM_DESTROY:
        PostQuitMessage(0);
        break;
    default:
        return DefWindowProc(hWnd, message, wParam, lParam);
    }
    return 0;
}

// 정보 대화 상자의 메시지 처리기입니다.
INT_PTR CALLBACK About(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
    UNREFERENCED_PARAMETER(lParam);
    switch (message)
    {
    case WM_INITDIALOG:
        return (INT_PTR)TRUE;

    case WM_COMMAND:
        if (LOWORD(wParam) == IDOK || LOWORD(wParam) == IDCANCEL)
        {
            EndDialog(hDlg, LOWORD(wParam));
            return (INT_PTR)TRUE;
        }
        break;
    }
    return (INT_PTR)FALSE;
}
