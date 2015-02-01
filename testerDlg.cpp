// testerDlg.cpp : implementation file
//

#include "stdafx.h"
#include "tester.h"
#include "testerDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif


/////////////////////////////////////////////////////////////////////////////
// CAboutDlg dialog used for App About

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// Dialog Data
	//{{AFX_DATA(CAboutDlg)
	enum { IDD = IDD_ABOUTBOX };
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAboutDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	//{{AFX_MSG(CAboutDlg)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
	//{{AFX_DATA_INIT(CAboutDlg)
	//}}AFX_DATA_INIT
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAboutDlg)
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
	//{{AFX_MSG_MAP(CAboutDlg)
		// No message handlers
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CTesterDlg dialog

CTesterDlg::CTesterDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CTesterDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CTesterDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CTesterDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CTesterDlg)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CTesterDlg, CDialog)
	//{{AFX_MSG_MAP(CTesterDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CTesterDlg message handlers

BOOL CTesterDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		CString strAboutMenu;
		strAboutMenu.LoadString(IDS_ABOUTBOX);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon
	
	// TODO: Add extra initialization here
	
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CTesterDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CTesterDlg::OnPaint() 
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, (WPARAM) dc.GetSafeHdc(), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

// The system calls this to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CTesterDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}


void CTesterDlg::OnCancel() 
{
	// TODO: Add extra cleanup here
	
	CDialog::OnCancel();
}

// ����Ϊ�Լ��Ĳ��Դ��롣
//------------------------- test001: ����oemsbl ������㷨�Ĳ�����.--------------------------------------------
//---------------------------------------------------------------------------------------------------------------
CString my_test_program(CString str_start,CString str_end)
{
	long l_start = 0;
	long l_end = 0;
	long l_result = 0;
	long ii = 0;
	long m1=0;
	long m2=0;
	CString str_result;

	sscanf(str_start, "%d", &l_start);
	sscanf(str_end, "%d", &l_end);
	for(ii=l_start;ii<l_end;ii++)
	{
		m1 = (ii+16383)/(16384);
		m2 = (ii+15871)/(15872);

		if((m2-m1)>=1)
		{
			l_result++;
		}
	}
	
	//sscanf(l_result/(str_end-str_start)*100, "%s", &str_result);
	str_result.Format("%f", (l_result*100.0)/(l_end-l_start));

	str_result = "��������Ϊ��" + str_result + "%";

	return str_result;
}


//------------------------- test0002: �������ֽڶ����sizeof()��ֵ.--------------------------------------------
//---------------------------------------------------------------------------------------------------------------
// 
#pragma pack(2)

typedef struct tagABC
{
    unsigned char ucpa1:2;
    unsigned char ucPa2:1;
    unsigned char ucpa3:7;
    unsigned char ucpa4:6;
    unsigned char ucpa5:4;
    unsigned char ucpa6:4;
    unsigned char ulpa8;
	
    unsigned long ulpa9;
}ABCD;

//------------------------- test0003: ����һ��100K��ȫΪ�ض��ַ����ļ�.--------------------------------------------
//---------------------------------------------------------------------------------------------------------------
//
#define FILE_LEN  100*1024
#define FILE_CHAR  1

int creat_file()
{
	FILE *fpsrc=NULL;
    unsigned char buffer[1024];
	int flag=0;
	int ii=0;

	memset(buffer,sizeof(buffer),FILE_CHAR);

	if(fpsrc = fopen("test.bin","wb"))
    {
	}
    else 
	{
		return 2;
	}

	while (ii<FILE_LEN)
	{
		if(fwrite( buffer,sizeof(buffer),1,fpsrc )!=sizeof(buffer))
		{
			//return 3;
		}

		ii+=sizeof(buffer);
	}

	if(fclose ( fpsrc )!=0)
	{
		return 4;
	};

   return 0;
}

