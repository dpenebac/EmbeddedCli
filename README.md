# µRun

## Overview

µRun is a small tool that helps easily run functions in embedded projects with microcontrollers. It makes it simple to trigger specific actions from a computer, connecting to the microcontroller through common interfaces like UART or Ethernet.

## Background

I ran into an issue where I had unit test code within a soft-processor in an FPGA. The FPGA utilization reached 100% and with new features needed to be added, I needed to reduce the memory size of the soft-processor. This spread to the solution of having two builds, one with only soft-processor and its available peripherals, and another with the full build. This was not satisfactory as the ability to run tests with the full system was needed. This begain a long pain of opttimization for code size which wasn't necessary for the product itself, rather just for testing and bringup. To avoid this problem in the future, the solution is to offboard the unit test framework to a PC which can control the soft-processor over any interface.

## Usage TODO

1. Include the µRun library in your project.
2. Configure the debug interface (UART, Ethernet, etc.) for communication with the external PC.
3. ...

## License

µRun is licensed under the MIT License.
