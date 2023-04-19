[![License: MIT](https://img.shields.io/github/license/MichaelWhyYou/diploma-project)](https://spdx.org/licenses/MIT.html) (Please leave credits)
# Diploma Project
#### Measuring Energy Consumption of Programming Languages and Investigating their Role in Green Computing.

# About
This repository contains the testing framework for my Gymnasium's **Diploma Project**. It aims to answer the following:
RQ1: Does the energy consumption of processing differ across different programming languages when performing the same set of tasks? 
RQ2: Is the faster programming language always the most energy efficient?

# Prerequisites
- **pyRAPL** must be installed. Can be installed with pip: `pip install pyRAPL`.
- Compilers/Interpreters of each programming language must be installed.
- Linux

# Basic usage
1. Grant sudo access for RAPL to access the machine's energy registers:
```
sudo chmod -R a+r /sys/class/powercap/intel-rapl
```
2. Run generate.py to generate input data
```
diploma-project/Test_Data_Maker/generate.py
```
3. Run brain.py to begin testing
```
diploma-project/brain.py
```
