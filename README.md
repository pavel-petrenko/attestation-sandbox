# sandbox

## Build and Run

### Windows


```
$out = ".\out"
If((Test-Path $out))
{
    Remove-Item $folderPath -Force -Recurse -ErrorAction $out
}
New-Item -ItemType Directory -Force -Path $out
cd $out 
cmake ../

$Env:Path
Set-Item -Path Env:Path -Value ($Env:Path + ";C:\Program Files (x86)\Microsoft Visual Studio\2019\Enterprise\MSBuild\Current\Bin")
msbuild ValidateMaaJwt.sln
cd Debug

```