//------------------------- test0004: ��֤�ֽ���ת�Ĵ���.--------------------------------------------
//---------------------------------------------------------------------------------------------------------------
//
int dword_order_change()
{
    int transaction_id = 0xFB0000;
	return (transaction_id>>16)+(((transaction_id)&0xFFFF)<<16);

	//return ((transaction_id)&0xFFFF)<<16;
}

//------------------------- test0005: ��֤##��ʹ��.--------------------------------------------
//---------------------------------------------------------------------------------------------------------------
//
#define   paster(n)    sprintf(mystring,"token" #n " = %d", token##n)

static char mystring[20];

char * link_test()
{
    int token3 = 4;
    int tokenn = 3;

    paster(3);

	return mystring;
}


//------------------------- test006: ȡGPIO ��ַ.--------------------------------------------
//---------------------------------------------------------------------------------------------------------------
CString my_test_program2(CString str_start,CString str_end,CString str_other)
{
	#define GPIO_POLARITY_MASK      0x3UL
	#define GPIO_SIGNAL_MASK        0x000fUL
	#define GPIO_SIGNAL_POSITION    0x0000UL
	#define GPIO_REGISTER_MASK      0x00f0UL
	#define GPIO_REGISTER_POSITION  0x0004UL
	#define GPIO_NUMBER_MASK        0xff00UL
	#define GPIO_NUMBER_POSITION    0x0008UL
	#define GPIO_DIRECTION_MASK     0x10000UL
	#define GPIO_DIRECTION_POSITION 0x10UL
	#define GPIO_PULL_MASK          0x60000UL
	#define GPIO_PULL_POSITION      0x11UL

	long l_start = 0;
	long l_end = 0;
	long l_other = 0;
	long l_result = 0;

	long GPIO_INPUT = 0;

	CString str_result;

	sscanf(str_start, "%d", &l_start);
	sscanf(str_end, "%d", &l_end);	
	sscanf(str_other, "%d", &l_other);

	if(l_other == 1)
	{
		l_other = 0;
		GPIO_INPUT = 1;
	}

	l_result = (((l_start)<<GPIO_NUMBER_POSITION & GPIO_NUMBER_MASK) 
		| ((l_end)<<GPIO_REGISTER_POSITION &GPIO_REGISTER_MASK) 
		| ((0)&GPIO_SIGNAL_MASK) | ((GPIO_INPUT)<<GPIO_DIRECTION_POSITION & GPIO_DIRECTION_MASK) 
		| ((l_other)<<GPIO_PULL_POSITION & GPIO_PULL_MASK));
	
	//sscanf(l_result/(str_end-str_start)*100, "%s", &str_result);
	str_result.Format("0x%x--%d", l_result,l_result);

	str_result = "GPIO ��ַΪ��" + str_result + "..\n\r\n\r------------------" + "\n\r\n\r"
		+ "�����GPIO_OUT������threeһ��д��1��" + "\n\r\n\r" + "����2��ʾdown��3��ʾup.";

	return str_result;
}

