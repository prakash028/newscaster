// WidgieThread.cpp : implementation file
//

#include "stdafx.h"
#include <afxsock.h>

#include "Widgie.h"
#include "WidgieThread.h"
#include "WidgieDlg.h"
#include "Picture.h"
#include "utils.h"

#include <sys/types.h>
#include <sys/stat.h>


#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif


/** 
 *  CLASS WidgieThread
 *  Implements a thread for newsbar dialog so that the 
 *  other components of the system do not effect the newsflash
 *  operation. 
 *
 *  The newsflash doesn't effect the operation of other components either
 *  
 *  This have been implemented in order to maintain real-time behaviour
 */


IMPLEMENT_DYNCREATE(WidgieThread, CWinThread)




WidgieThread::WidgieThread()
{
	OutDebugs( "WidgieThread::WidgieThread()" );
	running = TRUE;
}

WidgieThread::~WidgieThread()
{
	OutDebugs( "WidgieThread::~WidgieThread()" );


	OutDebugs( "WidgieThread::~WidgieThread() Done." );
}

/**
 *  Implements the event handler that is called when an new thread it created
 *
 *  creates a newsbar ans starts it operating.
 *
 *
 */

BOOL WidgieThread::InitInstance()
{
    /* Display the newsbar */	
	m_pMainWnd->Create( IDD_WIDGIE_DIALOG, NULL);

	m_pMainWnd->ShowDialog(1);
	return TRUE;
}

int WidgieThread::ExitInstance()
{
	// TODO:  perform any per-thread cleanup here
	OutDebugs( "WidgieThread::ExitInstance" );   
	return CWinThread::ExitInstance();
}



BEGIN_MESSAGE_MAP(WidgieThread, CWinThread)
	//{{AFX_MSG_MAP(WidgieThread)
		// NOTE - the ClassWizard will add and remove mapping macros here.
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()



/** 
 *  Destroys the newBar and the thread
 *
 *  A method that the main thread in the application can use to kill
 *  this thread and the CNewsBar
 *
 */

void WidgieThread::Die()
{
	running = FALSE;

	OutDebugs( "WidgieThread - Die" );

//	AfxEndThread(1);
}
