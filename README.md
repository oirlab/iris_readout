IRIS DRS ROP C Library
=============================

C readout library for the TMT/IRIS instrument

## Getting Started
These instructions will get you a copy of the project up and running on your local machine for development and testing purposes. 

### Prerequisites
```
cfitsio
cmocka
```


# Installation


Execute the following commands for installation
```
$ sh autogen .sh
$ ./configure
$ make
$ sudo make install
```

# Usage
```
iris_readout -s utr/cds/mcds /path/filename.fits
```

# Examples
```
iris_readout -s utr ../data/sample_ramp.fits
```
# Tests
```
./tests
```
