# µCLI

## Overview

EmbeddedCli is a lightweight library designed to streamline the integration of a command-line interface (CLI) into embedded projects utilizing microcontrollers. The primary objective is to facilitate seamless communication between the microcontroller and an external PC through commonly available interfaces such as UART or Ethernet.

## Background

I ran into an issue where I had unit test code within a soft-processor in an FPGA. The FPGA utilization reached 100% and with new features needed to be added, I needed to reduce the memory size of the soft-processor. This spread to the solution of having two builds, one with only soft-processor and its available peripherals, and another with the full build. This was not satisfactory as the ability to run tests with the full system was needed. This begain a long pain of opttimization for code size which wasn't necessary for the product itself, rather just for testing and bringup. To avoid this problem in the future, the solution is to offboard the unit test framework to a PC which can control the soft-processor over any interface.

## Goal

The goal of µCLI is to provide a readily deployable solution for incorporating a CLI into any microcontroller-based project with minimal overhead. By leveraging a standard debug interface like UART, developers can enable external control and monitoring of microcontroller functions.

## Usage TODO

1. Include the µCLI library in your project.
2. Configure the debug interface (UART, Ethernet, etc.) for communication with the external PC.
3. ...

## License

EmbeddedCli is licensed under the MIT License.
