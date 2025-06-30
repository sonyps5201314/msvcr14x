Option Explicit

Dim AppPath
Dim Dist_x64, Dist_x86
Function CheckDists()
    Dim fs 'As FileSystemObject
    Set fs = CreateObject("Scripting.FileSystemObject")
    Dim objShell 'As WshShell
    Set objShell = CreateObject("WScript.Shell")
    AppPath = fs.GetParentFolderName(WScript.ScriptFullName) & "\"
    
    Dist_x64 = "msvcr14x_dist.x64.exe"
    Dist_x86 = "msvcr14x_dist.x86.exe"
    If fs.FileExists(AppPath & Dist_x64) = False And fs.FileExists(AppPath & Dist_x86) = False Then
        Call MsgBox(Dist_x64 & " or " & Dist_x86 & " does not exist, Please use setup.vbs to create them or copy them here along with ExtractToSystemDir.vbs first!", vbCritical, "msvcr14x")
        Exit Function
    End If
    CheckDists = True
End Function

Function ExtractToSystemDir()
    Err.Clear
    On Error Resume Next
    
    Dim objShell 'As WshShell
    Set objShell = CreateObject("WScript.Shell")
    Dim fs 'As FileSystemObject
    Set fs = CreateObject("Scripting.FileSystemObject")
    
    Dim windir
    windir = objShell.Environment("Process").Item("windir")
    Dim ProcArch
    Dim SysArch
    SysArch = objShell.Environment("System").Item("PROCESSOR_ARCHITECTURE")
    
    Set objShell = CreateObject("Shell.Application")
    If SysArch = "AMD64" Or SysArch = "ARM64" Then
        If fs.FileExists(AppPath & Dist_x64) Then
            ProcArch = "x86" 'IsPEFile64Bit(Dist_x64)
            If ProcArch = "x86" Then
                Call objShell.ShellExecute(Dist_x64, "-y -o" + windir + "\sysnative\", AppPath, "runas", 1)
            Else
                Call objShell.ShellExecute(Dist_x64, "-y -o" + windir + "\system32\", AppPath, "runas", 1)
            End If
        End If
        If fs.FileExists(AppPath & Dist_x86) Then
            Call objShell.ShellExecute(Dist_x86, "-y -o" + windir + "\syswow64\", AppPath, "runas", 1)
        End If
    ElseIf SysArch = "x86" Then
        If fs.FileExists(AppPath & Dist_x86) Then
            Call objShell.ShellExecute(Dist_x86, "-y -o" + windir + "\system32\", AppPath, "runas", 1)
        End If
    Else
        MsgBox SysArch + " is a unsupported system architecture!", vbCritical, "msvcr14x"
    End If
    ExtractToSystemDir = Err.Number = 0
End Function

If CheckDists() = False Then
    WScript.Quit
End If
If MsgBox("Extract to System32/SysWOW64 directory?", vbQuestion Or vbYesNo Or vbDefaultButton1, "msvcr14x") <> vbYes Then
    WScript.Quit
End If
If ExtractToSystemDir() = False Then
    Call MsgBox("Failed to extract to system directory!" & vbCrLf & "Error message:" & Err.Description, vbCritical, "msvcr14x")
End If