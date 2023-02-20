/*Little Pathetic square wave tracker for the HBSound
 *---------------------------------------------------
 * here's a little tracker to test the sound card, 
 * and visualize the features in plain english.
 * 
 * there is 1 track, each note uses a value determined by
 * The Formula:
 *              RND((7200 / <note freq. in hz>)*2)
 *               (see the atatched spread sheet)
 * 
 * If I have done the math right %') it should be fairly
 * accurate.  You can set the BPM, Device addres, and 
 * skip note delay in the #Defines below
 * 
 * each frame 2.2mS long. (aprox) 
 * each note is 85 frames long you can change this by 
 * setting BPM #DEFINE
 * 
 * Released under CERN-OHL-P see attached docs for 
 * liablitiy release and legal details :)               
 *  C 2023 D. Collins                                    */

#include <cmoc.h>
#pragma limit 0x7EAA        // start ASSIST09 reserved memory starts here
//#pragma limit 0x7E3A      // start TRACE reserved mem starts here
//#pragma limit 0x7E2A      // start DISSASEMBLER reserved mem starts here
//#pragma limit 0x7FFF      // end of memory 32k 

#pragma org 0x179 

// ASSIST09 SYSTEM CALLS USED
#define OUTCH   1           // sends a character to the terminal
#define MONITR  8           // soft start ASSIST09

// HBSound Device Addresses
#define HBSNDD  0x9000      // HBSound Device base address
#define HBSNDR  0x9001      // HBSound Device Configuration Register

// Tracker Settings
#define BPM     85          // how many 2.2ms piriods to hold a note


// device pointers:
unsigned char* sample   = HBSNDD;
unsigned char* control  = HBSNDR;
unsigned char* flags    = HBSNDD;


// Global

unsigned char scpos = 0;              // position counter
unsigned char frequencyCount = 0;    // counter for frequency
unsigned char frequencyState = 0;    // state of frequency
unsigned int  bufferPeriod = 0;      // at 7.2kHz this works out to be about 2.2 ms 



// Tracker Data: (a certan song about a plumber!)
unsigned char noteslist[] = {22,22,22,
                             28,22,18,37,
                             0,0,
                             28,37,44,
                             33,29,31,33,
                             37,22,18,16,
                             21,18,22,28,25,29,
                             0,0,
                             28,37,44,
                             33,29,31,33,
                             37,22,18,16,
                             21,18,22,28,25,29,
                             0,0,
                             18,19,21,25,22,
                             37,33,28,0,
                             33,28,25,
                             18,19,21,25,22,
                             14,14,14,
                             0,0,
                             18,19,21,25,22,
                             37,33,28,
                             33,28,25,
                             23,25,28,
                             0,0,                                      
                             28,28,28,
                             28,25,22,28,33,37,
                             28,28,28,
                             28,25,22,
                             0,0,
                             28,28,28,
                             28,25,22,28,33,37,
                             22,22,22,
                             28,22,18,0,
                             37,
                             0,0,
                             28,37,44,
                             33,29,31,33,
                             37,22,18,16,
                             21,18,22,28,25,29,
                             0,0,
                             28,37,44,
                             33,29,31,33,
                             37,22,18,16,
                             21,18,22,28,25,29,
                             0,0,
                             22,28,37,
                             37,33,21,21,33,
                             29,16,16,16,18,21,
                             22,28,33,37,
                             0,0,
                             22,28,37,
                             37,33,21,21,33,
                             29,21,21,21,22,25,28,
                             37,44,55,
                             0,0,
                             28,37,44,
                             33,29,33,
                             35,31,35,
                             37,39,37
};

// lets redirect printf... ASSIST09 has a built in character output
asm void newOutputRoutine(void) {
    asm {
        pshs    x,b         // save registers swi handler uses them 
        swi
        fcb     OUTCH       // system call to ASSIST09 Sends ch in A Reg to Screen
        puls     b,x        // put them back
    }
}

// call the monitor to soft-start...
asm void softStart(void) {
    asm {
        swi
        fcb     MONITR      // system call to ASSIST09 Soft start to system
    }
}

// Fill up the buffer till flags indicate it's full.
void fillBuffer (unsigned char maxFrequencyCount) {
    while (*flags != 2) {       // while not full
        if (maxFrequencyCount == 0)  {           // handles control code
            frequencyState = 0;
            goto CNTCODE;
        }
        
        frequencyCount++;
        
        if (frequencyCount == maxFrequencyCount) {
            frequencyState = !frequencyState;   //switch dac between high and low
            frequencyCount = 0;
        }
        CNTCODE:
        *sample = frequencyState;
    }
}


int main() {
    // console redirect for CMOC 
    setConsoleOutHook(newOutputRoutine);

    // clear the screen and set up the on screen graphics
    printf("%c[2J",27);
    printf("---------------+\n");
    printf("               |\n");
    printf("               |\n");
    printf("               |\n");
    printf("               |\n");
    printf("               |\n");
    printf("               |\n");
    printf("               |\n");
    printf("               |\n");
    printf("               |\n");
    printf("---------------+\n");
    printf("Frame Note Tone\n\n");
    printf("PathiTrack6809 (C) - 2023 D.Collins\n\n"); 
    printf("Mario Bros ""Ground Theme"" \n"); 
    printf("Original Arr. Koji Kondo,1985");
    
    printf("%c[H",27);
    
    *control = 3;  //Set DAC Clock to slowest speed
    unsigned int tones = sizeof(noteslist);
    unsigned int note;
    for (note = 0; note < tones ; note++) {  // determines what note we are on
        scpos++;
        if (scpos == 9) {                    //this manages the tracker window
            printf("%c[H",27);
            scpos = 0;
        }
        // right before the note plays...
        printf("\n    : %3d | %2d",note,noteslist[note]);  // prints curent note
        // this is one note
        while (bufferPeriod != BPM) {
            while (*flags !=1) {        //while not empty
              // do stuff here    
            }
            bufferPeriod++;
            fillBuffer(noteslist[note]);
            // or do stuff here!
            printf("%c%d",13,bufferPeriod);        // prints the position in frame
        }
    frequencyCount = 0;    // counter for frequency
    frequencyState = 0;    // state of frequency
    bufferPeriod = 0; 
    }   
    scpos = 0;
    *control = 0;
    printf("%c[18;0H",27);
    softStart();            //Return to monitor
    return(0);
}
