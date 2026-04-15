ORG 0000H

START:
    MOV P1, #00H    

    ACALL DELAY

    MOV P1, #0FFH  

    ACALL DELAY

    SJMP START      

DELAY:
    MOV R2, #255
D1: MOV R1, #255
D2: DJNZ R1, D2
    DJNZ R2, D1
    RET

END