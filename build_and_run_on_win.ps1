# THIS IS NOT A WELL DEVELOPED SCRIPT, IT IS JUST A SET OF STEPS TO BUILD AND RUN "HELLO-WORLD"

$curdir = Get-Location
$out = ".\out"
If((Test-Path $out))
{
    Remove-Item $out -Force -Recurse
}
New-Item -ItemType Directory -Force -Path $out
cd $out 
cmake ..\
If($Args[0] -eq "") {
    $msbuildpath = ";C:\Program Files (x86)\Microsoft Visual Studio\2019\Enterprise\MSBuild\Current\Bin"
}
else {
    $msbuildpath = $Args[0]
}
Set-Item -Path Env:Path -Value ($Env:Path + $msbuildpath)
msbuild validatejwt.sln
cd .\Debug
.\validatejwt.exe
cd $curdir
