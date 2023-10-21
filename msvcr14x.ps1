param(
    [switch]$off
)

if($off) { $off_v = $true }
else { $off_v = $false  }

Set-Alias println Write-Host

$cfgs = @(
    # on
    @{
       include='E:\dev\ntdll\include;$(IncludePath)';
       libs=@('$(msvcr14x_ROOT)\Release;$(msvcr14x_ROOT)\Debug;$(msvcr14x_ROOT)\AnsiRelease;$(msvcr14x_ROOT)\AnsiDebug;%(AdditionalLibraryDirectories)',
       '$(msvcr14x_ROOT)\x64\Release;$(msvcr14x_ROOT)\x64\Debug;$(msvcr14x_ROOT)\x64\AnsiRelease;$(msvcr14x_ROOT)\x64\AnsiDebug;%(AdditionalLibraryDirectories)')
    },
    # off
    @{
        include='$(IncludePath)';
        libs=@('%(AdditionalLibraryDirectories)', '%(AdditionalLibraryDirectories)')
    }
)

function Format-Xml
{
    #.Synopsis
    # Pretty-print formatted XML source
    #.Description
    # Runs an XmlDocument through an auto-indenting XmlWriter
    #.Example
    # [xml]$xml = get-content Data.xml
    # C:\PS>Format-Xml $xml
    #.Example
    # get-content Data.xml | Format-Xml
    #.Example
    # Format-Xml C:\PS\Data.xml -indent 1 -char `t
    # Shows how to convert the indentation to tabs (which can save bytes dramatically, while preserving readability)
    #.Example
    # ls *.xml | Format-Xml
    #
    [CmdletBinding()]
    param(
        # The Xml Document
        [Parameter(Position=0, Mandatory=$true, ValueFromPipeline=$true, ParameterSetName="Document")]
        $Xml,

        # The path to an xml document (on disc or any other content provider).
        [Parameter(Position=0, Mandatory=$true, ValueFromPipelineByPropertyName=$true, ParameterSetName="File")]
        [Alias("PsPath")]
        [string]$Path,

        # The indent level (defaults to 2 spaces)
        [Parameter(Mandatory=$false)]
        [int]$Indent=2,

        # The indent character (defaults to a space)
        [char]$Character= ' '
    )
    process {
        ## Load from file, if necessary
        if($Path) { [xml]$xml = Get-Content $Path }

        $StringWriter = New-Object System.IO.StringWriter
        $XmlWriter = New-Object System.XMl.XmlTextWriter $StringWriter
        $xmlWriter.Formatting = [System.Xml.Formatting]::Indented
        $xmlWriter.Indentation = $Indent
        $xmlWriter.IndentChar = $Character
        $xml.WriteContentTo($XmlWriter)
        $XmlWriter.Flush()
        $StringWriter.Flush()
        Write-Output $StringWriter.ToString()
    }
}

function mod_msbuild_conf($conf_file, $off_v, $is_x64) {
    $incs = $cfgs[$off_v].include
    $libs = $cfgs[$off_v].libs[$is_x64]

    println "mod: $conf_file, incs=$incs, libs=$libs ..."

    [XML]$msbcProps = Get-Content $conf_file

    $msbcProps.Project.PropertyGroup.IncludePath = $incs
    $msbcProps.Project.ItemDefinitionGroup.Link.AdditionalLibraryDirectories.InnerText = $libs

    $strXml = Format-Xml -Xml $msbcProps -Indent 1 -Character "`t"
    Set-Content -Path $conf_file -Value $strXml
}

$x86_conf_file = Join-Path $env:LOCALAPPDATA 'Microsoft\MSBuild\v4.0\Microsoft.Cpp.Win32.user.props'
$x64_conf_file = Join-Path $env:LOCALAPPDATA 'Microsoft\MSBuild\v4.0\Microsoft.Cpp.x64.user.props'

mod_msbuild_conf $x86_conf_file $off_v $false
mod_msbuild_conf $x64_conf_file $off_v $true

if($off_v) {
    println "msvcr14x: off."
} else {
    println "msvcr14x: on."
}
