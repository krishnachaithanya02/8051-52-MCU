ORG 0000H

MOV A, #0FEH      

MAIN:
    MOV P1, A  
    ACALL DELAY   

    RL A          
    SJMP MAIN     

DELAY:
    MOV R7, #200
D1: MOV R6, #200
D2: DJNZ R6, D2
    DJNZ R7, D1
    RET

END