//------------------------- test007: ���������ӡ.--------------------------------------------
//---------------------------------------------------------------------------------------------------------------
typedef enum
  {
  ACK,                    /* Success. Send an acknowledgement.           */
  NAK_INVALID_FCS,        /* Failure: invalid frame check sequence.      */
  NAK_INVALID_DEST,       /* Failure: destination address is invalid.    */
  NAK_INVALID_LEN,        /* Failure: operation length is invalid.       */
  NAK_EARLY_END,          /* Failure: packet was too short for this cmd. */
  NAK_TOO_LARGE,          /* Failure: packet was too long for my buffer. */
  NAK_INVALID_CMD,        /* Failure: packet command code was unknown.   */
  NAK_FAILED,             /* Failure: operation did not succeed.         */
  NAK_WRONG_IID,          /* Failure: intelligent ID code was wrong.     */
  NAK_BAD_VPP,            /* Failure: programming voltage out of spec    */
  NAK_OP_NOT_PERMITTED,   /* Failure: memory dump not permitted          */
  NAK_INVALID_ADDR,       /* Failure: invalid address for a memory read  */
  NAK_VERIFY_FAILED,      /* Failure: readback verify did not match      */
  NAK_NO_SEC_CODE,        /* Failure: not permitted without unlock       */
  NAK_BAD_SEC_CODE,        /* Failure: invalid security code              */
  NAK_MD5_RSA_RECEIVE_ERROR,        /* MD5_RSA������ʧ�� */
  NAK_CRC_RECEIVE_ERROR,            /* CRC������ʧ�� */
  NAK_CRC_LENGTCH_ERROR,            /* CRC�����ֽ���Ϊ�������Ǵ���� */
  NAK_MD5_RSA_NONE_ERROR,           /* û��MD5_RSA�� */
  NAK_CRC_MD5_RSA_VERIFY_ERROR,     /* CRC��MD5_RSAУ��ʧ�� */
  NAK_CRC_NONE_ERROR,               /* û��CRC�� */
  NAK_MD5_RSA_TOO_LARGE,            /* MD5_RSA������ */
  NAK_CRC_TOO_LARGE,                /* CRC������ */
  NAK_CRC_VERIFY_ERROR,             /* CRC����ʧ�� */
  NAK_OEMSBL_VER_LIST_RECEIVE_ERROR,/* OEMSBL_VER_LIST����ʧ�� */
  NAK_OEMSBL_VER_LIST_TOO_LARGE,    /* OEMSBL_VER_LIST���� */
  NAK_OEMSBL_VER_LIST_LENGTCH_ERROR,/* OEMSBL_VER_LIST���ȴ��� */
  NAK_OEMSBL_VERSION_CHECK_ERROR,   /* OEMSBL�汾ƥ��ʧ�� */
  NAK_AMSS_VER_LIST_RECEIVE_ERROR,  /* AMSS_VER_LIST����ʧ�� */
  NAK_AMSS_VER_LIST_TOO_LARGE,      /* AMSS_VER_LIST���� */
  NAK_AMSS_VER_LIST_LEN_ERROR,      /* AMSS_VER_LIST���ȴ��� */
  NAK_AMSS_VERSION_CHECK_ERROR,     /* AMSS�汾ƥ��ʧ�� */
  NAK_ECC_RECEIVE_ERROR,            /* ECC����ʧ�� */
  NAK_ECC_LENGTCH_ERROR,            /* ECC���ȴ��� */
  NAK_ECC_TOO_LARGE,                /* ECC���� */
  NAK_AMSS_VER_TOO_LARGE,           /* AMSS_VER���� */
  NAK_AMSS_VER_RECEIVE_ERROR,       /* AMSS_VER����ʧ�� */
  NAK_OEMINFO_WRITE_ERROR,          /* OEMINFO����д��ʧ�� */
  NAK_EFS_VER_RECEIVE_ERROR,       /* EFS_VER����ʧ�� */
  NAK_EFS_VERSION_CHECK_ERROR,      /* EFS�汾ƥ��ʧ�� */
  NAK_MAX
  } response_code_type;

