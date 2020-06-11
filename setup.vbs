Option Explicit

Const adTypeBinary = 1
Const adSaveCreateOverWrite = 2

Function IIf( expr, truepart, falsepart )
   IIf = falsepart
   If expr Then IIf = truepart
End Function

'https://stackoverflow.com/questions/6405236/forcing-msxml-to-format-xml-output-with-indents-and-newlines
Private Sub FormatDocToFile(ByVal Doc, ByVal FileName)
    'Reformats the DOMDocument "Doc" into an ADODB.Stream
    'and writes it to the specified file.
    '
    'Note the UTF-8 output never gets a BOM.  If we want one we
    'have to write it here explicitly after opening the Stream.
    Dim rdrDom 'As MSXML2.SAXXMLReader
    Dim stmFormatted 'As ADODB.Stream
    Dim wtrFormatted 'As MSXML2.MXXMLWriter

    Set stmFormatted = CreateObject("ADODB.Stream")
    With stmFormatted
        .Open
        .Type = adTypeBinary
        Set wtrFormatted = CreateObject("MSXML2.MXXMLWriter")
        With wtrFormatted
            .omitXMLDeclaration = False
            .standalone = True
            .byteOrderMark = False 'If not set (even to False) then
                                   '.encoding is ignored.
            .encoding = "utf-8"    'Even if .byteOrderMark = True
                                   'UTF-8 never gets a BOM.
            .indent = True
            .output = stmFormatted
            Set rdrDom = CreateObject("MSXML2.SAXXMLReader")
            With rdrDom
                Set .contentHandler = wtrFormatted
                Set .dtdHandler = wtrFormatted
                Set .errorHandler = wtrFormatted
                .putProperty "http://xml.org/sax/properties/lexical-handler", _
                             wtrFormatted
                .putProperty "http://xml.org/sax/properties/declaration-handler", _
                             wtrFormatted
                .parse Doc
            End With
        End With
        .SaveToFile FileName, adSaveCreateOverWrite
        .Close
    End With
End Sub

'本脚本修改自https://github.com/KindDragon/vld/blob/master/setup/vld-setup.iss
Private Function VarIsNull(V)
    VarIsNull = IsEmpty(V)
End Function

Public Function FileExists(File)
    Dim fs 'As FileSystemObject
    Set fs = CreateObject("Scripting.FileSystemObject")
    FileExists = fs.FileExists(File)
End Function
Function DirExists(Folder)
    Dim fs 'As FileSystemObject
    Set fs = CreateObject("Scripting.FileSystemObject")
    DirExists = fs.FolderExists(Folder)
End Function

Function Pos(SubStr, S)
   Pos = InStr(S, SubStr)
End Function

Sub StringChangeEx(S, FromStr, ToStr, SupportDBCS)
    S = Replace(S, FromStr, ToStr, 1, -1, IIf(SupportDBCS, vbTextCompare, vbBinaryCompare))
End Sub

Function ExpandConstant(S)
    Dim scriptdir
    scriptdir = CreateObject("Scripting.FileSystemObject").GetParentFolderName(WScript.ScriptFullName)
    'scriptdir = "F:\MyCppProjects\msvcr14x"
    ExpandConstant = Replace(S, "{app}", scriptdir)
End Function

Function EncodeString(S)
    Dim result
    result = S
    Call StringChangeEx(result, "(", "%28", True)
    Call StringChangeEx(result, ")", "%29", True)
    EncodeString = result
End Function

Sub UpdateString(dirList, Path, suffix)
    If (Len(dirList) = 0) Then
      dirList = Path + suffix
    Else
      If ((Pos(Path, dirList) = 0) And (Pos(EncodeString(Path), dirList) = 0)) Then
        dirList = Path + dirList
      End If
    End If
    'Debug.Print (dirList)
End Sub

