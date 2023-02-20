05 REM *** this simply tests the flags register for the HBSound ***
06 REM *** this is a good baseline test to see if it is working ***
07 REM *** this should output 1,0, and 2 in that order          ***
10 POKE &H9001,7                                                                
20 GOSUB 1000                                                                   
30 POKE &H9000,255                                                              
40 GOSUB 1000                                                                   
50 FOR A = 1 TO 17                                                              
60 POKE &H9000,255                                                              
70 NEXT A                                                                       
80 GOSUB 1000                                                                   
90 POKE &H9001,0                                                                
100 END                                                                         
1000 PRINT PEEK (&H9000)                                                        
1010 RETURN
