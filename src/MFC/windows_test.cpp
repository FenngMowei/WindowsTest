#include "windows_test.h"
#include "windows_test.h"

MyApp app;

BOOL MyApp::InitInstance()
{
    MyFrame* frame = new MyFrame;
    frame->ShowWindow(SW_SHOWNORMAL);
    frame->UpdateWindow();

    m_pMainWnd = frame;

    return TRUE;
}

MyFrame::MyFrame() {
    Create(NULL, TEXT("mfc"));
}