const char * dload_err_string[NAK_MAX] =
{
  "OK:dload success!",
  "Failure: invalid frame check sequence.\n",
  "Failure: destination address is invalid. \n",
  "Failure: operation length is invalid. \n",
  "Failure: packet was too short for this cmd.\n",
  "Failure: packet was too long for my buffer.\n",
  "Failure: packet command code was unknown.  \n",
  "Failure: operation did not succeed.  \n",
  "Failure: intelligent ID code was wrong. \n",
  "Failure: programming voltage out of spec.\n",
  "Failure: memory dump not permitted.\n",
  "Failure: invalid address for a memory read.\n",
  "Failure: readback verify did not match.\n",
  "Failure: not permitted without unlock.\n",
  "Failure: invalid security code.\n",
  "Failure: MD5_RSA������ʧ��.\n",
  "Failure: CRC������ʧ��.\n",
  "Failure: CRC�����ֽ���Ϊ�������Ǵ����.\n",
  "Failure: û��MD5_RSA��.\n",
  "Failure: CRC��MD5_RSAУ��ʧ��.\n",
  "Failure: û��CRC��.\n",
  "Failure: MD5_RSA������.\n",
  "Failure: CRC������.\n",
  "Failure: CRC����ʧ��.\n",
  "Failure: OEMSBL_VER_LIST����ʧ��.\n",
  "Failure: OEMSBL_VER_LIST����.\n",
  "Failure: OEMSBL_VER_LIST���ȴ���. \n",
  "Failure: OEMSBL�汾ƥ��ʧ��.\n",
  "Failure: AMSS_VER_LIST����ʧ��.\n",
  "Failure: AMSS_VER_LIST������.\n",
  "Failure: AMSS_VER_LIST���ȴ���.\n",
  "Failure: AMSS�汾ƥ��ʧ��.\n",
  "Failure: ECC����ʧ��.\n",
  "Failure: ECC���ȴ���.\n",
  "Failure: ECC������.\n",
  "Failure: AMSS_VER������.\n",
  "Failure: AMSS_VER����ʧ��.\n",
  "Failure: OEMINFO����д��ʧ��.\n",
  "Failure: EFS_VER����ʧ��.\n",
  "Failure: EFS_VER�汾ƥ��ʧ��.\n",
};



//------------------------- test008: <<  / >> ����.(2008-11-19)--------------------------------------------
//---------------------------------------------------------------------------------------------------------------
CString my_test_program3(CString str_start,CString str_end,CString str_other)
{
	long l_start = 0;
	long l_end = 0;
	long l_other = 0;

	CString str_result;

	sscanf(str_start, "%d", &l_start);
	sscanf(str_end, "%d", &l_end);	
	sscanf(str_other, "%d", &l_other);

	str_result.Format("%d", l_start|(l_end<<1));

	return str_result;
}



//------------------------- test009: ����ʱ���.(2009-08-21)--------------------------------------------
//---------------------------------------------------------------------------------------------------------------
/* Julian time structure */
typedef struct
{
  short  year;        /* Year [1980..2100]                         */
  short  month;       /* Month of year [1..12]                     */
  short  day;         /* Day of month [1..31]                      */
  short  hour;        /* Hour of day [0..23]                       */
  short  minute;      /* Minute of hour [0..59]                    */
  short  second;      /* Second of minute [0..59]                  */
  short  day_of_week; /* Day of the week [0..6] [Monday .. Sunday] */
}
fs_time_julian_type;

/*  definitions for ctime  */
#define F_CTIME_SEC_SHIFT		0
#define F_CTIME_SEC_MASK	0x001f  /* 0-30 in 2seconds */
#define F_CTIME_MIN_SHIFT		5
#define F_CTIME_MIN_MASK	0x07e0  /* 0-59  */
#define F_CTIME_HOUR_SHIFT		11
#define F_CTIME_HOUR_MASK	0xf800  /* 0-23 */

/*  definitions for cdate  */
#define F_CDATE_DAY_SHIFT		0
#define F_CDATE_DAY_MASK	0x001f  /* 0-31 */
#define F_CDATE_MONTH_SHIFT		5
#define F_CDATE_MONTH_MASK	0x01e0  /* 1-12 */
#define F_CDATE_YEAR_SHIFT		9
#define F_CDATE_YEAR_MASK	0xfe00  /* 0-119 (1980+value) */

