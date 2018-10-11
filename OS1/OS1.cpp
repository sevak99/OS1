// OS1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

int _tmain(int argc, TCHAR* argv[], TCHAR** envp)
{
    HANDLE ConsoleHandle = CreateFile(_T("CONOUT$"),
                               GENERIC_WRITE | GENERIC_READ,
                               0, NULL,
                               OPEN_EXISTING,
                               0, NULL);
    int TestNum;
    SetConsoleTextAttribute(ConsoleHandle, 4);
    _tprintf(_T("%s"), PTCHAR(_T("Input Test number to start. For more information read the ReadMe file.\n")));
    SetConsoleTextAttribute(ConsoleHandle, 9);
    if(_tscanf_s(_T("%d"), &TestNum))
    {
        SetConsoleTextAttribute(ConsoleHandle, 7);
        switch(TestNum)
        {
            case 0:
                _tprintf(_T("%s\n"), PTCHAR(_T("Test 0: Error Handling.\n")));
                TestPrintLastErrorText();
                break;
            case 1:
                _tprintf(_T("%s"), PTCHAR(_T("Test 1.1: Getting command line arguments and enviroment variables.\n")));
                GetArgsAndVars(argc, argv, envp);
                _tprintf(_T("\n%s\n"), PTCHAR(_T("Press enter to get to next test.\n")));
                while(getchar() != _T('\n'));
                while(getchar() != _T('\n'));
                _tprintf(_T("%s"), PTCHAR(_T("Test 1.2: Setting an enviroment variable.\n")));
                SetVars();
                _tprintf(_T("\n%s\n"), PTCHAR(_T("Press enter to get to next test.\n")));
                while(getchar() != _T('\n'));
                _tprintf(_T("%s"), PTCHAR(_T("Test 1.3: Getting current directory.\n")));
                GetCurrDir();
                break;
            default:
                _tprintf(_T("%s"), PTCHAR(_T("Test 0: Error Handling.\n\n")));
                TestPrintLastErrorText();
                _tprintf(_T("\n%s\n"), PTCHAR(_T("Press enter to get to next test.\n")));
                while(getchar() != _T('\n'));
                while(getchar() != _T('\n'));
                _tprintf(_T("%s"), PTCHAR(_T("Test 1.1: Getting command line arguments and enviroment variables.\n")));
                GetArgsAndVars(argc, argv, envp);
                _tprintf(_T("\n%s\n"), PTCHAR(_T("Press enter to get to next test.\n")));
                while(getchar() != _T('\n'));
                _tprintf(_T("%s"), PTCHAR(_T("Test 1.2: Setting an enviroment variable.\n")));
                SetVars();
                _tprintf(_T("\n%s\n"), PTCHAR(_T("Press enter to get to next test.\n")));
                while(getchar() != _T('\n'));
                _tprintf(_T("%sn"), PTCHAR(_T("Test 1.3: Getting current directory.\n")));
                GetCurrDir();
        }
        _tmain(argc, argv, envp);
    }
    else
    {
        SetConsoleTextAttribute(ConsoleHandle, 4);
        _tprintf(_T("%s"), PTCHAR(_T("Exiting programm...\n")));
    }
    return 0;
}