Private Sub ModifyProps(FileName, includefolder, dlibfolder, slibfolder)
  Dim XMLDocument
  Dim XMLParent, IdgNode, XMLNode, XMLNodes
  Dim IncludeDirectoriesNode
  Dim AdditionalIncludeDirectories
  Dim DynamicLibraryDirectoriesNode
  Dim AdditionalDynamicLibraryDirectories
  Dim StaticLibraryDirectoriesNode
  Dim AdditionalStaticLibraryDirectories
  If (False = FileExists(FileName)) Then
    Exit Sub
  End If
    Set XMLDocument = CreateObject("Msxml2.DOMDocument.3.0")
    XMLDocument.async = False
    XMLDocument.Load (FileName)
    If (XMLDocument.parseError.errorCode = 0) Then
      Call XMLDocument.setProperty("SelectionLanguage", "XPath")
      Call XMLDocument.setProperty("SelectionNamespaces", "xmlns:b='http://schemas.microsoft.com/developer/msbuild/2003'")
      Set XMLNodes = XMLDocument.selectNodes("//b:Project")
      If (XMLNodes.length = 0) Then
        Exit Sub
      End If
      Set IdgNode = XMLNodes.Item(0)
      Set XMLNodes = IdgNode.selectNodes("//b:ItemDefinitionGroup")
      If (XMLNodes.length > 0) Then
        Set IdgNode = XMLNodes.Item(0)
      Else
        Set XMLNode = XMLDocument.createNode(1, "ItemDefinitionGroup", "http://schemas.microsoft.com/developer/msbuild/2003")
        Set IdgNode = IdgNode.appendChild(XMLNode)
      End If
      
      If Len(includefolder) > 0 Then
        Set XMLNodes = IdgNode.selectNodes("//b:ClCompile")
        If (XMLNodes.length > 0) Then
          Set XMLParent = XMLNodes.Item(0)
        Else
          Set XMLNode = XMLDocument.createNode(1, "ClCompile", "http://schemas.microsoft.com/developer/msbuild/2003")
          Set XMLParent = IdgNode.appendChild(XMLNode)
        End If
        Set XMLNodes = XMLParent.selectNodes("//b:ClCompile/b:AdditionalIncludeDirectories")
        If (XMLNodes.length > 0) Then
          Set IncludeDirectoriesNode = XMLNodes.Item(0)
        Else
          Set XMLNode = XMLDocument.createNode(1, "AdditionalIncludeDirectories", "http://schemas.microsoft.com/developer/msbuild/2003")
          Set IncludeDirectoriesNode = XMLParent.appendChild(XMLNode)
        End If
      End If
      If Len(dlibfolder) > 0 Then
        Set XMLNodes = IdgNode.selectNodes("//b:Link")
        If (XMLNodes.length > 0) Then
          Set XMLParent = XMLNodes.Item(0)
        Else
          Set XMLNode = XMLDocument.createNode(1, "Link", "http://schemas.microsoft.com/developer/msbuild/2003")
          Set XMLParent = IdgNode.appendChild(XMLNode)
        End If
        Dim s_value
        s_value = "'$(PlatformToolset)' == 'v142' or '$(PlatformToolset)' == 'v141' or '$(PlatformToolset)' == 'v141_xp' or '$(PlatformToolset)' == 'v140' or '$(PlatformToolset)' == 'v140_xp'"
        Set XMLNodes = XMLParent.selectNodes("//b:Link/b:AdditionalLibraryDirectories[@Condition=""" + s_value + """]")
        If (XMLNodes.length > 0) Then
          Set DynamicLibraryDirectoriesNode = XMLNodes.Item(0)
        Else
          Set XMLNode = XMLDocument.createNode(1, "AdditionalLibraryDirectories", "http://schemas.microsoft.com/developer/msbuild/2003")
          Set DynamicLibraryDirectoriesNode = XMLParent.appendChild(XMLNode)
          Call DynamicLibraryDirectoriesNode.setAttribute("Condition", s_value)
        End If
     End If
     If Len(slibfolder) > 0 Then
        Set XMLNodes = IdgNode.selectNodes("//b:Lib")
        If (XMLNodes.length > 0) Then
          Set XMLParent = XMLNodes.Item(0)
        Else
          Set XMLNode = XMLDocument.createNode(1, "Lib", "http://schemas.microsoft.com/developer/msbuild/2003")
          Set XMLParent = IdgNode.appendChild(XMLNode)
        End If
        Set XMLNodes = XMLParent.selectNodes("//b:Lib/b:AdditionalLibraryDirectories[@Condition=""" + s_value + """]")
        If (XMLNodes.length > 0) Then
          Set StaticLibraryDirectoriesNode = XMLNodes.Item(0)
        Else
          Set XMLNode = XMLDocument.createNode(1, "AdditionalLibraryDirectories", "http://schemas.microsoft.com/developer/msbuild/2003")
          Set StaticLibraryDirectoriesNode = XMLParent.appendChild(XMLNode)
          Call StaticLibraryDirectoriesNode.setAttribute("Condition", s_value)
        End If
      End If
      
      If Len(includefolder) > 0 Then
        AdditionalIncludeDirectories = ""
        If (False = VarIsNull(IncludeDirectoriesNode)) Then
          AdditionalIncludeDirectories = IncludeDirectoriesNode.Text
        End If
      End If
      If Len(dlibfolder) > 0 Then
        AdditionalDynamicLibraryDirectories = ""
        If (False = VarIsNull(DynamicLibraryDirectoriesNode)) Then
          AdditionalDynamicLibraryDirectories = DynamicLibraryDirectoriesNode.Text
        End If
      End If
      If Len(slibfolder) > 0 Then
        AdditionalStaticLibraryDirectories = ""
        If (False = VarIsNull(StaticLibraryDirectoriesNode)) Then
          AdditionalStaticLibraryDirectories = StaticLibraryDirectoriesNode.Text
        End If
      End If
      
      If Len(includefolder) > 0 Then
        Call UpdateString(AdditionalIncludeDirectories, ExpandConstant(includefolder + ";"), "%(AdditionalIncludeDirectories)")
      End If
      If Len(dlibfolder) > 0 Then
        Call UpdateString(AdditionalDynamicLibraryDirectories, ExpandConstant(dlibfolder + ";"), "%(AdditionalLibraryDirectories)")
      End If
      If Len(slibfolder) > 0 Then
        Call UpdateString(AdditionalStaticLibraryDirectories, ExpandConstant(slibfolder + ";"), "%(AdditionalLibraryDirectories)")
      End If
      
      If Len(includefolder) > 0 Then
        IncludeDirectoriesNode.Text = AdditionalIncludeDirectories
      End If
      If Len(dlibfolder) > 0 Then
        DynamicLibraryDirectoriesNode.Text = AdditionalDynamicLibraryDirectories
      End If
      If Len(slibfolder) > 0 Then
        StaticLibraryDirectoriesNode.Text = AdditionalStaticLibraryDirectories
      End If
      'XMLDocument.save (FileName)
      FormatDocToFile XMLDocument, FileName
    End If
End Sub

Sub ModifyAllProps()
  Dim objShell
  Dim Path
  Set objShell = CreateObject("WScript.Shell")
  Path = objShell.Environment("Process").Item("LOCALAPPDATA") + "\Microsoft\MSBuild\v4.0\"
  If (DirExists(Path)) Then
    Call ModifyProps(Path + "Microsoft.Cpp.Win32.user.props", vbNullString, "$(msvcr14x_ROOT)\Release;$(msvcr14x_ROOT)\Debug", vbNullString)
    Call ModifyProps(Path + "Microsoft.Cpp.x64.user.props", vbNullString, "$(msvcr14x_ROOT)\x64\Release;$(msvcr14x_ROOT)\x64\Debug", vbNullString)
  End If
End Sub

Sub SetEnvironment()
  Dim objShell
  Set objShell = CreateObject("WScript.Shell")
  objShell.Environment("System").Item("msvcr14x_ROOT") = ExpandConstant("{app}")
End Sub

Sub AskForCopyDlls()
   If MsgBox("Copy all generated dlls to System32/SysWOW64 directory?" & vbCrLf & "It's a good idea for test and debug.", vbYesNo Or vbDefaultButton1) = vbYes Then
      Dim AppPath
      AppPath = ExpandConstant("{app}") + "\"
      Dim fs 'As FileSystemObject
      Set fs = CreateObject("Scripting.FileSystemObject")
      Dim AllDlls(11)
      AllDlls(0) = "Debug\MSVCR14XD.dll"
      AllDlls(1) = "Debug\MSVCP14XD.dll"
      AllDlls(2) = "Debug\CONCRT14XD.dll"
      AllDlls(3) = "Release\MSVCR14X.dll"
      AllDlls(4) = "Release\MSVCP14X.dll"
      AllDlls(5) = "Release\CONCRT14X.dll"
      AllDlls(6) = "x64\Debug\MSVCR14XD.dll"
      AllDlls(7) = "x64\Debug\MSVCP14XD.dll"
      AllDlls(8) = "x64\Debug\CONCRT14XD.dll"
      AllDlls(9) = "x64\Release\MSVCR14X.dll"
      AllDlls(10) = "x64\Release\MSVCP14X.dll"
      AllDlls(11) = "x64\Release\CONCRT14X.dll"
      Dim OneDll
      For Each OneDll In AllDlls
         If fs.FileExists(AppPath + OneDll) = False Then
            Call MsgBox("Please build all msvcr14x dlls first!", vbCritical)
            Exit Sub
         End If
      Next
      
      Dim objShell
      Set objShell = CreateObject("WScript.Shell")
      Dim windir
      windir = objShell.Environment("Process").Item("windir")
      Dim ProcArch
      ProcArch = objShell.Environment("Process").Item("PROCESSOR_ARCHITECTURE")
      Dim SysArch
      SysArch = objShell.Environment("System").Item("PROCESSOR_ARCHITECTURE")
      If SysArch = "AMD64" Then
        For Each OneDll In AllDlls
          If Left(OneDll, 3) = "x64" Then
            If ProcArch = "x86" Then
                Call fs.CopyFile(AppPath + OneDll, windir + "\sysnative\")
            Else
                Call fs.CopyFile(AppPath + OneDll, windir + "\system32\")
            End If
          Else
            Call fs.CopyFile(AppPath + OneDll, windir + "\syswow64\")
          End If
        Next
      ElseIf SysArch = "x86" Then
        For Each OneDll In AllDlls
            Call fs.CopyFile(AppPath + OneDll, windir + "\system32\")
        Next
      Else
        MsgBox SysArch + " is a unsupported system architecture!", vbCritical
      End If
      
   End If
End Sub

ModifyAllProps
SetEnvironment
AskForCopyDlls