CString my_test_program9(CString str_start,CString str_end,CString str_other)
{
	long hfat_time = 0;
	long hfat_date = 0;
	long l_other = 0;

    long epoch_time;
    fs_time_julian_type hfat_jul;

	CString str_result;

	sscanf(str_start, "%d", &hfat_time);
	sscanf(str_end, "%d", &hfat_date);	
	sscanf(str_other, "%d", &l_other);


  hfat_jul.year = hfat_date >> F_CDATE_YEAR_SHIFT;
  hfat_jul.year += 1980;

  hfat_jul.month = (hfat_date & F_CDATE_MONTH_MASK) >> F_CDATE_MONTH_SHIFT;

  hfat_jul.day = (hfat_date & F_CDATE_DAY_MASK) >> F_CDATE_DAY_SHIFT;

  hfat_jul.hour = (hfat_time & F_CTIME_HOUR_MASK) >> F_CTIME_HOUR_SHIFT;
  hfat_jul.minute = (hfat_time & F_CTIME_MIN_MASK) >> F_CTIME_MIN_SHIFT;
  hfat_jul.second = ((hfat_time & F_CTIME_SEC_MASK) >> F_CTIME_SEC_SHIFT) << 1;

  str_result.Format("%d-%d-%d %d:%d:%d",hfat_jul.year,hfat_jul.month,hfat_jul.day,hfat_jul.hour,hfat_jul.minute,hfat_jul.second);
  return str_result;
}


//------------------------- test010: �����ַ����е�*.(2009-08-31)--------------------------------------------
//---------------------------------------------------------------------------------------------------------------
char * str_sift_star(char * res_string)
{
  int non_star_count = 0;
  char * str_index = res_string;
  
  while(*str_index)
  {
    if('*' != *str_index)
    {
	  *(res_string + non_star_count) = *str_index;
      non_star_count++;
    }

	str_index++;
  }

  *(res_string + non_star_count) = 0;

  return res_string;
}

CString my_test_program10(CString str_start,CString str_end,CString str_other)
{
	CString str_result;
	char res_string[1024];

	sscanf(str_start, "%s", &res_string);

	return str_sift_star(res_string);
}

//------------------------- test011: U7510_����������Դ����(2010-02-09)--------------------------------------------
//---------------------------------------------------------------------------------------------------------------
// Data struct use for lanuages table
typedef struct 
{
	TCHAR pType[MAX_PATH];	// Lanuage Type string
	TCHAR pName[MAX_PATH];	// 
} LANUAGE_TYPE;

