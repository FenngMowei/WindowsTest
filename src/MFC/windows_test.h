#ifndef MFC_DEMO_MFC_H
#define MFC_DEMO_MFC_H

#include <afxwin.h>

class MyApp :public CWinApp {
public:
    virtual BOOL InitInstance();
};

class MyFrame :public CFrameWnd
{
public:
    MyFrame();

};

#endif //MFC_DEMO_MFC_H