// This file is part of www.nand2tetris.org
// and the book "The Elements of Computing Systems"
// by Nisan and Schocken, MIT Press.
// File name: projects/04/Fill.asm

// Runs an infinite loop that listens to the keyboard input.
// When a key is pressed (any key), the program blackens the screen,
// i.e. writes "black" in every pixel;
// the screen should remain fully black as long as the key is pressed. 
// When no key is pressed, the program clears the screen, i.e. writes
// "white" in every pixel;
// the screen should remain fully clear as long as no key is pressed.

// Put your code here.



// overarching loop to continually detect keypress
// and reset the variable that is holding the screen
// location
(RESET_SCREEN_LOC)
    // set variables to hold a counter for the screen words
    @ind
    M=0
    @LOOP
    0;JMP
 
// loop over the screen
// check if 
(LOOP)
    // check if new key on keyboard has been pressed
    @KBD
    D=M
    @KEYOFF
    D;JEQ
    @KEYON
    D;JNE

// if detect no input, set value register to 0
// else set it to 1 -> this will be used in the inner loops
(KEYON)
    @value
    M=-1
    @INNERLOOP
    0;JMP

(KEYOFF)
    @value 
    M=0
    @INNERLOOP
    0;JMP

(INNERLOOP)
    @ind
    D=M
    @8192
    D=A-D
    @RESET_SCREEN_LOC
    D;JLT

    // set ptr to have location based on SCREEN + ind
    @SCREEN
    D=A
    @ptr 
    M=D
    @ind
    D=M
    @ptr 
    M=M+D 

    // now load value 0 or 1 to write to screen location
    @value 
    D=M

    // load memory location into A register
    @ptr
    A=M

    // set memory location to have the value 0 or 1 
    M=D

    // increment ind 
    @ind 
    M=M+1

    @LOOP
    0;JMP