CString GetLangTypeString(const CString& strLanName)
{
	/*< Modified by Yinxuehui 2009-9-11 Begin*/
	/* Modified by duangan 2009-11-17 Begin */
    // LANUAGE_TYPE *arrLanuages;
	LANUAGE_TYPE arrLanuages[256];
	int nLanuageTypeCount = 0;
	// int nLanguageSize = 128;
	/* Modified by duangan 2009-11-17 end */
	
	CString strModulePath;
	TCHAR chrModulePath[MAX_PATH];
	GetModuleFileName(NULL,chrModulePath,MAX_PATH);
	strModulePath = chrModulePath;

	/* Modified by duangan 2009-11-17 Begin */
	// arrLanuages = (LANUAGE_TYPE *) malloc(sizeof(LANUAGE_TYPE) * nLanguageSize);
	/* Modified by duangan 2009-11-17 end */

	strModulePath = strModulePath.Left(strModulePath.ReverseFind('\\'));

	strcpy(chrModulePath,strModulePath);
	strcat(chrModulePath,_T("\\LanguageCfg.data"));
	FILE *fp = NULL;
	fp = fopen(chrModulePath,_T("r"));

	if(!fp)
	{

		int i=0;
		strcpy(arrLanuages[i].pType,_T("xx"));
		strcpy(arrLanuages[i++].pName , _T("Default"));

		strcpy(arrLanuages[i].pType , _T("am"));
		strcpy(arrLanuages[i++].pName , _T("Ameriacan English"));

		strcpy(arrLanuages[i].pType , _T("ar"));
		strcpy(arrLanuages[i++].pName , _T("Arabic"));

		strcpy(arrLanuages[i].pType , _T("au"));
		strcpy(arrLanuages[i++].pName , _T("Austrialian Englis"));

		strcpy(arrLanuages[i].pType , _T("at"));
		strcpy(arrLanuages[i++].pName , _T("Austrian German"));

		strcpy(arrLanuages[i].pType , _T("bl"));
		strcpy(arrLanuages[i++].pName , _T("Belgian Flemish"));

		strcpy(arrLanuages[i].pType , _T("bf"));
		strcpy(arrLanuages[i++].pName , _T("Belgian French"));

		strcpy(arrLanuages[i].pType , _T("cs"));
		strcpy(arrLanuages[i++].pName , _T("Czech"));

		strcpy(arrLanuages[i].pType , _T("cn"));
		strcpy(arrLanuages[i++].pName , _T("chinese"));

		strcpy(arrLanuages[i].pType , _T("da"));
		strcpy(arrLanuages[i++].pName , _T("Danish"));

		strcpy(arrLanuages[i].pType , _T("nl"));
		strcpy(arrLanuages[i++].pName , _T("Dutch"));

		strcpy(arrLanuages[i].pType , _T("en"));
		strcpy(arrLanuages[i++].pName , _T("English"));

		strcpy(arrLanuages[i].pType , _T("fi"));
		strcpy(arrLanuages[i++].pName , _T("Finnish"));

		strcpy(arrLanuages[i].pType , _T("fr"));
		strcpy(arrLanuages[i++].pName , _T("French"));

		strcpy(arrLanuages[i].pType , _T("de"));
		strcpy(arrLanuages[i++].pName , _T("German"));

		strcpy(arrLanuages[i].pType , _T("he"));
		strcpy(arrLanuages[i++].pName , _T("Hebrew"));

		strcpy(arrLanuages[i].pType , _T("hk"));
		strcpy(arrLanuages[i++].pName , _T("Hong Kong Chinese"));

		strcpy(arrLanuages[i].pType , _T("hu"));
		strcpy(arrLanuages[i++].pName , _T("Hungarian"));

		strcpy(arrLanuages[i].pType , _T("is"));
		strcpy(arrLanuages[i++].pName , _T("Icelandic"));

		strcpy(arrLanuages[i].pType , _T("if"));
		strcpy(arrLanuages[i++].pName , _T("International French"));

		strcpy(arrLanuages[i].pType , _T("it"));
		strcpy(arrLanuages[i++].pName , _T("Italian"));

		strcpy(arrLanuages[i].pType , _T("ja"));
		strcpy(arrLanuages[i++].pName , _T("Japanese"));

		strcpy(arrLanuages[i].pType , _T("ko"));
		strcpy(arrLanuages[i++].pName , _T("Korean"));

		strcpy(arrLanuages[i].pType , _T("nz"));
		strcpy(arrLanuages[i++].pName , _T("New Zealand English"));

		strcpy(arrLanuages[i].pType , _T("no"));
		strcpy(arrLanuages[i++].pName , _T("Norwegian"));

		strcpy(arrLanuages[i].pType , _T("zh"));
		strcpy(arrLanuages[i++].pName , _T("PRC Chinese"));

		strcpy(arrLanuages[i].pType , _T("pl"));
		strcpy(arrLanuages[i++].pName , _T("Polish"));

		strcpy(arrLanuages[i].pType , _T("pt"));
		strcpy(arrLanuages[i++].pName , _T("Portuguese"));

		strcpy(arrLanuages[i].pType , _T("ru"));
		strcpy(arrLanuages[i++].pName , _T("Russian"));

		strcpy(arrLanuages[i].pType , _T("sk"));
		strcpy(arrLanuages[i++].pName , _T("Slovak"));

		strcpy(arrLanuages[i].pType , _T("sl"));
		strcpy(arrLanuages[i++].pName , _T("Slovenian"));

		strcpy(arrLanuages[i].pType , _T("es"));
		strcpy(arrLanuages[i++].pName , _T("Spanish"));

		strcpy(arrLanuages[i].pType , _T("sv"));
		strcpy(arrLanuages[i++].pName , _T("Swedish"));

		strcpy(arrLanuages[i].pType , _T("sf"));
		strcpy(arrLanuages[i++].pName , _T("Swiss French"));

		strcpy(arrLanuages[i].pType , _T("sg"));
		strcpy(arrLanuages[i++].pName , _T("Swiss German"));

		strcpy(arrLanuages[i].pType , _T("tc"));
		strcpy(arrLanuages[i++].pName , _T("Taiwan Chinese"));

		strcpy(arrLanuages[i].pType , _T("th"));
		strcpy(arrLanuages[i++].pName , _T("Thai"));

		strcpy(arrLanuages[i].pType , _T("tr"));
		strcpy(arrLanuages[i++].pName , _T("Turkish"));

		nLanuageTypeCount = i;

	}
	else
	{
		int i = 0;
		while(!feof(fp))
		{
			TCHAR strReadString[MAX_PATH];
			fgets(strReadString,MAX_PATH,fp);

			CString strStringForDisPose = strReadString;
			if(strStringForDisPose.Find(_T("\"")) == -1 ||
				 strStringForDisPose.Find(_T(",")) == -1)
			{
				continue;
			}
			
			/* Modified by duangan 2009-11-17 Begin */
			/* if( i == nLanguageSize )
			{
				nLanguageSize += 10;
				arrLanuages = (LANUAGE_TYPE *) realloc(arrLanuages,nLanguageSize * sizeof(LANUAGE_TYPE) );
			} */
			/* Modified by duangan 2009-11-17 end */

			memset(arrLanuages[i].pType,0,sizeof(arrLanuages[i].pType));
			memset(arrLanuages[i].pName,0,sizeof(arrLanuages[i].pName));

			//==========��ȡtype==================
			int i_Type = 0;
			int i_chars = 0;
			while(strReadString[i_chars] != _T('\"'))
			{
				i_chars++;
				if(i_chars == MAX_PATH)
				{
					break;
				}
			}

			i_chars++;
			for(; i_chars < MAX_PATH; i_chars++)
			{
				if(strReadString[i_chars] == _T('\"'))
				{
					break;
				}
				arrLanuages[i].pType[i_Type++] = strReadString[i_chars];
			}

			//==========��ȡname==================
			i_Type = 0;
			while(strReadString[i_chars] != _T(','))
			{
				i_chars++;
				if(i_chars == MAX_PATH)
				{
					break;
				}
			}

			while(strReadString[i_chars] != _T('\"'))
			{
				i_chars++;
				if(i_chars == MAX_PATH)
				{
					break;
				}
			}

			i_chars++;
			for(; i_chars < MAX_PATH; i_chars++)
			{
				if(strReadString[i_chars] == _T('\"'))
				{
					break;
				}
				arrLanuages[i].pName[i_Type++] = strReadString[i_chars];
			}

			i++;
		}

		nLanuageTypeCount = i;	
		fclose(fp);
	}

	/* Modified by duangan 2009-11-17 Begin */
	// free(arrLanuages);
	/* Modified by duangan 2009-11-17 end */

	/* Modified by Yinxuehui 2009-9-11 end>*/
	// Find the string type
	for (int i = 0; i < nLanuageTypeCount; i++)
	{
		if ( 0 ==strLanName.CompareNoCase(arrLanuages[i].pName)) 
		{
			return arrLanuages[i].pType;
		}
	}

	// BEGIN : yanzhijun @@@@@@@@@ 2008-5-8
	return strLanName;
	// END : yanzhijun @@@@@@@@@ 2008-5-8
}

