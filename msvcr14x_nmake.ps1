if ($env:Platform -eq 'x64') {
    $env:LIB = "$env:msvcr14x_ROOT\x64\Release;$env:msvcr14x_ROOT\x64\Debug;$env:msvcr14x_ROOT\x64\AnsiRelease;$env:msvcr14x_ROOT\x64\AnsiDebug;$env:LIB"
}
elseif($env:Platform -eq 'x86') {
    $env:LIB = "$env:msvcr14x_ROOT\Release;$env:msvcr14x_ROOT\Debug;$env:msvcr14x_ROOT\AnsiRelease;$env:msvcr14x_ROOT\AnsiDebug;$env:LIB"
}
