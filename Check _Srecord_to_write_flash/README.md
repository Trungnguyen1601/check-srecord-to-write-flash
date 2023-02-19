# Check Srecord 

This repository provides you check file Srcord.
## Guide

Motorola S-record is a file format, created by Motorola in the mid-1970s, that conveys binary information as hex values in ASCII text form. This file format may also be known as SRECORD, SREC, S19, S28, S37. It is commonly used for programming flash memory in microcontrollers, EPROMs, EEPROMs, and other types of programmable logic devices. In a typical application, a compiler or assembler converts a program's source code (such as C or assembly language) to machine code and outputs it into a HEX file. The HEX file is then imported by a programmer to "burn" the machine code into non-volatile memory, or is transferred to the target system for loading and execution.

An SREC format file consists of a series of ASCII text records. The records have the following structure from left to right:

Record start - each record begins with an uppercase letter "S" character (ASCII 0x53) which stands for "Start-of-Record".[2]
Record type - single numeric digit "0" to "9", defining the type of record.
Byte count - two hex digits, indicating the number of bytes (hex digit pairs) that follow in the rest of the record (address + data + checksum). This field has a minimum value of 3 for 16-bit address field plus 1 checksum byte, and a maximum value of 255 (0xFF).
Address - four / six / eight hex digits as determined by the record type. The address bytes are arranged in big-endian format.
Data - a sequence of 2n hex digits, for n bytes of the data. For S1/S2/S3 records, a maximum of 32 bytes per record is typical since it will fit on an 80 character wide terminal screen, though 16 bytes would be easier to visually decode each byte at a specific address.
Checksum - two hex digits, the least significant byte of ones' complement of the sum of the values represented by the two hex digit pairs for the byte count, address and data fields. See example section for a detailed checksum example.

## Doing

"https://en.wikipedia.org/wiki/SREC_(file_format)"