//------------------------- test012: ����otp����(2010-03-08)---------------------------------------
//------------------------------------------------------------------------------------------------
void string_reversal(char * des, int count_by_byte)
{
	char my_char;

	for(int ii = 0 ; ii < count_by_byte/2 ; ii++)
	{
		my_char =  *(des + ii);
		*(des + ii) = *(des + (count_by_byte - ii - 1));
		*(des + (count_by_byte - ii - 1)) = my_char;
	}
}


boolean make_otp_data()
{
	char version_code[130];
	char produce_code[130];
	char otp_data[520];
	FILE *fp1 = NULL;
	FILE *fp2 = NULL;
	FILE *fp3 = NULL;

	CString my_path;
	char module_path[256];
	GetModuleFileName(NULL,module_path,MAX_PATH);
	my_path = module_path;
	my_path = my_path.Left(my_path.ReverseFind('\\'));

	memset(version_code,0,sizeof(version_code));
	memset(produce_code,0,sizeof(produce_code));
	memset(otp_data,0,sizeof(otp_data));

	// version code
	// header
	otp_data[1]=0x4;

	// data
	fp1 = fopen(my_path + _T("\\1005"),_T("rb"));
	if(!fp1)
	{
		return FALSE;
	}
	if(fread(version_code,sizeof(char),sizeof(version_code),fp1) != sizeof(version_code))
	{
		return FALSE;
	}
	memcpy((void *)&otp_data[4],(void *)&version_code[2],128);
	string_reversal((char *)&otp_data[4],128);
	fclose(fp1);

	// tail
	otp_data[256 + 1]=0x1;
	otp_data[256 + 3]=0x1;

	// produce code
	// header
	otp_data[256 + 5]=0x4;

	// data
	fp2 = fopen(my_path + _T("\\9901"),_T("rb"));
	if(!fp2)
	{
		return FALSE;
	}
	if(fread(produce_code,sizeof(char),sizeof(produce_code),fp2) != sizeof(produce_code))
	{
		return FALSE;
	}
	memcpy((void *)&otp_data[256 + 8],(void *)&produce_code[2],128);
	string_reversal((char *)&otp_data[256 + 8],128);
	fclose(fp2);
	
	// tail
	otp_data[512 + 5]=0x1;
	otp_data[512 + 7]=0x1;

	// write OTP data
	fp3 = fopen(my_path + _T("\\otp_data.bin"),_T("wb"));
	fwrite(otp_data,sizeof(char),sizeof(otp_data),fp3);
	fclose(fp3);

	return TRUE;
}

