## References 

The code in this directory is copied/pasted and reimplemented from:
* Greg Kostal's https://github.com/gkostal/attestation/tree/master/sgx.attest.sample/validatequotes.net
* Larry Osterman's https://github.com/LarryOsterman/RetrieveAndVerifyMetadataCerts/tree/master/VerifyMetadataCertificates

Thanks to Larry and Greg for the samples!

## Windows OS
#### Prerequisites
- [ ] Install cmake https://cmake.org/install/
- [ ] VS tools

#### Build and Run
```
.\windows_build_and_run.ps1
```
or
```
.\windows_build_and_run.ps1 PATH_TO_MSBUILD.EXE
```

## Linux
#### Prerequisites
ubuntu linux
```
sudo apt install -y cmake make g++
```
#### Build and Run
```
sudo chmod +x linux_build_and_run.sh
./linux_build_and_run.sh
```
