$curdir = Get-Location
$out = ".\out"
If((Test-Path $out))
{
    Remove-Item $out -Force -Recurse
}
New-Item -ItemType Directory -Force -Path $out
cd $out 
cmake ..\
$msbuildpath = ";C:\Program Files (x86)\Microsoft Visual Studio\2019\Enterprise\MSBuild\Current\Bin"
Set-Item -Path Env:Path -Value ($Env:Path + $msbuildpath)
msbuild validatejwt.sln
cd .\Debug
.\validatejwt.exe
cd $curdir