//---------------------------------------------------------------------------------------------------------------
//---------------------------------------------------------------------------------------------------------------
//-------------------------------------����Ϊ����ӿ�.--------------------------------------------------------
// 1.����Ϊ�ܻ�ȡ�������������ӿ�.
void CTesterDlg::OnOK() 
{
	// TODO: Add extra validation here

	CString str_start;
	CString str_end;
	CString str_other;
    CString str_result;

	GetDlgItemText(IDC_EDIT_START, str_start);   // ��ȡ�������1
	GetDlgItemText(IDC_EDIT_END, str_end);	     // ��ȡ�������2
    GetDlgItemText(IDC_EDIT_OTHER, str_other);	     // ��ȡ�������3

	if(make_otp_data())
	{
		str_result = _T("OK");
	}
	else
	{
		str_result = _T("FAIL");
	}

	SetDlgItemText(IDC_EDIT_RESULT, str_result);
}


// 2.����Ϊ����ȡ�������������ӿ�.
/*
void CTesterDlg::OnOK() 
{
	// TODO: Add extra validation here
	char str_result[100];
    
	// for test002
	//sprintf(str_result,"#pragma pack(?), len is %d",sizeof(ABCD));

	// for test003
	//int result = creat_file();
	//if(!result)
	//{
	//	sprintf(str_result,"creat_file ok!");
	//}
	//else
	//{
	//	sprintf(str_result,"creat_file fail. fail id = %d !",result);
	//}

	// for test0004: ��֤�ֽ���ת�Ĵ���.
    // sprintf(str_result,"�����0x%X",dword_order_change());

	// for test0005: ��֤##��ʹ��..
    //sprintf(str_result,"%s",link_test());

    // for test0006: ȡGPIO ��ַ
    int my_number = ((36)<<0x0008UL & 0xff00UL) | ((1)<< 0x0004UL &0x00f0UL);
    sprintf(str_result,"0x%x--%d",my_number,my_number);


	SetDlgItemText(IDC_EDIT_RESULT, str_result);
}
*/